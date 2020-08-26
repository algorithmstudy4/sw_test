N, L, R = map(int,input().split())

country = [list(map(int, input().split())) for _ in range(N)]
count = 0


while True:
    open = []
    _sum = 0
    for i in range(N):
        for j in range(N):
            if j+1 < N:
                if L <= abs(country[i][j]-country[i][j+1]) <= R:
                    if [i,j] in open:
                        if [i,j+1] in open:
                            sum += 0
                        else:
                            open.append([i,j+1])
                            sum += country[i][j+1]
                    else:
                        if [i, j+1] in open:
                            open.append([i,j])
                            sum += country[i][j]
                        else:
                            open += [[[i,j],[i,j+1]]]
                            sum += country[i][j]+country[i][j+1]

            if i+1 < N:
                if L <= abs(country[i][j]-country[i+1][j]) <= R:
                    if [i,j] in open:
                        open.append([i+1,j])
                        sum += country[i+1][j]
                    else:
                        open += [[i,j],[i+1,j]]
                        sum += country[i][j]+country[i+1][j]

    for _ in range(len(open)):
        country[open[_][0]][open[_][1]] = sum // len(open)

    if len(open) == 0:
        break
    else:
        count += 1

print(count)
