numbers = []

for i in range(0, 10):

    numbers.insert(i, int(input()) % 42)

count = 0
other_numbers = []


for i in range(0, 10):

    if i == 0:

        other_numbers.insert(0, numbers[0])

        count = count + 1

    else:

        for j in range(0, count):

            if numbers[i] == other_numbers[j]:

                break

            elif j == count-1:

                other_numbers.insert(count, numbers[i])

                count = count + 1


print(count)
