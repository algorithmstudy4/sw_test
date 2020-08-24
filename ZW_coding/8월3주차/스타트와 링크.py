from itertools import combinations

N = int(input())
team = []
for i in range(N):
    team.append(list(map(int, input().split())))
ans = 987654321
team_combi = list(combinations(list(range(N)), (N // 2 )))

leng = len(team_combi)
for i in range(leng // 2):
    a = team_combi[i]
    b = team_combi[leng - 1 - i]
    sum1 = sum2 = 0
    for x in range(len(a) - 1):
        for y in range(x + 1, len(a)):
            sum1 += team[a[x]][a[y]]  + team[a[y]][a[x]]
            sum2 += team[b[x]][b[y]] + team[b[x]][b[y]]
    sum = abs(sum1 - sum2)
    if sum < ans:
        ans = sum
print(ans)

