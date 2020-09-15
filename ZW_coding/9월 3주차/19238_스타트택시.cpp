#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int map[21][21];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct passenger {
    int cy, cx, ty, tx, pn;
    bool flag;
};
struct taxi {
    int y, x, fuel;
};
passenger p[20*20];
taxi t;
bool operator<(passenger a, passenger b) {
    return a.cy == b.cy ? a.cx > b.cx : a.cy > b.cy;
}
int n, m;
int exists(int y, int x) {
    for(int i = 0; i < m; i++)
        if(p[i].flag && p[i].cy == y && p[i].cx == x)
            return i;
    return -1;
}
int findP() {
    bool v[21][21] = {false, };
    queue<taxi> q;
    int pas = exists(t.y, t.x);
    if(pas != -1)
        return pas;
    v[t.y][t.x] = true;
    q.push(t);
    priority_queue<passenger> pq;
    while(!q.empty() && pq.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            taxi cur = q.front();
            q.pop();
            for(int j = 0; j < 4; ++j) {
                int nx = cur.x + dx[j];
                int ny = cur.y + dy[j];
                if(1<=nx && nx <= n && 1 <=ny && ny <= n && !map[ny][nx] && !v[ny][nx] && cur.fuel) {
                    q.push(taxi{.y = ny, .x = nx, .fuel = cur.fuel - 1});
                    v[ny][nx] = true;
                    pas = exists(ny, nx);
                    if(pas != -1) {
                        pq.push(p[pas]);
                        t.fuel = cur.fuel - 1;
                    }
                }
            }
        }
    }
    return pq.empty() ? -1 : pq.top().pn;
}

int moveP(int pas) {
   queue<taxi> q;
   bool v[21][21] = {false, };
   q.push(t);
   v[t.y][t.x] = true;
   while(!q.empty()) {
       taxi cur = q.front();
       q.pop();
       for(int i = 0; i < 4; ++i) {
           int nx = cur.x + dx[i];
           int ny = cur.y + dy[i];
           if(1<=nx && nx <= n && 1 <=ny && ny <= n && !map[ny][nx] && !v[ny][nx] && cur.fuel) {
               q.push(taxi{.y = ny, .x = nx, .fuel = cur.fuel - 1});
               v[ny][nx] = true;
               if(ny == p[pas].ty && nx == p[pas].tx) {
                  // printf("cfuel : %d\n",cur.fuel);
                   return t.fuel - cur.fuel + 1;
               }
           }
       }
   }
   printf("-1");
   exit(0);
}

int main() {
   scanf("%d %d %d", &n, &m, &t.fuel);
   for(int i = 1; i <= n; i++)
       for(int j = 1; j <= n; ++j)
           scanf("%d",&map[i][j]);
   scanf("%d %d",&t.y, &t.x);
   for(int i = 0; i < m; ++i) {
       scanf("%d %d %d %d", &p[i].cy, &p[i].cx, &p[i].ty, &p[i].tx);
       p[i].flag = true; p[i].pn = i;
   }
   for(int i = 0; i < m; ++i) {
       int pas = findP();
       if(pas == -1) {
           printf("-1");
           exit(0);
       }
       p[pas].flag = false;
       t.y = p[pas].cy;
       t.x = p[pas].cx;
       t.fuel += moveP(pas);
       t.y = p[pas].ty;
       t.x = p[pas].tx;
   }
   printf("%d",t.fuel);
}
