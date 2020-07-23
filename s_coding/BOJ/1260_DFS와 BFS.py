#DFS와 BFS
#https://www.acmicpc.net/problem/1260
import sys
from collections import deque
sys.stdin = open("input.txt","r")
input=sys.stdin.readline

def DFS(v):
    visited[v]=1 #방문표시
    print(v,end=' ')

    for i in range(1,n+1):
        if visited[i]==0 and adj[v][i]==1: #방문하지 않았고 연결되어 있으면
            DFS(i)

def BFS(v):
    Q=deque()
    Q.append(v)
    visited[v]=1

    while Q:
        v=Q.popleft()
        print(v,end=' ')
        for i in range(1, n + 1):
            if visited[i] == 0 and adj[v][i] == 1:  # 방문하지 않았고 연결되어 있으면
                Q.append(i)
                visited[i]=1


if __name__=="__main__":
    n,m,v=map(int,input().split())
    adj = [[0] * (n + 1) for _ in range(n + 1)]
    visited = [0] * (n + 1)
    for _ in range(m):
        s,e=map(int,input().split())
        adj[s][e]=adj[e][s]=1
    DFS(v)
    print()
    visited = [0] * (n + 1)
    BFS(v)
