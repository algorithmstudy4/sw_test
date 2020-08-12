word = input()

word_askii = 'a'
count_list = [0 for i in range(26)]
max_count = 0
max_count_index = 0
same_count = 0

for i in range(0, len(word)):

    word_askii = ord(word[i])

    if 90 >= word_askii > 64:

        count_list[word_askii - 65] = count_list[word_askii - 65] + 1

    elif 122 >= word_askii > 96:

        count_list[word_askii - 97] = count_list[word_askii - 97] + 1

for j in range(0, 26):

    if j == 0:

        max_count = count_list[0]
        max_count_index = 0

    else:

        if max_count < count_list[j]:

            max_count = count_list[j]
            max_count_index = j

        elif max_count == count_list[j]:

            same_count = max_count

if max_count == same_count:

    print('?')

else:

    print(chr(max_count_index + 65))
