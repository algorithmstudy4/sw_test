#나이트의 이동
#https://www.acmicpc.net/problem/7562
import sys
from collections import deque
sys.stdin = open("input.txt","r")
dh=[-2,-1,1,2,2,1,-1,-2]
dw=[1,2,2,1,-1,-2,-2,-1]
t=int(input())

def BFS(h,w):
    Q=deque()
    Q.append((h,w))
    visited[h][w]=1
    if h==eh and w==ew:
        return
    while Q:
        h,w=Q.popleft()
        for i in range(8):
            nh=h+dh[i]
            nw=w+dw[i]
            if 0<=nh<n and 0<=nw<n and visited[nh][nw]==0:
                Q.append((nh,nw))
                visited[nh][nw]=visited[h][w]+1


while t>0:
    t-=1
    n=int(input())
    board=[[0]*n for _ in range(n)]
    visited = [[0] * n for _ in range(n)]
    sh,sw=map(int,input().split())
    eh, ew = map(int, input().split())
    BFS(sh,sw)
    print(visited[eh][ew]-1)
