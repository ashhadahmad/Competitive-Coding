#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	int count[2] = {0};
	while(n % 2 == 0) {
		count[0]++;
		n /= 2;
	}
	while(n % 3 == 0) {
		count[1]++;
		n /= 3;
	}

	if(n > 1 || count[0] > count[1]) {
		cout << "-1\n";
		return;
	}
	cout << count[1] + count[1] - count[0] << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}