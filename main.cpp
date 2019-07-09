#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/fair-candy-swap/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ex;
        set<int> inB;
        int suma = 0;
        int sumb = 0;
        for (auto& i : A) suma += i;
        for (auto& i : B) {
            inB.insert(i);
            sumb += i;
        }
        int need = (suma + sumb) / 2 - suma;
        for (int i = 0; i < A.size(); ++i) {
            int toget = need + A[i];
            if (inB.count(toget)) {
                return vector<int>{A[i], toget};
            }

        }
        assert(false && "Should never get here");
        return vector<int>{-1, -1};
    }
};

void test1() {
    vector<int> v1{1,1};
    vector<int> v2{2,2};

    cout << " [1,2] ? " << Solution().fairCandySwap(v1, v2) << endl;

    vector<int> v3{1,2};
    vector<int> v4{2,3};

    cout << " [1,2] ? " << Solution().fairCandySwap(v3, v4) << endl;

    vector<int> v5{2};
    vector<int> v6{1,3};

    cout << " [2,3] ? " << Solution().fairCandySwap(v5, v6) << endl;

    vector<int> v7{1,2,5};
    vector<int> v8{2,4};

    cout << " [5,4] ? " << Solution().fairCandySwap(v7, v8) << endl;
}

void test2() {

}

void test3() {

}