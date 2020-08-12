dial_char = input()

time = 0

for i in range(0, len(dial_char)):

    if 65 <= ord(dial_char[i]) < 68:

        time = time + 3

    elif 68 <= ord(dial_char[i]) < 71:

        time = time + 4

    elif 71 <= ord(dial_char[i]) < 74:

        time = time + 5

    elif 74 <= ord(dial_char[i]) < 77:

        time = time + 6

    elif 77 <= ord(dial_char[i]) < 80:

        time = time + 7

    elif 80 <= ord(dial_char[i]) < 84:

        time = time + 8

    elif 84 <= ord(dial_char[i]) < 87:

        time = time + 9

    elif 87 <= ord(dial_char[i]) < 91:

        time = time + 10


print(time)
