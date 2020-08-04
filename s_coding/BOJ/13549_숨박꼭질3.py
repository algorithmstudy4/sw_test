#숨바꼭질3
#https://www.acmicpc.net/problem/13549
import sys
from collections import deque
sys.stdin = open("input.txt","r")
input=sys.stdin.readline

n,k=map(int,input().split())
MAX=100000
time=[-1]*(MAX+1) #순간이동은 0초이므로 -1로 초기화
Q=deque()
Q.append(n)
time[n]=0
while Q:
    cur=Q.popleft()
    if cur == k:
        print(time[cur])
        break

    for next in (cur - 1, cur + 1, cur * 2):
        if 0 <= next <= MAX and time[next] == -1:
            if next==cur*2: #순간이동이라면
                Q.appendleft(next)
                time[next] = time[cur]
            else:
                Q.append(next)
                time[next] = time[cur] + 1
