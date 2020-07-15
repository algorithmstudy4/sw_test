#1, 2, 3 더하기 3
#https://www.acmicpc.net/problem/15988
import sys
sys.stdin = open("input.txt","r")
t=int(input())
dp=[0,1,2,4]
for i in range(4, 1000000 + 1):
    dp.append((dp[i - 1] + dp[i - 2] + dp[i - 3])%1000000009)
for _ in range(t):
    n=int(input())
    print(dp[n]%1000000009)
