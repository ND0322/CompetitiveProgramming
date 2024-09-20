#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int f(int x, int l, int r){
    return (l+l+x - 1) * x / 2 - (l+x + r) * (r-l-x+1)/2;
}
int main(){

}