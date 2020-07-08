
a = int(input())

number = []

wanted_number = []

k = 0

number = list(map(int, input().split()))

for i in range(0, len(number)):

    count = 0

    for j in range(2, number[i]):

        if number[i] % j == 0:

            break

        else:

            count = count + 1

    if count == number[i] - 2:

        k = k + 1

print(k)
