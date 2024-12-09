#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

//you can swap 2 values that differ by 1
//its like the ccc swapping seats thing or book question
//split into sections and casework
//when encountering a 2 we want to swap with the rightmost 1 or any 1 in section 3
//if there are no 1s in section 3 that means there must be 0s that are to be swapped
//each things needs to be swapped with at most once?
//we can either swap a 2 with 1 or 0 with 1 for cost one
//or we swap 2 with 0 for cost two

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        int cnt[3] = {0,0,0};

        vector<vector<set<int>>> sect(3, vector<set<int>>(3));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }


        for(int i = 1; i <= n; i++){
            int s;

            if(i <= cnt[0]) s = 0;
            else if(i <= cnt[0] + cnt[1]) s = 1;
            else s = 2;

            sect[s][a[i]].insert(i);
        }

        vector<pair<int,int>> ans;

        for(int i = 1; i <= cnt[0]; i++){
            if(a[i] == 0) continue;
            if(a[i] == 2){
                
                
                int pos = 0;
                int ts = 0;

                for(int j = 2; j >= 0; j--){
                    if(sect[j][1].size() >= 1){
                        pos = *sect[j][1].begin();
                        sect[j][1].erase(sect[j][1].begin());
                        sect[j][2].insert(pos);
                        ts = j;
                        break;
                    }
                }

                //swap with sect c 1 then 0

                if(ts == 2){
                    ans.push_back({i, pos});
                    swap(a[i], a[pos]);
                    sect[0][2].erase(i);
                    sect[0][1].insert(i);

                    pos = 0;

                    for(int j = 2; j >= 0; j--){
                        if(sect[j][0].size() >= 1){
                            pos = *sect[j][0].begin();
                            sect[j][0].erase(sect[j][0].begin());
                            sect[j][1].insert(pos);
                            break;
                        }
                    }

                    ans.push_back({i, pos});
                    swap(a[i], a[pos]);
                    sect[0][1].erase(i);
                    sect[0][0].insert(i);
                }
                else{
                    //there must be a sect c 0

                    int pz = *sect[2][0].begin();

                    sect[2][0].erase(sect[2][0].begin());
                    sect[2][2].insert(pz);
                    swap(a[i], a[pz]);

                    ans.push_back({pos, pz});
                    ans.push_back({i, pz});
                    ans.push_back({i, pos});
                    
                }

                
            }
            else{
                int pos = 0;

                for(int j = 2; j >= 0; j--){
                    if(sect[j][0].size()){
                        pos = *sect[j][0].begin();
                        sect[j][0].erase(sect[j][0].begin());
                        sect[j][1].insert(pos);
                        break;
                    }
                }

                ans.push_back({i, pos});
                swap(a[i], a[pos]);
                sect[0][1].erase(i);
                sect[0][0].insert(i);
            }
        }

        for(int i = cnt[0]+1; i <= cnt[1] + cnt[0]; i++){
            if(a[i] == 2){
                int pos = *sect[2][1].begin();

                ans.push_back({i, pos});

                sect[2][1].erase(sect[2][1].begin());
                swap(a[i], a[pos]);
            }
        }

        
        cout << ans.size() << "\n";

        for(auto [x,y] : ans) cout << x << " " << y << "\n";





    }
}