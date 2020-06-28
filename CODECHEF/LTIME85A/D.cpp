#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> parent(n+1);
	for(int i=0; i<=n; i++) parent[i] = i;
	while(q--) {
		int l,r;
		cin >> l >> r;
		for(int i=0; i<=(r-l); i++) {
			if(l+i >= r-l) break;
			else {
				int temp = l+i;
				if(temp != parent[temp]) while(temp != parent[temp]) temp = parent[temp];
				parent[temp] = r-i;
			}
		}

		set<int> s;
		for(int i=1; i<=n; i++) {
			int temp = i;
			while(parent[temp] != temp) temp = parent[temp];
			s.insert(temp);
		}
		cout << (int) s.size() << "\n";
	}
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}