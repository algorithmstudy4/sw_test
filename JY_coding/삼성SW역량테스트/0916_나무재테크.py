N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)] #S2D2 양분로봇


trees = [[0]*N for _ in range(N)] # 나무 나이
ground = [[5]*N for _ in range(N)] # 땅의 총 양분


for _ in range(M):
    x,y,z = map(int, input().split())
    if trees[x-1][y-1] == 0:
        trees[x-1][y-1] = [z]
    else:
        trees[x-1][y-1].append(z)


e = [-1,0,1] # fall -expansion
for _ in range(K): # for K year
    for i in range(N): # roop: Spring~Summer
        for j in range(N):
            if trees[i][j]: # exists
                for t in range(len(trees[i][j])-1,-1,-1): # from youngest
                    if ground[i][j] < trees[i][j][t]: # 양분 부족시,
                        for r in range(t+1):
                            ground[i][j] += trees[i][j][r]//2 # 나무는죽고 양분으로 변함.
                        trees[i][j] = trees[i][j][t+1:]
                        break
                    else:
                        ground[i][j] -= trees[i][j][t] # spring, 나이만큼 양분흡수
                        trees[i][j][t] += 1 # 나이 1증가

    for x in range(N): # roop: Fall, 인접한 8칸에 나이가 1인 나무 추가.
        for y in range(N):
            if trees[x][y]:
                for t in range(len(trees[x][y])):
                    if trees[x][y][t] % 5 == 0:
                        for i in e:
                            nx = x + i
                            if nx < 0 or nx >= N:
                                continue
                            for j in e:
                                ny = y + j
                                if ny < 0 or ny >= N:
                                    continue
                                if nx == x and ny == y:
                                    continue
                                if trees[nx][ny] == 0:
                                    trees[nx][ny] = [1]
                                else:
                                    trees[nx][ny].append(1)
    for r in range(N): # roop: Winter
        for c in range(N):
            ground[r][c] += A[r][c] # S2D2 로봇: 양분추가


ans = 0
for i in range(N):
    for j in range(N):
        if trees[i][j] != 0:
            ans += len(trees[i][j])

print(ans)










'''
5 2 1
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
'''