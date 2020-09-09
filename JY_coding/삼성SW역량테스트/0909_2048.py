from copy import deepcopy


def find_max(arr):
    global max_value
    for i in range(N):
        for j in range(N):
            if max_value < arr[i][j]: max_value = arr[i][j]


def left(board):
    for i in range(N):
        p = 0
        x = 0
        for q in range(N):
            if board[i][q] == 0:
                continue
            if x == 0:
                x = board[i][q]
            else:
                if x == board[i][q]:
                    board[i][p] = 2*x
                    p = p + 1
                    x = 0
                else:
                    board[i][p] = x
                    p = p + 1
                    x = board[i][q]
            board[i][q] = 0
        if x != 0: board[i][p] = x
    return board

def right(board):
    for i in range(N):
        p = N-1
        x = 0
        for q in range(N-1, -1, -1):
            if board[i][q] == 0:
                continue
            if x == 0:
                x = board[i][q]
            else:
                if x == board[i][q]:
                    board[i][p] = 2*x
                    p = p - 1
                    x = 0
                else:
                    board[i][p] = x
                    p = p - 1
                    x = board[i][q]
            board[i][q] = 0
        if x != 0: board[i][p] = x
    return board


def up(board):
    for i in range(N):
        p = 0
        x = 0
        for q in range(N):
            if board[q][i] == 0:
                continue
            if x == 0:
                x = board[q][i]
            else:
                if x == board[q][i]:
                    board[p][i] = 2*x
                    p = p + 1
                    x = 0
                else:
                    board[p][i] = x
                    p = p + 1
                    x = board[q][i]
            board[q][i] = 0
        if x != 0: board[p][i] = x
    return board


def down(board):
    for i in range(N):
        p = N-1
        x = 0
        for q in range(N-1, -1, -1):
            if board[q][i] == 0:
                continue
            if x == 0:
                x = board[q][i]
            else:
                if x == board[q][i]:
                    board[p][i] = 2*x
                    p = p - 1
                    x = 0
                else:
                    board[p][i] = x
                    p = p - 1
                    x = board[q][i]
            board[q][i] = 0
        if x != 0: board[p][i] = x
    return board

def dfs(dfs_board, n):
    if n == 5:
        find_max(dfs_board)
        return
    dfs(left(deepcopy(dfs_board)), n+1)
    dfs(right(deepcopy(dfs_board)), n+1)
    dfs(up(deepcopy(dfs_board)), n+1)
    dfs(down(deepcopy(dfs_board)), n+1)



N = int(input())
max_value = 0
map_board = [list(map(int, input().split())) for _ in range(N)]
dfs(map_board, 0)
print(max_value)