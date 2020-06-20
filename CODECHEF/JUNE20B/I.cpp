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
	int n;
	cin >> n;
	int l = 1, r = n;
	while(l <= r){
		int mid = l + ((r - l) >> 1);
		char last = 'A';
		char cur = 'B';
		while(cur != last){
			cout << mid << endl;
			last = cur;
			cin >> cur;
			if(cur == 'E') return;
		}
		if(cur == 'L') r = mid - 1;
		if(cur == 'R') l = mid + 1;
	}
}

int main(){
	FASTIO(); 
	localIO();
	int t = 1; 
	// cin >> t;
	while(t--) 
		solve();
	return 0;
}