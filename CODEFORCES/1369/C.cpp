#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(k);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int count1 = 0;
	for(int i=0; i<k; i++) count1 += (b[i] == 1);
	
	int l = 0, r = n-1;
	ll ans = 0;

	while(count1--){
		ans += (2 * a[r--]);
	}

	for(int i=0; i < k; i++) {
		if(b[i] == 1) {
			continue;
		}
		else {
			ans += (a[l] + a[r]);
			r--;
			l += (b[i] - 1);
		}
	}
	cout << ans << endl;
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}