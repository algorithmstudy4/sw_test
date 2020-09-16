#나무 재테크
#https://www.acmicpc.net/problem/16235
import sys
sys.stdin = open("input.txt","r")
n,m,k=map(int,input().split())
A=[list(map(int,input().split())) for _ in range(n)]
nutrient=[[5]*n for _ in range(n)]
tree=[[[] for i in range(n)] for _ in range(n)]
dh=[-1,-1,-1,0,0,1,1,1]
dw=[-1,0,1,-1,1,-1,0,1]

for _ in range(m):
    h,w,age=map(int,input().split())
    tree[h-1][w-1].append(age)

for _ in range(k): # 몇 년
    for i in range(n):
        for j in range(n):
            if tree[i][j]: 
                next_tree=[]
                nutri=0
                #봄. 나이만큼 양분먹고, 나이 1 증가 
                for t in tree[i][j]: #t 나이
                    if nutrient[i][j]>=t:
                        nutrient[i][j]-=t
                        next_tree.append(t+1)
                    else: #여름
                        nutri+=t//2 #죽는나무
                tree[i][j]=next_tree
                nutrient[i][j]+=nutri #여름
    for i in range(n):
        for j in range(n):
            for t in tree[i][j]: #가을
                if t%5==0: 
                    for d in range(8): 
                        if 0<=i+dh[d]<n and 0<=j+dw[d]<n:
                            tree[i+dh[d]][j+dw[d]].insert(0,1)
            #겨울
            nutrient[i][j]+=A[i][j]
cnt=0
for i in range(n):
    for j in range(n):
        cnt+=len(tree[i][j])
print(cnt)
