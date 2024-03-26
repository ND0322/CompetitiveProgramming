#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n,k;

string s;


bool can(int x, char one){
    vector<int> a,psa(1);

    int ans = 2e9;

    for(int i = 0; i <n ; i++){
        if(s[i] == one){
            a.push_back(i);
            //cout << 1 << "\n";
        }
    }

    int m = a.size();

    for(int i = 0; i < m; i++) psa.push_back(psa[i] + a[i]);

    for (int i = 0; i < m - x + 1; i++) ans = min(ans, psa[i + x] - psa[x / 2 + i] - psa[(x + 1) / 2 + i] + psa[i]);
       
    //cout<< ans << "\n";
    ans -= (x / 2) * ((x + 1) / 2);

    //cout << x << " " << ans << "\n";
    return ans <= k;







}

int main(){
    cin >> n >> k;

    cin >> s;

    int lo = (count(s.begin(),s.end(),'1') >= 1);
    int hi = count(s.begin(),s.end(),'1');
    int ans = -1;

    while(lo <= hi){
        int mid = (lo+hi)/2;

        if(can(mid,'1')){
            lo = mid+1;
            ans = mid;
        }
        else{
            hi = mid-1;
        }
    }

    cout << ans << " ";

    lo = (count(s.begin(),s.end(),'0') >= 1);
    hi = count(s.begin(),s.end(),'0');
    ans = -1;

    while(lo <= hi){
        int mid = (lo+hi)/2;

        if(can(mid,'0')){
            lo = mid+1;
            ans = mid;
        }
        else{
            hi = mid-1;
        }
    }

    cout << ans << "\n";


}