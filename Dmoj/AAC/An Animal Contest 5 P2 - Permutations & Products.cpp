#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

double ans[MAXN];

bool used[MAXN];

/*
query first 3 and solve a system

x * y = a
y * z = b
x * z = c

x = a/y
z = b/y

a*b/y^2 = c

a*b/c = y^2
y = sqrt((a*b)/c)
*/



int query(int x, int y){
    cout << "? " << x << " " << y << "\n";
    int ans; cin >> ans;
    return ans;
}

int main(){
    cin >> n;

    if(n == 3){
        int a = query(1,2);
        int b = query(2,3);

        if(a == 2 && b == 6){
            cout << "! 1 2 3\n";
            return 0;
        }

        if(a == 3 && b == 6){
            cout << "! 1 3 2\n";
            return 0;
        }

        if(a == 2 && b == 3){
            cout << "! 2 1 3\n";
            return 0;
        }

        if(a == 3 && b == 2){
            cout << "! 3 1 2\n";
            return 0;
        }

        if(a == 6 && b == 3){
            cout << "! 2 3 1\n";
            return 0;
        }

        if(a == 6 && b == 2){
            cout << "! 3 2 1\n";
            return 0;
        }

       
        
    }

    int a = query(1,2);
    int b = query(2,3);
    int c = query(1,3);

    if(a == -1 || b == -1 || c == -1) return 0;

    ans[2] = sqrt((a*b)/c);
    ans[1] = a/ans[2];
    ans[3] = b/ans[2];

    used[(int)ans[2]] = 1;
    used[(int)ans[1]] = 1;
    used[(int)ans[3]] = 1;

    for(int i = 4; i < n; i++){
        ans[i] = query(1, i)/ans[1];
        if(ans[i] < 0) return 0;
        used[(int)ans[i]] = 1;
    }

    if(n > 3){
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                ans[n] = i;
                break;
            }
        }
    }
    
    cout << "! ";
    for(int i = 1; i < n; i++) cout << (int)ans[i] << " ";
    cout << (int)ans[n] << "\n";
    


}