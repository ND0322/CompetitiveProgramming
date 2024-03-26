#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 105;

int n,m, a[MAXN], scores[MAXN];

bool solved[MAXN][MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        for(int j = 0; j < m ; j++){
            if(s[j] == 'o'){
                scores[i] += a[j];
                solved[i][j] = true;
            }
        }

        scores[i] += i+1;
    }

    int best = 0;

    for(int i = 0; i < n; i++){
        best = max(best, scores[i]);
    }

    for(int i = 0; i < n; i++){
        vector<int> temp;

        for(int j = 0; j < m; j++){
            if(!solved[i][j]) temp.push_back(a[j]);
        }

        sort(temp.begin(), temp.end());

        reverse(temp.begin(), temp.end());

        int cnt = 0;

        while(scores[i] < best){
            scores[i] += temp[cnt];
            cnt++;
        }

        cout << cnt << "\n";

        
        

    }




}