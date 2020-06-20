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

string led[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

map<string,vector<pair<int, int> > > mp;

vector<pair<int, int > > getNum(string s){
	vector<pair<int, int> > choices;
	for(int i=9; i>=0; i--){
		string cur = led[i];
		bool valid = true;
		int count = 0;
		for(int i=0; i<7; i++){
			if(s[i] == '1' && cur[i] == '0') {
				valid = false;
				break;
			}
			if(s[i] == '0' && cur[i] == '1'){
				count++;
			}
		}
		if(valid) choices.push_back(make_pair(i, count));
	}

	return choices;
}


void fill(string cur, int i){
	if(i == 7) {
		mp[cur] = getNum(cur);
		return;
	}
	fill(cur + "0", i + 1);
	fill(cur + "1", i + 1);
}


string f(int n, int k, vector<string> &v, vector<vector<string> > &dp, int i = 0){
	if(i == n && k == 0) return "";
	if(k < 0) return "-1";
	if(i == n) return "-1";
	if(dp[i][k] != "") return dp[i][k];
	for(auto x: mp[v[i]]) {
		string smallAns = f(n,k-x.second,v,dp,i+1);
		if(smallAns != "-1") {
			dp[i][k] = to_string(x.first) + smallAns;
			return dp[i][k];
		}
	}
	dp[i][k] = "-1";
	return dp[i][k];
}

// string f2(int n, int k, vector<string> &v){
// 	vector<vector<string> > dp(n+1, vector<string>(k+1, ""));
// 	for(int i = 0; i<=n; i++){
// 		for(int j=0; j<=k; j++){
// 			if(i+j == 0) dp[i][j] = "";
// 			else if(i+j == 1) dp[i][j] = "-1";
// 			else{
// 				for(auto x: mp[v[i-1]]){
// 					if(j - x.second < 0) dp[i][j] = "-1";
// 					else if(dp[i-1][j-x.second] == "-1") dp[i][j] = "-1";
// 					else{
// 						dp[i][j] = to_string(x.first) + dp[i-1][j-x.second];
// 						break;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return dp[n][k];
// }

void solve(){
	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	vector<vector<string> > dp(n+1, vector<string>(k+1, ""));
	// cout << f2(n, k, v) << "\n";
	cout << f(n,k,v,dp) << "\n";
}

int main(){
	FAST(); 
	lol();
	fill("", 0);
	solve();
	return 0;
}