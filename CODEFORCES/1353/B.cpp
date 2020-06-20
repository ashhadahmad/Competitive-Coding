#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int p=0;
	while(k > 0){
		if(a[p] < b[p]){
			p++;
			k--;
		}
		else break;
	}
	ll ans = 0;
	for(int i=0; i<p; i++) ans += b[i];
	for(int i=p; i<n; i++) ans += a[i];
	cout << ans << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}