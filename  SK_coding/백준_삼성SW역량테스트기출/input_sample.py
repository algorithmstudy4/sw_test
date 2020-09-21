

from sys import *

input = stdin.readline

a = input()
b = input()

print(a+b)


c, d = input().split()

print(c+d)

e, f = map(int, input().split())

n = 4
board = [[int(x) for x in input().split()] for y in range(n)]
