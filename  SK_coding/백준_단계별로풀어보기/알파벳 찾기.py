word = input()

for i in range(ord('a'), ord('z')+1):

    for j in range(len(word)):

        if i == ord(word[j]):

            print(j)

            break

        elif i != ord(word[j]) and j == len(word)-1:

            print('-1')
