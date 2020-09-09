from sys import *

input = stdin.readline


def level_up():
    global size, eat
    if size == eat:
        size += 1
        eat = 0
    return


n = int(input())

board = [[int(x) for x in input().split()] for y in range(n)]

for i in range(n):
    TF = False
    for j in range(n):
        if board[i][j] == 9:
            s_y = i
            s_x = j
            TF = True
            break
    if TF:
        break

dy = [-1, 0, 0, 1]
dx = [0, -1, 1, 0]
size = 2
eat = 0
queue = [[i, j]]
board[i][j] = 0
cnt = 0
cnt2 = 0
visited = [[False] * n for _ in range(n)]
visited[i][j] = True
while queue:
    cnt2 += 1
    eat_lst = []
    TF = False
    for i in range(len(queue)):
        current = queue.pop(0)
        y = current[0]
        x = current[1]
        for dir in range(4):
            ny = y+dy[dir]
            nx = x+dx[dir]
            if 0 <= ny <= n-1 and 0 <= nx <= n-1 and board[ny][nx] <= size and not visited[ny][nx]:
                if 0 < board[ny][nx] < size:
                    eat_lst.append([ny, nx])
                    visited[ny][nx] = True
                else:
                    visited[ny][nx] = True
                    queue.append([ny, nx])

    if not eat_lst == []:
        eat_y = n-1
        eat_x = n-1
        for e in eat_lst:
            if e[0] < eat_y:
                eat_y = e[0]
                eat_x = e[1]
            elif e[0] == eat_y:
                if e[1] < eat_x:
                    eat_x = e[1]

        eat += 1
        level_up()
        queue = [[eat_y, eat_x]]
        cnt += cnt2
        cnt2 = 0
        board[eat_y][eat_x] = 0
        visited = [[False] * n for _ in range(n)]
        visited[eat_y][eat_x] = True

print(cnt)
