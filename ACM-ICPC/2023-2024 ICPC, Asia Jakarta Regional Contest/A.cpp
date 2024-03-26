#include <bits/stdc++.h>
#include <iostream>

using namespace std;


char grid[3][3];

 
bool check(int x, int y) {
  int a1 = x / 3;
  int b1 = x % 3;
  int a2 = y / 3;
  int b2 = y % 3;
  return (abs(a1 - a2) <= 1 && abs(b1 - b2) <= 1);
    
  
}
int main(){
    int n = 3;
    string b = "";
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        b += s;
    }


    string ans = "CCC";



    for(int i = 0; i < 9; i++){
        for(int j = 0;j < 9; j++){

            if(i == j) continue;

            for(int k = 0; k < 9; k++){

                if(i == k || j == k) continue;
                string tmp = "";
                tmp += b[i];
                tmp += b[j];
                tmp += b[k];

                if(check(i,j) && check(j,k)) ans = min(ans, tmp);
            }
            
            


        }
    }

    cout << ans << "\n";
}

