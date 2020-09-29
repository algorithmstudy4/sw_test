from collections import deque
n, m, h = map(int,input().split())
mp = [[0 for _ in range(n)] for __ in range(h+2)]
for _ in range(m):
    a,b = map(int, input().split())
    b -= 1
    mp[a][b],mp[a][b+1] = 1,2#1 이면, 오른쪽! , 2면 왼!쪾!
canbe = []
for i in range(1, h + 1):
    for j in range(n-1):
        if mp[i][j] == 0 and mp[i][j + 1] == 0:
            canbe.append((i, j))
canbe2 = []
for i in range(len(canbe)):
    ok = set()
    ok.add(canbe[i])
    for j in range(i + 1, len(canbe)):
        xt = ok.copy()
        xt.add(canbe[j])
        canbe2.append(xt)
canbe3 =[]
for i in range(len(canbe)):
    ok = set()
    ok.add(canbe[i])
    for j in range(i + 1, len(canbe)):
        xt = ok.copy()
        xt.add(canbe[j])
        for k in range(j + 1, len(canbe)):
            ot = xt.copy()
            ot.add(canbe[k])
            canbe3.append(ot)
def find(i):
    x, y =0, i
    start = i
    q = deque()
    q.append((x, y,False))
    while q:
        d = q.popleft()
        if d[0] == h + 1:
            if start == d[1]:
                return True
            else:
                return False
        x,y,z = d[0], d[1],d[2]
        if mp[x][y] == 0:
            q.append((x + 1,y,z))
        else:
            if z:
                q.append((x + 1,y, False))
            else:
                if mp[x][y] == 1:
                    q.append((x, y + 1, True))
                else:
                    q.append((x, y -1, True))
    return False
ans = 4
def make_map(st):
    for pos in st:
        x,y = pos[0],pos[1]
        mp[x][y],mp[x][y+1] = 1, 2
def debuf_map(st):
    for pos in st:
        x,y = pos[0],pos[1]
        mp[x][y],mp[x][y+1] = 0,0
over = True
for i in range(n):
    isit = find(i)
    if isit == False:
        over = False
if over:
    print(0)
else:
    f,s,t = False,False,False
    for xt in canbe:
        okk = False
        stos = set()
        stos.add(xt)
        make_map(stos)
        for i in range(n):
            if find(i) == False:
                okk = True
                debuf_map(stos)
                break
        if okk == False:
            print(1)
            f = True
            break
    if f == False:
        for xt in canbe2:
            okk = False
            make_map(xt)
            for i in range(n):
                if find(i) == False:
                    okk = True
                    debuf_map(xt)
                    break
            if okk == False:
                print(2)
                s = True
                break
        if s == False:
            for xt in canbe3:
                okk = False
                make_map(xt)
                for i in range(n):
                    if find(i) == False:
                        okk = True
                        debuf_map(xt)
                        break
                if okk == False:
                    print(3)
                    t = True
                    break
    if f == False and s== False and t == False:
        print(-1)
