#include"Solution.h"
#include <fstream>
int main()
{
	Solution test;
	//vector<vector<int>> input = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<vector<int>> input = { {1,4,7,11,15} ,{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}
								};
	vector<int> res;
	//test.rotate(input);
	bool ans = test.searchMatrix(input, 5);
	/*for (const auto& row : input) {
		for (const auto& element : row) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}*/
	cout << ans << endl;
	return 0;
}