#쇠막대기
#https://www.acmicpc.net/problem/10799
import sys
sys.stdin = open("input.txt","r")
s= input()
stack=[]
cnt=0
for i in range(len(s)):
    if s[i]=='(':
        stack.append(x)
    else:
        stack.pop()
        if s[i-1]=='(': #레이저
            cnt += len(stack)
        else:
            cnt += 1
print(cnt)
