#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

bool a[MAXN][2];

/*
kinda caseworky
if current column is 0 1 we continue and add 2
if current column is 0 0 and next is 1 1 or vice versa we want to take it
otherwise we for 0 0 just continue and add 1 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            char c; cin >> c;
            a[i][0] = c - '0';
        }

        for(int i = 1; i <= n; i++){
            char c; cin >> c;
            a[i][1] = c - '0';
        }

        int i = 1;
        int cnt = 0;

        while(i <= n){
            if(a[i][0] + a[i][1] == 1){
                cnt+=2;
                i++;
                continue;
            }

            if(i == n){
                cnt += !(a[i][0] + a[i][1]);
                break;
            }

            if((a[i][0] + a[i][1] == 0 && a[i+1][0] + a[i+1][1] == 2) || (a[i][0] + a[i][1] == 2 && a[i+1][0] + a[i+1][1] == 0)){
                cnt += 2;
                i += 2;
                continue;
            }

            cnt += !(a[i][0] + a[i][1]);
            i++;
        }

        cout << cnt << "\n";


    }
}