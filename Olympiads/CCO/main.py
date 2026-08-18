
import heapq
import sys
from fractions import Fraction
from math import gcd

def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(data[idx]); M = int(data[idx+1]); r = int(data[idx+2]); v = int(data[idx+3]); s = int(data[idx+4])
    idx += 5
    r -= 1
    
    edges = []
    adj = [[] for _ in range(N)]
    for _ in range(M):
        a = int(data[idx])-1; b = int(data[idx+1])-1; l = int(data[idx+2])
        idx += 3
        adj[a].append((b, l)); adj[b].append((a, l))
        edges.append((a, b, l))
    
    INF = float('inf')
    
    def dijkstra(src):
        dist = [INF] * N
        dist[src] = 0
        pq = [(0, src)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]: continue
            for w, wt in adj[u]:
                nd = d + wt
                if nd < dist[w]:
                    dist[w] = nd
                    heapq.heappush(pq, (nd, w))
        return dist
    
    # CORRECT FORMULA:
    # T* = max_{p: v*dist_t(p) >= s*dist_r(p)} dist_t(p) / s
    # Intuition: Roger can safely reach any point p where he arrives before students
    # (v*dist_t(p) >= s*dist_r(p) means dist_t(p)/s >= dist_r(p)/v).
    # He goes to p and WAITS until students catch him at time dist_t(p)/s.
    # He wants to maximize this waiting time.
    
    dist_r = dijkstra(r)
    
    results = []
    
    for t in range(N):
        dist_t = dijkstra(t)
        
        # Track best as fraction (numerator/denominator) with denominator = s
        # T = dt / s, maximize dt subject to v*dt >= s*dr
        # Use integer comparisons: best = best_dt / s
        best_dt_num = 0  # numerator of best_dt (could be fractional)
        best_dt_den = 1  # denominator
        
        def try_update(dt_num, dt_den, dr_num, dr_den):
            # Feasibility: v * (dt_num/dt_den) >= s * (dr_num/dr_den)
            # => v * dt_num * dr_den >= s * dr_num * dt_den
            nonlocal best_dt_num, best_dt_den
            if v * dt_num * dr_den >= s * dr_num * dt_den:
                # Compare dt_num/dt_den vs best_dt_num/best_dt_den
                if dt_num * best_dt_den > best_dt_num * dt_den:
                    best_dt_num = dt_num
                    best_dt_den = dt_den
        
        # Check all nodes (integer distances)
        for u in range(N):
            dr = dist_r[u]
            dt = dist_t[u]
            if dr == INF or dt == INF: continue
            try_update(dt, 1, dr, 1)
        
        # Check edge interiors
        for (a, b, L) in edges:
            dr_a = dist_r[a]; dr_b = dist_r[b]
            dt_a = dist_t[a]; dt_b = dist_t[b]
            if dr_a == INF or dr_b == INF or dt_a == INF or dt_b == INF: continue
            
            # On edge at distance x from a (0 <= x <= L):
            # dist_r(x) = min(dr_a + x, dr_b + L - x), peak at x_r = (dr_b+L-dr_a)/2
            # dist_t(x) = min(dt_a + x, dt_b + L - x), peak at x_t = (dt_b+L-dt_a)/2
            #
            # Both are piecewise linear with 1 breakpoint each in [0,L] (if breakpoint is in range).
            # Breakpoints divide [0,L] into at most 3 segments.
            # In each segment, both are linear => feasibility is a half-interval => max dist_t at an endpoint.
            # So candidates are: all breakpoints + segment endpoints + feasibility crossing points.
            
            # Compute breakpoints (as fractions with denominator 2):
            # x_r = (dr_b+L-dr_a)/2, valid if 0 <= dr_b+L-dr_a <= 2L
            # x_t = (dt_b+L-dt_a)/2, valid if 0 <= dt_b+L-dt_a <= 2L
            
            bps = [0, 2*L]  # stored as 2*x to keep integers (multiply through by 2)
            xr2 = dr_b + L - dr_a  # = 2*x_r
            if 0 < xr2 < 2*L: bps.append(xr2)
            xt2 = dt_b + L - dt_a  # = 2*x_t
            if 0 < xt2 < 2*L: bps.append(xt2)
            bps = sorted(set(bps))
            
            # For each consecutive pair, determine linear functions and find max feasible dist_t
            for i in range(len(bps)-1):
                lo2 = bps[i]; hi2 = bps[i+1]
                mid2 = lo2 + 1  # use lo+1 (integer, in interior since hi2>=lo2+2 for distinct breakpoints)
                # Actually mid2 might equal hi2 if hi2=lo2+1. Use lo2 itself for branching.
                # We need mid2 strictly between lo2 and hi2. Since all are even or endpoints...
                # Actually bps are 0, 2*L, xr2, xt2 which may not be even. They're just integers.
                # Use lo2 for determining branch (not mid; both endpoints are on the same branch within a segment)
                
                # Determine branches using lo2 (or any interior point; endpoints are on same branch within segment)
                # Be careful at breakpoints themselves: use a point strictly between lo2 and hi2.
                # Since we may have bps like [0, 3, 6, 10] (all integers, not necessarily even),
                # we can use 2*lo2+1 vs 2*hi2 to pick interior... Actually let's just use Fraction for safety.
                
                # Evaluate functions at lo2/2 and hi2/2 and midpoint
                # x coordinates as fractions
                x_lo = Fraction(lo2, 2)
                x_hi = Fraction(hi2, 2)
                
                # dist_r at lo and hi
                dr_lo = min(dr_a + x_lo, dr_b + L - x_lo)
                dr_hi = min(dr_a + x_hi, dr_b + L - x_hi)
                dt_lo = min(dt_a + x_lo, dt_b + L - x_lo)
                dt_hi = min(dt_a + x_hi, dt_b + L - x_hi)
                
                # Linear: dist_r(x) = A + B*x, dist_t(x) = C + D*x in [x_lo, x_hi]
                if x_lo == x_hi:
                    continue
                dx = x_hi - x_lo
                B = (dr_hi - dr_lo) / dx  # should be +1 or -1
                D = (dt_hi - dt_lo) / dx
                A = dr_lo - B * x_lo
                C = dt_lo - D * x_lo
                
                # Feasibility: v*(C+D*x) >= s*(A+B*x)
                # => (v*D - s*B)*x >= s*A - v*C
                coeff = v * D - s * B
                rhs_val = s * A - v * C
                
                # Determine feasible sub-interval [flo, fhi] within [x_lo, x_hi]
                if coeff == 0:
                    if rhs_val <= 0:
                        flo, fhi = x_lo, x_hi
                    else:
                        continue  # infeasible
                elif coeff > 0:
                    # x >= rhs_val / coeff
                    flo = max(x_lo, rhs_val / coeff)
                    fhi = x_hi
                else:
                    # x <= rhs_val / coeff
                    flo = x_lo
                    fhi = min(x_hi, rhs_val / coeff)
                
                if flo > fhi:
                    continue
                
                # Max dist_t = C + D*x in [flo, fhi]
                if D >= 0:
                    x_opt = fhi
                else:
                    x_opt = flo
                
                dt_opt = C + D * x_opt
                dr_opt = A + B * x_opt
                
                # Convert to fraction representation for try_update
                # dt_opt and dr_opt are Fraction objects
                try_update(dt_opt.numerator, dt_opt.denominator,
                           dr_opt.numerator, dr_opt.denominator)
        
        # best T = best_dt_num / (best_dt_den * s)
        T_num = best_dt_num
        T_den = best_dt_den * s
        g = gcd(abs(T_num), abs(T_den))
        T_num //= g; T_den //= g
        results.append(f"{T_num}/{T_den}")
    
    sys.stdout.write('\n'.join(results) + '\n')

solve()
