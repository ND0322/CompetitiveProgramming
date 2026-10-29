#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 55;

int n, a[MAXN], b[MAXN];
int main(){
   
    cin >> n;

    int s1 = 0;
    int s2 = 0;
    int c1 = 0;
    int c2 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s1 += a[i];
        c1+= a[i] & 1;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        s2 += b[i];
        c2 += b[i] & 1;
    }

    if(s1 != s2){
        cout << "NO\n";
        return 0;
    }

    if(c1 != c2){
        cout << "NO\n";
        return 0;
    }

    
    if(!c1){
        bool flag = 1;
        for(int i = 1; i <= n; i++) flag &= a[i] == b[i];
        if(!flag){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    
    
}