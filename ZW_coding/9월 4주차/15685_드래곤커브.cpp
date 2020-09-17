#include<cstdio>
#include<vector>
using namespace std;
int n;
struct dragon {
    int x, y, dir, g;
    dragon(int x, int y, int dir, int g) {
        this->x = x;
        this->y = y;
        this->dir = dir;
        this->g = g;
    }
};
vector<dragon> dr;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
bool d[101][101];

//앞부분
void make_dragon(dragon drr, int cnt, vector<int> dr) {
    if (cnt == drr.g + 1) {
        return;
    }
    int x = drr.x; int y = drr.y;
    for (int i = dr.size() / 2; i < dr.size(); i++) {
        x += dx[dr[i]]; y += dy[dr[i]];
        if (x > 100 || y > 100 || x < 0 || y < 0) return;
        d[x][y] = true;
    }
    int s = 1 << drr.g;
    vector<int> td;
    for (int i = dr.size() - 1; i >= 0; i--) {
        int nd = dr[i];
        nd++;
        if (nd > 3) nd = 0;
        dr.push_back(nd);
    }

    drr.x = x; drr.y = y;
    make_dragon(drr, cnt + 1, dr);
}
void solve(){
    for (int i = 0; i < dr.size(); i++) {
        vector<int> s;
        s.push_back(dr[i].dir);
        make_dragon(dr[i], 0, s);
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (d[i][j] == true) {
                if (d[i + 1][j] && d[i][j + 1] && d[i + 1][j + 1]) {
                    ans++;
                }
            }
        }
    }
    printf("%d", ans);
}
void input(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y, dir, g;
        scanf("%d %d %d %d", &x, &y, &dir, &g);
        d[y][x] = true;
        dr.push_back(dragon(y, x, dir, g));
    }
}
int main() {
    input();
    solve();
    return 0;
}
