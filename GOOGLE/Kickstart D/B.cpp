#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int up = 0, down = 0;
	for(int i=0;)
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	for(int i=1; i<=t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}