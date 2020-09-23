#이차원배열과연산
#https://www.acmicpc.net/problem/17140
import sys
from collections import Counter
from functools import reduce
sys.stdin = open("input.txt","r")

r,c,k = map(int,input().split())
r,c = r-1, c-1
board=[list(map(int,input().split())) for _ in range(3)]
t=0

def solve(board):
    maxv = 0 
    for i in range(len(board)):
        cnt = Counter(board[i])
        del cnt[0] 
        cnt = list(cnt.items())
        cnt.sort(key=lambda x: (x[1], x[0]))
        if len(cnt) > 50:
            cnt = cnt[:50]  
        board[i] = reduce(lambda x, y: list(x) + list(y), cnt[1:], list(cnt[0]))
        maxv = max(maxv, len(board[i]))

    for i in range(len(board)):
        if len(board[i]) < maxv:
            board[i].extend([0] * (maxv - len(board[i])))

if r < len(board) and c < len(board[0]):
    if board[r][c]==k:
        print(t)
        sys.exit(0)

while True:
    if len(board) >= len(board[0]): 
        solve(board)  
    else:  
        board = list(map(list, zip(*board))) 
        solve(board) 
        board = list(map(list, zip(*board))) 
    t += 1
    if t > 100:
        t=-1
        break
    if r < len(board) and c < len(board[0]):
        if board[r][c] == k:
            break


print(t)
