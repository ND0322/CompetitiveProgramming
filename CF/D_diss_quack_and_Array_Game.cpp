#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int msb(int x){
    return 31 - __builtin_clz(x);
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        int ans1 = 0;
        int ans2 = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];

            for(int j = 0; j < msb(a[i]); j++){
                if(a[i] & (1<<j)){
                  
                    if((1<<j) + __builtin_popcount(a[i] + (1<<j)) + msb(a[i] + (1<<j)) < __builtin_popcount(a[i]) + msb(a[i])){
                        a[i] += (1<<j);
                        ans1 += (1<<j);
                        ans2 += (1<<j);
                    }
                }
            }

        }


        vector<int> b(n+1);

        for(int i = 1; i <= n ;i++) b[i] = a[i];
        while(1){
            bool flag = 1;

            for(int i =1 ; i <= n; i++) flag &= !(b[i] % 2);
            if(!flag) break;
            for(int i = 1; i <= n; i++) b[i] >>=1;
            ans1++;
        }

        for(int i = 1; i <= n; i++) ans1 += msb(b[i]) + __builtin_popcount(b[i]);

        for(int i = 1; i <= n; i++){
            if(a[i] & 1){
                ans2++;
                a[i]++;
            }
        }

        while(1){
            bool flag = 1;

            for(int i =1 ; i <= n; i++) flag &= !(a[i] % 2);
            if(!flag) break;
            for(int i = 1; i <= n; i++) a[i] >>=1;
            ans2++;
        }

        for(int i = 1; i <= n ;i++) ans2 += msb(a[i]) + __builtin_popcount(a[i]);

        cout << min(ans1, ans2) << "\n";







        

        




        
    }
}