#include <bits/stdc++.h>
#include <iostream>

/*
the sequence of blocks added tends to repeat similarly

for example 

S = 100
T = 10

the sequence of adding for the first 10
is: 0 1 0 0 1 0 1 0 0 1

compare this to
S = 10
T = 0

similarly the sequence of adding for the first 10
is: 0 1 0 0 1 0 1 0 0 1

another similar but not exact case is

S = 01
T = 0

the sequence is
0 0 1 0 1 0 0 1 0 0 1

maybe the sequence is shifted over to the right
*/