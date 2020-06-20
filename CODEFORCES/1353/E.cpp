//https://codeforces.com/contest/1353/problem/E
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
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	vector<string> store(k,"");
	int totalOnes = 0;
	vector<int> subOnes(k, 0);
	for(int i=0; i<n; i++){
		int temp_idx = i%k;
		store[temp_idx] += s[i];
		if(s[i] == '1'){
			++totalOnes;
			++subOnes[temp_idx];
		}
	}

	int final_ans = totalOnes;

	for(int p=0; p<k; p++){
		// cout << "-------\n";
		int temp_ans = subOnes[p];
		int size = store[p].size();
		int pre = 0;
		vector<int> prefix(size), dp(size);
		for(int i=0; i<size; i++){
			pre += store[p][i] == '1';
			prefix[i] += pre;
		}
		for(int i=0; i<size; i++){
			if(i == 0) {
				dp[i] = store[p][i] == '0';
			}
			else {
				dp[i] = store[p][i] == '0' + min(dp[i-1], prefix[i-1]);
			}
			temp_ans = min(temp_ans, subOnes[p] - prefix[i] + dp[i]);
		}
		final_ans = min(final_ans, totalOnes - subOnes[p] + temp_ans);
	}

	cout << final_ans << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}
