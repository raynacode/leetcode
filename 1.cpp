#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

	vector<int> res(2);
	if (nums.size() < 2)
		return res;

	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		if (map.find(target - nums[i]) != map.end() && map[target - nums[i]] < i) {
			res[0] = map[target - nums[i]] + 1;
			res[1] = i + 1;
			break;
		}
		map[nums[i]] = i;
	}
	return res;
}

int main() {
	vector<int> nums(4);
	nums[0] = 0;
	nums[1] = 4;
	nums[2] = 3;
	nums[3] = 0;
	vector<int> res = twoSum(nums, 0);
	cout << res[0] << " " << res[1] << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

