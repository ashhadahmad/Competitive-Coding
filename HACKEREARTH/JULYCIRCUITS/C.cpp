## PYPY3

def solve(sieve):
    n,m,k = (int(x) for x in input().strip().split())
    a = [int(x) for x in input().strip().split()]
    final_primes = {}
    for el in a:
        d = {}
        while sieve[el] != -1:
            d[sieve[el]] = d.get(sieve[el], 0) + 1
            el = el // sieve[el]
        d[el] = d.get(el, 0) + 1
        for key,val in d.items():
            final_primes[key] = max(val, final_primes.get(key, 0))
    ans = 1
    for key, val in final_primes.items():
        ans *= pow(key, val, m)
        ans %= m
    ans = pow(ans, k, m)
    print(ans)
 
maxN = int(1e6+10)
sieve = [-1 for i in range(maxN)]
for i in range(2, maxN):
    if sieve[i] == -1:
        for j in range(i+i, maxN, i):
            sieve[j] = i
for _t in range(int(input())):
    solve(sieve)