#퇴사
#https://www.acmicpc.net/problem/14501
import sys
sys.stdin = open("input.txt","r")

n=int(input())
t=[] #걸리는 시간
p=[] #수익
res=-1e9
def dfs(day,sum):
    global res
    if day==n+1:
        if sum > res:
            res=sum
    else:
        if day+t[day]<=n+1: #상담이 가능한 경우
            dfs(day+t[day],sum+p[day])
        dfs(day+1,sum)

for i in range(n):
    a,b=map(int,input().split())
    t.append(a) 
    p.append(b)
t.insert(0,0) #인덱스번호를 날짜로 사용하기 위해
p.insert(0,0)
dfs(1,0)
print(res)
