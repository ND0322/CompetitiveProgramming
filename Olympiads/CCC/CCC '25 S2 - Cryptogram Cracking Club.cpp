#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
int n, a[MAXN];

char c[MAXN];

string s;
int main(){
    cin >> s;

    s = "." + s;


    
    n = s.size() / 2;

    long long sm = 0;

    for(int i = 1; i < s.size(); i+=2){
        c[i] = s[i];
        a[i] = s[i+1] - '0';

        sm += a[i];
    }

    long long k; cin >> k;

    k %= sm;





    for(int i = 1; i <= n; i++){
        if(k - a[i] <= 0){
            cout << c[i];
            return 0;
        }

        k -= a[i];
    }




    


}