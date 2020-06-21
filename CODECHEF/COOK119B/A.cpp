#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n,b,m;
	cin >> n >> b >> m;

	vector<int> a(m);
	for(int i=0; i<m; i++) cin >> a[i];

	int count = 0;
	int last = -1;
	for(int i=0; i<m; i++){
		if(last != (a[i]/b)) {
			last = a[i]/b;
			++count;
		}
	}
	cout << count << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}