#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        int va = 0;
        int vb = 0;
        
        int bf[2] = {0,0};

        for(int i = 1; i <= n; i++){
            if(a[i] == b[i] && a[i]){
                bf[a[i] > 0]++;
                continue;
            }

            if(a[i] == 1) va++;
            if(b[i] == 1) vb++;
        }

        //cout << va << " " << vb << " " << bf[0] << " " << bf[1] << "\n";

        
        while(bf[1]--){
            if(va < vb) va++;
            else vb++;
        }

        while(bf[0]--){
            if(va > vb) va--;
            else vb--;
        }
        
    

        cout << min(va,vb) << "\n";

    }
}