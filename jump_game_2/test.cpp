#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "jump_game_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {2, 3, 1, 1, 4};
        int n = sizeof(a) / sizeof(a[0]);

        cout << solution.jump(a, n) << endl;;
    }
	
    //Error test cases from leetcode.com
    {
        int a[] = {9,4,5,4,1,8,1,2,0,7,8,7,0,6,6,1,1,2,5,0,9,8,4,7,9,6,8,1,4,0,8,5,5,3,9,8,1,2,2,3,0,1,3,2,7,9,3,0,1};
        int n = sizeof(a) / sizeof(a[0]);

        cout << solution.jump(a, n) << endl;;
    }
	
	
	return 0;
}
