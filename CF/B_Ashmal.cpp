#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
greedy
compares happen in o(n)
so n^2
*/

int main(){
    int tt; cin >> tt;

    while(tt--){

        int n; cin >> n;

        string s;

        for(int i = 0; i < n; i++){
            string t; cin >> t;

            string a = t + s;
            string b = s + t;

            bool flag = 0;
            for(int j = 0; j < a.size(); j++){
                if(a[j] != b[j]){
                    if(a[j] < b[j]) flag = 1;
                    else flag = 0;
                    break;
                }
            }

            if(flag) s = a;
            else s = b;
        }

        cout << s << "\n";
    }
}