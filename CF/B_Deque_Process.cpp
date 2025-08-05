#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        deque<int> dq;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dq.push_back(a[i]);
        }

        bool flag = 1;

        for(int i = 1; i <= n-4; i++){
            flag &= !(a[i] < a[i+1] && a[i+1] < a[i+2] && a[i+2] < a[i+3] && a[i+3] < a[i+4]);
            flag &= !(a[i] > a[i+1] && a[i+1] > a[i+2] && a[i+2] > a[i+3] && a[i+3] > a[i+4]);
        }

        if(flag){
            for(int i = 1; i <= n; i++) cout << "L";
            cout << "\n";
            continue;
        }

        string ans = "";
        while(dq.size()){
            if(dq.size() & 1){
                if (dq.front() < dq.back()){
                    ans += "L";
                    dq.pop_front();
                }
                else{
                    ans += "R";
                    dq.pop_back();
                }
            }
            else{
                if (dq.front() > dq.back()){
                    ans += "L";
                    dq.pop_front();
                }
                else{
                    ans += "R";
                    dq.pop_back();
                }
            }
            
        }

        cout << ans << "\n";


    }
}