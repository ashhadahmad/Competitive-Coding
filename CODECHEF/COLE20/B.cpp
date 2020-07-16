#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	set<int> s;
	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
		s.insert(v[i]);
	}
	sort(v.begin(), v.end());
	int q;
	cin >> q;
	while(q--) {
		int a,b;
		cin >> a >> b;
		if(s.count(a+b)) {
			cout << "-1\n";
			continue;
		}
		else {
			auto dif = upper_bound(v.begin(), v.end(), a+b) - v.begin();
			cout << dif << "\n";
		}
	}

}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}