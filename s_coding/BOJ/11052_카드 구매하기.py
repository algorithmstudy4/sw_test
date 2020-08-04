#카드 구매하기
#https://www.acmicpc.net/problem/11052
import sys
sys.stdin = open("input.txt","r")
n=int(input())
card=list(map(int,input().split()))
dp=[0]*(n+1)
card.insert(0,0)
dp[1]=card[1]
print(card)
print(dp)
for i in range(2,n+1):
    for j in range(1,i+1):
        dp[i]=max(dp[i],dp[i-j]+card[j])
print(dp[n])
print(dp)
