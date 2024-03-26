#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n;

vector<pair<pair<int,int>,string>> v;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        int p; cin >> p;

        int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;

        v.push_back({{p*10 + a+b+c+d+e+f - min({a,b,c,d,e,f}) - max({a,b,c,d,e,f}), -i}, s});
    }

    sort(v.rbegin(), v.rend());

    int cnt = 0;
    int last = -1;
    int a[3] = {0,0,0};

    for(int i = 0; i < n; i++){
        if(v[i].first.first != last){
            cnt++;
            last = v[i].first.first;
        }

        if(cnt == 2 && a[0] > 2) break;
        if(cnt == 3 && a[0] + a[1] > 2) break;

      
        if(cnt == 3) break;

        cout << v[i].second << " " << v[i].first.first << "\n";
        a[cnt-1]++;
        
    }
}