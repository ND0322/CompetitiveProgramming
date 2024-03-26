#include <bits/stdc++.h>
#include <iostream>


using namespace std;





int main(){

    int tt; cin >> tt;

    while(tt--){
        int px,py,ax,ay,bx,by;
        cin >> px >> py >> ax >> ay >> bx >> by;

        double ab = sqrt((ax-bx)*(ax-bx) + (ay-by) * (ay-by));
        double ao = sqrt(ax*ax + ay*ay);
        double bo = sqrt(bx*bx + by*by);
        double ap = sqrt((ax-px)*(ax-px) + (ay-py)*(ay-py));
        double bp = sqrt((bx-px)*(bx-px) + (by-py)*(by-py));

        

        cout << setprecision(10) << fixed << min({max(ao,ap),max(bp,bo),max({ab/2,ap,bo}),max({ab/2,bp,ao})}) << "\n";

        

        


    }

    
}