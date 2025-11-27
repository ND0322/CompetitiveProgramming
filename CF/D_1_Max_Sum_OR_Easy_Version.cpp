#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//we match 0 and 1
//odd case too


//go bit by bit 

/*
split previous that has 1 into having 1 and not having 1

we should try to match a 1 1 with a 0 0
or a 1 0 with a 0 1


select mins in case of tie 

*/

int ans[200005],l,r;

int msb(int x){
    return 31 - __builtin_clz(x);
}


vector<int> dac(vector<int> b, vector<int> a, int d){

    if(a.size() )

    vector<int> aa[2] = {{}, {}};
    vector<int> bb[2] = {{}, {}};

    for(int i : a) aa[(i >> d) & 1].push_back(i);
    for(int i : b) bb[(i>>d) & 1].push_back(i);

    //go increasing bit
    //aa[0] match bb[1]
    //aa[1] match bb[0]
    //then aa[0] to aa[1]
    //aa[1] to bb[0]
    //finally aa[0] to bb[0]
    //bb[0] to aa[1]




    
}



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> l >> r;
        



        vector<int> a,b;

        for(int i = l; i <= r; i++){
            a.push_back(i);
            b.push_back(i);
        }

        dac(b,a,0);

        for(int i = l; i <= r; i++) cout << ans[i] << " ";
        cout << "\n";


        
        
    }
}