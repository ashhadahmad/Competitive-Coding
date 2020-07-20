#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n);

	for(ll i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<ll> right(n, 0), left(n,0);
	for(int i=n-1; i>=0; i--) {
		if(i == n-1) right[i] = a[i];
		else right[i] = (a[i] | right[i+1]);
	}
	for(int i=0; i<n; i++) {
		if(i == 0) left[i] = a[i];
		else left[i] = (a[i] | left[i-1]);
	}

	for(int i=0; i<n; i++){
		bool isUnique = true;
		if(i > 0) if(left[i-1] == (left[i-1] | a[i])) isUnique = false;
		if(i < n-1) if(right[i+1] == (right[i+1] | a[i])) isUnique = false;
		if(!isUnique) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}