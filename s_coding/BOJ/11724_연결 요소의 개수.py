#연결 요소의 개수
#https://www.acmicpc.net/problem/11724
import sys
sys.stdin = open("input.txt","r")
input=sys.stdin.readline
sys.setrecursionlimit(10**8)

def DFS(v):
    #v가 시작이 됨
    visited[v]=1

    for i in range(1,n+1):
        #둘다 연결되어 있고 아직 방문안했을 때
        if board[v][i]==1 and board[i][v]==1 and visited[i]==0 :
            DFS(i)


if __name__=="__main__":
    n, m = map(int, input().split())
    board = [[0] * (n + 1) for _ in range(n + 1)]
    visited=[0]*(n+1)
    for _ in range(m):
        s, e = map(int, input().split())
        board[s][e] = board[e][s] = 1

    cnt=0

    for i in range(1,n+1):
            if visited[i]==0: #방문아직 안했으면
                DFS(i)
                cnt+=1
    print(cnt)
