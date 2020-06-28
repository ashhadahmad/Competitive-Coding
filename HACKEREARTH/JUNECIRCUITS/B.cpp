#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int count = 0;
	
	for(int i=0; i<n; i++){
		bool isswap = false;
		for(int j=1; j<n; j++) {
			if(a[j] < a[j-1]) {
				swap(a[j], a[j-1]);
				isswap = true;
			}
		}
		if(!isswap) break;
		else count++;
	}
 
	cout << 1 + count << "\n";
}
 
int main(){
	int t = 1; 
	// cin >> t; 
	while(t--){
		solve();
	}
	return 0;
}