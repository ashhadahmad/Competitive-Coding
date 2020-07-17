#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

bool check(int n, int k, vector<int> &a) {
	vector<bool> inc(n, true);
	vector<bool> dec(n, true);
	for(int i=k; i<n; i++) {
		if(i == k) continue;
		if(a[i] >= a[i-1] && inc[i-1]) inc[i] = true;
		else inc[i] = false;
	}
	for(int i=n-1; i>=k; i--) {
		if(i == n-1) continue;
		if(a[i] >= a[i+1] && dec[i+1]) dec[i] = true;
		else dec[i] = false;
	}

	for(int i=k; i<n; i++) {
		if(inc[i] && dec[i]) return true;
	}
	return false;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int ans = n-1;
	int lo = 0, hi = n-1;
	while(lo <= hi) {
		int mid = ((lo + hi) >> 1);
		if(check(n, mid, a)) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << '\n';
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}