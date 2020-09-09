from collections import deque
from copy import deepcopy

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

count = 0
dx = [-1, 0, 1, 0]  # 위/오른쪽/아래/왼쪽
dy = [0, 1, 0, -1]

def board_max(board):
    q = deque([board])
    _max = 0
    step = 0
    while q:
        for d in range(len(q)):
            or_board = q.popleft()

            for _ in range(4):      # 기존 보드를 카피한 것 > 4가지 방향을 위해 다시 카피 > 결과값을 큐에 저장
                movedBoard = move(deepcopy(or_board),_)
                q.append(movedBoard)

                for i in range(N):  # 보드 값 중 가장 큰 값을 구함
                    for j in range(N):
                        if movedBoard[i][j] > _max:
                            _max = movedBoard[i][j]
        step += 1

        if step == 5:
            return _max

def move(c_board, direct):
    check = [[True] * N for _ in range(N)]

    if direct in [0, 3]:
        start_idx, end_idx, step = 0, N, 1   # 아래 또는 오른쪽 
    else:
        start_idx, end_idx, step = N-1, -1, -1

    for i in range(start_idx, end_idx, step):
        for j in range(start_idx, end_idx, step): 
            if c_board[i][j] == 0: 
                continue 
            
            x, y = i, j 
            value = c_board[x][y] 
            c_board[x][y] = 0 
            nx, ny = x + dx[direct], y + dy[direct] 

            while True: # 범위
                if nx < 0 or nx >= N or ny < 0 or ny >= N: 
                    break 
                if c_board[nx][ny] == 0: 
                    x, y = nx, ny 
                    nx, ny = x + dx[direct], y + dy[direct]
                elif c_board[nx][ny] == value and check[nx][ny]: 
                    x, y = nx, ny 
                    check[x][y] = False 
                    break # 종료. 
                else: 
                  break 
            
            c_board[x][y] = c_board[x][y] + value     
    return c_board

print(board_max(board))
