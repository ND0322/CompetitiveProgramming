#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//compl counting with PIE

#define int long long

int l,r;

int f(int x){
    int a = (l%x ? (l + x-l%x) : l);
    int b = (r%x ? (r - r%x) : r);
    return (b-a)/x+1;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> l >> r;

        vector<int> nums = {2,3,5,7};

        long long ans = 0;

        for(int i : nums) ans += f(i);
        for(int i = 0; i < 4; i++){
            for(int j=i+1; j < 4;j ++) ans -= f(nums[i] * nums[j]);
        }

        for(int i = 0; i < 4; i++){
            for(int j = i+1; j < 4; j++){
                for(int k = j+1; k < 4; k++) ans += f(nums[i] * nums[j] * nums[k]);
            }
        }

        ans -= f(2*3*5*7);

        cout << r - l + 1 - ans << "\n";


    }
}