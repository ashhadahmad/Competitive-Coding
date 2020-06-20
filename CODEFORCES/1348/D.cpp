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
	ll n;
	cin >> n;
	vector<int> ans;
	for(int i=1; i<=n; i*=2){
		ans.push_back(i);
		n -= i;
	}

	if(n > 0){
		ans.push_back(n);
		sort(ans.begin(), ans.end());
	}
	cout << ans.size() - 1 << '\n';
	for(int i=1; i<ans.size(); i++) cout << ans[i] - ans[i-1] << " ";
	cout << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}