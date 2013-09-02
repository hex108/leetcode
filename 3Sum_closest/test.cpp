#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "3Sum_closest.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {-1, 2, 1, -4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 1;
        cout << solution.threeSumClosest(v, target) << endl;
    }
	
    {
        int a[] = {-1, 2, 1, -4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 2;
        cout << solution.threeSumClosest(v, target) << endl;
    }
	
    {
        int a[] = {-1, 2, 1, 8, 2, 3,-4, 8, 8};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 25;
        cout << solution.threeSumClosest(v, target) << endl;
    }
	
    //Error test cases from leetcode.com

	
	return 0;
}
