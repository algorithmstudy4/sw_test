from sys import stdin
from collections import deque
input = stdin.readline

ans = 0
dx, dy = (-1, -1, -1, 0, 0, 1, 1, 1), (-1, 0, 1, -1, 1, -1, 0, 1)
N, M, K = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(N)]
tree = [[deque() for _ in range(N)] for _ in range(N)]
nutrient = [[5 for _ in range(N)] for _ in range(N)]
for _ in range(M):
    x, y, z = map(int, input().split())
    tree[x-1][y-1].append(z)
    ans += 1

def spring_summer():
    global ans
    for i in range(N):
        for j in range(N):
            for k in range(len(tree[i][j])):
                if nutrient[i][j] >= tree[i][j][k]:
                    nutrient[i][j] -= tree[i][j][k]
                    tree[i][j][k] += 1
                else:
                    while k < len(tree[i][j]):
                        nutrient[i][j] += (tree[i][j].pop()//2)
                        ans -= 1
                    break

def fall_winter():
    global ans
    for i in range(N):
        for j in range(N):
            for k in range(len(tree[i][j])):
                if tree[i][j][k]%5 == 0:
                    for t in range(8):
                        x, y = i+dx[t], j+dy[t]
                        if x < 0 or x >= N or y < 0 or y >= N:
                            continue
                        tree[x][y].appendleft(1)
                        ans += 1
            nutrient[i][j] += a[i][j]

def solve():
    for _ in range(K):
        spring_summer()
        fall_winter()
    print(ans)

solve()
