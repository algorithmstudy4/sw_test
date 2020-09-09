#치킨배달
#https://www.acmicpc.net/problem/15686
import sys
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())
board=[list(map(int,input().split())) for _ in range(n)]
home=[]
chicken=[] #치킨집
result=[]
for i in range(n):
    for j in range(n):
        if board[i][j]==1:#집
            home.append((i,j))
        if board[i][j]==2: #치킨집
            chicken.append((i,j))
check=[0]*(len(chicken)) #치킨집 체크 배열
selected=[] #선택된 치킨집의 개수
def chicken_distance(chick):
    dist = [5000] * (len(home))
    for i,j in chick:
        for k in range(len(home)):
            a,b=home[k]
            tmp=abs(i-a)+abs(j-b)
            dist[k]=min(dist[k],tmp)
    return sum(dist)

#치킨집 중에서 m개 만큼 뽑음
def dfs(d,s):
    res=0
    if d==m:
        for i in range(len(chicken)):
            if check[i]==1:
                selected.append(chicken[i])
        #print(selected)
        cd=chicken_distance(selected)
        res=max(cd,res)
        selected.clear()
        #print(res)
        result.append(res)
    else:
        for i in range(s,len(chicken)):
            check[i]=1
            dfs(d+1,i+1)
            check[i]=0


dfs(0,0)
print(min(result))
