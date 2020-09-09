from copy import deepcopy
from collections import deque

N, M = map(int, input().split())

mapp = [list(map(int, input().split())) for _ in range(N)]
max_cnt = 0


dx = [0,-1,0,1] #우-아-왼-위
dy = [1,0,-1,0] #우-아-왼-위

def bfs_virus():
    global max_cnt
    cnt = 0
    queue = deque()
    visited = [[0 for _ in range(M)] for _ in range(N)]
    maps = deepcopy(mapp)
    for i in range(N):
        for j in range(M):
            if mapp[i][j] == 2:
                queue.append((i,j))

    while(queue):
        x, y = queue.popleft()
        visited[x][y] = 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if visited[nx][ny] == 0 and maps[nx][ny] == 0:
                queue.append((nx,ny))
                maps[nx][ny] = 2
    for i in range(N):
        for j in range(M):
            if maps[i][j] == 0:
                cnt += 1
    max_cnt = max(cnt, max_cnt)

def dfs(count, x, y):
    if count == 3:
        bfs_virus()
        return 0

    for nx in range(x,N):
        for ny in range(y,M):
            if mapp[nx][ny] == 0:
                mapp[nx][ny] = 3
                dfs(count+1, nx, ny)
                mapp[nx][ny] = 0
        y = 0
    return 0

dfs(0,0,0)
print(max_cnt)
