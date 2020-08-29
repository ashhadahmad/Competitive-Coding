#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

// void localIO(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// 	#endif	
// }

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<ll> bestAns(n,0);
	deque<int> dq;
	for(int i=m+1; i<n; i++) {
		ll curBest = -1;
		for(int j=1; j<=m; j++) {
			if((i - j) < 0) curBest = 0;
			else if(a[i-j] == 0 || bestAns[i-j] == -1) continue;
			else if(curBest == -1) curBest = bestAns[i-j] + a[i-j];
			else curBest = min(curBest, bestAns[i-j] + a[i-j]);
		}
		bestAns[i] = curBest;
	}
	cout << bestAns[n-1] << '\n';
}

int main(){
	// localIO();
	IOS;
	int t = 1; 
	cin >> t;
	for(int i=0; i<t; i++) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}