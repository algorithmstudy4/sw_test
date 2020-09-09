#도시 분할 계획
#https://www.acmicpc.net/problem/1647
'''
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4
#출력
8
'''
import sys
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())

parent=[0]*(n+1)
edges = []
result=0
for _ in range(m):
    a,b,c=map(int,input().split())
    edges.append((c,a,b)) #비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정

edges.sort()

for i in range(1,n+1):
    parent[i]=i

def find_parent(parent,x):
    if parent[x]!=x:
        parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a=find_parent(parent,a)
    b=find_parent(parent,b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b


max_cost=0
for edge in edges:
    c,a,b=edge
    #사이클이 발생하지 않는 경우에만 집합에 포함
    if find_parent(parent,a) != find_parent(parent,b):
        union_parent(parent,a,b)
        result+=c
        max_cost=max(max_cost,c)

result-=max_cost
print(result)
