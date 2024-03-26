#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 5005;

int ans;

vector<string> suffixes;



int main() {

    cin.tie(NULL)->ios_base::sync_with_stdio(0);

    int tt; cin >> tt;

    while(tt--){
        ans=0;

        suffixes.clear();
        string s; cin >> s;

       

        

        for(int i = 0; i < s.size(); i++) suffixes.push_back(s.substr(i,s.size()-i));

        sort(suffixes.begin(), suffixes.end());
        //all suffixes

        //cout << suffixes[0] << "\n";

        ans += suffixes[0].size();
        

        //a aa aaa
        for(int i = 1; i < suffixes.size(); i++){

            int common =  min(suffixes[i-1].size(), suffixes[i].size());
            

            for(int j = 0; j < min(suffixes[i-1].size(), suffixes[i].size()); j++){                

                //new node
                if(suffixes[i-1][j] != suffixes[i][j]){
                    //cout << suffixes[i-1][j] << " " << suffixes[i][j] << "\n";
                    
                    common = j;
                    break;
                }

                
            }

            ans += suffixes[i].size() - common;

        }

        cout << ans + 1 << "\n";
        


        
    }
        


    
}