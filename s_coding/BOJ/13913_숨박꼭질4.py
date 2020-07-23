#숨바꼭질4
#https://www.acmicpc.net/problem/13913
import sys
from collections import deque
sys.stdin = open("input.txt","r")
input=sys.stdin.readline

n,k=map(int,input().split())
MAX=100000
time = [0]*(MAX+1)
path = [0]*(MAX+1)
Q=deque()
Q.append(n)
while Q:
    cur=Q.popleft()
    if cur==k:
        print(time[cur])
        p=[]
        print(path)
        while cur!=n:
            p.append(cur)
            cur=path[cur]
        print(p)
        p.append(n)
        p.reverse()
        print(' '.join(map(str,p)))
        break
    for next in (cur-1,cur+1,cur*2):
        if 0<=next<=MAX and time[next]==0:
            time[next]=time[cur]+1
            path[next]=cur
            Q.append(next)
