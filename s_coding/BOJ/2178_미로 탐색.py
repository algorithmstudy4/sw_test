#미로 탐색
#https://www.acmicpc.net/problem/2178
import sys
from collections import deque
sys.stdin = open("input.txt","r")
dh=[-1,1,0,0]
dw=[0,0,-1,1]
n,m=map(int,input().split())
board=[list(map(int,input())) for _ in range(n) ]
dis=[[0]*m for _ in range(n)]
Q=deque()
Q.append((0,0)) #출발점
board[0][0]=0
while Q:
    cur=Q.popleft()
    for i in range(4):
        nh=cur[0]+dh[i]
        nw=cur[1]+dw[i]
        if 0<=nh<n and 0<=nw<m and board[nh][nw]==1:
            board[nh][nw]=0
            dis[nh][nw]=dis[cur[0]][cur[1]]+1
            Q.append((nh,nw))
if dis[n-1][m-1]+1==0:
    print(-1)
else:
    print(dis[n-1][m-1]+1)
for x in dis:
    print(x,end=' ')
    print()
