problem_num = int(input())

test_result = []

for i in range(0, problem_num):

    test_result.insert(i, input())


count = 0
score = 0

for j in range(0, problem_num):

    each_test_result = test_result[j]

    for k in range(0, len(each_test_result)):

        if each_test_result[k] == 'O':

            count = count + 1

            score = score + count

        elif each_test_result[k] == 'X':

            count = 0

    print(score)

    count = 0
    score = 0
