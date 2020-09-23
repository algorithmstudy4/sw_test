#드래곤 커브
#https://www.acmicpc.net/problem/15685
import sys
sys.stdin = open("input.txt","r")
board=[[0]*101 for _ in range(101)]
dh=[0,-1,0,1] # -> 위 <- 아래
dw=[1,0,-1,0]
n=int(input())
for _ in range(n):
    x,y,d,g=map(int,input().split())
    board[y][x]=1
    cur=[d]
    for _ in range(g):  
        tmp=cur
        tmp=tmp[::-1] 
        for i in range(len(tmp)):
            tmp[i]=(tmp[i]+1)%4
        cur+=tmp 
    for dir in cur:
        h = y + dh[dir]
        w = x + dw[dir]
        board[h][w]=1
        y,x=h,w

sol=0
for i in range(100):
    for j in range(100):
        if board[i][j] and board[i][j+1] and board[i+1][j] and board[i+1][j+1]:
            sol+=1
print(sol)
