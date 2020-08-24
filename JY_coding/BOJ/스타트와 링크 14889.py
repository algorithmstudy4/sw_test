import itertools

N = int(input())

s = []
for i in range(N):
    s.append(list(map(int, input().split())))

team = list(itertools.combinations([i for i in range(N)],int(N/2)))
size = len(team)//2


d = 999999
for c in range(size):
    s_ability = list(itertools.permutations(team[c],2))
    l_ability = list(itertools.permutations(team[-c-1],2))

    s_sum = sum(s[i][j] for i,j in s_ability)
    l_sum = sum(s[i][j] for i,j in l_ability)

    d = min(d, abs(s_sum-l_sum))

print(d)




