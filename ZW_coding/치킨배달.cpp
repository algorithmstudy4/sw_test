#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int map[50][50];

int ans = 100000;
int n, m;

vector<pair<int,int>> chick;
vector<pair<int, int>> home;

void go(){
    vector<int> permu;
    for(int i = 0; i < chick.size(); i++){
        if(i < m)
            permu.push_back(1);
        else permu.push_back(0);
    }
    do{

        int sumna = 0;
        for(int i = 0; i < home.size(); i++){
            int s = 10000;
            for(int j = 0; j < chick.size(); j++){
                if(permu[j] == 1){
                    int temp = abs(home[i].first - chick[j].first) + abs(home[i].second - chick[j].second);
                   s = s >  temp ? temp : s;
                }
            }
            sumna += s;
        }
        ans = ans < sumna ? ans:sumna;
    }while(prev_permutation(permu.begin(), permu.end()));

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int chicken  =0;
    cin>> n>> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>map[i][j];
            if(map[i][j] == 2){
                chick.push_back(make_pair(i,j));
            }
            if(map[i][j] == 1){
                home.push_back(make_pair(i,j));
            }
        }
    }
    go();
    cout<<ans<<endl;
    return 0;



}
