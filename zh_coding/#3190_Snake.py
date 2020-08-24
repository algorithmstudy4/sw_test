import sys
from collections import deque

N = int(input())       # 보드 크기
K = int(input())       # K개의 사과

board = [[0]*N for _ in range(N)]     # N*N 크기의 0으로 채워진 보드판
for apples in range(K):             # K개의 사과 위치 = 1
    a, b = map(int, input().split())
    board[a-1][b-1] = 1

L = int(input())      # 변환 횟수
L_arr = list(map(lambda x:[int(x[0]), x[1]], [input().split() for _ in range(L)]))

dx = [0,1,0,-1]     # 뱀의 방향(북, 동, 남, 서)
dy = [-1,0,1,0]

time = 0      # 시작 시간 = 0
x = y = 0     # 첫 뱀 위치
board[0][0] = 2     # 뱀이 위치하고 있는 곳 = 2
snake = deque([[0,0]])    # 뱀의 정보
d = 1     # 현재 방향(동)

while True:
    x = x + dx[d]     # 뱀의 위치 이동
    y = y + dy[d]

    if 0<=x<N and 0<=y<N and board[y][x] != 2:
        if board[y][x] == 1:
            board[y][x] == 2      # 사과가 있던 1을 뱀의 머리 2로 바꿔줌
            snake.append([y, x])     # 뱀 정보에 추가(추가된 항목이 머리)
            time += 1

        elif board[y][x] == 0:
            board[y][x] = 2
            snake.append([y,x])
            del_y, del_x = snake.popleft()    # 뱀의 꼬리 제거
            board[del_y][del_x] = 0
            time += 1

        else:
            time += 1
            break

        if len(L_arr) != 0:
            if time == L_arr[0][0]:
                if L_arr[0][1] == 'L':
                    d = (d-1)%4
                else:
                    d = (d+1)%4

                del L_arr[0]

    else:
        time += 1
        break

print(time)
