// Neat quick sort implementation. Use a replace pointer to swap elements
// Sorting in ascending order

#include <vector>
#include <iostream>

using namespace std;

void quickSort(vector<int> &nums, int start, int end) {
	if(start >= end)
		return;

	int boundary = start, pivot = nums[end];
	for(int i=start; i<end; i++) {
		if(nums[i] < pivot)
			swap(nums[i], nums[boundary++]);
	}
	swap(nums[end], nums[boundary]);
	quickSort(nums, start, boundary-1);
	quickSort(nums, boundary+1, end);
}

void printVector(const vector<int> &nums) {
	for(int n : nums)
		cout << n << " ";
	cout << endl;
}

int main() {
	vector<int> nums = {4, 3, 7, 6, 8, 1, 9, 0, 2, 5};
	printVector(nums);
	quickSort(nums, 0, nums.size()-1);
	printVector(nums);
}
