#include <bits/stdc++.h>
#include <iostream>

/*
for each ai

define dpl as dp of smaller values
dpr as dp of larger values

dpl[i] = max(dpl[divisor]) + 1
dpr[i] = max(dpr[multiple]) + 1;

to transition to dpr

consider ai >= sqrt n

we only have to check up to sqrt n multiples

ai * k

if ai < sqrt n


ai can only be a factor of numbers larger than sqrt n

keep sqrt n seg trees 



*/