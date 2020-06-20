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
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	set<int> s(a.begin(), a.end());
	int cur = 1; auto it = s.begin(); 
	while(k >= 0 && it != s.end()){
		// cout << *it << " " << cur << endl;
		if(*it == cur){
			++it, ++cur;
		}
		else{
			++cur;
			--k;
		}
	}

	cout << cur + k - 1 << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}