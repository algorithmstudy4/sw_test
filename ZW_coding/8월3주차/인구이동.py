from collections import deque

N,L,R = map(int, input().split())
mp = []
for _ in range(N):
    mp.append(list(map(int,input().split())))
d = [[False for _ in range(N)] for c in range(N)]
dir = [(0,1), (0,-1), (1,0), (-1,0)]
def bfs(x, y):
    q = deque()
    d[x][y] = True
    q.append((x, y, mp[x][y]))
    val = mp[x][y]
    lset = set()
    lset.add((x,y))
    while q:
        tp = q.popleft()
        for di in dir:
            nx,ny = tp[0] + di[0],tp[1] + di[1]
            if 0 <= nx < N and 0 <= ny < N:
                if d[nx][ny] == False:
                    if L <= abs(tp[2] - mp[nx][ny]) <= R:
                        d[nx][ny] = True
                        val += mp[nx][ny]
                        lset.add((nx, ny))
                        q.append((nx, ny, mp[nx][ny]))
    if len(lset) == 1:
        return False
    val = val // len(lset)
    for x in lset:
        mp[x[0]][x[1]] = val
    return True

ans = 0
while True:

    isit = False
    for i in range(N):
        for j in range(N):
            if d[i][j] == False:
                ok = bfs(i, j)
                if ok:
                    isit = True
    #print()
    #for xt in mp:
     #   print(xt)
    if not isit:
        break

    ans += 1
    d = [[False for _ in range(N)] for c in range(N)]                
print(ans)                
