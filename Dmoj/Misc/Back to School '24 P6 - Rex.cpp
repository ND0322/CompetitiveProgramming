#include <bits/stdc++.h>
#include <iostream>

/*
for each node find the tree it goes to
for the up part the answer is sum of distances from nodes that go deeper + the closest distance to the one ancestor node
this will be the target node with smallest depth along the path
for the down part
all nodes higher or in different subtrees are summed 


*/