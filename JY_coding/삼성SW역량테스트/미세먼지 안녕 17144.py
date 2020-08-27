from copy import deepcopy

def spread():
    global maps
    residual = [[0 for _ in range(C)] for _ in range(R)]
    for x in range(R):
        for y in range(C):
            amount = 0

            A = maps[x][y]
            if A > 0:
                for i in range(4):
                    nx = x + dx[i]
                    ny = y + dy[i]
                    if nx < 0 or nx >= R or ny < 0 or ny >= C or maps[nx][ny] == -1:
                        continue
                    residual[nx][ny] += A // 5
                    amount += A // 5
            residual[x][y] -= amount

    # merge residual
    for x in range(R):
        for y in range(C):
            maps[x][y] += residual[x][y]

def activate():
    global maps
    copy = deepcopy(maps)
    for i in range(2): #공기청정기 위/아래
        idx = 0
        mx, my = machine[i]
        r = (R - mx + C) * 2 - 5 if i else (mx + 1 + C) * 2 - 5

        for _ in range(r):
            nx = mx + dx[idx]
            ny = my + dy[idx]
            if nx < 0 or nx >= R or ny < 0 or ny >= C:
                idx = (idx + 1) % 4 if i else (idx + 3) % 4

                nx = mx + dx[idx]
                ny = my + dy[idx]

            if maps[mx][my] != -1: #공기청정기 옆
                copy[nx][ny] = maps[mx][my]
            else:
                copy[nx][ny] = 0
            mx = nx
            my = ny
    maps = deepcopy(copy)

R, C, T = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(R)]
machine = []
dust = 2

#공기청정기 위치
for x in range(R):
    if maps[x][0] == -1:
        machine.append((x,0))

dx = [0, 1, 0, -1] #우-아-왼-위
dy = [1, 0, -1, 0]

for _ in range(T):
    spread()
    activate()

for i in range(R):
    dust += sum(maps[i])

print(dust)
