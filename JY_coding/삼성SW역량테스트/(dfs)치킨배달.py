import sys

result = []
home_loc = []
ch_loc = []
ch_pick = []
N, M = map(int, sys.stdin.readline().split())
city = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

def dfs(cnt, i):
    if cnt == M:
        d = 0
        for h in home_loc:
            min_dist = 1000000
            for ch in ch_pick:
                min_dist = min(min_dist, abs(h[0] - ch[0]) + abs(h[1] - ch[1]))
            d += min_dist
        result.append(d)
        return 0

    # Pick
    for p in range(i,len(ch_loc)):
        ch_pick.append(ch_loc[p])
        dfs(cnt+1, p+1)
        ch_pick.pop()


#집/치킨집 위치
for y in range(N):
    for x in range(N):
        n = city[y][x]
        if n == 1:
            home_loc.append((y,x))
        elif n == 2:
            ch_loc.append((y,x))

dfs(0,0)
print(min(result))