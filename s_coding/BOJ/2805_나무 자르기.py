#나무 자르기
#https://www.acmicpc.net/problem/2805
import sys
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())
tree=list(map(int,input().split()))
lt=0
rt=max(tree)
res=0
def count(mid):
    sum=0
    for x in tree:
        if x-mid>0:
            sum+=(x-mid)
    return sum

while lt<=rt:
    mid=(lt+rt)//2
    sum=count(mid)
   # print(sum,mid)
    if sum >= m:
        res=mid
        lt=mid+1
    else:
        rt=mid-1
print(res)
