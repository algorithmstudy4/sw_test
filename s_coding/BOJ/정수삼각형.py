#정수 삼각형
#https://www.acmicpc.net/problem/1932
import sys
sys.stdin = open("input.txt","r")
n=int(input())
dp=[list(map(int,input().split())) for _ in range(n)] #dp테이블

for i in range(1,n):
    for j in range(len(dp[i])):
        if j==0: #왼쪽 위 대각선이 없음
            dp[i][j]+=dp[i-1][j]
        elif j==len(dp[i])-1:#오른쪽 대각선이 없음
            dp[i][j]+=dp[i-1][j-1]
        else:
            dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1])
print(max(dp[n-1]))
