#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, k, r;

bool has[MAXN];

int main(){
    cin >> n >> k >> r;

    for(int i = 0; i < k; i++){
        int x; cin >> x;

        has[x-1] = 1;
    }

    int ans = 0;
    int cnt = 0;


    for(int i = 0; i < r; i++){
        cnt += has[i];
    }

    
    

    for(int i = r; i <= n; i++){
      
        //cout << i << " " << cnt << "\n";
        if(cnt == 1){
            if(has[i-1]) has[i-2]=1;
            else has[i-1] = 1;
            ans++;
            cnt++;
        }

        if(!cnt){
            has[i-1] = 1;
            has[i-2] = 1;
            ans+=2;
            cnt+=2;
        }

        cnt -= has[i-r];
        cnt+=has[i];
        
    }

    cout << ans << "\n";
}