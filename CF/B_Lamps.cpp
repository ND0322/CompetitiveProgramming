#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool cmp(const pii& a,
                const pii& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}

typedef pair<int,int> pii;

bool cmp(int x,int y){

}

void solve(){
    int n; cin >> n;

    vector<pii> vals;

    

    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        vals.push_back({a,b});
    }

    sort(vals.begin(),vals.end(),cmp);

    


}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}