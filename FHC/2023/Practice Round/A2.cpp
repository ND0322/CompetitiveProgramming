#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long a,b,c;


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> a >> b >> c;

        long long ans = 0;

        long long tmp = c;

        ans = max(ans, min((tmp / b) * 2 - 1, (tmp / b) * 2));

        //cout << min((tmp / b) * 2 - 1, (tmp / b) * 2) << "\n";

        if(c - a >= 0){

            tmp = c - a;

            ans = max(ans, min((tmp / b) * 2 + 2 - 1, (tmp / b) * 2 + 1));

            //cout << min((tmp / b) * 2 + 2 - 1, (tmp / b) * 2 + 1) << "\n";
        }

        
        if(c - 2*a >= 0){

        
            tmp = c - 2*a;

            ans = max(ans, min((tmp / b) * 2 + 4 - 1, (tmp / b) * 2 + 2));

            //cout << min((tmp / b) * 2 + 4 - 1, (tmp / b) * 2 + 2) << "\n";

        }


        tmp = c - (c/a) * a;

        ans = max(ans, min((tmp / b) * 2 + 2 * c/a - 1, (tmp / b) * 2 + c/a));

        //cout << min((tmp / b) * 2 + 2 * c/a - 1, (tmp / b) * 2 + c/a) << "\n";

        
        cout << "Case #" << _ << ": " << ans << "\n";
    }
}