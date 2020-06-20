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
	for(int i=0; i<n; i++) cin >> a[i];
	unordered_set<int> s;
	vector<int> store(n,0);
	for(int i=0; i<n; i++){
		if(!s.count(a[i])){
			s.insert(a[i]);
			if(i > 0 && a[i] < a[i-1]) store[i] = store[i-1]+1;
		}
	}

	for(int i=0; i<n; i++) cout << store[i] << " ";

	cout << *max_element(store.begin(), store.end()) + 1 << endl; 
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}