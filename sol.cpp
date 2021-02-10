#include <bits/stdc++.h>

using namespace std;

int main() {                            
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
  	int r, c;
  	cin >> r >> c;
  	// view the image in this repository for better understanding
  	// create a two-dimensional array
  	vector<vector<int>> v(r, vector<int> (c, 0));
  	for (int i = 0; i < r; i++) {
  		for (int j = 0; j < c; j++) {
  			cin >> v[i][j];
  		}
  	}
  	bool checker = true;
  	for (int i = 0; i < r; i++) {
  		for (int j = 0; j < c; j++) {
  			if ((i > 0 && i < r - 1) && (j == 0 || j == c - 1)) {
  				// this is the cell if it's not in the first or last row and either in the first or last column
  				// the value of this must not be greater than 2 
  				if (v[i][j] > 2) {
  					checker = false;
  					break;
  				}
  			} else if ((i > 0 && i < r - 1) && (j > 0 && j < c - 1)) {
  				// this is the cell if it's not in the first or last row and not in the first or last column either
  				// the value of this must not be greater than 3
  			  if (v[i][j] > 3) {
  			  	checker = false;
  					break;
  			  }
  			} else if (j == 0 || j == c - 1) {
  				// this is the cell in all the corners of the array
  				// the value of this must not be greater than 1
  				if (v[i][j] > 1) {
  					checker = false;    	
  					break;
  				}
  			} else if (i == 0 || i == r - 1) {
  				// these are the cells located in the first or last row and between the first and last columns
  				// the value of this must not be greater than 2
  				if (v[i][j] > 2) {
  					checker = false;
  					break;
  				}
  			} 
  		}
  		if (!checker) {
  			break;
  		}
  	}
  	cout << (checker ? "Stable" : "Unstable") << '\n';
  }  
  return 0;
}      