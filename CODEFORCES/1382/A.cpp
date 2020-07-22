#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	set<int> a;
	vector<int> b(m);
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.insert(x);
	}
	for(int i=0; i<m; i++) cin >> b[i];
	for(int i=0; i<m; i++) {
		if(a.count(b[i])) {
			printf("YES\n1 %d\n",b[i]);
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}