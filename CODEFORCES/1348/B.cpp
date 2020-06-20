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
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	set<int> s;
	for(auto x:a) s.insert(x);
	if(s.size() > k) {
		cout << "-1\n";
		return;
	}
	int i = 0;
	vector<int> ans;
	map<int, bool> vis;
	for(int i=0; i<n; i++){
		if(!vis[a[i]]) ans.push_back(a[i]);
		vis[a[i]] = true;
	}
	int mx = *max_element(s.begin(), s.end());
	while(ans.size()  < k){
		ans.push_back(mx);
	}

	cout << ans.size() * n << endl;
	for(int i=0; i<n; i++) for(auto x: ans) cout << x << " ";
	cout << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}