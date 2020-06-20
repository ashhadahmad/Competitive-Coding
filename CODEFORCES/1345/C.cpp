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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a) cin >> x;
	set<int> s;
	for(int i=0; i<2*n; i++){
		if(s.count(a[(i%n)] + i)){
			printf("NO\n"); return;
		}
		s.insert(a[(i%n)] + i);
	}
	printf("YES\n"); return;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}