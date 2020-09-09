import sys

input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def check(x, y, cnt, _sum, cx, cy):
    global ans
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        ncx = cx + dx[i]
        ncy = cy + dy[i]
        if not 0 <= nx < n or not 0 <= ny < m or c[ncx][ncy]:
            continue
        if cnt == 3:
            ans = max(ans, _sum + a[nx][ny])
        else:
            c[ncx][ncy] = 1
            check(nx, ny, cnt + 1, _sum + a[nx][ny], ncx, ncy)
            c[ncx][ncy] = 0


n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

ans = 0
for i in range(n):
    for j in range(m-1):
        _sum = a[i][j] + a[i][j+1]
        if i + 2 < n:
            ans = max(ans, _sum + a[i+1][j] + a[i+2][j])
        if i - 1 >= 0 and i + 1 < n:
            ans = max(ans, max(_sum + a[i+1][j] + a[i-1][j], _sum + a[i+1][j+1] + a[i-1][j+1]))
        c = [[0 for _ in range(4)] for _ in range(5)]
        c[2][0], c[2][1] = 1, 1
        check(i, j+1, 2, _sum, 2, 1)

for j in range(m):
    for i in range(n-1):
        _sum = a[i][j] + a[i+1][j]
        if j + 2 < m:
            ans = max(ans, _sum + a[i][j+1] + a[i][j+2])
        if j - 1 >= 0 and j + 1 < m:
            ans = max(ans, max(_sum + a[i][j+1] + a[i][j-1], _sum + a[i+1][j+1] + a[i+1][j-1]))
        c = [[0 for _ in range(5)] for _ in range(4)]
        c[0][2], c[1][2] = 1, 1
        check(i+1, j, 2, _sum, 1, 2)

print(ans)