#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//build incrementally
//for some current string s we can guess 0 and 1 on the right
//if both increase it doesnt matter just choose 0
//if only one increases obviously choose that one
//if neither increase we need to flip to left

bool query(string s){
    cout << "? " << s << "\n";
    bool x; cin >> x;
    return x;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;


        string s = "";

        while(s.size() < n){
            bool a = query(s + '0');

            if(a){
                s += '0';
                continue;
            } 
            bool b = query(s + '1');

            if(!a && !b) break;

            s += '1';
        }

        while(s.size() < n){
            bool a = query('0' + s);

            if(a){
                s = '0' + s;
                continue;
            }

            s = '1' + s;
        }

        cout << "! " << s << "\n";

    }

    /*
    8
    10101110

    1100
    */
}