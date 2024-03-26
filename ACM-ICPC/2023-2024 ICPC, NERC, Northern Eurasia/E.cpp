#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//find a solution for p = 1 q = 0
//can multiply this by x to find the answer for p = x q = 0
//do the same in reverse for q

//12−3*4+5−6+7−8+9 thank you chatgpt

//12-4*4+5 is better also the other one doesnt work

//12 * a -4*4*a+5*a
int main(){
    long long a,b; cin >> a >> b;

    cout << "12*" << a << "-4*4*" << a << "+5*" << a <<  "+";
    cout << abs(b) << (b < 0 ? "-5" : "*5"); *5" << (b < 0 ? to_string(b) : "+" + to_string(b)) << "*4*4" << (b < 0 ? "+" + to_string(-b) : "-" + to_string(b)) << "*21\n";

    string s = "12*1-4*4*1+5*1-1*5-1*4*4+1*21";

    reverse(s.begin(), s.end());

    cout << s << "\n";
    



}
