from collections import deque

def rotate_right(number, direction, Gears) :
    if number == 4 :
        return

    if Gears[number-1][2] != Gears[number][6] :
        rotate_right(number + 1, -direction, Gears)
        Gears[number].rotate(direction)
    else :
        return

def rotate_left(number,direction, Gears) :
    if number == -1 :
        return

    if Gears[number + 1][6] != Gears[number][2] :
        rotate_left(number - 1, -direction, Gears)
        Gears[number].rotate(direction)
    else :
        return

if __name__ == "__main__" :
    Gears=[]
    answer = 0
    for _ in range(4) :
        gear = input()
        li = []
        for a in gear :
            li.append(int(a))
        Gears.append(deque(li))

    N = int(input())
    for _ in range(N) :
        number, direction = map(int,input().split())
        rotate_right(number, -direction, Gears)
        rotate_left(number-2, -direction, Gears)
        Gears[number-1].rotate(direction)

    for i in range(4) :
        answer += (2**i)*Gears[i][0]
    print(answer)