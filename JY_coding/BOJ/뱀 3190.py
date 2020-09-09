N = int(input()) #N*N
K = int(input()) #사과개수

mapp = [[0 for _ in range(N+1)] for _ in range(N+1)]
dx = [0, 1, 0, -1] #오-아-왼-위
dy = [1, 0, -1, 0]

for _ in range(K):
    x, y = map(int, input().split())
    mapp[x][y] = 2

L = int(input()) #명령개수

def sol():
    time = 0
    head_x, head_y = 1, 1
    tail_x, tail_y = 1, 1
    idx = 0 #방향 인덱스
    snack = [(1, 1)]
    mapp[head_x][head_y] = 1
    direction = [list(input().split()) for _ in range(L)]
    dir_idx = 0 #명령방향
    n, d = direction[dir_idx]

    while(True):
        time+=1
        new_x = dx[idx] + head_x
        new_y = dy[idx] + head_y

        if new_x > N or new_x < 1 or new_y > N or new_y < 1 or mapp[new_x][new_y]==1:
            return time

        if mapp[new_x][new_y] == 0:
            a,b = snack.pop(0)
            mapp[a][b] = 0
            if snack:
                tail_x = snack[0][0]
                tail_y = snack[0][1]
            else:
                tail_x = head_x
                tail_y = head_y


        mapp[new_x][new_y] = 1
        head_x = new_x
        head_y = new_y
        snack.append((head_x, head_y))

        if (int(n)==time):
            if d == 'D':
                idx = (idx+1)%4
            elif d == 'L':
                idx = (idx+3)%4

            if dir_idx+1 < len(direction):
                dir_idx += 1
                n,d = direction[dir_idx]


print(sol())


'''
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
'''

'''
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L
'''