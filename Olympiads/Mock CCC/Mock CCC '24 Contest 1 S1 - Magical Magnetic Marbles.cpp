#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

bool a[MAXN];

int main(){
    int n,k; cin >> n >> k;

    for(int i = 0; i < n; i++){
        char s; cin >> s;

        a[i] = (s == '1');
    }
    

    vector<int> gaps;
    int cur = 0;
    int i = 0;
    int cnt = 0;

    while(i < n){
        if(a[i]){
            while(i < n && a[i]){
                a[i] = 0;
                i++;
                cur++;      
            }

            gaps.push_back(cur-1);
            cnt++;
            cur = 0;

            a[i-1] = 1;
        }

        else{
            i++;
            cur++;
        }
    }

    gaps.push_back(cur);

    if(!k){
        cout << cnt << "\n";
        return 0;
    }

    
    vector<int> tmp;

    for(int i = 1; i < gaps.size()-1; i++) tmp.push_back(gaps[i]);

    sort(tmp.begin(), tmp.end());


    for(int i : tmp){
        if(i > k) break;
        k -= i;
        if(i) cnt--;
       
        
    }

    //cout << k << "\n";

    cout << max(cnt,1) << "\n";
    
    
    


   


}