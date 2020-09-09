#미세먼지 안녕!
#https://www.acmicpc.net/problem/17144
import sys
sys.stdin = open("input.txt","r")
r,c,time=map(int,input().split())
board=[]
air=[]
dh=[-1,1,0,0]
dw=[0,0,-1,1]
t=0
for i in range(r):
    board.append(list(map(int,input().split())))
    for j in range(c):
        if board[i][j]==-1:
            air.append((i,j))

def diffuse():
    tmp=[[0]*c for _ in range(r)]
    for h in range(r):
        for w in range(c):
            if board[h][w]>0: #미세먼지
                p=board[h][w]//5
                for i in range(4):
                    nh=h+dh[i]
                    nw=w+dw[i]
                    if nh<0 or nh>=r or nw<0 or nw>=c or board[nh][nw]==-1:
                        continue
                    tmp[nh][nw]+=p
                    board[h][w]-=p

    for i in range(r): #합치는 과정
        for j in range(c):
            board[i][j]+=tmp[i][j]
def clean():
    airh,airw=air[0]

    #위쪽 반시계 방향
    #왼
    for i in range(airh-2,-1,-1): #for문은 시계방향
        board[i+1][0]=board[i][0] #반시계방향
    #위
    for i in range(c-1):
        board[0][i]=board[0][i+1]
    #오
    for i in range(airh):
        board[i][c-1]=board[i+1][c-1]

    #아래
    for i in range(c-2,-1,-1):
        board[airh][i+1]=board[airh][i]

    board[airh][1]=0


    airh,airw=air[1]
    #아래쪽 시계방향
    #왼
    for i in range(airh+1,r-1):
        board[i][0]=board[i+1][0]

    for i in range(c-1):
        board[r-1][i]=board[r-1][i+1]

    #오
    for i in range(r-2,airh-1,-1):
        board[i+1][c-1]=board[i][c-1]

    #위
    for i in range(c-2,0,-1):
        board[airh][i+1]=board[airh][i]

    board[airh][1]=0

while True:
    if t==time:
        print(sum(map(sum,board))+2)
        break
    diffuse() #오염 확산
    clean() #공기청정
    t+=1
