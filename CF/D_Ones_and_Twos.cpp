#include <bits/stdc++.h>    
#include <iostream>
#include <set>


using namespace std;


int n, q;



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        set<int> ones;

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];

            if(a[i] == 1) ones.insert(i);
        }

        while(q--){
            int t; cin >> t;

            if (t == 1){
                int x; cin >> x;
                int sz = ones.size();
                if ((x-sz) & 1) {
                    if (!sz){
                        cout << "NO\n";
                        continue;
                    }

                    //cout << x << "\n";

                    
                    int opt1 = 2 * (n-*ones.begin() -1)  - (sz - 1);
                    int opt2 = 2* *ones.rbegin() - (sz-1);
                   

                    cout << (x <= max(opt1,opt2 ) ? "YES\n" : "NO\n");
                    
                        
                    
                }
                else cout << (x <= 2*n - sz ? "YES\n" : "NO\n");
            } 
            else{
                int x; cin >> x;

                x--;
                ones.erase(x);
                cin >> a[x];

                if(a[x] == 1) ones.insert(x);


            }
        }


    }
}