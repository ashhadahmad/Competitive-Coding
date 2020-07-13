#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
		a[i]--;
		// cout << a[i] << " ";
	}
	bool works1 = true, works2 = true;
	
	for(int i=0; i<n; i++) {
		if(a[i] != i) {
			works1 = false;
			break;
		}
	}

	int left = 0, right = n-1;

	while(a[left] == left) ++left;
	while(a[right] == right) --right;

	// cout << left << " " << right << "\n";

	for(int i=left; i<=right; i++) {
		if(a[i] == i) {
			works2 = false;
			break;
		}
	}

	if(works1) cout << "0\n";
	else if (works2) cout << "1\n";
	else cout << "2\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}