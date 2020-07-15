up, down, height = input().split()

afternoon_distance = 0
night_distance = 0
day = 1


while afternoon_distance < int(height):

    afternoon_distance = night_distance + int(up)
    night_distance = afternoon_distance - int(down)
    day = day + 1

print(day)
