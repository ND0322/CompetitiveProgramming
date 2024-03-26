#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int valid(int n, int inputSeq[]){
    for(int i = 0; i < n; i++){
        if(inputSeq[0] % n != inputSeq[1]%n) return false;
    }
    return true;
}