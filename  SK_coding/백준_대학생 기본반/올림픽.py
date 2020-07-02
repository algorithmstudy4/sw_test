
country_all, country = map(int, input().split())

gold = []
silver = []
bronze = []

same_gold_country = []
same_silver_country = []
same_bronze_country = []

for i in range(0, country_all):

    a, b, c = map(int, input().split())

    gold.append(a)
    silver.append(b)
    bronze.append(c)


point = gold[country-1]

level = 1

for i in range(0, country_all):

    if i == country-1:

        continue

    if gold[i] > point:

        level = level + 1

    elif gold[i] == point:

        same_gold_country.append(i)

if not same_gold_country:

    print(level)

else:

    level = 0

    point = silver[country-1]

    for i in range(0, len(same_gold_country)):

        if silver[same_gold_country[i]] > point:

            level = level + 1

        elif silver[same_gold_country[i]] == point:

            same_silver_country.append(same_gold_country[i])

    if not same_silver_country:

        print(level)

    else:

        level = 0

        point = bronze[country-1]

        for i in range(0, len(same_silver_country)):

            if bronze[same_silver_country[i]] > point:

                level = level + 1

            elif bronze[same_silver_country[i]] == point:

                same_bronze_country.append(same_silver_country[i])

        # level reset 잘못됨.
        # 마지막 동메달 비교 추가.
