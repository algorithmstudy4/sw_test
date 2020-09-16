#연구소 3
#https://www.acmicpc.net/problem/17142
import sys
from collections import deque
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())
board=[list(map(int, input().split())) for _ in range(n)]
selected=[False]*10 #바이러스 최대 10개 가능 
dh=[-1,0,1,0]
dw=[0,1,0,-1]
virus=[] #바이러스
q=deque()
empty=0
sol=1e9
for i in range(n):
    for j in range(n):
        if board[i][j]==2:
            virus.append((i,j))
        if board[i][j]==0:
            empty+=1

def bfs(visited):
    global sol
    v=0
    t=0
    while q:
        h,w=q.popleft()
        for i in range(4):
            nh=h+dh[i]
            nw=w+dw[i]
            if 0<=nh<n and 0<=nw<n:
                if board[nh][nw]!=1 and visited[nh][nw]==-1:
                    visited[nh][nw]=visited[h][w]+1
                    q.append((nh,nw))
                    if board[nh][nw]==0: #바이러스 전염
                        v+=1
                        t=visited[nh][nw]
    if v==empty: #최소시간
        sol=min(sol,t)

def dfs(idx,cnt,d):
    if cnt==m:
        visited=[[-1]*n for _ in range(n)]
        for i in range(d):
            if selected[i]:
                h,w=virus[i]
                q.append((h,w))
                visited[h][w]=0
        bfs(visited)
        return
    else:
        for i in range(idx,d):
            if not selected[i]:
                selected[i]=True
                dfs(i+1,cnt+1,d)
                selected[i]=False

dfs(0,0,len(virus))
if sol==1e9:
    print(-1)
else:
    print(sol)
