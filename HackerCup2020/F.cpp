#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<ll> bestAns(n,0);
	deque<int> dq;
	for(int i=1; i<=m && i<n; i++) {
		if(a[i] == 0) continue;
		while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
		dq.push_back(i);
	}
	for(int i=m+1; i<n; i++) {
		if(!dq.empty() && dq.front() == i-m-1) dq.pop_front();
		ll curBest = (dq.empty() ? -1 : a[dq.front()] + bestAns[dq.front()]);
		bestAns[i] = curBest;
		if(a[i] == 0) continue;
		while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
		dq.push_back(i);
	}
	for(int i=0; i<n; i++) cout << bestAns[i] << ' ';
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