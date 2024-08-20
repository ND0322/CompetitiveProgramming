/*
value 0 is nice case
we can set all in range to 0
if we have value 1 we can only set it in the case that the range has exactly one unknown and the rest is 0
if there is already a 1 in that range we can discard the query
otherwise bsearch for the solution
if it has more than 1 unknown we have to queue it and do it later 
recalculate at the point queries
look for all ranges that intersect this point
we need to test at most 2 queries being the one with the minimum r and the one with the max l
*/