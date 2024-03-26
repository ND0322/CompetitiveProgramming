#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 1e6+5;
bool nums[MAXN];

int main(){
   
    int i = 2;

    while(i + i * i  + 1 <= 1e6){
        int j = i*i;
        int last = i + i*i + 1;

        nums[last] = true;

        while(last +  j * i <= 1e6){
            last += j * i;
            j *= i;

            nums[last] = true;
        }

        i++;
    }


    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        cout << (nums[n] ? "YES\n" : "NO\n");
    }

}