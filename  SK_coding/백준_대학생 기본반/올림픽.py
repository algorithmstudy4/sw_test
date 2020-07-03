
country_all, country = map(int, input().split())

gold = []
silver = []
bronze = []

same_gold_country = []
same_silver_country = []

for i in range(0, country_all):

    num, a, b, c = map(int, input().split())

    gold.insert(num-1, a)
    silver.insert(num-1, b)
    bronze.insert(num-1, c)


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

    point = silver[country-1]

    for i in range(0, len(same_gold_country)):

        if silver[same_gold_country[i]] > point:

            level = level + 1

        elif silver[same_gold_country[i]] == point:

            same_silver_country.append(same_gold_country[i])

    if not same_silver_country:

        print(level)

    else:

        point = bronze[country-1]

        for i in range(0, len(same_silver_country)):

            if bronze[same_silver_country[i]] > point:

                level = level + 1

        print(level)


""" 
4 4 
1 1 0 0
2 1 0 0
3 0 1 0
4 0 1 0

--> error
"""
