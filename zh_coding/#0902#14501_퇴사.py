N = int(input())
schedule = [list(map(int, input().split())) for _ in range(N)]
max_pay = [0]*N

for i in range(N-1, -1, -1):
    day = schedule[i][0]
    pay = schedule[i][1]
    if i == N-1:
        if day == 1:
            max_pay[i] = pay
        else:
            max_pay[i] = 0
    elif day + i == N:
        max_pay[i] = max(pay, max_pay[i+1])
    elif day + i < N:
        max_pay[i] = max(pay + max_pay[day+i], max_pay[i+1])
    else:
        max_pay[i] = max_pay[i+1]

print(max_pay[0])
