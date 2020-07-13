#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

int getBest(int n, vector<int> &a, int weight, int idx, map<pair<int, int>, int> &mp){
	if(idx == n) return 0;
	pair<int, int> p(idx, weight);
	if(mp[p]) return mp[p];
	int ans1 = getBest(n,a,weight,idx+1,mp);
	if(a[idx] <= weight) {
		int ans2 = a[idx] + getBest(n,a,weight-a[idx],idx+1,mp);
		mp[p] = max(ans1, ans2);
		return mp[p];
	}
	mp[p] = ans1;
	return mp[p];
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int w;
	cin >> w;
	map<pair<int, int>, int> dp;
	cout << getBest(n,a,w,0,dp) << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}