#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

struct triplet{
	int x,y,z;
	triplet() {
		x = y = z = 0;
	}
	triplet(int a,int b,int c){
		x=a; y=b; z=c;
	}
};

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> both, left, right;
	for(int i=0; i<n; i++) {
		int time, l, r;
		cin >> time >> l >> r;
		if(l && r) both.push_back(time);
		else if(l) left.push_back(time);
		else if(r) right.push_back(time);
	}

	sort(both.begin(), both.end());
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	vector<int> bothSum(both.size() + 1, 0);
	for(int i=1; i<=both.size(); i++) {
		bothSum[i] = bothSum[i-1] + both[i-1];
	}

	vector<int> leftSum(left.size() + 1, 0);
	for(int i=1; i<=left.size(); i++) {
		leftSum[i] = leftSum[i-1] + left[i-1];
	}

	vector<int> rightSum(right.size() + 1, 0);
	for(int i=1; i<=right.size(); i++) {
		rightSum[i] = rightSum[i-1] + right[i-1];
	}

	int ans = -1;

	for(int i=0; i<=(min((int) both.size(), k)); i++) {
		int p = k - i;
		// cout << i << " " << p << endl; 
		if(left.size() < p || right.size() < p) continue;
		int tempans = bothSum[i] + leftSum[p] + rightSum[p];
		if(ans == -1) ans = tempans;
		ans = min(ans, tempans);
	}

	cout << ans;
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}