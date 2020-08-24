from itertools import combinations
from collections import deque
N, M = map(int, input().split())
mp = []
for i in range(N):
    mp.append(list(map(int, input().split())))

canbe = []
notbe = []
for i in range(N):
    for j in range(M):
        if mp[i][j] == 0:
             canbe.append((i, j))
        elif mp[i][j] == 2:
            notbe.append((i, j))

posi = list(combinations(canbe, 3))
dx = [0,0,1,-1]
dy = [1,-1,0,0]
def sumit(d):
    global N, M
    global mp
    ret = 0
    for i in range(N):
        for j in range(M):
            if mp[i][j] == 0 and d[i][j] == 0:
                ret +=1
    return ret
ans = 0
for x in posi:
    q = deque()
    d = [[0 for _ in range(M)] for __ in range(N)]
    for y in x:
        d[y[0]][y[1]] = 1
    for o in notbe:
        q.append(o)
        d[o[0]][o[1]] = 1
    while len(q):
        newthing = q.popleft()
        for i in range(4):
            nx, ny = newthing[0] + dx[i], newthing[1] + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if mp[nx][ny] == 1:
                continue
            if d[nx][ny] == 1:
                continue
            d[nx][ny] = 1
            q.append((nx, ny))
    sum = sumit(d)
    if sum > ans :
        ans = sum
print(ans)
