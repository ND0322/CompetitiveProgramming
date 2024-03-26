#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;


    double ans = 0;
    double acc;
    int last; cin >> last >> acc;

   

    for(int i = 0; i < n-1; i++){
        int d,a; cin >> d >> a;

        ans += (double)(last - d)/ acc;

        last = d;
        

        acc = max(acc,(double) a);

        
    }

    ans += last/acc;

    cout << setprecision(6) << fixed << ans << "\n";
    
}