

y = 0
num_list = []

while True:

    n = int(input())
    num_list.insert(y, n)

    if num_list[y] == 0:

        break

    y = y+1

for i in range(0, len(num_list)-1):

    x = 0

    for j in range(num_list[i]+1, (2*num_list[i])+1):

        count = 0

        for k in range(2, j):

            if j % k == 0:

                break

            else:

                count = count + 1

        if count == j - 2:

            x = x+1

    print(x)
