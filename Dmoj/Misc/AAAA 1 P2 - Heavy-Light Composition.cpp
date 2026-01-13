#include <bits/stdc++.h>
#include <iostream>

using namespace std; 

/*
at the end caps we just find the left most and right most people - leftmost and rightmost ligths

then we are left with a lot of n = 2
iterate over b and try prefix and suffix 
*/

int main(){
    int n, m; cin >> n >> m;

    vector<int> b(m+1);
    set<int> s;

    vector<int> a(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i =1 ; i <= m; i++){
        cin >> b[i];
        s.insert(b[i]);
    }

    

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());


    if(n == 1){
        int ans = 0;
        if(b[1] < a[1]) ans += a[1] - b[1]; 
        
        if(b[m] > a[1]) ans += b[m] - a[1];


        cout << ans << "\n";
        return 0;
    }

    int ans = 0;

    for(int i = 1; i < n; i++){
        vector<int> c;

        auto it = s.lower_bound(a[i]);

        while(it != s.end() && *it <= a[i+1]){
            c.push_back(*it);
            it++;
        }

        if(!c.size()) continue;

        int mn = a[i+1] - c[0];

        for(int j = 0; j < c.size()-1; j++) mn = min(mn, c[j] - a[i] + a[i+1] - c[j+1]);
        mn = min(mn, c[c.size()-1] - a[i]);

        ans += mn;


    }

    if(b[1] < a[1]) ans += a[1] - b[1];
    if(b[m] > a[n]) ans += b[m] - a[n];

    cout << ans << "\n";


}