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
	vector<int> a(n);
	for(auto&x: a) cin >> x;
	sort(a.begin(), a.end());
	int ans = 0;
	int want = 0, have = 0;
	for(int i=0; i<n; i++){
	// cout << want << " " << have << endl;
		if(have > 0 && want == have){
			have = want = 0;
			++ans;
		}
		want = max(want, a[i]);
		++have; 
	}
	if(have > 0 && want == have){
		++ans;
	}
	cout << ans << endl; 
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}