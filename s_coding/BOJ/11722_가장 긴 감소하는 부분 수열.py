#가장 긴 감소하는 부분 수열
#https://www.acmicpc.net/problem/11722
import sys
sys.stdin = open("input.txt","r")
n=int(input())
arr=list(map(int,input().split()))
arr.insert(0,0)
dp=[0]*(n+1) #최대 길이 저장
dp[1]=1
res=1
for i in range(2,n+1):
    max=0 #최대 길이
    for j in range(i-1,0,-1):
        if arr[i]<arr[j] and dp[j]>max:
            max=dp[j]
    dp[i]=max+1
    if dp[i]>res:
        res=dp[i]
print(res)
