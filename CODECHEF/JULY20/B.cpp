#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	map<int, int> mp_a, mp_b;
	int min_a = INT_MAX, min_b = INT_MAX;
	for(int i=0; i<n; i++) {
		int x; 
		cin >> x;
		min_a = min(x, min_a);
		mp_a[x]++;
	}
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		min_b = min(x, min_b);
		if(mp_a[x] > 0) mp_a[x]--;
		else mp_b[x]++;
	}
	vector<int> final;
	for(auto x: mp_a) {
		if(x.second == 0) continue;
		else if(x.second  & 1) {
			cout << "-1\n";
			return;
		}
		else {
			for(int i=0; i<(x.second >> 1); i++) final.push_back(x.first);
		}
	}
	for(auto x: mp_b) {
		if(x.second == 0) continue;
		else if(x.second  & 1) {
			cout << "-1\n";
			return;
		}
		else {
			for(int i=0; i<(x.second >> 1); i++) final.push_back(x.first);
		}
	}

	sort(final.begin(), final.end());

	int smallestInBoth = min(min_a, min_b);

	ll ans = 0;

	// for(auto x: final) cout << x << " ";
	// cout << "\n";

	for(int i=0; i<(final.size() >> 1); i++) {
		ans += min(final[i], 2 * smallestInBoth);
	}

	cout << ans << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}