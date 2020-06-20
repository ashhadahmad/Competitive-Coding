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

// void solve(){
// 	int n, k;
// 	cin >> n >> k;
// 	vector<int> a(n);
// 	for(int i=0; i<n; i++) cin >> a[i];
// 	vector<int> longest(n,1);
// 	for(int i=1; i<n; i++) {
// 		if(a[i-1] == a[i] + 1) {
// 			longest[i] = longest[i-1] + 1;
// 		}
// 	}
// 	int ans = 0 ;
// 	for(int i=0; i<n; i++) {
// 		if(a[i] == 1 && longest[i] >= k) ++ans;
// 	}
// 	cout << ans << endl;
// }

int main(){
	// FAST(); 
	// lol();
	int t; cin >> t;
	for(int i=1; i<=t; i++) {
		printf("Case #%d: ",i);
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		vector<int> longest(n,1);
		for(int i=1; i<n; i++) {
			if(a[i-1] == a[i] + 1) {
				longest[i] = longest[i-1] + 1;
			}
		}
		int ans = 0 ;
		for(int i=0; i<n; i++) {
			if(a[i] == 1 && longest[i] >= k) ++ans;
		}
		cout << ans << endl;
	}
	return 0;
}