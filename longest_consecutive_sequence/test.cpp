#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "longest_consecutive_sequence.h"

using namespace std;

int main()
{
    Solution solution;

    //Test cases
    vector<int> v;
    
    int arr1[] = {-1, 0, 1, 5, 9, 6};
    INT_ARR_TO_VEC(v, arr1);
    cout << solution.longestConsecutive(v) << endl;

    int arr2[] = {2147483646, -2147483647, 200, 0, 2, 2147483644, -2147483645, 2147483645};
    INT_ARR_TO_VEC(v, arr2);
    cout << solution.longestConsecutive(v) << endl;

    //Error test cases from leetcode.com
    int arr3[] = {2147483646, -2147483647, 200, 0, 2, 2147483644, -2147483645, 2147483645};
    INT_ARR_TO_VEC(v, arr3);
    cout << solution.longestConsecutive(v) << endl;

    int arr4[] = {1, 3, 5, 2, 4};
    INT_ARR_TO_VEC(v, arr4);
    cout << solution.longestConsecutive(v) << endl;

    int arr5[] = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    INT_ARR_TO_VEC(v, arr5);
    cout << solution.longestConsecutive(v) << endl;

    return 0;
}
