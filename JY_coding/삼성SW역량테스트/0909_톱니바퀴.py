def rotate(n, d):
    r = [0]*8
    if d == 1:
        for i in range(8):
            r[(i+1)%8] = W[n][i]
    else:
        for i in range(8):
            r[i] = W[n][(i+1)%8]
    for i in range(8):
        W[n][i] = r[i]


W = [list(input()) for _ in range(4)]
for _ in range(int(input())):
    n, d = map(int, input().split())
    direct = [0] * 4
    direct[n - 1] = d
    for i in range(n - 1, 3):
        if W[i][2] != W[i + 1][6]:
            direct[i + 1] = -direct[i]
    for i in range(n - 1, 0, -1):
        if W[i][6] != W[i - 1][2]:
            direct[i - 1] = -direct[i]
    for i in range(4):
        if direct[i]:
            rotate(i, direct[i])

ans = 0
for i in range(4):
    if W[i][0] == '1':
        ans += (1 << i)
print(ans)
