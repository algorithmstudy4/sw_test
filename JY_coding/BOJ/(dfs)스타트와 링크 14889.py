N = int(input())
S = [list(map(int, input().split())) for i in range(N)]
team = [0 for _ in range(N)]
d = 99999

def ability():
    global d
    #인덱스 저장
    team_a = [i for i in range(len(team)) if team[i]]
    team_b = [i for i in range(len(team)) if team[i]==0]

    sum_a, sum_b = 0,0
    for i in range(N//2):
        for j in range(i, N//2):
            if i != j: #같은경우 0으로 제외
                sum_a += S[team_a[i]][team_a[j]] + S[team_a[j]][team_a[i]]
                sum_b += S[team_b[i]][team_b[j]] + S[team_b[j]][team_b[i]]
    d = min(d, abs(sum_a-sum_b))


def dfs(cur,count):
    if(count == (N//2)):
        ability()
        return d
    #(1,1,1,0,0,0) 팀 나누기
    for i in range(cur, N):
        team[i] = 1
        dfs(i+1, count+1)
        team[i] = 0

dfs(0,0)
print(d)


'''
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0
'''

'''
6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0
'''
