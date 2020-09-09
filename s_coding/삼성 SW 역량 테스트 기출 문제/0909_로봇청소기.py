#로봇 청소기
#https://www.acmicpc.net/problem/14503
import sys
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())
r,c,d=map(int,input().split())
board=[list(map(int,input().split())) for _ in range(n)]
dh=[-1,0,1,0]
dw=[0,1,0,-1]
board[r][c]=2 #현재 위치를 청소한다
cnt=1
def solve(h,w,d):
    global cnt
    while True:
        flag=False
        for i in range(4):
            nd = (d + 3) % 4
            nh=h+dh[nd]
            nw=w+dw[nd]
            d=nd
            # 왼쪽방향에 청소하지않은 곳이 존재하면, 그방향 회전,다음 전진, 다시 위로진행
            if board[nh][nw] == 0:
                board[nh][nw] = 2  # 청소한다
                h, w = nh, nw
                cnt += 1
                flag=True
                break
        # 네방향모두 청소되어 있거나 벽이면(네방향 모두 2(청소)나 1(벽)이 나오면 false일 수 밖에 없음
        if flag==False:
            if board[h-dh[d]][w-dw[d]] ==1 : #후진 시 벽이면
                return #작동을 멈춘다
            else:
                h,w=h-dh[d],w-dw[d] #후진한다
solve(r,c,d)
print(cnt)
