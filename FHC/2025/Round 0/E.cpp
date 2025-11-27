/*
call an area bounded by 2 walls a bucket

what are the intersections in each bucket

naturally i will collide will all i+1, i+2, ... in order

let d1 and d2 be the distances to left wall for i and i+1

collision at d1 + (d2 - d1)/2

(2d1 + d2 - d1)/2 = (d2 + d1) / 2

kl + (d1+d2)/2 <= t

d2 <= 2(t % l) - d1

index must be > i
max(d2) <= k
must be in same bucket => add L 2L 3L ... to distinguish buckets 
*/