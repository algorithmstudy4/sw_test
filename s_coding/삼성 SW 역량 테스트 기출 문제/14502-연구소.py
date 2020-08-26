#연구소
#https://www.acmicpc.net/problem/14502
import sys
import copy
from collections import deque
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())
board=[list(map(int,input().split())) for _ in range(n)]

dh=[1,-1,0,0]
dw=[0,0,-1,1]
maxv=-1e9

def BFS(i,j,afterwall,visited): #바이러스 퍼뜨리기
    cnt=0
    visited[i][j]=True
    q=deque()
    q.append((i,j))
    while q:
        cur=q.popleft()
        for i in range(4):
            nh=cur[0]+dh[i]
            nw=cur[1]+dw[i]
            if nh<0 or nh>=n or nw<0 or nw>=m or visited[nh][nw]==True:
                continue
            if afterwall[nh][nw]==0:
                q.append((nh,nw))
                visited[nh][nw]=True
                afterwall[nh][nw]=2

    return cnt

def wall(d): #벽을 세우는 함수

    global maxv
    if d==3: #벽이 세개면
        sol= Solve()
        maxv = max(maxv, sol)
        return
    else:
        for i in range(n):
            for j in range(m):
                if board[i][j]==0:
                    board[i][j]=1 #울타리 설치
                    wall(d+1)
                    board[i][j]=0

def Solve():
    afterwall=copy.deepcopy(board)
    cnt=0
    global sol
    visited = [[False] * (m + 1) for _ in range(n)] #방문초기화
    for i in range(n):
        for j in range(m):
            if afterwall[i][j]==2 and visited[i][j]==False:
                BFS(i,j,afterwall,visited)
    for i in range(n):
        for j in range(m):
            if afterwall[i][j] == 0:
                cnt+=1
    return cnt


wall(0)
print(maxv)
