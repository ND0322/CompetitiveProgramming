#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
two pointers

minimum left for borrowing requires that all right of it have >= 1 (can use bsearch if needed)

x x x -1 x x x x x x -1
x x x x  x x x -1 x x x x
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;
        string t; cin >> t;

        vector<int> a(n+1);
        vector<int> b(n+1);

        vector<int> prefa(n+1);
        vector<int> prefb(n+1);

        for(int i =1 ; i <= n; i++){
            a[i] = pow(-1, s[i-1] != '(');
            b[i] = pow(-1, t[i-1] != '(');
        }


        set<pair<int,int>> sa, sb;

        //minimum amount of wiggle room
        //whenever we do a swap the wiggle room goes down 

        int l = 1;

        bool ans = 1;
        for(int i = 1; i <= n; i++){
            prefa[i] = prefa[i-1] + a[i];
            prefb[i] = prefb[i-1] + b[i];

            if(prefa[i] < 0 && prefb[i] < 0){
                ans = 0;
                break;
            }

            if(prefa[i] < 0){
                //need to swap
            }


        }
    }
}