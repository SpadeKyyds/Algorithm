#include <iostream>
#include <vector>
using namespace std;

// 自创解法：反向遍历数组，遇到目标值将之和数组中最后一个元素交换，同时数组长度减一
// 时间复杂度O(n) 空间复杂度O(1)
// 在目标元素值占比较少的情况下优于快慢指针法，元素赋值操作次数较少，但元素乱序了，这是不足
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size() - 1;
        for (int i = len; i >= 0; --i) {
            if (nums[i] == val) {
                int temp = nums[i];
                nums[i] = nums[len];
                nums[len] = temp;
                --len;
            }
        }
        return ++len;
    }
};

// 快慢指针法
// 快指针：寻找新数组的元素，新数组即为不含目标元素的数组
// 慢指针：指向新数组
// 时间复杂度O(n) 空间复杂度O(1) 在数组、链表、字符串中应用频繁
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex; //这里不需要加一，因为最后一次赋值操作后自增了
    }
};

// 快慢指针优化 经典版本 时间复杂度O(n) 空间复杂度O(1)
// 基本思想：左指针从左往右扫描，右指针从右往左，当左指针扫描到目标值时，右指针指向的值赋给左指针指向的值，
// 右指针左移，当左指针指向的值不为目标值时，左指针右移，当左指针大于右指针时，结束循环，返回左指针索引即为新数组长度。
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int lIndex = 0, rIndex = nums.size() - 1;
        while (lIndex <= rIndex) {
            if (nums[lIndex] == val) {
                nums[lIndex] = nums[rIndex--];
            } else {
                ++lIndex;
            }
        }
        return lIndex;
    }
};

void print(vector<int>& nums, int len) {
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    Solution s;
    int len = s.removeElement(nums, 3);
    print(nums, len);

    return 0;
}