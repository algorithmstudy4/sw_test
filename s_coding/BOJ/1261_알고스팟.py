#알고스팟
#https://www.acmicpc.net/problem/1261
#최적의 경로에 1의 개수가 몇개인가?
import sys
from collections import deque
sys.stdin = open("input.txt","r")
#input=sys.stdin.readline
m,n=map(int,input().split()) #가로, 세로
board = [list(map(int, input())) for _ in range(n)] #붙어있는 입력 받기
visited = [[0]*(m) for _ in range(n)]

dh=[-1,1,0,0]
dw=[0,0,-1,1]
Q=deque()
Q.append((0,0))
visited[0][0]=1
while Q:
    h,w=Q.popleft()
    if h==n-1 and w==m-1 :
        break
    for i in range(4):
        nh=h+dh[i]
        nw=w+dw[i]
        if 0<=nh<n and 0<=nw<m and visited[nh][nw]==0:
            if board[nh][nw]==0:
                Q.appendleft((nh,nw))
                visited[nh][nw]=visited[h][w]
            else :
                Q.append((nh, nw))
                visited[nh][nw] = visited[h][w] + 1

print(visited[n-1][m-1]-1)
