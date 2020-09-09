#아기상어
#https://www.acmicpc.net/problem/16236
import sys
from collections import deque
sys.stdin = open("input.txt","r")
n=int(input())
board=[list(map(int,input().split())) for _ in range(n)]
dh=[-1,1,0,0]
dw=[0,0,-1,1]
INF = 1e9

shark_size=2 #아기상어 크기
sh,sw=0,0

#아기상어 위치 찾기
for i in range(n):
    for j in range(n):
        if board[i][j]==9:
            sh,sw=i,j
            board[sh][sw]=0

#최단 거리 계산
def bfs():
    dist=[[-1]*n for _ in range(n)]
    q=deque([(sh,sw)])
    dist[sh][sw]=0
    while q:
        curh,curw=q.popleft()
        for i in range(4):
            nh=dh[i]+curh
            nw=dw[i]+curw
            if nh<0 or nh>=n or nw<0 or nw>=n:
                continue
            if dist[nh][nw]==-1 and board[nh][nw]<=shark_size:
                #아직 방문하지 않았거나 , 물고기가 상어보다 작거나같으면
                dist[nh][nw]=dist[curh][curw]+1
                q.append((nh,nw))

    return dist #최단 거리 테이블

#먹을 물고기 찾기
def find(dist):
    h,w=0,0
    min_dist=INF
    for i in range(n):
        for j in range(n):
            #도달 가능하면서 먹을 수 있는 물고기
            if dist[i][j]!=-1 and 1<=board[i][j]<shark_size:
                if dist[i][j]<min_dist:
                    h,w=i,j
                    min_dist=dist[i][j] #가장 가까운 물고기 선택
    if min_dist == INF : #가장 가까운 물고기가 없으면
        return None
    else:
        return h,w,min_dist

t=0
ate =0 #먹은 양
while True:
    fish=find(bfs())
    if fish==None: #먹을 수 있는 물고기 없으면
        print(t)
        break
    else:
        sh,sw=fish[0],fish[1]
        t+=fish[2]
        #먹은 위치 제거
        board[sh][sw]=0
        ate+=1
        if ate >= shark_size: #먹은양이 상어크기보다 같거나 크면
            shark_size+=1
            ate=0
