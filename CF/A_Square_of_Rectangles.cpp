#include <bits/stdc++.h>
#include <iostream>

using namespace std;




int main(){
    int tt; cin >> tt;

    while(tt--){
        int x1,y1,x2,y2,x3,y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        int a = x1 * y1 + x2 * y2 + x3 * y3;

        int s = sqrt(a);

        if(s * s != a){
            cout << "NO\n";
            continue;
        }

        bool flag = 0;

        //try placing on the right

        if(x1 + x2 == s){
            if(x2 == x3 && y2 + y3 == y1 && y1 == s) flag = 1;
        }


        if(y1 == y2 && y2 == y3){
            if(x1 + x2 + x3 == s) flag = 1;
        }

        if(y1 + y2 == s){
            if(y2 == y3 && x2 + x3 == x1 && x1 == s) flag = 1;
        }


        if(x1 == x2 && x2 == x3){
            if(y1 + y2 + y3 == s) flag = 1;
        }

        cout << (flag ? "YES\n" : "NO\n");


        





       

        

        


    }
}