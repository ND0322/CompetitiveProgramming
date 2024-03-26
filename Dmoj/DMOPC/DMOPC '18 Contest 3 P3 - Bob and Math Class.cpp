#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, psa[MAXN];

string s;

int main(){
    cin >> n;

    long long ans=  0;
    cin >> s;

    for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + (s[i-1] == 'T');

    for(int i = 1; i <= n; i++){
        int lo = 1;
        int hi = i;

        int res = -1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(psa[i] - psa[mid-1] == (i-mid+1) || !(psa[i] - psa[mid-1])){
                res = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        if(res-i)
    }
}