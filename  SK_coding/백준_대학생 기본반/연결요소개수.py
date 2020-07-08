
import sys

n, m = map(int, sys.stdin.readline().split())

m1 = []
m2 = []

count = 1

for i in range(0, m):

    a, b = map(int, sys.stdin.readline().split())

    m1.append(a)
    m2.append(b)


for i in range(0, m):

    point1 = m1[0]
    point2 = m2[0]

    for j in range(1, len(m1)):

        if m1[j] == point1:

            del m1[0], m1[j-1]
            m1.insert(0, m2[j])
            del m2[j]
            break

        elif m2[j] == point1:

            del m1[0], m2[j]
            m1.insert(0, m1[j-1])
            del m1[j]
            break

        elif m1[j] == point2:

            del m2[0], m1[j]
            m2.insert(0, m2[j-1])
            del m2[j]
            break

        elif m2[j] == point2:

            del m2[0], m2[j-1]
            m2.insert(0, m1[j])
            del m1[j]
            break

        elif j == len(m1)-1:
            count = count + 1
            del m1[0], m2[0]
            break

print(count)
