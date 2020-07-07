
num = int(input())
channel = list()

for i in range(0, num):

    channel.append(input())

    if channel[i] == 'KBS1':

        KBS1_num = i

    elif channel[i] == 'KBS2':

        KBS2_num = i


if KBS1_num < KBS2_num:

    for i in range(0, KBS1_num):

        print(1, end="")

    for i in range(0, KBS1_num):

        print(4, end="")

    for i in range(0, KBS2_num):

        print(1, end="")

    for i in range(1, KBS2_num):

        print(4, end="")


elif KBS1_num > KBS2_num:

    for i in range(0, KBS1_num):

        print(1, end="")

    for i in range(0, KBS1_num):

        print(4, end="")

    for i in range(0, KBS2_num+1):

        print(1, end="")

    for i in range(1, KBS2_num+1):

        print(4, end="")
