#N과 M (9) 
#https://www.acmicpc.net/problem/15663
import sys
from collections import Counter
sys.stdin = open("input.txt","r")

def DFS(L):
    if L==m:
        for x in res:
            print(x,end=' ')
        print()
        return
    else:
        for i in range(len(cnt)):
            if cnt[i]:
                res[L]=num[i]
                cnt[i]-=1
                DFS(L+1)
                cnt[i]+=1

if __name__=="__main__":
    n, m = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    num, cnt = map(list, zip(*list(Counter(a).items())))
    res=[0]*m
    DFS(0)
