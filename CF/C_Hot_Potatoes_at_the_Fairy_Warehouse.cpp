#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
if color a controls a run of even length by the k-1 round, then it gains two score 
By control it means that furthest clockwise head is color a
odd length gains by 1
count runs

run ending at color x will be a contribution of -1 +1 x and y respective
counting across cycle is a bitch
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> a(2*n+1);

        bool flag = 1;
        for(int i = 1; i <= 2*n; i++){
            char c; cin >> c;

            a[i] = c - '0';
            flag &= a[i];
        }


        int cnt[2] = {0,0};

        for(int i = 1; i <= 2*n; i++){
            if(a[i]) cnt[i&1]++;
        }


        if(flag){
            cout << cnt[0] << " " << cnt[1] << "\n";
            continue;
        }


        int pos = 0;
    
        for(int i = 1; i <= 2*n; i++){
            if(a[i]){
                pos = i;
                break;
            }
        }
        

        //cnt[0] is number eliminated by odd

        for(int i = pos; i <= 2*n; i++){

            if(i == 2 * n && a[i] && a[1]) break;
            if(a[i] && (i == 2 * n || !a[i+1])){
                //cout << i << "\n";
                cnt[i&1]--;
                cnt[!(i&1)]++;
            }
        }

        cout << cnt[0] << " " << cnt[1] << "\n";
    }
}