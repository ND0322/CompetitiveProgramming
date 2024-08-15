#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n);

        int mn = 1e9;
        int mx = 0;
        set<int> s,b;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] %= 2*k;
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);

            s.insert(a[i]);   
            b.insert((a[i] + k) % (2*k));
        }

        //4 and 8
        //turn on at 0 4 8

        int ans = 1;

       for(int i = 0; i < n; i++) cout << a[i] << " ";
       cout << "\n";

        //if any (a[i] + k) % 2k < a[j] or greater than a[j]+k

        bool flag = 1;

        for(int i = 0; i < n; i++){
            if(s.lower_bound((a[i] + k) % (2*k)+1) != s.end()){
                cout <<a[i] << " " << *s.lower_bound((a[i] + k) % (2*k)+1) << "\n";
                if(*s.lower_bound((a[i] + k) % (2*k)+1) + k < (a[i] + k) % (2*k)) flag = 0;
            }
        }

        if(!flag){
            cout << "-1\n";
            continue;
        }








       

    }
}