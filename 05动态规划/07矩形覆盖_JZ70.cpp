#include <iostream>
using namespace std;

// 这题其实就是一个斐波那契问题 不知道规律就不知道怎么做
class Solution {
public:
    int rectCover(int number) {
        if (number < 3) return number;
        int n1 = 1, n2 = 2, n3;
        for (int i = 3; i <= number; ++i) {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
};