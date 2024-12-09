#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int n,t; 

vector<int> pos;

vector<int> house;

//bsearch on k 

bool can(int x){
    int h = 0;
    int s = 0;

    int i = 0;
    int cnt = 1;

    while(i < n){

        if(pos[s] == i){
            x++;
            s++;
        }

        if(house[h] == i){
            if(x) x--;
            else{
                if(s < pos.size()){
                    cnt += 2 * (pos[s] - i) - 1;
                    s++;
                }
                else cnt = 1e18;
            }

            h++;
        }

        if(h == house.size()) break;

        i++;
        cnt++;
    }

    cout << cnt << "\n";
    
    return cnt <= t;
}
int32_t main(){
    cin >> n >> t;

    string s; cin >> s;

    

    for(int i = 0; i < n; i++){
        if(s[i] == 'H') house.push_back(i);

        if(s[i] == 'S') pos.push_back(i);
    }


    cout << can(0) << "\n";


    /*
    int lo = 0;
    int hi = 5e5;

    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }

    cout << ans << "\n";
    */
    
    

    
    



}