#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

bool isPossible(int n, vector<int> &a, int k, int mid) {
	int count = 0;
	for(int i=0; i<n; i++) {
		if(count & 1) {
			count++;
		}
		else {
			if(a[i] <= mid) {
				count++;
			}
		}
	}

	if(count >= k) return true;
	count = 0;
	
	for(int i=0; i<n; i++) {
		if(count & 1) {
			if(a[i] <= mid) {
				count++;
			}
		}
		else {
			count++;
		}
	}

	if(count >= k) return true;
	return false;
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int lo = *min_element(a.begin(), a.end());
	int hi = *max_element(a.begin(), a.end());

	int ans = -1;
	while(lo <= hi) {
		int mid = lo + ((hi - lo) >> 1);
		if(isPossible(n,a,k,mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	cout << ans << "\n";
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}