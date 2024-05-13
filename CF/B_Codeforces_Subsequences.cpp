#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int cnt[10];
char c[10];

#define int long long

int32_t main(){
    int n; cin >> n;

    c[0] = 'c';
    c[1] = 'o';
    c[2] = 'd';
    c[3] = 'e';
    c[4] = 'f';
    c[5] = 'o';
    c[6] = 'r';
    c[7] = 'c';
    c[8] = 'e';
    c[9] = 's';

    int i = 1;

    int j= 1;
    while(i < n){
        j++;
        i = pow(j, 10);
    }

    i = 10;
    //i is the number of j-1
    for(; i >= 0; i--){
        if((long long)pow(j-1, i) * (long long)pow(j, 10-i) >= n){;
            for(int k = 0; k < i; k++) cnt[k] = j-1;
            for(int k = i; k < 10; k++) cnt[k] = j;
            break;
        }
    }

    reverse(cnt,cnt+10);


    for(int i = 0; i < 10; i++){
        for(int j = 0; j < cnt[i]; j++) cout << c[i];
    }


}
