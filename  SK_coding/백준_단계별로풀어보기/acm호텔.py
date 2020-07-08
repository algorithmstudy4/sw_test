
test_num = int(input())

room_number_list = []
room_number = 'a'

for i in range(0, test_num):

    floor_num, room_num, client_num = map(int, input().split())

    if client_num < floor_num:

        room_number = str(client_num) + '01'

    elif client_num % floor_num == 0:

        if (client_num / floor_num) < 10:

            room_number = str(floor_num) + '0' + str(int(client_num/floor_num))

        else:

            room_number = str(floor_num) + str(int(client_num/floor_num))

    else:

        if (client_num / floor_num) < 9:

            room_number = str(int(client_num % floor_num)) + \
                '0' + str(int(client_num / floor_num)+1)

        else:

            room_number = str(int(client_num % floor_num)) + \
                str(int(client_num / floor_num)+1)

    room_number_list.insert(i, room_number)


for j in range(0, test_num):

    print(room_number_list[j])
