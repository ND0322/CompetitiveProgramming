#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
assume magic number s

sum of grid will equal s * n
will also equal s * m

therefore s * m = s*n

only true for all (m,n) if s = 0

we know the top left corner because either the first row or first column must have only one 0
same goes for bottom right 
*/