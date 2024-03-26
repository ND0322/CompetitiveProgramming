#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n;

string a,b;


int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    cin >> n;


    cin >> a >> b;


    int i = 0; 

    int ans = 0;
    while(i < n){
        if(a[i] != b[i]){
            ans++;
            while(i < n && a[i] != b[i]) i++;
        }
        else i++;
    }
    cout << ans << "\n";
}