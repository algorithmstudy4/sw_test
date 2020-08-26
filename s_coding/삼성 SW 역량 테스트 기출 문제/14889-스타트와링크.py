#스타트와 링크
#https://www.acmicpc.net/problem/14889
import sys
sys.stdin = open("input.txt","r")

n=int(input())
board=[list(map(int,input().split())) for _ in range(n)]
team=[False]*(n+1)
minv=1e9
def dfs(t,d):
    global minv
    if d==n:
        return
    if t==n//2: #팀의 반을 선택한 것
        #팀점수 계산
        start=link=0
        for i in range(n):
            for j in range(n):
                if team[i]==True and team[j]==True:
                    start+=board[i][j]
                elif team[i]==False and team[j]==False: 
                    link+=board[i][j]
        minv=min(abs(start-link),minv)
        return
    else:
        team[d]=True
        dfs(t+1,d+1)#팀을 선택한 것
        team[d]=False
        dfs(t,d+1)#팀을 선택하지 않은 것

dfs(0,0)
print(minv)
