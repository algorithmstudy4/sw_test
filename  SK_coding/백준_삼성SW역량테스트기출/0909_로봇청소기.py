from sys import *

input = stdin.readline
n, m = map(int, input().split())
r, c, d = map(int, input().split())

board = [[int(x) for x in input().split()] for y in range(n)]


def left(d):

    return(d-1) % 4


clear = 0
move = [(-1, 0), (0, 1), (1, 0), (0, -1)]

while True:

    if board[r][c] == 0:

        board[r][c] = 8
        clear += 1

    next_d = left(d)

    for i in range(4):

        if board[r+move[next_d][0]][c+move[next_d][1]] == 0:

            break

        next_d = left(next_d)

    if next_d == left(d) and board[r+move[next_d][0]][c+move[next_d][1]] != 0:

        if board[r-move[d][0]][c-move[d][1]] == 1:

            break

        else:

            r = r-move[d][0]
            c = c-move[d][1]

    else:

        d = next_d
        r += move[d][0]
        c += move[d][1]

print(clear)
