#이분 그래프
#https://www.acmicpc.net/problem/1707
import sys
from collections import deque
sys.stdin = open("input.txt","r")
input=sys.stdin.readline
sys.setrecursionlimit(10**6)
def DFS(v,color):
    global flag
    check[v]=color

    for i in adj[v]:
        if check[i]==color: #칠하려는 색깔로 이미 칠해져있을 경우, 이분그래프가 아님
            flag=0
            return
        if check[i]==0: #아직 안칠해져있으면
            check[i]=-color
            DFS(i,-color)

def BFS(v,color):
    global flag
    Q=deque()
    Q.append(v)
    check[v]=color
    while Q:
        v=Q.popleft()
        for i in adj[v]:
            if check[i]==check[v]:
                flag=0
                return
            elif check[i]==0:
                check[i]=-check[v]
                Q.append(i)



if __name__=="__main__":
    t=int(input())
    while t>0 :
        t-=1
        v,e=map(int,input().split())
        adj=[[] for _ in range(v+1)]
        check=[0]*(v+1)
        for _ in range(e):
            a,b=map(int,input().split())
            adj[a].append(b)
            adj[b].append(a)
        color=1
        flag=1
        for i in range(1,v+1):
            if check[i]==0: #방문했던 곳 다시 방문하면 안됨
                #DFS(i,color)
                BFS(i,color)
            if flag==0:
                break
        if flag==0:
            print("NO")
        else:
            print("YES")
