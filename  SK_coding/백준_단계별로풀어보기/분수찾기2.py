count = int(input())

n = 1

if count == 1 :

    print(1, end='')
    print('/', end='')
    print(1)

elif count > 1 :

    while n*(n+1)/2 >= count or count > (n+1)*(n+2)/2 :

        n = n + 1

if n%2 == 1 :

    y = n+1
    x = 1

    for i in range(0,count - int(n*(n+1)/2 + 1)) :

        y = y - 1
        x = x + 1

    print (x, end='')
    print('/', end='')
    print(y) 



elif n%2 == 0 :

    x = n+1
    y = 1

    for i in range(0,count - int(n*(n+1)/2 + 1)) :

        x = x -1
        y = y + 1
    
    print(x, end='')
    print('/', end='')
    print(y)





