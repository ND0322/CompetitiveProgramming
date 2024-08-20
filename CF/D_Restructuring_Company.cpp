//instead of treating each index as a node we instead treat each range as a node
//when we add a range that intersects a previous one we can make a new node and connect it
//treat the regular dsu merges when we need to 