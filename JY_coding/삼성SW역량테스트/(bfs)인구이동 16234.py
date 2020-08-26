from collections import deque

N, L, R = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(N)]

dx = [0, 1, 0, -1] #오-아-왼-위
dy = [1, 0, -1, 0]

visited = []
is_move = True
result = 0

def bfs(x,y):
    global is_move, visited
    union = [(x,y)]

    queue = deque()
    queue.append((x,y))

    total = maps[x][y]
    count = 1

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if visited[nx][ny] == 0 and abs(maps[nx][ny]-maps[x][y]) >= L and abs(maps[nx][ny]-maps[x][y]) <= R:
                visited[nx][ny] = 1
                queue.append((nx,ny))
                total += maps[nx][ny]
                count += 1
                union.append((nx,ny))

    if count>1:
        is_move = True
        for a,b in union:
            maps[a][b] = total//count

while is_move:
    visited = [[0 for _ in range(N)] for _ in range(N)]
    is_move = False
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0:
                visited[i][j] = 2
                bfs(i,j)
    if is_move:
        result += 1


print(result)

'''
3 5 10
10 15 20
20 30 25
40 22 10
'''

'''
3 5 10
10 30 50
20 70 10
20 100 20
'''