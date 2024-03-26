#include <bits/stdc++.h>   
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n);
    
    for(int i = 1; i <= n; i++) cin >> a[i-1];

    sort(a.begin(), a.end());

    //or(int i = 0; i < n; i++) cout << a[i] << " ";
    //cout << "\n";

    //oops

    if(n&1){
        for(int i = 1; i <= n; i++){
            int x = a[i-1];

            if(i == n/2+1){
                cout << x << "\n";
                break;
            }
        }
    }
    else{
        int last = 0;
        for(int i = 1; i <= n; i++){
            int x = a[i-1];
            if(i == n/2+1){
                cout << ceil((last+x)/2.0);
                break;
            }

            last = x;
        }
    }
}