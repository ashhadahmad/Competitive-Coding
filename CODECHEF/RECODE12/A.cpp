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
	int n;
	cin >> n;
	vector<int> v(n+1);
	for(int i=1; i<=n; i++) cin >> v[i];
	// for(int i=1; i<=n; i++) cout<< v[i] << " ";
	map<int, int> li;
	map<int, int> c;

	li[v[1]] = 1;
	++c[v[1]];

	for(int i=2; i<=n; i++){
		if(i - li[v[i]] > 1){
			++c[v[i]];
			li[v[i]] = i;
		}
	}

	int ans = -1, ans_count = -1;
	for(auto x: c){
		if(x.second > ans_count) {
			ans_count = x.second;
			ans = x.first;
		}
		// cout << x.first << " " << x.second << " ";
 	}
 	cout << ans << endl;
	
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}