#최소 힙
#https://www.acmicpc.net/problem/1927
import sys
import heapq as hq
sys.stdin = open("input.txt","r")
a=[]
n = int(input())
for _ in range(n):
    x=int(input())
    if x==-1: #종료
        break
    elif x==0: #출력
        if len(a)==0:
            print(0)
        else:
            print(hq.heappop(a))
    else: #넣기
        hq.heappush(a,x) #a리스트에 x넣음
