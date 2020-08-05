testcase_num = int(input())

each_testcase = []

for i in range(0, testcase_num):

    each_testcase.insert(i, input().split())

average = []

sum_num = 0

for j in range(0, len(each_testcase)):

    for k in range(1, len(each_testcase[j])):

        sum_num = sum_num + int(each_testcase[j][k])

    average.insert(j, sum_num/int(each_testcase[j][0]))

    sum_num = 0

count = 0

for j in range(0, len(each_testcase)):

    for k in range(1, len(each_testcase[j])):

        if int(each_testcase[j][k]) > int(average[j]):

            count = count + 1

    print('%.3f' % float((count/float(each_testcase[j][0]))*100), end='')
    print('%')

    count = 0
