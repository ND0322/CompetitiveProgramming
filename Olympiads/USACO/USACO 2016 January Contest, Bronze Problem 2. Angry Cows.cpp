#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int n, a[MAXN];

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a,a+n);

    int ans = 0;
    for(int i = 0; i < n; i++){
        
        int t = 1;
        int l = a[i]-t;
        int r = a[i]+t;

        int cnt = 1;

        int j = i-1;

        while(j >= 0 && a[j] >= l){
            int last = 0;
            while(j >= 0 && a[j] >= l){
                last = a[j--];
                cnt++;
            }

            t++;
            l = last-t;
        }

        j = i+1;

        t = 1;

        while(j < n && a[j] <= r){
            int last = 0;
            while(a[j] <= r && j < n){
                last = a[j++];
                cnt++;
            }

            //if(i == 1) cout << j << " " << last << " " << t << "\n";

            t++;
            r = last+t;
        }

        //cout << cnt << "\n";

        ans = max(ans, cnt);
    }

    

    cout << ans << "\n";
}