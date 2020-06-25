#회의실 배정
#https://www.acmicpc.net/problem/1931
import sys
sys.stdin = open("input.txt","r")

n=int(input())
meet=[]

for k in range(n):
    s,e=map(int,input().split())
    meet.append((s,e))

meet.sort(key=lambda x: (x[1],x[0]))

et=0
cnt=0
for s,e in meet:
    if et<=s:
        cnt+=1
        et=e
        #print(s,e,et)

print(cnt)
