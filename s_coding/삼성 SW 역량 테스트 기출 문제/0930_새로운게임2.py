#새로운 게임 2
#https://www.acmicpc.net/problem/17837
import sys
sys.stdin = open("input.txt","r")
input = sys.stdin.readline
n,k = map(int,input().split()) #체크판크기, 말의 개수
chess = [list(map(int,input().split())) for _ in range(n)]
horse = [[] for _ in range(k)]
board = [[[] for _ in range(n)] for _ in range(n)]
dh = [0, 0, -1, 1] #→, ←, ↑, ↓
dw = [1, -1, 0, 0]
for i in range(k):
    x, y, z = map(int, input().split())
    board[x-1][y-1].append(i)
    horse[i] = [x-1, y-1, z-1]

def move(index):
    h, w, d = horse[index]
    nh = h + dh[d]
    nw = w + dw[d]
    if not 0 <= nh < n or not 0 <= nw < n or chess[nh][nw] == 2:
        if 0 <= d <= 1:
            nd = (d+1) % 2
        else:
            nd = (d-1) % 2 + 2
        board[index][2] = nd
        nh = h + dh[nd]
        nw = w + dw[nd]
        if not 0 <= nh < n or not 0 <= nw < n or chess[nh][nw] == 2:
            return 0

    tmp = []
    for i, key in enumerate(board[h][w]):
        print(i,k)
        if key == index:
            tmp.extend(board[h][w][i:])
            board[h][w] = board[h][w][:i]
            break

    if chess[nh][nw] == 1: #빨강
        tmp = reversed(tmp)

    for i in tmp:
        board[nh][nw].append(i)
        horse[i][:2] = [nh, nw]

    if len(board[nh][nw]) >= 4:
        return 1
    return 0


cnt = 1
while cnt <= 1000:
    for i in range(k):
        flag = move(i)
        if flag:
            print(cnt)
            exit(0)
    cnt += 1
print(-1)
