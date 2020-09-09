#톱니바퀴
#https://www.acmicpc.net/problem/14891
import sys
from collections import deque
sys.stdin = open("input.txt","r")
gear= {} #딕셔너리 

for i in range(1,5):
    gear[i]= deque(list(map(int,input())))
n=int(input())

def check_right(num,dir):
    if num>4 or gear[num-1][2]==gear[num][6]:
        return

    if gear[num-1][2] !=gear[num][6]:
        check_right(num+1,-dir)
        gear[num].rotate(dir) 

def check_left(num,dir):
    if num < 1 or gear[num][2]==gear[num+1][6]:
        return
    if gear[num][2]!=gear[num+1][6]:
        check_left(num-1,-dir)
        gear[num].rotate(dir)

for _ in range(n):
    num,dir = map(int,input().split())
    check_right(num+1,-dir)
    check_left(num-1,-dir)
    gear[num].rotate(dir)

res=0
for i in range(4):
    res+= (2**i) *gear[i+1][0] #1이면 더하고 0이면 0점
print(res)
