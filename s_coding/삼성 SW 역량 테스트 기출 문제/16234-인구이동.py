#인구 이동
#https://www.acmicpc.net/problem/16234
import sys
from collections import deque
sys.stdin = open("input.txt","r")
n,l,r=list(map(int,input().split()))
arr=[]
for _ in range(n):
    arr.append(list(map(int,input().split())))

dh=[-1,1,0,0]
dw=[0,0,-1,1]

res=0 #결과

#연합하여 인구 이동
def union(united,sum,cnt):
    for i,j in united:
        arr[i][j]=sum//cnt

#특정 위치에서 출발하여 모든 연합을 체크한 뒤에 데이터 갱신
def bfs(h,w,index):
    #(h,w)와 연결된 나라 정보를 담는 리스트
    united=[]
    united.append((h,w))
    q=deque() #bfs를 위한 큐
    q.append((h,w))
    visited[h][w]=index #현재 연합 번호 할당, visited체크
    sum=arr[h][w] #현재 연합의 인구 수
    cnt=1 #현재 연합 국가 수
    while q:
        cur = q.popleft()
        for i in range(4):
            nh = dh[i] + cur[0]
            nw = dw[i] + cur[1]
            if 0 <= nh < n and 0 <= nw < n and visited[nh][nw] == -1:#아직방문하지 않은 곳은 -1
                if l <= abs(arr[nh][nw] - arr[cur[0]][cur[1]]) <= r:
                    q.append((nh, nw))
                    visited[nh][nw] = index
                    sum += arr[nh][nw]
                    cnt += 1
                    united.append((nh,nw)) #연결되어 있는 것을 저장, pop하는 과정이 없음
    union(united,sum,cnt)

while True:
    visited = [[-1] * (n) for _ in range(n)]  # 방문 초기화(방문하지 않았으면 -1)
    index=0
    for i in range(n):
        for j in range(n):
            cnt = 0  # 첫시작
            sum = 0
            if visited[i][j]==-1: #아직 방문하지 않았으면
                bfs(i,j,index)
                index+=1
    #인구 이동이 모두 끝나면
    if index == n*n:
        break
    res+=1

print(res)
