#include <bits/stdc++.h>
using namespace std;
//Count total bits in a number
unsigned int bits(unsigned int number){
  
   while (number){
      count++;
      number >>= 1;
   }
   
}
int main(){

   bits(number);
   return 0;
}