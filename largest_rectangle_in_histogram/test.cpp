#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "largest_rectangle_in_histogram.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {2, 1, 5, 6, 2, 3};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        cout << solution.largestRectangleArea(v) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        int a[] = {4, 2, 0, 3, 2, 5};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        cout << solution.largestRectangleArea(v) << endl;
    }
	
	
	return 0;
}
