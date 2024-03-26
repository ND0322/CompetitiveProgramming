#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 1e4+5;



int n, m, cnt[20];

bool out[25];

queue<int> votes[MAXN];

unordered_map<string, int> id;
string iton[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        id[s] = i;
        iton[i] = s;
    }

    for(int i = 0; i < m; i++){
        int x; cin >> x;

        for(int j = 0; j < x; j++){
            string s; cin >> s;

            votes[i].push(id[s]);

            if(!j) cnt[id[s]]++;
            
        }
    }

    for(int i = 1; i < n; i++){
        int small = 1e9;

        for(int j = 0; j < n; j++){
            if(out[j]) continue;
            small = min(small, cnt[j]);
             if(cnt[j] >= (m+1)/2){
                cout << iton[j] << endl;
                return 0;
            }
        }

        int ind = -1;

        for(int j = 0; j < n; j++){
            if(out[j]) continue;
            if(cnt[j] == small){
                ind = j;
                break;
            }
        }

        out[ind] = 1;

        for(int j = 0; j < m; j++){
            if(votes[j].size() && votes[j].front() == ind){
                votes[j].pop();
                while(votes[j].size() && out[votes[j].front()]) votes[j].pop();

                if(votes[j].size()) cnt[votes[j].front()]++;
            }
        }

        //for(int i = 0; i < n; i++) cout << cnt[i] << " ";
        //cout << "\n";
        //for(int i = 0; i < n; i++) cout << out[i] << " ";
        //cout << "\n";
    }

    int ans = -1;

    for(int i = 0; i < n; i++){
        if(!out[i]){
            ans = i;
            break;
        }
    }

    cout << iton[ans] << "\n";
}



