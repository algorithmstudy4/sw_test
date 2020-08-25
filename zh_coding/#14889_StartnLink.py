from itertools import combinations

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
members = [i for i in range(N)]
teams = []

for team in list(combinations(members, N//2)):
    teams.append(team)

_mini = 100

for i in range(len(teams)//2):
    start_team = teams[i]           # start team 멤버
    start_sum = 0
    for j in range(N//2):
        member = start_team[j]      # 각 멤버에 해당하는 값을 더해줌
        for k in start_team:
            start_sum += arr[member][k]

    link_team = teams[-i-1]         # link team 멤버
    link_sum = 0

    for j in range(N//2):
        member = link_team[j]
        for k in link_team:
            link_sum += arr[member][k]

    _mini = min(_mini, abs(start_sum - link_sum))       # 최소값 갱신

print(_mini)
