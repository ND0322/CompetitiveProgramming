/*
When can we not jump anymore
order kind of matters

20,000 jumps

lets say we use k on a in x row

let a,b be initial jump rates

x will move a * k + k*(k+1)/2
y will move b * k

and a += k;

how many times should we alternate blocks 

lets we have 4 runs

ie


XXXXX...YYYYY...XXXXX....YYYY
k1       k2     k3      k4

x = k1 * (k+1) / 2


x = k1 * k2 + k1 * (k+1)/2
y = k2 * (k+2)/2

x = k1 * k3 + k1 * k2 + k1 * (k+1) /2 + k3 * (k+3)/2
y = k2 * k3 + k2 * (k+2)/2

x = (k1 + k3) * k4 



*/