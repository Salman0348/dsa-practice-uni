#include <iostream>
#include <vector>

int findDuplicate(const std::vector<int>& nums) {
    int n = nums.size();
    int xorResult = 0;

    // XOR all elements in the array
    for (int i = 0; i < n; ++i) {
        xorResult ^= nums[i];
    }

    // XOR with numbers from 1 to n-1
    for (int i = 1; i < n; ++i) {
        xorResult ^= i;
    }

    return xorResult;
}

int main() {
    std::vector<int> nums = {1, 2, 4, 6, 6}; // Example array with a duplicate 2
    int duplicate = findDuplicate(nums);

    std::cout << "Duplicate number is: " << duplicate << std::endl;

    return 0;
}