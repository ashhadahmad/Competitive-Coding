#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	int temp = n;
	n += n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	
	for(int i = 1; i < n; i++) {
		pair<int, int> cur(i, a[i]);
		for(int j=i-1;j>=0; j--) {
			if(a[j] > cur.second) {
				cur.first = j;
				cur.second = a[j];
			}
		}
		cout << i - cur.first << ' ';
		if(i - cur.first > (temp/2)) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}