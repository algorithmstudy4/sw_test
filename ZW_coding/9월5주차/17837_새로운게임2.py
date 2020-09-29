from collections import deque
N, K = map(int, input().split())
mp = []
mp.append([2 for _ in range(N+2)])
for i in range(N):   
    ox = [2]
    ox.extend(list(map(int, input().split())))
    ox.append(2)
    mp.append(ox)
mp.append([2 for _ in range(N+2)])
chess = [[deque() for _ in range(N + 2)] for __ in range(N + 2)]
horse = dict()
for i in range(1, K+1):
    x,y,z = map(int, input().split())
    horse[i] = [x,y,z]
    chess[x][y].append(i)
dx = (0,0,0,-1,1)
dy = (0,1,-1,0,0)
def blue(i):
    x,y,d = horse[i][0], horse[i][1],horse[i][2]
    if d == 1: d = 2
    elif d == 2: d = 1
    elif d == 4: d = 3
    elif d == 3: d = 4
    nx, ny = x + dx[d], y +dy[d]
    horse[i] = [x,y,d]
    ret = False
    if mp[nx][ny] == 2:
        return False
    elif mp[nx][ny] == 0:
        ret = white(i)
    else:
        ret = red(i)
    return ret

def red(i):
    x,y,d = horse[i][0], horse[i][1], horse[i][2]
    isit, ret = False, False
    q = deque()
    qx,qy = x + dx[d], y + dy[d]
    while True:
        nb = chess[x][y].pop()
        if nb == i: isit = True
        horse[nb] = [qx,qy,horse[nb][2]]
        q.append(nb)
        if len(chess[qx][qy]) + len(q) >= 4 : return True
        if isit : break
    while q:
        chess[qx][qy].append(q.popleft())
        if len(chess[qx][qy]) >= 4: return True
    return False        

def white(i):
    x,y,d = horse[i][0], horse[i][1],horse[i][2]
    isit = False
    ret = False
    q = deque()
    qx,qy = x + dx[d], y + dy[d]
    while True:
        nb = chess[x][y].pop()
        if nb == i: isit = True
        horse[nb] = [qx,qy,horse[nb][2]]
        q.append(nb)
        if len(chess[qx][qy]) + len(q) >= 4 : return True
        if isit: break
    while q:
        chess[qx][qy].append(q.pop())
        if len(chess[qx][qy]) >= 4: return True
    return False
t = 0
ok = False     
while True:    
    t += 1; 
    if t > 1000:
        print(-1)
        break
    for i in range(1, K + 1):
        x,y,d = horse[i][0], horse[i][1], horse[i][2]
        nx,ny = x + dx[d], y + dy[d]
        if mp[nx][ny] == 0:
            ok = white(i)
            if ok:break
        elif mp[nx][ny] == 1:
            ok = red(i)
            if ok:break
        else: 
            ok = blue(i);
            if ok : break
    if ok:
        print(t)
        break    
