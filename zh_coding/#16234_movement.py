N, L, R = map(int,input().split())

country = [list(map(int, input().split())) for _ in range(N)]
count = 0

def present (cdt, open_list):     # 존재여부 및 인덱스 리턴
    if len(open_list) > 0:
        for i in range(len(open_list)):
            if cdt in open_list[i]:
                bo = True
                here = i
                break
            else:
                bo = False
                here = 0
        return bo, here
    else: return False, 0

def summ (country_list, sum_list):      # 연합국가끼리의 합 리턴
    _sum = 0
    for i in range(len(sum_list)):
        _sum += country_list[sum_list[i][0]][sum_list[i][1]]
    for i in range(len(sum_list)):
        country_list[sum_list[i][0]][sum_list[i][1]] = _sum // len(sum_list)

    return country_list

            
while True:
    open = []
    for i in range(N):
        for j in range(N):
            if j+1 < N:
                if L <= abs(country[i][j]-country[i][j+1]) <= R:
                    if len(open) == 0:
                        open += [[[i,j],[i,j+1]]]
                    else:
                        a,b = present([i,j], open)
                        c,d = present([i,j+1], open)

                        if a == True and c == True:
                            if b == d:
                                0
                            else:
                                u1=open[b]
                                u2=open[d]
                                union = u1+u2
                                open.remove(u1)
                                open.remove(u2)
                                open.append(union)
                        elif a == False and c == True:
                            open[d].append([i,j])
                        elif a == True and c == False:
                            open[b].append([i,j+1])
                        else:
                            open += [[[i,j],[i,j+1]]]

            if i+1 < N:
                if L <= abs(country[i][j]-country[i+1][j]) <= R:
                    if len(open) == 0:
                        open += [[[i,j],[i+1,j]]]
                    else:
                        e,f = present([i,j], open)
                        g,h = present([i+1,j], open)
                        if e == True and g == True:
                            if f == h:
                                0
                            else:
                                u1=open[f]
                                u2=open[h]
                                union = u1+u2
                                open.remove(u1)
                                open.remove(u2)
                                open.append(union)
                        elif e == False and g == True:
                            open[h].append([i,j])
                        elif e == True and g == False:
                            open[f].append([i+1,j])
                        else:
                            open += [[[i,j],[i+1,j]]]
    if len(open) == 1:                  # 연합국가의 개수를 파악하고 각 국가들의 인원을 업데이트 및 count 증가
        summ(country, open[0])
        count += 1
    elif len(open) > 1: 
        for i in range(len(open)):
            summ(country, open[i])
        count += 1
    else:                               # 연합국가가 존재하지 않을 경우 break
        break

print(count)
