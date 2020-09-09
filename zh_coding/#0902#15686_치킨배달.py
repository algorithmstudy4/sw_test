import itertools
import copy

N,M=map(int,input().split())
city_map = [list(map(int, input().split())) for _ in range(N)]

chicken_store = []

def sum_dist(city_map, selected):
    min_dist = 2500
    for _ in range(len(selected)):
        summ = 0
        for i in range(N):
            for j in range(N):
                if city_map[i][j] == 1:
                    min_chicken = 2500
                    for m in range(M):
                        x = selected[_][m][0]
                        y = selected[_][m][1]
                        chicken_dist = abs(x-i) + abs(y-j)
                        min_chicken = min(min_chicken, chicken_dist)
                    summ += min_chicken
        min_dist = min(summ, min_dist)
    return min_dist

for i in range(N):
    for j in range(N):
        if city_map[i][j] == 2:
            city_map[i][j] = 3
            chicken_store.append([i,j])

selected_store = list(itertools.combinations(chicken_store, M))

print(sum_dist(city_map, selected_store))
