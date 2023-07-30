#include <iostream>
using namespace std;

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