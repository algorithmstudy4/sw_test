k = -987654321
def go(n, t, p, day, pay):
    global k
    if day == n:
        if pay > k:
            k = pay
        return
    if day > n:
        return
    go(n, t, p, day + t[day], pay + p[day])
    go(n, t, p, day + 1, pay)

n = int(input())
t,p = [], []
for i in range(n):
   xo = list(map(int, input().split()))
   t.append(xo[0])
   p.append(xo[1])

go(n, t, p , 0, 0)
print(k)
