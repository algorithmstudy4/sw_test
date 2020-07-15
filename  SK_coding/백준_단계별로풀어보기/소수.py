m = int(input())
n = int(input())

k = 0
number = []
sum = 0

for i in range(m, n+1):

    count = 0

    for j in range(2, i):

        if i % j == 0:

            break

        else:

            count = count + 1

    if count == i - 2:

        number.insert(k, i)

        k = k + 1

if len(number) == 0:

    print(-1)

else:

    for i in range(0, len(number)):

        sum = sum + number[i]

    print(sum)
    print(number[0])
