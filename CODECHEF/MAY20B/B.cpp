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
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> cnt(26,0);
	for(char c: s){
		++cnt[c-'a'];
	}
	while(q--){
		int c;
		cin >> c;
		int wait = 0;
		for(int i=0; i<26; i++) wait += max(0, cnt[i] - c);
		cout << wait << endl;
	}
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}