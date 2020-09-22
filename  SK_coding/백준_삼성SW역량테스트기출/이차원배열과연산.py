
from sys import *

input = stdin.readline

s, r, k = map(int, input().split())
board = [[int(x) for x in input().split()] for y in range(3)]


def cal_r(board):

    size = 0
    add_zero = 0

    for i in range(len(board)):

        count = {}

        for j in range(len(board[i])):

            if board[i][j] == 0:
                continue

            if board[i][j] not in count:
                count[board[i][j]] = 1

            else:
                count[board[i][j]] += 1

        new_row = []

        for j in sorted(count, key=lambda val: (count[val], val)):

            new_row.append(j)
            new_row.append(count[j])

        if len(new_row) > size:

            size = len(new_row)

        board[i] = new_row

    for i in range(len(board)):

        if size > len(board[i]):

            add_zero = size - len(board[i])

        for j in range(add_zero):

            board[i].append(0)


def transpose(board):

    temp = [[board[i][j] for i in range(len(board))]
            for j in range(len(board[0]))]

    return temp


time = 0

while True:

    if board[s][r] == k:

        print(time)
        break

    elif board[s][r] >= 100:

        print(-1)
        break

    else:

        if len(board) >= len(board[0]):

            cal_r(board)
            time += 1

        else:

            board = transpose(board)
            cal_r(board)
            board = transpose(board)

            time += 1
