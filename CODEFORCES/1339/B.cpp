#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Documents/Codes/input.txt", "r", stdin);
	freopen("/Users/mac/Documents/Codes/output.txt", "w", stdout);
	#endif	
}

using namespace std;
int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		ll n;
		cin >> n;
		vector<ll> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		ll i = 0, j = n - 1;
		vector<ll> ans;
		while(i <= j){
			if(i == j) ans.push_back(a[i++]);
			else {
				ans.push_back(a[i++]);
				ans.push_back(a[j--]);
			}
		}
		reverse(ans.begin(), ans.end());
		for(int i=0; i<n; i++) cout << ans[i] << ' ';
		// cout << a.size() << "  " << ans.size() << endl;
		cout << endl;
	}
	return 0;
}