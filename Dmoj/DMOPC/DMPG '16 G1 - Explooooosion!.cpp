#include <bits/stdc++.h>
#include <iostream>
#include <queue> 

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

#define int long long

//note that if the array doesnt contain one
//we can do pure greedy
//for max we can multiply all
//for min add all
//the only difference with 1 is we apply the opposite operation

//focusing on max rn
//we would want to add 1s 

//2 4 6
//base: 48
//apply to 2: 72
//apply to 4: 60
//apply to 6: 56

//we should repeatitly apply to min

//lets say we have 3 1s
//2 3 5
//apply all to 1: 75
//1 to 1 2 to 2: 75
//apply 2 to 1 1 to 2: 80
//(2*3+1) * (5+2) = 49

//that sh is wrong

//min is obvious 

int n, a[MAXN];
//priority_queue<int, vector<int>, greater<int>> pq;

long long pow(int n){
    long long ans = 1;

    for(int i = 0; i < n; i++) ans = (ans*3)%MOD;
    return ans;
}

int32_t main(){
    cin >> n;

    int mn = 0;

    int cnt = 0;
    int cnt2 = 0;


    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) cnt++;
        else mn= (mn+a[i]) % MOD;   
        
    }

    if(cnt == n){
        cout << "1\n";
        if(n < 5) cout << n << "\n";
        else{
            int three = n/3;
            if(n%3 == 0) cout << pow(three)%MOD << "\n";
            if(n%3 == 1) cout << (pow(three-1) * 4)%MOD << "\n";
            if(n%3 == 2) cout << (pow(three) * 2)%MOD << "\n";
        }
        return 0;
    }



    for(int i = 0; i < n; i++){
        if(cnt && a[i] == 2){
            a[i]++;
            cnt--;
        }
    }

    if(!cnt){  
        cout << mn << "\n";
        long long mx = 1;
        for(int i = 0; i < n; i++) mx = (mx*a[i])%MOD;

        cout << mx << "\n";
        return 0;
    }

    if(cnt == 1){
        long long mx = 1;
        int small = -1;

        for(int i = 0; i < n; i++){
            if(a[i] != 1 && (a[small] > a[i] || small == -1)) small = i;
        }

        a[small]++;

        for(int i = 0; i < n; i++){
            mx = (mx*a[i])%MOD;
        }

        cout << mn << "\n";
        cout << mx << "\n";

        

    }

    //place holder for subtask 2

    if(cnt > 1){
        long long mx = 1;
        long long cur = 1;
        long long best = 0;

        for(int i = 0; i < n; i++) mx = (mx*a[i])%MOD;


        long long three = cnt/3;

        if(cnt%3 == 0) best = pow(three)%MOD;
        if(cnt%3 == 1) best = (pow(three-1) * 4)%MOD;
        if(cnt%3 == 2) best = (pow(three) * 2)%MOD;

        cout << mn << "\n";
        cout << (best * mx) % MOD << "\n";
    }


    //3 3 3 3 5 7
    //4 * 4 * 4 * 3 * 5 * 7
    //3 * 3 * 3 * 3 * 3 * 5 * 7



    //3 3 3 5 9
    //3 * 3 * 5 * 5 * 9 9^2 * 5^2
    //2 * 3 * 3 * 3 * 5 * 9 3^5 * 2 * 5

    //2 2 2 5 9
    //2^4 * 5 * 9
    //3^2 * 2 * 5 * 9
    //🙈

    //splitting 1s maximum
    //7: 3 * 4 vs 2 * 2 * 3
    //8: 2*2*2*2 vs 3 * 3 * 2
    //9: 2 * 2 * 2 * 3 vs 3 * 3 * 3
    //10: 2 * 2 * 2 * 2 * 2 vs 3 * 3 * 4
    //11: 2^4 * 3 vs 3 * 4 * 4
    //12: 2^6 vs 3^4
    //optimal to use some amount of 2 and 3s

    //always upgrade 2 to 3
    //then make new elements

    //3 * 3 * 5 * 9
    //2 * 2 * 2 * 5 * 9

    //2 * 2 * 4 * 5 * 9
    //4 * 4 * 5 * 9




}