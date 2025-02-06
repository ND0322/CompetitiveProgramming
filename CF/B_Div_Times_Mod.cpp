#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;

int main(){
    int n,k; cin >> n >> k;

    set<int> divs; 

    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            divs.insert(i);
            divs.insert(n % i);
        }
    }

    int ans = 1e9;
    for(int i : divs){
        for(int j = 0; j < k; j++){}
    }

    
}