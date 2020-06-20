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

int main(){
	FAST(); 
	lol();
	// int t; cin >> t; while(t--){
		
	// }
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i=0; i<n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<pair<int, int> > vp;
	for(auto x: mp) vp.push_back(make_pair(x.second, x.first));
	sort(vp.begin(), vp.end());
	reverse(vp.begin(), vp.end());
	int i =0, cur_sum = 0;
	for(;i<vp.size() && cur_sum < (n >> 1); i++) cur_sum += vp[i].first;
	cout << i << endl;
	return 0;
}