#사다리 조작
#https://www.acmicpc.net/problem/15684
import sys
sys.stdin = open("input.txt","r")
n,m,height=map(int,input().split())
board=[[0]*(n+1) for _ in range(height+1)]
sol=4 
def check(): 
    for k in range(1,n+1):
        goal=k
        for i in range(1,height+1):
            if board[i][goal]==1:
                goal+=1
            elif board[i][goal-1]==1: 
                goal-=1
        if goal != k:
            return False
    return True
def dfs(h,w,cnt):
    global sol
    if cnt>= sol: 
        return
    if check()==True:
        sol=cnt
        return
    if cnt==3:
        sol = cnt
        return
    else:
        for i in range(h,height+1):
            for j in range(w,n):
                if board[i][j]==0 and board[i][j-1]==0 and board[i][j+1]==0:
                    board[i][j]=1
                    dfs(i,j,cnt+1)
                    board[i][j]=0
            w=1

for _ in range(m):
    a,b=map(int,input().split())
    board[a][b]=1

dfs(1,1,0)

if sol>3:
    sol=-1
print(sol)
