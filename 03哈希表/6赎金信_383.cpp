/**
 * 难度：简单
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

    如果可以，返回 true ；否则返回 false 。

    magazine 中的每个字符只能在 ransomNote 中使用一次。

    // ！！！重点：ransomNote 和 magazine 由小写英文字母组成
    
    
     

    示例 1：

    输入：ransomNote = "a", magazine = "b"
    输出：false
    示例 2：

    输入：ransomNote = "aa", magazine = "ab"
    输出：false
    示例 3：

    输入：ransomNote = "aa", magazine = "aab"
    输出：true
     

    提示：

    1 <= ransomNote.length, magazine.length <= 105
    // ！！！重点：ransomNote 和 magazine 由小写英文字母组成

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/ransom-note
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 此题较为简单 使用ordered_map解决 时间复杂度O(n+m) 空间复杂度O(n) 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> u_map;
        for (auto ch : magazine) {
            if (u_map.find(ch) != u_map.end()) {
                ++u_map[ch];
            } else {
                u_map.insert(pair<char, int>(ch, 1));
            }
        }
        for (auto ch : ransomNote) {
            if (u_map.find(ch) != u_map.end()) {
                if (--u_map[ch] < 0) return false;
            } else return false;
        }
        return true;
    }
};

// 在可以使用数组的情况下 还是推荐使用数组 在数据量增加的时候 数组相对于map的优势就可体现出来
// 本题有个关键 说明里有提到 ransomNote和magazine内均为小写字母
class Solution1 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.length() < ransomNote.length()) return false;
        int magazineArray[26] = {0};
        for (auto ch : magazine) {
            ++magazineArray[ch - 'a'];
        }
        for (auto ch : ransomNote) {
            if (--magazineArray[ch - 'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    string ransomNote = "hahahhaha";
    string magazine = "nihaohahanihao nnhahha";
    if (s.canConstruct(ransomNote, magazine)) {
        cout << "ransomNote can be constructed by magazine." << endl;
    } else {
        cout << "ransomNote can't be constructed by magazine!" << endl;
    }
    return 0;
}