#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

//could do some dp but just check ba before ab and ab before ba

int main(){
    string s; cin >> s;

    int n = s.size();

    int found = 0;

    for(int i = 0; i < n-1; i++){
        if(s[i] == 'A' && s[i+1] == 'B' && !found){
            found = 1;
            i++;
            continue;
        }
        if(found == 1 && s[i] == 'B' && s[i+1] == 'A'){
            found = 2;
            break;
        }
    }

    if(found == 2){
        cout << "YES\n";
        return 0;
    }

    found = 0;

    for(int i = 0; i < n-1; i++){
        if(s[i] == 'B' && s[i+1] == 'A' && !found){
            found = 1;
            i++;
            continue;
        }
        if(found == 1 && s[i] == 'A' && s[i+1] == 'B'){
            found = 2;
            break;
        }
    }

    if(found == 2){
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";


}