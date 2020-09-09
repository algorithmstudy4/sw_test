N,M = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(N)]

x=[]
for i in range(N):   
    for k in range(M):
        #가로네칸
        if k+3 < M :
            x.append(paper[i][k] + paper[i][k+1] + paper[i][k+2] + paper[i][k+3])
        #세로칸
        if i+3 < N :
            x.append(paper[i][k] + paper[i+1][k] + paper[i+2][k] + paper[i+3][k])
        

        #정사각형
        if k+1<M and i+1<N :
            x.append(paper[i][k] + paper[i][k+1]+paper[i+1][k] + paper[i+1][k+1])

        #ㅗ
        if k+2 < M and i+1 < N :
            x.append(paper[i][k+1] + paper[i+1][k] + paper[i+1][k+1] + paper[i+1][k+2])
        #ㅜ
        if k+2< M and i+1<N :
            x.append(paper[i+1][k+1] + paper[i][k] + paper[i][k+1] + paper[i][k+2])    
        #ㅓ
        if k+1 < M and i+2<N :
            x.append(paper[i+1][k] + paper[i][k+1] + paper[i+1][k+1] + paper[i+2][k+1])    
        #ㅏ  
        if k+1 < M and i+2<N :
            x.append(paper[i+1][k+1] + paper[i][k] + paper[i+1][k] + paper[i+2][k])    

        #ㄴ,ㄱ
        if k+1 <M and i+2<N:
            x.append(paper[i][k]+paper[i][k+1]+paper[i+1][k+1]+paper[i+2][k+1])
        if k+1 < M and i+2<N:
            x.append(paper[i][k]+paper[i][k+1]+paper[i+1][k]+paper[i+2][k])
        if k+1 < M and i+2<N:
            x.append(paper[i][k]+paper[i+1][k]+paper[i+2][k]+ paper[i+2][k+1])
        if k+1 <M and i+2<N:
            x.append(paper[i+2][k]+paper[i][k+1]+paper[i+1][k+1]+paper[i+2][k+1])
        if k+2<M and i+1<N:
            x.append(paper[i][k]+paper[i][k+1]+paper[i][k+2]+paper[i+1][k])

        if k+2<M and i+1<N:
            x.append(paper[i][k+2]+paper[i+1][k]+paper[i+1][k+1]+paper[i+1][k+2])
        if k+2<M and i+1<N:
            x.append(paper[i][k]+paper[i+1][k]+paper[i+1][k+1]+paper[i+1][k+2])
        if k+2<M and i+1<N:
            x.append(paper[i][k]+paper[i][k+1]+paper[i][k+2]+paper[i+1][k+2])
        if k+2<M and i+1<N:
            x.append(paper[i][k]+paper[i][k+1]+paper[i][k+2]+paper[i+1][k])

        #번개
        if k+1<M and i+2 <N:
            x.append(paper[i][k]+paper[i+1][k] + paper[i+1][k+1] + paper[i+2][k+1])
        if k+1<M and i+2 <N:
            x.append(paper[i][k+1]+paper[i+1][k] + paper[i+1][k+1] + paper[i+2][k])
        if k+2<M and i+1<N:
            x.append(paper[i][k]+paper[i][k+1]+paper[i+1][k+1]+paper[i+1][k+2])
        if k+2<M and i+1<N:
            x.append(paper[i][k+1]+paper[i][k+2]+paper[i+1][k]+paper[i+1][k+1])
print(max(x))
