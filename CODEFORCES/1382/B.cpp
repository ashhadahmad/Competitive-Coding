#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int count = 0;
	int i = 0;
	while(i < n && a[i++] == 1) count++;
	if(count == n) {
		if(n & 1) cout << "First\n";
		else cout << "Second\n";
		return;
	}
	if(count & 1) cout << "Second\n";
	else cout << "First\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}