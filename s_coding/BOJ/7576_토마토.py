#토마토
#https://www.acmicpc.net/problem/7576
import sys
from collections import deque
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())
board=[list(map(int,input().split())) for _ in range(m)]
dh=[-1,1,0,0]
dw=[0,0,-1,1]
Q=deque()

def BFS(h,w):

    while Q:
        cur=Q.popleft()
        for i in range(4):
            nh=cur[0]+dh[i]
            nw=cur[1]+dw[i]
            if 0<=nh<m and 0<=nw<n and board[nh][nw]==0:
                board[nh][nw]=board[cur[0]][cur[1]]+1
                Q.append((nh,nw))

#출발점 넣기
for i in range(m):
    for j in range(n):
        if board[i][j]==1:
            Q.append((i,j))

BFS(0,0)

for x in board:
    print(x)

flag=0
for i in range(m):
    for j in range(n):
        if board[i][j]==0:
            flag=1 #안익은 토마토 있음

if flag==1:#안익은 토마토 있으면
    print(-1)
else: #익었으면
    res=0
    for i in range(m):
        for j in range(n):
            res=max(res,board[i][j])
    print(res-1)
