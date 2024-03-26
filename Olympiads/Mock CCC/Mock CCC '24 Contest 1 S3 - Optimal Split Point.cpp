#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;




const int MAXN = 1e6+5;

int n, a[MAXN];



multiset<int> s, t;

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    long long psum = 0;
    long long ssum = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ssum += a[i];
        s.insert(a[i]);

    
        
    } 

    //for full binary search for first and then do some processing bs

    pair<long long,int> ans;

    ans = {1e18, -1};

    for(int i = 1; i <= n; i++){
        
        s.erase(s.find(a[i]));
        ssum -= a[i];

    
        ans = min(ans, {abs(ssum - psum), i});

        
        //might need to move the lower bound outside the abs

       
        auto it = s.lower_bound((abs(ssum - psum))/2);
        if(it != s.end()) ans = min(ans, {abs(psum - ssum + 2 * *it), i});
        if(it != s.begin()){
            it--;
            ans = min(ans, {abs(psum - ssum + 2* *it), i});
        }

        it = t.lower_bound((abs(ssum - psum))/2);

        if(it != t.end()) ans = min(ans, {abs(psum - ssum - 2 * *it), i});

       
    
        if(it != t.begin()){
            it--;
            ans = min(ans, {abs(psum - ssum - 2* *it), i});
        }

        

        psum += a[i];
        t.insert(a[i]);
    }

    

    psum = 0;
    ssum = 0;

    for(int i = 1; i <= n; i++) ssum += a[i];
    for(int i = 1; i < ans.second; i++){
        psum += a[i];
        ssum -= a[i];
    }

    ssum -= a[ans.second];
    
    if(psum == ssum){
        cout << ans.second << " -1\n";
        return 0;
    }

    

    for(int i = 1; i < ans.second; i++){
        if(abs(psum -ssum - 2 * a[i])  == ans.first){
            cout << ans.second << " " << i << "\n";
            return 0;
        }
    }

    
    for(int i = ans.second+1; i <= n; i++){
        if(abs(psum - ssum + 2 * a[i]) == ans.first){
            cout << ans.second << " " << i << "\n";
            return 0;
        }
    }
    

        
    

    

    //cout << psum << " " << ssum << "\n";




    
    
    
}