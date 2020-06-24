
a = int(input())

room = [input() for _ in range(a)]

count = 0

can_sleep1 = 0
can_sleep2 = 0

for i in range(0, a):

    for j in range(0, a):

        if room[i][j] == '.':

            count = count + 1

            if count == 2:

                can_sleep1 = can_sleep1 + 1

        elif room[i][j] == 'X':

            count = 0

    count = 0

for i in range(0, a):

    for j in range(0, a):

        if room[j][i] == '.':

            count = count + 1

            if count == 2:

                can_sleep2 = can_sleep2 + 1

        elif room[j][i] == 'X':

            count = 0

    count = 0

print(can_sleep1, end=" ")
print(can_sleep2)
