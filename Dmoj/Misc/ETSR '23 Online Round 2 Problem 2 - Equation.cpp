#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
dp state => prefix i, current sum from 0 to s+1, s+1 represents anything greater than s and must be reset with a * 0

if we do + and then * then we have to bruteforce over the endpoint of the * 
if we have l and r then we have to iterate through splits of *

range dp?
*/