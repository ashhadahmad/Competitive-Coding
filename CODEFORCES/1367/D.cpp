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

void f(int n, vector<int> &occ, vector<int> &v, vector<char> &ans){

	set<int> zeroVertex;
	int count = 0;
	for(int i=0; i<n; i++){
		if(v[i] == 0){
			zeroVertex.insert(i);
			++count;
		}
	}

	if(count == 0) return;

	int bestIdx;
	for(bestIdx = 25; bestIdx>=0; bestIdx--){
		if(occ[bestIdx] >= count) {
			occ[bestIdx] = -1;
			break;
		}
		else{
			occ[bestIdx] = -1;
		}
	}

	char bestChar = bestIdx + 'a';

	for(auto x: zeroVertex){
		ans[x] = bestChar;
	}	

	for(auto x: zeroVertex){
		for(int i=0; x-i >= 0; i++){
			if(v[x-i] > 0) v[x-i] -= i;
		}
		for(int i=0; x+i < n; i++){
			if(v[x+i] > 0) v[x+i] -= i;
		}
	}

	for(auto x: zeroVertex){
		v[x] = -1;
	}

	f(n,occ,v,ans);
}

void solve(){
	string s;
	int n;
	cin >> s >> n;
	vector<int> v(n);
	vector<char> ans(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	vector<int> occ(26, 0);
	for(char c: s){
		occ[c-'a']++;
	}

	f(n, occ, v, ans);

	for(int i=0; i<n; i++){
		cout << ans[i];
	}
	cout << '\n';
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