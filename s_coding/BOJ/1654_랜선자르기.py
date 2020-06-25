#랜선자르기
#https://www.acmicpc.net/problem/1654
import sys
sys.stdin = open("input.txt","r")

K,N = map(int,input().split())
lan = []
largest=0
for i in range(K):
    tmp= int(input())
    lan.append(tmp)
    largest= max(largest,tmp)

lt =1
rt =largest

while lt <= rt:
    mid = (lt+rt)//2
    cnt=0
    for x in lan:
        cnt += x//mid
    if cnt >= N: #mid값을 크게한다. 
        res=mid
        lt = mid + 1
    else: #개수가 더 많이 필요함 mid값을 작게한다.
        rt = mid - 1
print(res)
