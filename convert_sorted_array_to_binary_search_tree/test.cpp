#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "convert_sorted_array_to_binary_search_tree.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 2, 3, 4, 5, 6};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        draw_tree(solution.sortedArrayToBST(v), "1.dot");
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
