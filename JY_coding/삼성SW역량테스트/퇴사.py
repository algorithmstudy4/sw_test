N = int(input())

T = []
P = []

for i in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)

S = [0 for _ in range(N)]
S[-1] = P[-1] if T[-1] <= 1 else 0

for i in range(N-2,-1,-1):
    if i+T[i] <= N:
        if i + T[i] == N:
            S[i] = max(P[i], S[i + 1])
        else:
            S[i] = max(P[i]+S[T[i]+i], S[i+1])
    else:
        S[i] = S[i+1]

print(S[0])