#include <bits/stdc++.h>

using namespace std;

// these are the four adjacent cells:
                       
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

// dx[0], dy[0] = (1, 0) = x + 1
// dx[1], dy[1] = (0, 1) = y + 1
// dx[2], dy[2] = (-1, 0) = x + 1
// dx[3], dy[3] = (0, -1) = y - 1

int AdjacentCells(int i, int j, int r, int c) {
	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		// check the four adjacent cells:
		// if k = 0 -> it's checking x + 1
		// if k = 1 -> it's checking y + 1
		// if k = 2 -> it's checking x - 1
		// if k = 3 -> it's checking y - 1
		int x = dx[k] + i;
		int y = dy[k] + j;
		// if it goes beyond the row or column, then don't increment the counter
		if (x < 1 || y < 1 || x > r || y > c) {
			continue;
		}
		cnt++;
	}
	return cnt;
}

int main() {                            
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
  	int r, c;
  	cin >> r >> c;
  	// view the second image in this repository for better understanding
  	vector<vector<int>> v(r + 1, vector<int> (c + 1, 0));
  	for (int i = 1; i <= r; i++) {
  		for (int j = 1; j <= c; j++) {
  			cin >> v[i][j];
  		}
  	}                                                                                      	
		bool is_stable = true;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				// check if the value inside the cell is less than the number of its adjacent cells
				is_stable = is_stable && (v[i][j] < AdjacentCells(i, j, r, c));
			}
		}		
		cout << (is_stable ? "Stable" : "Unstable") << '\n';
  }  
  return 0;
}      
