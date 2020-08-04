#안전영역 DFS
#https://www.acmicpc.net/problem/2468
import sys
sys.stdin = open("input.txt","r")

dh=[-1,1,0,0]
dw=[0,0,-1,1]
sys.setrecursionlimit(10**6) #재귀 허용 깊이를 늘려주는 경우
def DFS(h,w,t):

    visited[h][w]=1

    for i in range(4):
        nh=h+dh[i]
        nw=w+dw[i]
        if 0 <= nh < n and 0 <= nw < n and visited[nh][nw]==0 and board[nh][nw]>t:
            DFS(nh,nw,t)


if __name__=="__main__":
    n=int(input())
    board = [list(map(int, input().split())) for _ in range(n)]
    top=0
    res=0
    for t in range(100):
        visited=[[0]*n for _ in range(n)]
        safe=0
        for i in range(n): #제일 높은 위치 찾기
            for j in range(n):
                if visited[i][j]==0 and board[i][j]>t: #방문하지 않았고, 높이보다 큰 경우
                    DFS(i,j,t)
                    safe+=1
        if res<safe:
            res=safe
        if safe==0:
            break
    print(res)
