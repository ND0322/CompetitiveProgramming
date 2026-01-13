#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
for t == 2
when ci decreases, it means we have that many ai = 
when ci increases, it mean we have that ci-1 of ci = ai-1 
if ci doesnt change we can omitt that element 

when we have to place island break lets place in the form 0 1 0 1 0 1  x

such that we have a chunk of x size to work with on the right for future things
place decrease elements in the 0 gaps 

it can only decrease as much as there are gaps
*/

const int MAXN = 2e5+5;

int n, q, ans[MAXN], a[MAXN], parents[MAXN];

map<int,vector<int>> mp;

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}


bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return 0;
    parents[x] = y;
    return 1;
}




int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int t; cin >> t;
    cin >> n;

    if(t == 1){
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        int cnt = 0;

        for(int i = n; i >= 1; i--){
            for(int j : mp[i]){
                cnt++;

                parents[j] = j;

                if(parents[j-1]) cnt -= uni(j,j-1);
                if(parents[j+1]) cnt -= uni(j, j+1);
            }
            ans[i] = cnt;
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    else{
        for(int i = 1; i <= n ;i++) cin >> a[i];
        a[0] = 1;
        a[n+1] = 0;

        set<int> clean;
        int l = 1;
        bool flag = 1;
        int r = 0;
        for(int i = 0; i <= n; i++){
            if(a[i+1] > a[i]){
                if(l+2 * (a[i+1] - a[i]) - 1 > n){
                    flag = 0;
                    break;
                }
        
                for(int j = l; j < l + (2 * (a[i+1] - a[i])); j+=2){
                    clean.insert(j);
                    ans[j+1] = i;
                }
                l += 2 * (a[i+1] - a[i]);
            }

            if(a[i] > a[i+1]){
                int cnt = 0;
                for(int j = 0; j < a[i] - a[i+1]; j++){
                    if(!clean.size()) break;
                    auto it = clean.begin();

                    ans[*it] = i;
                    clean.erase(it);
                    cnt++;
                }

                a[i] -= cnt;
            }

            if(!a[i+1]){
                r = i;
                break;
            }
        }


        
        for(int i = r+1; i<= n; i++) flag &= (!a[i]);

        if(!flag || ceil((n-l+1 / 2.0)) < a[r]){
            cout << "-1\n";
            return 0;
        }
        
        for(int i = l; i <= n && a[r]; i+=2){
            ans[i] = r;
            a[r]--;
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";

       

       
    }
    

}