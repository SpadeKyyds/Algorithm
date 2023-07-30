#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        int a, b = 1;
        for (int i = 0; i < number; ++i) {
            a = b;
            b = 2 * a;
        }
        return a;
    }
};