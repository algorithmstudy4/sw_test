from copy import deepcopy

dx = [-1, -1, 0, 1, 1, 1, 0, -1] # 1~8
dy = [0, -1, -1, -1, 0, 1, 1, 1]

def dfs(x, y, d, cnt):
    global max_count, info, fish

    # 물고기 이동
    for i in range(16):
        if fish[i]:
            fx, fy = fish[i][0], fish[i][1]
            for _ in range(9):
                nx, ny = fx + dx[info[fx][fy][1]], fy + dy[info[fx][fy][1]]
                if not 0 <= nx < 4 or not 0 <= ny < 4 or (nx == x and ny == y):
                    info[fx][fy][1] = (info[fx][fy][1] + 1) % 8
                    continue
                if info[nx][ny]:
                    fish[info[nx][ny][0]] = [fx, fy]
                info[nx][ny], info[fx][fy] = info[fx][fy], info[nx][ny]
                fish[i] = [nx, ny]
                break

    while True:
        nx, ny = x + dx[d], y + dy[d]
        if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:
            max_count = max(max_count, cnt)
            return
        if not info[nx][ny]:
            x, y = nx, ny
            continue

        temp_info, temp_fish = deepcopy(info), deepcopy(fish)
        temp1, temp2 = fish[info[nx][ny][0]], info[nx][ny]
        fish[info[nx][ny][0]], info[nx][ny] = [], []
        dfs(nx, ny, temp2[1], cnt + temp2[0] + 1) #재귀
        info, fish = temp_info, temp_fish
        fish[info[nx][ny][0]], info[nx][ny] = temp1, temp2
        x, y = nx, ny



info = [[] for _ in range(4)]
fish = [[] for _ in range(16)]
for i in range(4):
    temp = list(map(int, input().split()))
    for j in range(4):
        info[i].append([temp[j*2]-1, temp[j*2+1]-1])
        fish[temp[j*2]-1] = [i, j]

max_count = 0
d, cnt = info[0][0][1], info[0][0][0] + 1
fish[info[0][0][0]], info[0][0] = [], []
dfs(0, 0, d, cnt)
print(max_count)