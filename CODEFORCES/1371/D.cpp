#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, k;
	cin >> n >> k;

	vector<int> row_total(n, k/n);
	for(int i=0; i<(k%n); i++) {
		++row_total[i];
	}
	
	int ptr = 0;

	vector<vector<int>> ans(n,vector<int>(n,0));

	for(int i=0; i<n; i++) {
		for(int j=0; j<row_total[i]; j++) {
			ans[i][ptr] = 1;
			++ptr;
			if(ptr == n) ptr = 0;
		}
	}

	vector<int> row_sum(n, 0);
	vector<int> col_sum(n, 0);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			row_sum[i] += ans[i][j];
			col_sum[j] += ans[i][j];
		}
	}

	int minrow = *min_element(row_sum.begin(), row_sum.end());
	int maxrow = *max_element(row_sum.begin(), row_sum.end());
	int mincol = *min_element(col_sum.begin(), col_sum.end());
	int maxcol = *max_element(col_sum.begin(), col_sum.end());

	int tt = ((maxcol - mincol) * (maxcol - mincol)) + (maxrow - minrow) * (maxrow - minrow);
	cout << tt << "\n";

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}