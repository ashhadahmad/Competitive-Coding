#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a) cin >> x;

	vector<int> bits(21, 0);

	for(auto x: a) {
		for (int i = 0; i <= 20; i++){
			bits[i] += ((x & (1 << i)) > 0);
		}
	}

	ll ans = 0;
	for(int i=0; i < n; i++){
		ll tempNum = 0;
		for(int i=20; i>=0; i--){
			if(bits[i]){
				tempNum |= (1 << i);
				bits[i]--;
			}
		}
		ans += (tempNum * tempNum);
	}

	cout << ans;
}

int main(){
	FASTIO(); 
	int t = 1; 
	// cin >> t;
	while(t--) 
		solve();
	return 0;
}