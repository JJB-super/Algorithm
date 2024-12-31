#include"Solution.h"
#include <fstream>
int main()
{
	Solution test;
	//vector<vector<int>> input = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<vector<int>> input = { {5,1,9,11},
								  {2,4,8,10},
								  {13,3,6,7},
								  {15,14,12,16} 
								};
	vector<int> res;
	test.rotate(input);
	for (const auto& row : input) {
		for (const auto& element : row) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}