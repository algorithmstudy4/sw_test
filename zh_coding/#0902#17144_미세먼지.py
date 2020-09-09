import copy
R, C, T = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(R)]

def spread(c_room):
    cleaner = []
    x = [-1, 0, 1, 0]
    y = [0, 1, 0, -1]

    for i in range(R):
        for j in range(C):
            dust = room[i][j]                     # 기존 해당 칸의 먼지량
            if dust != 0 and dust != -1:
                count = 0                           # 퍼진 방향의 갯수
                for _ in range(4):
                    nx = i + x[_]
                    ny = j + y[_]
                    if (0<=nx<R and 0<=ny<C):       # 공기청정기와 벽이 아닐 때 퍼뜨림
                        if room[nx][ny] != -1:
                            c_room[nx][ny] += dust // 5
                            count += 1
                        else: count += 0
                    else: count += 0
                if dust - (dust//5)*count >= 0:
                    c_room[i][j] -= (dust // 5) * count
                else:
                    c_room[i][j] = 0
            elif c_room[i][j] == -1:                  # 공기청정기 위치 저장
                cleaner.append([i,j])

    # 공기청정기 가동
    upper = cleaner[0]
    if upper[0]-1 >= 0 :
        for row in range(upper[0]-1, 0, -1):
            c_room[row][0] = c_room[row-1][0]
        for col in range(0, C-1):
            c_room[0][col] = c_room[0][col+1]
        for row in range(0, upper[0]):
            c_room[row][C-1] = c_room[row+1][C-1]
    for col in range(C-1, 1, -1):
        c_room[upper[0]][col] = c_room[upper[0]][col-1]
    c_room[upper[0]][1] = 0   # 공기청정기 바로 앞 미세먼지는 밀려나 0이 됨

    lower = cleaner[1]
    if lower[0]+1 <= R-1 :
        for row in range(lower[0]+1, R-1):
            c_room[row][0] = c_room[row+1][0]
        for col in range(0, C-1):
            c_room[R-1][col] = c_room[R-1][col+1]
        for row in range(R-1, lower[0], -1):
            c_room[row][C-1] = c_room[row-1][C-1]
    for col in range(C-1, 1, -1):
        c_room[lower[0]][col] = c_room[lower[0]][col-1]
    c_room[lower[0]][1] = 0

    return c_room


time = 0
while time != T:
    c_room = copy.deepcopy(room)
    room = spread(c_room)
    time += 1

summ = 0
for i in range(R):
    for j in range(C):
        if room[i][j] != 0 and room[i][j] != -1:
            summ += room[i][j]

print(summ)
