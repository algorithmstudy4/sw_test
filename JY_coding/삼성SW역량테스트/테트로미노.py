N, M = map(int, input().split())
mapp = [list(map(int, input().split())) for _ in range(N)]


def rotate(maps):
    return [list(reversed(i)) for i in list(map(list, zip(*maps)))]

def get_count(shape):
    global max_cnt
    y_move = N - len(shape) + 1
    x_move = M - len(shape[0]) + 1
    for y in range(y_move):
        for x in range(x_move):
            count = 0
            for ny in range(len(shape)):
                for nx in range(len(shape[0])):
                    if shape[ny][nx] == 1:
                        count += mapp[y+ny][x+nx]
            max_cnt = max(max_cnt, count)

    return 0


# 회전 수, 총 19shapes
shape_list = [
    [[1,1],[1,1]], #1
    [[1,1,1,1]], #2
    [[1,0],[1,1],[0,1]], #2
    [[0,1],[1,1],[1,0]], #2
    [[1,1],[1,0],[1,0]], #4
    [[1,1],[0,1],[0,1]], #4
    [[1,1,1],[0,1,0]] #4
]
max_cnt = 0
for i in range(len(shape_list)):
    shape = shape_list[i]
    if i == 0:
        get_count(shape)
    elif i>0 and i<=3:
        for _ in range(2):
            get_count(shape)
            shape = rotate(shape)
    else:
        for _ in range(4):
            get_count(shape)
            shape = rotate(shape)


print(max_cnt)