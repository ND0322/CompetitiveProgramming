    #include <bits/stdc++.h>
    #include <iostream>
    #include <set>

    using namespace std;

    int main(){

        int tt; cin >> tt;

        while(tt--){
            int n; cin >> n;

            vector<int> freq(n+1);

            for(int i = 0; i < n; i++){
                int x; cin >> x;

                freq[x]++;
            }

            bool flag = 0;

            for(int i = 0; i <= n; i++){
                if(!freq[i]){
                    cout << i << "\n";
                    break;
                }

                if(freq[i] == 1){
                    if(!flag) flag = 1;
                    else{
                        cout << i << "\n";
                        break;
                    }
                }
                
            }

            
        }

    }