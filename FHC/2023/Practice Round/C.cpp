#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;

    
        long long sm = 0;
        vector<int> a;
        for(int i = 0; i < 2*n-1;i++){
            int x; cin >> x;
            sm += x;
            a.push_back(x);
        }

        if(n == 1){
            cout << "Case #" << _ << ": " << 1 << "\n";
            continue;
        }

        sort(a.begin(),a.end());
        vector<int> b = a;
        vector<int> c = a;
        long long avg = a.front() + a.back();

        long long ans = avg*n - sm;
        if(!ans) ans = 1e16;
        a.push_back(avg * n - sm);

        sort(a.begin(),a.end());

        bool flag = 1;
        for(int i = 0; i < n; i++) flag &= (a[i] + a[2*n-i-1] == avg);

        if(!flag) ans = 1e16;

        avg = b[1] + b.back();

        long long ans2 = avg * n - sm;
        if(!ans2) ans2 = 1e16;
        b.push_back(avg * n - sm);

        sort(b.begin(),b.end());

        flag = 1;
        for(int i = 0; i < n; i++) flag &= (b[i] + b[2*n-i-1] == avg);

        if(!flag) ans2 = 1e16;

        long long ans3 = 1;

        c.push_back(1);

        sort(c.begin(), c.end());

        avg = c.back() + 1;

        flag = 1;
        for(int i = 0; i < n; i++) flag &= (c[i] + c[2*n-i-1] == avg);


        if(!flag) ans3 = 1e16;

        ans = min({ans, ans2,ans3});

        if(ans == 1e16) ans = -1;



        cout << "Case #" << _ << ": " << ans << "\n";
    }
}