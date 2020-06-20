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

bool check(vector<int> a, int size1, int size2){ 
	set<int> s1;
	set<int> s2;
	// cout << size1 << " " << size2 << endl;
	// for(int i=0; i<size1; i++) cout << a[i] << " ";
	// cout << endl;
	// for(int i=size1; i<size1 + size2; i++) cout << a[i] << " ";
	// cout << endl;
	for(int i=0; i<size1; i++){
		if(s1.count(a[i])) return false;
		s1.insert(a[i]);
	}
	for(int i=size1; i<size1 + size2; i++) {
		if(s2.count(a[i])) return false;
		s2.insert(a[i]);
	}
	for(auto x: s1){
		if(x == 1) continue;
		else if(!s1.count(x-1)) return false;
	}
	for(auto x: s2){
		if(x == 1) continue;
		else if(!s2.count(x-1)) return false;
	}
	return true;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a) cin >> x;
	int ma = *max_element(a.begin(), a.end());
	
	vector<pair<int, int> > ans;
	if(check(a,n-ma, ma)) {
		ans.push_back(make_pair(n-ma,ma));
	}

	if(ma != n-ma){
		if(check(a,ma,n-ma)) {
			ans.push_back(make_pair(ma,n-ma));
		}
	}
	cout << ans.size() << endl;
	for(auto x: ans) cout << x.first << " " << x.second << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}