#스타트택시
#https://www.acmicpc.net/problem/19238
import sys
sys.stdin = open("input.txt","r")
from collections import deque

dh = [-1, 1, 0, 0]
dw = [0, 0, -1, 1]

n, m, fuel = map(int, input().split())  # 지도 크기, 승객 수,초기 연료량
array = [list(map(int, input().split())) for _ in range(n)]
h,w = map(int, input().split())  # 시작 위치 입력받기
people = {}
for _ in range(m):  
    sh, sw, eh, ew = map(int, input().split()) #출발지 행열,목적지행열
    people[(sh - 1, sw- 1)] = (eh - 1, ew - 1)

h -= 1
w -= 1

for key in people.keys():
    array[key[0]][key[1]] = 2

def bfs(h,w):
    global fuel, people

    if array[h][w] == 2:  # 같은 자리에 있는 경우
        candidate = [[h, w, people[(h, w)][0], people[(h, w)][1]]]
        distance = 0
    else:
        distance = sys.maxsize
        candidate = []  # 승객 후보
        q = deque()
        q.append([h, w, 0])
        visited = set()
        visited.add((h, w))
        while q:
            curh, curw, d = q.popleft()
            for i in range(4):
                nh, nw = curh + dh[i], curw + dw[i]
                if 0 <= nh < n and 0 <= nw < n:
                    if array[nh][nw] == 0 and (nh, nw) not in visited:
                        if fuel >= d + 1: 
                            q.append([nh, nw, d + 1])
                            visited.add((nh, nw))
                    elif array[nh][nw] == 2 and (nh,nw) not in visited: 
                        if fuel >= d + 1 and d + 1 <= distance:
                            distance = min(distance, d + 1)
                            candidate.append([nh, nw, people[(nh,nw)][0], people[(nh,nw)][1]])  
                            visited.add((nh,nw))

    if len(candidate) == 0: 
        print(-1)
        sys.exit(0)
    else:
        if len(candidate) != 1:
            candidate = sorted(candidate, key=lambda k: (k[0], k[1]))

        array[candidate[0][0]][candidate[0][1]] = 0  
        del people[(candidate[0][0], candidate[0][1])]
        fuel -= distance
        if fuel < 0:  
            print(-1)
            return
        visited = set()
        visited.add((candidate[0][0], candidate[0][1]))
        start_h, start_w, end_h, end_w = candidate[0]
        q = deque()
        q.append([start_h,start_w, 0])
        while q:
            curh, curw, d = q.popleft()
            for i in range(4):
                nh, nw = curh + dh[i], curw + dw[i]
                if 0 <= nh < n and 0 <= nw < n:
                    if [nh,nw] == [end_h, end_w]:
                        fuel = fuel - (d + 1) 
                        if fuel< 0:  # 연료가 부족한경우
                            print(-1)
                            sys.exit(0)
                        else:  # 연료 충전
                            fuel = fuel + (d + 1) * 2
                        return nh, nw
                    elif array[nh][nw] != 1 and (nh,nw) not in visited:
                        if fuel >= d + 1:
                            visited.add((nh,nw))
                            q.append([nh,nw, d + 1])
        print(-1)
        return

for _ in range(m): 
    h,w = bfs(h,w)

print(fuel)
