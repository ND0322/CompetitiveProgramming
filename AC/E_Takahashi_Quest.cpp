#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

int n;

stack<int> st[MAXN];

bool take[MAXN];

pair<int,int> things[MAXN];


int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int t, x; cin >> t >> x;

        things[i] = {t,x};


        if(t == 1) st[x].push(i);
        else{
            if(!st[x].size()){
                cout << "-1\n";
                return 0;
            }
            take[st[x].top()] = 1;
            st[x].pop();
        }
    }

    int cnt = 0;
    int ans = 0;

    vector<int> a;

    for(int i = 0; i < n; i++){
        if(things[i].first == 1){
            cnt += take[i];
            a.push_back(take[i]);
        }
        else cnt--;

        ans = max(ans, cnt);
    }

    cout << ans << "\n";

    for(int i : a) cout << i << " ";
    cout << "\n";

    


}