a = int(input())
b = int(input())
c = int(input())

result = a*b*c

string_result = '0'

string_result = str(result)

count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

for i in range(0, len(string_result)):

    if string_result[i] == '0':

        count[0] = count[0] + 1
    elif string_result[i] == '1':

        count[1] = count[1] + 1
    elif string_result[i] == '2':

        count[2] = count[2] + 1
    elif string_result[i] == '3':

        count[3] = count[3] + 1
    elif string_result[i] == '4':

        count[4] = count[4] + 1
    elif string_result[i] == '5':

        count[5] = count[5] + 1
    elif string_result[i] == '6':

        count[6] = count[6] + 1
    elif string_result[i] == '7':

        count[7] = count[7] + 1
    elif string_result[i] == '8':

        count[8] = count[8] + 1
    elif string_result[i] == '9':

        count[9] = count[9] + 1


for i in range(0, 10):

    print(count[i])
