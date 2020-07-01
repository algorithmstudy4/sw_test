#트리 순회
#https://www.acmicpc.net/problem/1991
import sys
sys.stdin = open("input.txt","r")

#전위순회
def preorder(r):
    print(chr(r+65),end='') #다시 대문자로 바꾸어 출력하기위함
    if node[r][0]!=-1:
        preorder(node[r][0])
    if node[r][1]!=-1:
        preorder(node[r][1])

#중위순회
def inorder(r):
    if node[r][0]!=-1:
        inorder(node[r][0])
    print(chr(r + 65), end='')
    if node[r][1]!=-1:
        inorder(node[r][1])

#후위순회
def postorder(r):
    if node[r][0]!=-1:
        postorder(node[r][0])
    if node[r][1]!=-1:
        postorder(node[r][1])
    print(chr(r + 65), end='')

if __name__=="__main__":
    n = int(input())
    node=[[-1,-1] for _ in range(26)]
    for _ in range(n):
        p,left,right=input().split()
        if left.isupper(): #대문자 알파벳이면 노드에 넣기
            node[ord(p)-65][0]=ord(left)-65
        if right.isupper():  # 대문자 알파벳이면 노드에 넣기
            node[ord(p)-65][1] = ord(right)-65

    preorder(0) #스타트는 항상 루트노드(A)
    print()
    inorder(0)
    print()
    postorder(0)
