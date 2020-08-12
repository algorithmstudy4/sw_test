from sys import*
import math

y = 0
num_list = []

input = stdin.readline


def get_primes(n):

    count = 0

    is_primes = [True]*n
    max_length = math.ceil(math.sqrt(n))

    for i in range(2, max_length):

        if is_primes[i]:

            for j in range(i+i, n, i):

                is_primes[j] = False

    for i in range(2, n):
        if is_primes[i]:
            count = count + 1

    return (count)


while True:

    n = int(input())
    num_list.insert(y, n)

    if num_list[y] == 0:

        break

    y = y+1

for i in range(0, len(num_list)-1):

    x = 0

    x = get_primes((2*num_list[i])+1) - get_primes(num_list[i]+1)

    print(x)
