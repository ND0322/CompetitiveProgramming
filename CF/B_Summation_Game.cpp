#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;


    while(tt--){
        int n,x,y; cin >> n >> x >> y;

        //cout << n << " " << x << " " << y << "\n";

        //removing the largest element has the cost of -next largest + 0
        //vs not removing it has the cost of -largest + next largest

        //b will always multiply the y largest numbers only once
        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin()+1, a.end());
        reverse(a.begin()+1, a.end());

        vector<int> psa(n+1);

        //for(int i = 1; i <= n; i++) cout << a[i] << " ";
        //cout << "\n";

        for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i];
            
        
    
        int ans = 0;


        for(int i = 1; i <= n; i++){
            if(i <= y) ans -= a[i];
            else ans += a[i];
            //cout << a[i] << "\n";
        }

        //cout << ans << "\n";
    

        //remove only first -> remove first and second just push the y stuff forward one
        for(int i = 1; i <= x; i++){
            ans = max(ans, -(psa[min(i+y,n)]-psa[i]) + psa[n] - psa[min(i+y,n)]);
            //cout << -(psa[min(i+y,n)]-psa[i]) << " " << psa[n] - psa[min(i+y,n)] << "\n";
        }

        cout << ans << "\n";



        

        

    }
}