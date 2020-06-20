#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int i;
	for(i=n; i >= 0; i--){
		if(k % i == 0) break;
	}

	vector<pair<int, int> > freq(26);
	for(int i=0; i<26; i++) freq[i].second = i;
	for(auto x: s) freq[x-'a'].first++;

	sort(freq.begin(), freq.end());

	cout << i << endl;
}

int main(){
	FASTIO(); 
	localIO();
	int t; 
	cin >> t;
	while(t--) 
		solve();
	return 0;
}