#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void push(int value) {
        vec.push_back(value);
    }
    void pop() {
        vec.pop_back();
    }
    int top() {
        return *(vec.end() - 1);
    }
    int min() {
        return *min_element(vec.begin(), vec.end());
    }

private:
    vector<int> vec;
};