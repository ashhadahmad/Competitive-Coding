#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

vector<int> f(int n, string s) {
	vector<int> ans;
	bool cur = 0;
	for(int i=n-1; i>=0; i--) {
		if((s[i] - '0') != cur) {
			cur ^= 1;
			ans.push_back(i);
		}
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<int> ans = f(n,a);
	vector<int> ans2 = f(n,b);
	cout << ans.size() + ans2.size() << ' ';
	reverse(ans.begin(), ans.end());
	for(auto x: ans) cout << x + 1 << ' ';
	for(auto x: ans2) cout << x + 1 << ' ';
	cout << '\n';
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}