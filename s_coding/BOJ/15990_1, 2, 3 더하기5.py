#1, 2, 3 더하기 5
#https://www.acmicpc.net/problem/15990
import sys
sys.stdin = open("input.txt","r")
t=int(input())
dp=[[0]*4 for _ in range(100000+1)]
dp[1]=[0,1,0,0]
dp[2]=[0,0,1,0]
dp[3]=[0,1,1,1]
d=1000000009
for i in range(4,100000 +1):
    dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % d
    dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % d
    dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % d
for _ in range(t):
    n=int(input())
    print(sum(dp[n])%d)
