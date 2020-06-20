#include <bits/stdc++.h>
 
using namespace std;
 
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};
 
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, t;
  cin >> h >> w >> t;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  vector<vector<int> > when(h, vector<int>(w, -1));
  vector<pair<int, int> > que;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int dir = 0; dir < 4; dir++) { 
        int ni = i + di[dir];
        int nj = j + dj[dir];
        if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
          if (s[ni][nj] == s[i][j]) {
            que.push_back(make_pair(i, j));
            when[i][j] = 0;
            break;
          }
        }
      }
    }
  }

  for(auto x: que){
    cout << x.first << " " << x.second << endl;
  }


  // for (int b = 0; b < (int) que.size(); b++) {
  //   int i = que[b].first;
  //   int j = que[b].second;
  //   for (int dir = 0; dir < 4; dir++) { 
  //     int ni = i + di[dir];
  //     int nj = j + dj[dir];
  //     if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
  //       if (when[ni][nj] == -1) {
  //         que.push_back(make_pair(ni, nj));
  //         when[ni][nj] = when[i][j] + 1;
  //       }
  //     }
  //   }
  // }


  // for(auto x: when){
  //   for(auto y: x) cout << y << " ";
  //   cout << endl;
  // }

  // while (t--) {
  //   int i, j;
  //   long long p;
  //   cin >> i >> j >> p;
  //   --i; --j;
  //   if (when[i][j] == -1 || p < when[i][j] || (p - when[i][j]) % 2 == 0) {
  //     cout << s[i][j] << '\n';
  //   } else {
  //     cout << (char) (s[i][j] ^ 1) << '\n';
  //   }
  // }
  return 0;
}