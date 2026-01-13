#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
chunks of consecutive things only change at the endpoints 
left will be left with one
right will be max - 1

Basically rotating the sizes within each chunk by 1 
Each chunk leaves a trail of consecutive single numbers
all chunks propagate forward at the same speed, so we can only intersect a trail

3 1 2 -> 1 3 1 1 -> 1 1 3 1 -> 1 1 1 3 -> 1 1 1 1 2 -> 1 1 1 1 1 1


4 0 1 1 1 -> 1 3 1 1 1 -> 1 1 3 1 1 

do it from right to left 

every time we reach a non 1 element it turns into 1

maintain a set/stack of non 1s and delete them every time 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(4 * n+1, 0);

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            a[x]++;
        }

        stack<int>st;

        int ans = 0;

        for(int i = 4 * n; i >= 1; i--){
            if(a[i] == 1) continue; 
            if(a[i] <= k){
                st.push(i);
                continue;
            }


            int cur = a[i];
            int last = i;
            int r = i;


            while(cur > k){
                int x = st.top();

                r = x;
                //cout << i << " " << x << " " << last << "\n";
                if(a[x] == 0){
                    a[x] = 1;
                    st.pop();
                    cur--;
                }

                else{
                    cur += a[x]-1;
                    a[x] = 1;
                    st.pop();
                }
            }

            ans = max(ans, r - i);

            a[r] += cur-1;
            if(a[r] != 1) st.push(r);


        }

        cout << ans << "\n";
    }
}