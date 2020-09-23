'''
Collections.Counter : 컨테이너에 동일한 값이 몇개인지 사용하는 객체 (return 딕셔너리)
행열 변환 후 사용.(transpose) - zip
'''

from collections import Counter

r,c,k=map(int,input().split())
A = [list(map(int,input().split())) for _ in range(3)]


time = 0
while time<=100:
    if len(A) >= r and len(A[0]) >= c and A[r-1][c-1] == k:
        print(time)
        break

    C_flag = False
    if len(A)<len(A[0]):  #행 < 열
        C_flag = True
        A = list(zip(*A)) #행/열바꾸기

    max_len = 0
    tmp_A = []
    for row in A:
        ct = Counter(row)
        if ct.get(0):
            del ct[0]
        L = list(map(list,ct.items()))                     # 딕셔너리 -> 리스트 [[숫자,카운트]]
        L = sum(sorted(L, key=lambda x: (x[1],x[0])), [])  # 솔팅 후 카운트 순으로 정렬
        tmp_A.append(L[:100])

        max_len = max(max_len,len(tmp_A[-1]))

    for i in range(len(tmp_A)):
        if len(tmp_A[i]) < max_len:
            tmp_A[i] += [0]*(max_len-len(tmp_A[i])) # 나머지 0으로 채움

    A = tmp_A
    if C_flag:      # C연산, 다시 행열 바꾸기
        A = list(zip(*A))
    time += 1

if time > 100: #100초 이상시,
    print(-1)
