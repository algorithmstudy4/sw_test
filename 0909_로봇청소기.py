N, M = map(int, input().split())
r, c, d = map(int, input().split())

maps = [list(map(int, input().split())) for _ in range(N)]

dx = [-1,0,1,0] #북-동-남-서
dy = [0,1,0,-1]
maps[r][c] = 2
cnt = 1

while True:
    clean = False
    for _ in range(4):
        nx = r + dx[(d+3)%4] #북(0)->서(3)->남(2)->동(1)
        ny = c + dy[(d+3)%4]
        d = (d + 3) % 4

        if maps[nx][ny] == 0:
            maps[nx][ny] = 2
            r = nx
            c = ny
            cnt += 1
            clean = True
            break

    if not clean:
        if maps[r-dx[d]][c-dy[d]] == 1:
            break
        r = r - dx[d]
        c = c - dy[d]

print(cnt)