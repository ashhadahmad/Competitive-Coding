#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const int mxN = (int) 1e5 + 10; 
vector<int> depth(mxN, 0);
vector<int> bestSum(mxN, 0);

void precompute() {
	depth[1] = 1;
	bestSum[1] = 0;
	for(int i=2; i<mxN; i++) {
		if(i&1) {
			depth[i] = depth[(i >> 1)] + 1;
			bestSum[i] = bestSum[i-1] + depth[i] - 1;
		}
		else bestSum[i] = bestSum[i-1];
	}
}

int main(){
	IOS;
	precompute();
	
	int t;
	cin >> t;
	while(t--) {
		int q; 
		cin >> q;
		cout << bestSum[q] << "\n";
	}
	return 0;
}