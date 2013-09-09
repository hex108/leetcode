#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "container_with_most_water.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {3, 8, 3, 4, 6};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        cout << solution.maxArea(v) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
