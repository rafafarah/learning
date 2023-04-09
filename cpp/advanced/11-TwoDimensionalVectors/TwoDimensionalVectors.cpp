//============================================================================
// Name        : 31-TwoDimensionalVectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> grid(3, vector<int>(4, 0));

	// Makes second row longer than the others
	grid[1].push_back(8);

	for (unsigned int row = 0; row < grid.size(); ++row) {
		for (unsigned int col = 0; col < grid[row].size(); ++col) {
			cout << grid[row][col] << flush;
		}
		cout << endl;
	}

	return 0;
}
