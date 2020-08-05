subject_numbers = int(input())

score = list(map(int, input().split()))

max_num = 0

for j in range(len(score)):

    if score[j] > max_num:

        max_num = score[j]


fake_score = []

for i in range(len(score)):

    fake_score.insert(i, (score[i]/max_num)*100)


sum = 0

for k in range(len(fake_score)):

    sum = sum + fake_score[k]


print(sum/subject_numbers)

