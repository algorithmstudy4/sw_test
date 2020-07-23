#ABCDE
#https://www.acmicpc.net/problem/13023
import sys
sys.stdin = open("input.txt","r")
input=sys.stdin.readline
sys.setrecursionlimit(10**6)
def DFS(v,depth):
    global flag
    visited[v]=1
    if depth>=4: #깊이가 4이상이면 참
        flag=1
        return

    for i in adj[v]:
        if visited[i]==0:
            DFS(i,depth+1)
            visited[i]=0 #다음 방문시 처리를 위해
            if flag==1:
                return

if __name__=="__main__":
    n,m=map(int,input().split())
    adj = [[] * n for _ in range(n)]
    visited = [0] * (n)
    for _ in range(m):
        a,b=map(int,input().split())
        #adj[a][b]=adj[b][a]=1
        adj[a].append(b)
        adj[b].append(a)

    for x in adj:
        print(x)
    flag=0
    for i in range(n): #시작점
        DFS(i,0)
        visited[i]=0 #visited배열을 매번 만드는 것보다 다쓰고 0으로 초기화하면 메모리 아낌
        if flag==1:
            break

    print(flag)
