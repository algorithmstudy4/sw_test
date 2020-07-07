on = int(input())

cn = on

nn = 0
mn = 0
count = 0


while True:

    mn = cn % 10 + cn//10

    nn = (cn % 10)*10 + mn % 10

    cn = nn

    count = count + 1

    if nn == on:
        break

print(count)
