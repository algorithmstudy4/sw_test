#청소년상어
#https://www.acmicpc.net/problem/19236
import sys
import copy
sys.stdin = open("input.txt","r")
dh=[-1,-1,0,1,1,1,0,-1] #↑, ↖, ←, ↙, ↓, ↘, →, ↗
dw=[0,-1,-1,-1,0,1,1,1]
result=0
board=[[None]*4 for _ in range(4)]

for i in range(4):
    data=list(map(int,input().split()))
    for j in range(4):
        board[i][j]=[data[j*2],data[j*2+1]-1] #물고기번호, 방향

def turn_left(direction):
    return (direction+1)%8

def find_fish(board,index):
    for i in range(4):
        for j in range(4):
            if board[i][j][0] == index:
                return (i,j)
    return None

def move_fish(board,curh,curw):
    for i in range(1,17):
        pos=find_fish(board,i)
        if pos !=None:
            h,w=pos[0],pos[1]
            direction = board[h][w][1]
            for j in range(8):
                nh= h + dh[direction]
                nw= w+ dw[direction]
                if 0<=nh<4 and 0<=nw<4:
                    if not (nh == curh and nw == curw):
                        board[h][w][1]=direction
                        board[h][w],board[nh][nw]=board[nh][nw],board[h][w]
                        break
                direction = turn_left(direction)


def move_shark(board,curh,curw):
    shark=[]
    direction=board[curh][curw][1]
    for i in range(4):
        curh+=dh[direction]
        curw+=dw[direction]
        if 0<=curh<4 and 0<=curw<4:
            if board[curh][curw][0]!=-1:
                shark.append((curh,curw))
    return shark

def dfs(board,curh,curw,cnt):
    global result
    board=copy.deepcopy(board) 

    cnt+=board[curh][curw][0]
    board[curh][curw][0]=-1

    move_fish(board,curh,curw) 
    shark=move_shark(board,curh,curw)
   
    if len(shark)==0:
        result=max(result,cnt)
        return

    for nh,nw in shark:
        dfs(board,nh,nw,cnt)

dfs(board,0,0,0)
print(result)
