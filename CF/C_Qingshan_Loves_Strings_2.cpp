#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;


        bool flag = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == s[n-i-1]){
                flag = 1;
                break;
            }
            
        }

        if(!flag){
            cout << "0\n\n";
            continue;
        }

        int i = 0;
        int j = n-1; 

        int cnt = 0;
        vector<int> ans;

        while(i <= j && cnt <= 300){
            if(s[i] == s[j]){
                if(s[i] == '1'){
                    cnt++;
                    ans.push_back(i);
                    s.insert(i, "01");
                }
                else{
                    cnt++;
                    ans.push_back(j+1);
                    s.insert(j+1,"01");
                }

                i++;
                j++;
            }
            else{
                i++;
                j--;
            }
        }

        if(cnt > 300){
            cout << "-1\n";
            continue;
        }

        cout << cnt << "\n";

        for(int i: ans) cout << i << " ";
        cout << "\n";
    }
}