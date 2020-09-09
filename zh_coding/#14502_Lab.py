import copy
N, M = map(int,input().split())     # N*M 크기의 연구소
lab = [list(map(int, input().split())) for _ in range(N)]
copiedLab = copy.deepcopy(lab)

dx = [0,1,0,-1]
dy = [1,0,-1,0]
wallArr = []        # 선택된 벽
max_val = 0         # 최대 공간

def walls(wall_count, x, y):
    global max_val
    if wall_count == 3 :                                  # 벽 3개 선택 완료 
        c_copyLab = copy.deepcopy(copiedLab)              # 연구실/바이러스 복사
        copyVs = copy.deepcopy(vs)
        for i in range(len(copyVs)):                      # 바이러스 퍼트리기
            [virusX, virusY] = copyVs[i]
            virus(virusX, virusY, c_copyLab)

        safe = sum(_.count(0) for _ in c_copyLab)        # 안전 지역
        max_val = max(max_val, safe)
        return 
    else:
        for i in range(x, N):
            if i == x:
                k = y
            else:
                k = 0
            for j in range(k, M):
                if(lab[i][j] == 0 and copiedLab[i][j] == 0):
                    copiedLab[i][j] = 1
                    walls(wall_count+1, i, j+1)
                    copiedLab[i][j] = 0

def virus(x,y, cLab):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if (0<=nx<N and 0<=ny<M):
            if cLab[nx][ny] == 0:
                cLab[nx][ny] = 2
                virus(nx, ny, cLab)

vs = []
for i in range(N):
    for j in range(M):
        if(lab[i][j] == 2):
            vs.append((i,j))
walls(0,0,0)
print(max_val)
