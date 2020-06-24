#부분수열의 합
#https://www.acmicpc.net/problem/1182
import sys
sys.stdin = open("input.txt","r")

def DFS(L,sum):
    global cnt
    if L==n:
        if sum==s:
            cnt+=1
        return
    else:
        DFS(L+1,sum+a[L])
        DFS(L+1,sum)


if __name__=="__main__":
    n,s=map(int,input().split())
    a=list(map(int,input().split()))
    cnt=0
    DFS(0,0)
    if s==0: #모든 값을 더하지 않은 경우
        cnt-=1
    print(cnt)
