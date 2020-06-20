#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n, b;
	cin >> n >> b;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int count = 0, i = 0;
	while(i < n){
		if(a[i] > b) break;
		b -= a[i];
		count++;
		i++;
 	}
 	k = 5;
 	printf("%d\n", count);
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}