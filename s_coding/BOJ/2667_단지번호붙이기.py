#단지번호붙이기
#https://www.acmicpc.net/problem/2667
import sys
sys.stdin = open("input.txt","r")
dh=[-1,1,0,0]
dw=[0,0,-1,1]
def DFS(h,w):
    global cnt
    board[h][w] = 0
    cnt += 1
    for i in range(4):
        nh=h+dh[i]
        nw=w+dw[i]
        if 0<=nh<n and 0<=nw<n and board[nh][nw]==1:
            DFS(nh,nw)


if __name__=="__main__":
    n=int(input())
    board = [list(map(int, input())) for _ in range(n)]
    res=[]
    cnt=0
    num=0
    for i in range(n):
        for j in range(n):
            if board[i][j]==1:
                num+=1
                cnt=0
                DFS(i, j)
                res.append(cnt)
    print(num)
    res.sort()
    for x in res:
        print(x)
