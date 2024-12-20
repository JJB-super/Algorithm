#include"Solution.h"
#include <fstream>
int main()
{
	Solution test;
	vector<int> input = { 1,2,3,4,5,6,7 };
	test.rotate(input, 3);
	for (const auto &mem : input) {
		
			cout << mem << ',';
		
		
	}
	cout << endl;
	return 0;
}