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
	for(auto &x: a) cin >> x;
	int mn = 10, mx = 0, count = 1;
	for(int i=1; i<n; i++){
		if(a[i] - a[i-1] > 2){
			mn = min(mn, count);
			mx = max(mx, count);
			count = 1; 
		}
		else ++count;
	}

	mn = min(mn, count);
	mx = max(mx, count);
	printf("%d %d\n", mn, mx);
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}