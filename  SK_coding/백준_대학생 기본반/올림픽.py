
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

s1 = set()
s2 = set()
s3 = set()

point = gold[country-1]
level = 1

for i in range(0, country_all):

    if i == country-1:

        continue

    if gold[i] > point:

        s1.add(gold[i])

    elif gold[i] == point:

        same_gold_country.append(i)

level = level + len(s1)

if not same_gold_country:

    print(level)

else:

    point = silver[country-1]

    for i in range(0, len(same_gold_country)):

        if silver[same_gold_country[i]] > point:

            s2.add(silver[same_gold_country[i]])

        elif silver[same_gold_country[i]] == point:

            same_silver_country.append(same_gold_country[i])

    level = level + len(s2)

    if not same_silver_country:

        print(level)

    else:

        point = bronze[country-1]

        for i in range(0, len(same_silver_country)):

            if bronze[same_silver_country[i]] > point:

                s3.add(bronze[same_silver_country[i]])

        level = level + len(s3)

        print(level)

"""
6 6
1 3 2 0
2 3 1 0
3 2 2 0
4 2 2 0
5 2 2 1
6 2 1 0
error
"""
