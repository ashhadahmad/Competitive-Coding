#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll num;
	cin >> num;
	string ans = "";
	while(num > 0) {
		num--;
		ans += ('a' + (num % 26));
		num /= 26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}