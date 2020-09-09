#2048
#https://www.acmicpc.net/problem/12100
import sys
from collections import deque
sys.stdin = open("input.txt","r")
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
sol=0
q=deque()

def get(i, j):
    if board[i][j]!=0: #0이 아닌 값이면
        q.append(board[i][j])
        board[i][j] = 0 #처리 된 것 0으로

def merge(i, j, di, dj):
    while q:
        x = q.popleft()
        if not board[i][j]: #0이라면
            board[i][j] = x #0
        elif board[i][j] == x:
            board[i][j] = x*2 #2베
            i, j = i+di, j+dj
        else: #값이 다르면
            i, j = i+di, j+dj #다음 좌표에 꺼낸 숫자를 넣음
            board[i][j] = x

def move(k):
    if k == 0: #위로 이동
        for j in range(n):
            for i in range(n):
                get(i, j)
            merge(0, j, 1, 0)
    elif k == 1: #아래
        for j in range(n):
            for i in range(n-1, -1, -1):
                get(i, j)
            merge(n-1, j, -1, 0)
    elif k == 2: #오른쪽
        for i in range(n):
            for j in range(n):
                get(i, j)
            merge(i, 0, 0, 1)
    else: #왼쪽       
         for i in range(n):
            for j in range(n-1, -1, -1):
                get(i, j)
            merge(i, n-1, 0, -1)

def dfs(cnt):
    global board, sol
    if cnt == 5:
        for i in range(n):
            sol = max(sol, max(board[i]))
        return
    b = [x[:] for x in board] #기존의 보드 복사
    for k in range(4): #상, 하, 좌 , 우 이동 가능
        move(k)
        dfs(cnt+1)
        board = [x[:] for x in b] #움직인 후 보드 복사

dfs(0)
print(sol)
