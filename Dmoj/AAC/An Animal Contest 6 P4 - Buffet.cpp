#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 5e5+5;

int n,a[MAXN],freq[MAXN];

ll ans,s;




bool can(ll x){
    //check the interval

    ll lo = x*s,hi = (x+1)*s,cnt = 0;

    fill(freq,freq+n+1,0);

    //checking last complete range freq for extras

    for(int i = 1; i <= n; i++){
        if(a[i] <= hi) cnt += (hi-a[i])/s;
        if(cnt > lo){
            ans = lo;
            return true;
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(a[i] <= hi) freq[a[i]%s]++;
    }


    //checking extras

    for(int i = 1; i <= n; i++){
        cnt += freq[i];

        if(cnt > x*s+i){
            ans = x*s+i;
            return true;
        }
    }

    return false;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1,a+n+1);

    if(s>=n){
        for(int i = 1; i <= n; i++){
            if(a[i] < i){
                cout << a[i] << "\n";
                return 0;
            }
        }

        cout << "INF\n";
        return 0; 
    }

    //obviously wont pass

    ll lo = 0, hi = 1e10,mid;
    

    while(lo <= hi){
        mid = (lo+hi)>>1;

        if(can(mid)) hi = mid-1;
        else lo = mid+1;
        
    }



    cout << ans << "\n";
    




}