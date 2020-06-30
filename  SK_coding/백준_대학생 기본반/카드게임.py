
card_color = []
card_num = []
box = 0

for i in range(0, 5):

    a, b = input().split()
    b = int(b)
    a = ord(a)
    card_color.append(a)
    card_num.append(b)

for i in range(0, 5):

    for j in range(i+1, 5):

        if card_num[i] > card_num[j]:

            box = card_num[i]
            card_num[i] = card_num[j]
            card_num[j] = box

        if card_color[i] > card_color[j]:

            box = card_color[i]
            card_color[i] = card_color[j]
            card_color[j] = box

for i in range(0, 5):

    card_color[i] = chr(card_color[i])

if card_color[0] == card_color[4]:

    if card_num[0] == card_num[1]-1 and card_num[1] == card_num[2]-1 and card_num[2] == card_num[3]-1 and card_num[3] == card_num[4]-1:

        score = card_num[4] + 900

    else:

        score = card_num[4] + 600

elif (card_num[0] == card_num[3] and card_num[4] != card_num[3]) or (card_num[1] == card_num[4] and card_num[0] != card_num[1]):

    score = card_num[4] + 800

elif (card_num[0] == card_num[2] and card_num[3] == card_num[4]) or (card_num[0] == card_num[1] and card_num[2] == card_num[4]):

    if card_num[0] == card_num[2] and card_num[3] == card_num[4]:

        score = card_num[0]*10 + card_num[3] + 700

    elif card_num[0] == card_num[1] and card_num[2] == card_num[4]:

        score = card_num[2]*10 + card_num[0] + 700

elif card_num[0] == card_num[1]-1 and card_num[1] == card_num[2]-1 and card_num[2] == card_num[3]-1 and card_num[3] == card_num[4]-1:

    score = card_num[4] + 500

elif (card_num[0] == card_num[2]) or (card_num[1] == card_num[3]) or (card_num[2] == card_num[4]):

    if card_num[0] == card_num[2]:

        score = 400 + card_num[0]

    elif card_num[1] == card_num[3]:

        score = 400 + card_num[1]

    elif card_num[2] == card_num[4]:

        score = 400 + card_num[2]

elif (card_num[0] == card_num[1] and card_num[2]) == card_num[3] or (card_num[0] == card_num[1] and card_num[3] == card_num[4]) or (card_num[1] == card_num[2] and card_num[3] == card_num[4]):

    score = 300 + card_num[1] + card_num[3]*10

elif card_num[0] == card_num[1] or card_num[1] == card_num[2]:

    score = 200 + card_num[1]

elif card_num[2] == card_num[3] or card_num[3] == card_num[4]:

    score = 200 + card_num[3]

else:
    score = 100 + card_num[4]

print(score)
