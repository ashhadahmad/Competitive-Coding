#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
const ll mod = (ll) 1e9+7;
const int mxN = 2e6 + 5;
 
int main(){
	IOS;
	int t = 1; 
	cin >> t;
	vector<ll> dp(mxN);
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2; i<mxN; i++){
		dp[i] = (2 * dp[i-2] + dp[i-1]);
		dp[i] += (i%3 == 0);
		dp[i] %= mod;
	}
	while(t--) {
		int n;
		cin >> n;
		cout << ((dp[n] * (ll)4) % mod) << "\n";
	}
	return 0;
}