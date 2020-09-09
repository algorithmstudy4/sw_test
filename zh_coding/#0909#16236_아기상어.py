from heapq import heappush, heappop

n = int(input())
tank = [list(map(int, input().split())) for _ in range(n)]
q = []

for i in range(n):
    for j in range(n):
        if tank[i][j] == 9:
            heappush(q, (0, i, j))
            tank[i][j] = 0

dx = [0, -1, 1, 0]
dy = [-1, 0, 0, 1]

def bfs():
    global q
    size = 2
    eat = 0
    distance = 0
    visit = [[0] * n for _ in range(n)]
    while q:
        d, y, x = heappop(q)
        if 0 < tank[y][x] < size:
            eat += 1
            tank[y][x] = 0
            if eat == size:
                size += 1
                eat = 0
            distance += d
            d = 0
            q = []
            visit = [[0]*n for _ in range(n)]
        for a in range(4):
            nd = d+1
            ny = y + dy[a]
            nx = x + dx[a]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if 0 < tank[ny][nx] > size or visit[ny][nx]:
                continue
            visit[ny][nx] = 1
            heappush(q, (nd, ny, nx))
    print(distance)

bfs()
