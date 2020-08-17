#실패율
#https://programmers.co.kr/learn/courses/30/lessons/42889

def solution(N, stages):
    answer = []
    stages.sort()
    arr=[0]*(N+1)
    total=len(stages)
    fail=[]
    for i in range(1,N+1):
        for x in stages:
            if i==x:
                arr[i]+=1
        if arr[i]==0:
            fail.append((0,i))
        else:
            fail.append((arr[i]/total,i))
        total-=arr[i]
    fail.sort(key=lambda x:(-x[0],x[1]))
    print(fail)
    for i in fail:
        answer.append(i[1])
    return answer
