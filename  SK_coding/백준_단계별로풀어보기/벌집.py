num = int(input())

n = 1

if num == 1 :

    print(1)

elif 1 < num <= 7 :

    print(2)

else :

    while 1 + n*( 2*6 + (n-1)*6)/2 >= num or 1 + (n+1)*( 2*6 + (n)*6)/2 < num :

        n = n + 1

    print( n + 2)

