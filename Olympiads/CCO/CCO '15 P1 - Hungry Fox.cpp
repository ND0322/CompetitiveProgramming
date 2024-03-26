#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//min is easy
//max we just check if we should use water first before going to the other side

const int MAXN = 1e5+5;

int n, w, a[MAXN];

int main(){
    cin >> n >> w;

    vector<int> tmp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tmp.push_back(a[i]);
    }

    tmp.push_back(w);

    sort(tmp.begin(), tmp.end());
    sort(a,a+n);

    long long ans = 0;

    for(int i = 0; i < tmp.size()-1; i++) ans += (tmp[i+1]-tmp[i]);
    cout << ans << " ";

    

    vector<long long> mx(2);

    for(int i = 0; i < 2; i++){
        mx[i] = abs(a[0] - w);

        bool side = 0;

        int l = 0;
        int r = n-1;


        while(l < r){
            if(!side){
                
                mx[i] += max(abs(a[r] - a[l]), abs(w-a[r]));
                l++;
            }
            else{
                mx[i] += max(abs(a[r] - a[l]), abs(w-a[l]));
                r--;
            }
            side ^= 1;
        }

        reverse(a,a+n);
    }

    //cout << mx[0] << " " << mx[1] << "\n";

    cout << max(mx[0], mx[1]) << "\n";
    
    
    


}