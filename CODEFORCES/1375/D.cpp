#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<int> badIdx;
	
	vector<int> has(n,0);
	for(int i=0; i<n; i++) has[a[i]]++;

	for(int i=0; i<n; i++) {
		if(a[i] != i) badIdx.push_back(i);
	}

	vector<int> ans;

	for(int i=0; i<(2 * n); i++) {
		int mex = n;
		for(int j=0; j<n; j++) {
			if(has[i] == 0) {
				mex = i;
				break;
			}
		}
	}

	cout << ans.size() << '\n';
	for(auto x: ans) cout << x << " ";
	cout << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}