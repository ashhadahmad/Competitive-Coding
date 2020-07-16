#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const int mxN = (int)1e7+10;
int bestAns[mxN];
int nextClose[mxN];

void solve(){
	string s; 
	cin >> s;
	int idx = -1;
	for(int i=s.size() - 1; i >= 0; i--) {
		if(s[i] == ')') {
			nextClose[++idx] = i;
			if(i == s.size() - 1) bestAns[i] = -1;
			else bestAns[i] = bestAns[i+1];
		}
		else {
			if(idx == -1) {
				bestAns[i] = -1;
			}
			else {
				bestAns[i] = nextClose[idx--];
			}
		}
	}


	int q; 
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(bestAns[x-1] != -1) cout << bestAns[x-1] + 1 << " ";
		else cout << -1 << " ";
	}
	cout << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}