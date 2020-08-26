#뱀
#https://www.acmicpc.net/problem/3190
import sys
from collections import deque
sys.stdin = open("input.txt","r")
n=int(input()) #보드의 크기
k=int(input()) #사과의 개수
board=[[0]*(n+1) for _ in range(n+1)]
dir=[] #방향 저장

for i in range(k):
    a,b=map(int,input().split())
    board[a][b]=1

l=int(input()) #뱀의 방향 전환 횟수
for _ in range(l):
    x,c=input().split()
    dir.append((int(x),c))
dh=[-1,0,1,0] #북 동 남 서
dw=[0,1,0,-1]

def rotate(d,c):
    if c=="D": #오른쪽
        d = (d + 1) % 4
    else: #왼쪽
        d = (d + 3) % 4
    return d

def simulate():
    h,w=1,1 
    board[h][w]=2 
    direction=1
    t=0 #시간
    nextdir =0 #다음에 회전할 정보
    q=deque() #q=[(h,w)] 리스트로 풀어도됨 
    q.append((h,w))
    while True:
        nh = h + dh[direction]
        nw = w + dw[direction]
        if 1<=nh<=n and 1<=nw<=n and board[nh][nw] !=2:
            #사과가 없으면 이동 후에 꼬리 제거
            if board[nh][nw]==0:
                board[nh][nw]=2 #이동
                q.append((nh,nw))
                curh,curw = q.popleft()
                board[curh][curw]=0 #꼬리 자르기
            if board[nh][nw]==1:
                board[nh][nw]=2
                q.append((nh,nw)) #꼬리는 냅두고 머리 새롭게 넣기
        else: #뱀이나 뱀의 몸통과 부딪히면
            t+=1
            break
        h,w=nh,nw 
        t+=1
        #방향 변환
        if nextdir<l and t==dir[nextdir][0]:
            direction = rotate(direction, dir[nextdir][1])
            nextdir+=1
    return t
print(simulate())
