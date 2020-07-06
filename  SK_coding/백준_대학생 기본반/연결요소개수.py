
n, m = map(int, input().split())

m1 = []
m2 = []

for i in range(0, n):

    a, b = map(int, input().split())

    m1.append(a)
    m2.append(b)


for i in range(0, len(m1)):

    point = m1[0]

    for j in range(0, len(m1)):


        # 간선 연결 끝 -> num++,  루프 새로 반복,
        # 간선 연결 -> 연결 점 리스트 삭제
