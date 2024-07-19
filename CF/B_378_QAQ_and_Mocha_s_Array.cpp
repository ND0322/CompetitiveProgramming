#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//if theres a 1 yes

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int b = a[0];

        int c = n;
        for(int i : a){
            if(i % b){
                c = i;
                break;
            }
        }

        bool flag = 1;

        for(int i : a){
            if(!(i % b == 0 || i % c == 0)) flag = 0;
        }

        cout << (flag ? "Yes\n" : "No\n");
    }

}