n, m = map(int, input().split())
mp = []
for i in range(n):
    mp.append(list(map(int, input().split())))

d = [[[0 for _ in range(3)] for __ in range(m)] for ___ in range(n + 1)]
ans = 987654321
def minn(a, b):
    if a< b:
        return a
    return b

for i in range(m):
    for j in range(3):
        d[0][i][j] = mp[0][i]

for i in range(1, n):
    for j in range(m):
        if j == 0:
            d[i][j][1] = d[i - 1][j + 1][0] + mp[i][j];
            d[i][j][2] = minn(d[i-1][j][1], d[i-1][j+1][0]) + mp[i][j]
        elif j == m - 1:
            d[i][j][0] = minn(d[i-1][j][1], d[i-1][j-1][2]) + mp[i][j]
            d[i][j][1] = d[i-1][j-1][2] + mp[i][j]
        else:
            d[i][j][0] = minn(d[i-1][j-1][2], d[i-1][j][1]) + mp[i][j]
            d[i][j][1] = minn(d[i-1][j-1][2], d[i-1][j+1][0]) + mp[i][j]
            d[i][j][2] = minn(d[i-1][j][1], d[i-1][j+1][0]) + mp[i][j]
for i in range(m):
    for j in range(3):
        if d[n-1][i][j] < ans and d[n-1][i][j] != 0:
            ans = d[n-1][i][j]
print(ans)
