#include <bits/stdc++.h>
#include <iostream>
#include <map>



using namespace std;

const int MAXN = 1e5+5;

typedef long long ll;

int n;

map<ll,ll> m;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        ll s,c; cin >> s >> c;

        m[s] += c;
    }

    ll ans = 0;


    map<ll,ll>::iterator it = m.begin();

    while(it != m.end()){
        if((*it).second-1) m[2*(*it).first] += (*it).second/2;
        if((*it).second & 1) ans++;

        it++;
    }
    

  

    cout << ans << "\n";
}

