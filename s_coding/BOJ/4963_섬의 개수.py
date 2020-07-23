#섬의 개수
#https://www.acmicpc.net/problem/4963
import sys
from collections import deque
sys.stdin = open("input.txt","r")
input=sys.stdin.readline
dh=[-1,0,1,0,-1,1,1,-1] #8방향
dw=[0,1,0,-1,1,1,-1,-1]

def BFS(h,w):
    board[h][w]=0 #방문표시
    Q.append((h,w))
    while Q:
        h,w=Q.popleft()
        for i in range(8):
            nh=h+dh[i]
            nw=w+dw[i]
            if 0<=nh<H and 0<=nw<W and board[nh][nw]==1:
                board[nh][nw] = 0  # 방문표시
                Q.append((nh,nw))


while True:
    W,H=map(int,input().split())
    if W==0 and H==0:
        break
    board=[list(map(int,input().split())) for _ in range(H)]
    cnt=0
    Q = deque()

    for i in range(H):
        for j in range(W):
            if board[i][j]==1:
                BFS(i,j)
                cnt+=1
    print(cnt)
