#이모티콘
#https://www.acmicpc.net/problem/14226
import sys
from collections import deque
sys.stdin = open("input.txt","r")
input=sys.stdin.readline
n=int(input())
visited = [[-1]*1001 for _ in range(1001)]
Q=deque()
Q.append((1,0)) #현재이모티콘 1개, tmp에 0개
visited[1][0]=0 #0초가 시작

while Q:
    s,c=Q.popleft()

    #복사
    if visited[s][s]==-1:
        visited[s][s]=visited[s][c]+1
        Q.append((s,s))

    #붙여넣기
    if s+c<=n and visited[s+c][c]==-1:
        visited[s+c][c] = visited[s][c] + 1
        Q.append((s+c, c))

    #삭제
    if s-1>=0 and visited[s-1][c] == -1:
        visited[s-1][c] = visited[s][c] + 1
        Q.append((s-1, c))

res=2147000000
for x in visited[n]:
    if x==-1:
        continue
    else:
        res=min(res,x)
print(res)
