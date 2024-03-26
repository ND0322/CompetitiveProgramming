#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b,c,d; cin >> a >> b >> c >> d;

    int tot; cin >> tot;
    int cnt = 0;
    int small = 1e9;

    for(int i = 0; i*a <= tot; i++){
        for(int j = 0; i*a + j*b <= tot; j++){
            for(int k = 0; i*a + j*b + k*c <= tot; k++){
                for(int l = 0; i*a + j*b + k*c + l*d <= tot; l++){
                    if(i * a + j*b + k*c + l * d == tot){
                        cout << "# of PINK is " << i << " ";
                        cout << "# of GREEN is " << j << " ";
                        cout << "# of RED is " << k << " ";
                        cout << "# of ORANGE is " << l << "\n";
                        
                        cnt++;
                        
                        small = min(small,i+j+k+l);

                    }
                }
            }
        }
    }

    cout << "Total combinations is " << cnt << ".\n";
    cout << "Minimum number of tickets to print is " << small << ".\n";


}



