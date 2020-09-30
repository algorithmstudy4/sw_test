#어른상어
#https://www.acmicpc.net/problem/19237
import sys
sys.stdin = open("input.txt","r")
input=sys.stdin.readline
n,m,k=map(int,input().split())
board=[list(map(int,input().split())) for _ in range(n)]
directions=list(map(int,input().split())) #1,2,3,4 = 위,아래,왼,오
priority=[[] for _ in range(m)]
for i in range(m):
    for j in range(4):
        priority[i].append(list(map(int,input().split())))
smell=[[[0,0]]*n for _ in range(n)]
dh=[-1,1,0,0]
dw=[0,0,-1,1]

def update_smell():
    for i in range(n):
        for j in range(n):
            if smell[i][j][1]>0:
                smell[i][j][1]-=1
            if board[i][j]!=0:
                smell[i][j]=[board[i][j],k] 

def move():
    tmp=[[0]*n for _ in range(n)]
    for h in range(n):
        for w in range(n):
            if board[h][w]!=0:
                dir=directions[board[h][w]-1] 
                flag=False
                for i in range(4):
                    nh=h+dh[priority[board[h][w]-1][dir-1][i]-1]
                    nw=w+dw[priority[board[h][w]-1][dir-1][i]-1]
                    if 0<=nh<n and 0<=nw<n:
                        if smell[nh][nw][1]==0:
                            directions[board[h][w]-1]=priority[board[h][w]-1][dir-1][i]
                            if tmp[nh][nw]==0: 
                                tmp[nh][nw]=board[h][w]
                            else:
                                tmp[nh][nw]=min(tmp[nh][nw],board[h][w])
                            flag=True
                            break
                if flag==True:
                    continue
                for i in range(4):
                    nh=h+dh[priority[board[h][w]-1][dir-1][i]-1]
                    nw=w+dw[priority[board[h][w]-1][dir-1][i]-1]
                    if 0<=nh<n and 0<=nw<n:
                        if smell[nh][nw][0]==board[h][w]:
                            directions[board[h][w]-1]=priority[board[h][w]-1][dir-1][i]
                            tmp[nh][nw]=board[h][w]
                            break
    return tmp
t=0
while True:
    update_smell() 
    tmp=move()
    board=tmp
    t+=1

    one=True
    for i in range(n):
        for j in range(n):
            if board[i][j]>1:
                one=False
    if one:
        print(t)
        break

    if t>=1000:
        print(-1)
        break
