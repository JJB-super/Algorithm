#include"Solution.h"
#include <fstream>
int main()
{
	Solution test;
	//vector<vector<int>> input = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<vector<int>> input = {{3},{2}};
	vector<int> res;
	res = test.spiralOrder(input);
	for (const auto &mem : res) {
		cout << mem << ',';
	}
	cout << endl;
	return 0;
}