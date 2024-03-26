//p2 reverse the graph intuitivly and use a min queue kinda like dijkstras. Use distance, entrance edge id, time of entry
//p3 binary search over convex function
//for some x binary search for the the rightmost point less than x
//the dist = #points less than x * x - sum of points less than x
//psa after sorting works for this

//for p1

//we can determine for each i and j if there is a direct edge between the two 
//by looking at the number of paths that already exist and the parity with probably dp
//go in reverse order


//basically heres the approach
//start for each i by checking if theres a direct flight to i+1. At max there is one flight so the parity determines the amount
//lets say we tryna find the direct flights from 1
//from the previous step lets say we know theres a direct flight from 1 to 2 but not from 2 to 3
//the number of flight paths currently is 0  
//if c[1][3] is 1 there must be a flight from 1 to 3
//otherwise there must not be
//if the number of flights from 1 to i matches the parity no flight to i

