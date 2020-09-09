#카드 정렬하기
#https://www.acmicpc.net/problem/1715
import heapq
import sys
sys.stdin = open("input.txt","r")

n=int(input())
heap=[]
for i in range(n):
    tmp=int(input())
    heapq.heappush(heap,tmp)

total=0
#힙에 원소 한 개 남을 때까지
while len(heap) !=1:
    print(heap)
    #가장 작은 2개의 묶음 꺼내기
    one=heapq.heappop(heap)
    two=heapq.heappop(heap)
    #카드 묶음을 합쳐서 다시 삽입
    sum=one+two
    total+=sum
    heapq.heappush(heap,sum)

print(total)
