#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "trapping_rain_water.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

        cout << solution.trap(a, sizeof(a) / sizeof(a[0])) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
