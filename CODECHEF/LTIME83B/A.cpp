#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
// Chef in Fantasy League
void localio(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

const int mod = 998244353;

void solve(){
	int n,s;
	cin >> n >> s;
	vector<int> inp(n);
	for(int i=0; i<n; i++) {
		cin >> inp[i];
	}
	bool ans = true; 
	vector<int> def, forw;
	for(int i=0; i<n; i++){
		int check; cin >> check;
		if(check) forw.push_back(inp[i]);
		else def.push_back(inp[i]);
	}

	sort(def.begin(),  def.end());
	sort(forw.begin(), forw.end());

	if(def.size() == 0 || forw.size() == 0){
		cout << "no\n";
		return;
	}

	if(def[0] + forw[0] + s <= 100) ans = true;
	else ans = false;
	cout << ((ans) ? "yes\n" : "no\n");
}

int main(){
	FAST(); 
	localio();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}