#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

//https://www.codechef.com/LTIME84B/problems/CONVSTR

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	vector<int> occA(26,-1);
	vector<vector<int> > ans(n);
	for(int i=0; i<n; i++) ans[i].push_back(i);

	for(int i=0; i<n; i++){
		char x = a[i];
		if(occA[x-'a'] == -1) occA[x-'a'] = i;
	}

	for(int i=0; i<n; i++){
		if(a[i] < b[i]){
			cout << "-1\n";
			return;
		}
		if(a[i] > b[i]){
			int ch = b[i] - 'a';
			if(occA[ch] == -1){
				cout << "-1\n";
				return;
			}
			else{
				ans[occA[ch]].push_back(i);
			}
		}
	}

	int ansLen = 0;
	for(int i=0; i<n; i++){
		if(ans[i].size() > 1) ++ansLen;
	}
	cout << ansLen << endl;
	for(int i=25; i>=0; i--){
		if(occA[i] == -1) continue;
		auto &p = ans[occA[i]];
		if(p.size() > 1){
			cout << p.size() << " ";
			sort(p.begin(), p.end());
			for(auto x: p) cout << x << " ";
			cout << "\n";
		}
	}
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