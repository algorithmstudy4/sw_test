#감시
#https://www.acmicpc.net/workbook/view/1152
import sys
import copy
sys.stdin = open("input.txt","r")
n,m=map(int,input().split())
board=[list(map(int,input().split())) for _ in range(n)]
cctv=[]
direction=[4,2,4,4,1]
ccsize=0
sol=1e9
for i in range(n):
    for j in range(m):
        if 1<=board[i][j]<=5: 
            cctv.append((i,j,board[i][j]-1))
            ccsize+=1

def update(dir,idx):
    dir=dir%4 
    curh=cctv[idx][0]
    curw=cctv[idx][1]
    if dir==0: 
        for w in range(curw+1,m):
            if board[curh][w]==6:
                break
            board[curh][w]=-1
    elif dir==1: 
        for h in range(curh-1,-1, -1):
            if board[h][curw] == 6:
                break
            board[h][curw]= -1
    elif dir==2: 
        for w in range(curw-1,-1,-1):
            if board[curh][w]==6:
                break
            board[curh][w]=-1
    elif dir == 3: 
        for h in range(curh+1,n):
            if board[h][curw] == 6:
                break
            board[h][curw]= -1



def dfs(idx):
    global sol,board
    if idx==ccsize:
        cnt=0
        for i in range(n):
            for j in range(m):
                if board[i][j]==0: 
                    cnt+=1
        return
    else:
        type=cctv[idx][2]

        for dir in range(direction[type]):
            
            tmp=copy.deepcopy(board)

            #update
            if type==0: 
                update(dir,idx)
            elif type==1:
                update(dir, idx)
                update(dir+2,idx)
            elif type==2:
                update(dir,idx)
                update(dir + 1, idx)
            elif type==3:
                update(dir, idx)
                update(dir + 1,idx)
                update(dir + 2,idx)
            elif type==4:
                update(dir, idx)
                update(dir + 1, idx)
                update(dir + 2, idx)
                update(dir + 3, idx)

            dfs(idx+1)

            board=copy.deepcopy(tmp)
dfs(0)
print(sol)
