#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const int MXN = 1e5 + 10;
const int LG = 19;
const int MOD = 1000000007;
int a[MXN], lvl[MXN] = {0}, PR[MXN][LG], BITS[MXN][32] = {0};
unsigned ll fac[MXN], CHOOSE[MXN][5];
 
 
void dfs(int u, int par, vector<vector<int>>& adj) {
	if(par != -1) {
		PR[u][0] = par;
		lvl[u] = lvl[par] + 1; 
		for(int i=0; i<32; i++) {
			BITS[u][i] = BITS[par][i];
		}
	}
	for(int i=0; i<32; i++) {
		BITS[u][i] += ((a[u] >> i) & 1);
	}
	for(auto x: adj[u]) if(x != par) dfs(x, u, adj);
}
 
int LowestCommonAncestor(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);
 
    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;
 
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = PR[u][i];
    }
 
    if (u == v) 
    	return u;
 
    for(i=lg; i>=0; i--){
        if (PR[u][i] != -1 and PR[u][i] != PR[v][i])
            u = PR[u][i], v = PR[v][i];
    }
 
    return PR[u][0];
}
 
unsigned long long power(unsigned long long x, int y, int p) { 
	unsigned long long res = 1;
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
} 
  
unsigned long long modInverse(unsigned long long n, int p) { 
	return power(n, p - 2, p); 
}
 
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) { 
	if(n < r) return 0;
	if (r == 0) return 1;
	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
}
 
int main(){
 	IOS;
	fac[0] = 1; 
	for (int i = 1; i <= MXN; i++) fac[i] = (fac[i - 1] * i) % MOD; 
 
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	vector<vector<int>> adj(n+1);
	for(int i=0; i<n-1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
 
	for(int i=0; i<MXN; i++) {
		for(int j=0; j<LG; j++) PR[i][j] = -1;
	}
 
	dfs(1, -1, adj);
 
	for(int i=1; i<LG; i++){
		for(int j = 1; j <= n; j++) {
			if (PR[j][i-1] != -1) PR[j][i] = PR[PR[j][i-1]][i-1];
		}
	}
 
	for(int i=0; i<MXN; i++) {
		for(int j=0; j<5; j++) {
			CHOOSE[i][j] = nCrModPFermat(i,j,MOD);
		}
	}
 
	int qq;
	cin >> qq;
	while(qq--) {
		int k, x, y;
		cin >> k >> x >> y;
		vector<int> onBits(32, 0);
		int lca = LowestCommonAncestor(x,y);
		int totalNodes = 1 + lvl[x] + lvl[y] - 2*lvl[lca];
		for(int i=0; i<32; i++) {
			onBits[i] += BITS[x][i];
			onBits[i] += BITS[y][i];
			onBits[i] -= (2 * BITS[lca][i]);
			onBits[i] += ((a[lca] >> i) & 1);
		}
		ll ans = 0;
		ll ncr = nCrModPFermat(totalNodes,k, MOD);
		for(int i=0; i<32; i++) {
			ll ways = ((ncr - CHOOSE[totalNodes - onBits[i]][k]) + MOD) % MOD;
			ans += (((1 << i) * ways)%MOD);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}