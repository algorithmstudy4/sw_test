import math

n = int(input())


def palindrome(a):

    if a < n:

        return False

    else:

        list_num = str(a)

        for i in range(0, len(list_num)//2):

            if list_num[i] == list_num[len(list_num) - 1 - i]:

                continue
            else:

                return False

        return True


def prime_num(a):

    if a == 1:

        return False

    b = int(math.sqrt(a))

    for i in range(2, b+1):

        if a % i == 0:

            return False

    return True


c = False

while (c == False):

    if palindrome(n) == True:

        c = prime_num(n)

    n = n + 1

print(n-1)
