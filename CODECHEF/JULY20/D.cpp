#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll n, q;
	cin >> n >> q;
	vector<ll> heights(n), taste(n);
	for(ll i=0; i<n; i++) cin >> heights[i];
	for(ll i=0; i<n; i++) cin >> taste[i];	
	while(q--) {
		ll t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			--x; 
			taste[x] = y;
		}
		else {
			--x, --y;
			stack<ll> st;
			st.push(x);
			bool bad = false;
			if(x <= y) {
				for(ll i=x+1; i<=y; i++) {
					while(!st.empty() && heights[st.top()] <= heights[i]) st.pop();
					if(st.empty()) {
						bad = true;
					}
					st.push(i);
				}
				if(bad) cout << "-1\n";
				else {
					ll ans = 0;
					while(!st.empty()) {
						// cout << st.top() + 1<< " ";
						ans += taste[st.top()];
						st.pop();
					}
					cout << ans << "\n";
				}
			}
			else {
				for(ll i=x-1; i>=y; i--) {
					while(!st.empty() && heights[st.top()] <= heights[i]) st.pop();
					if(st.empty()) {
						bad = true;
					}
					st.push(i);
				}
				if(bad) cout << "-1\n";
				else {
					ll ans = 0;
					while(!st.empty()) {
						// cout << st.top() + 1<< " ";
						ans += taste[st.top()];
						st.pop();
					}
					cout << ans << "\n";
				}
			}
		}
	}
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}