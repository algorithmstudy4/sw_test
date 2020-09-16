#구슬탈출2
#https://www.acmicpc.net/problem/13460
import sys
from collections import deque
sys.stdin = open("input.txt","r")
n, m = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline()) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if board[i][j] == 'R':
            board[i][j] = '.'
            red = [i, j]
        elif board[i][j] == 'B':
            board[i][j] = '.'
            blue = [i, j]


def move(h,w, dh, dw):
    cnt = 0
    while board[h+dh][w+dw] != '#':
        if board[h+dh][w+dw] == 'O':
            return 0, 0, 0
        h += dh
        w += dw
        cnt += 1
    return h, w, cnt


def bfs():
    visit = {}
    queue = deque([red + blue])
    visit[red[0], red[1], blue[0], blue[1]] = 0
    while queue:
        rh, rw, bh, bw = queue.popleft()
        for dh, dw in (-1, 0), (1, 0), (0, -1), (0, 1):
            nrh, nrw, rmove = move(rh, rw, dh, dw)
            nbh, nbw, bmove = move(bh, bw, dh, dw)
            if not nbh and not nbw:
                continue
            elif not nrh and not nrw:
                print(visit[rh, rw, bh, bw] + 1)
                return
            elif nrh == nbh and nrw == nbw:
                if rmove > bmove:
                    nrh -= dh
                    nrw -= dw
                else:
                    nbh -= dh
                    nbw -= dw
            if (nrh, nrw, nbh, nbw) not in visit:
                visit[nrh, nrw, nbh, nbw] = visit[rh, rw, bh, bw] + 1
                queue.append([nrh, nrw, nbh, nbw])
        if not queue or visit[rh, rw, bh, bw] >= 10:
            print(-1)
            return

bfs()
