#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "spiral_matrix.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 3, 3);

        print_vector(solution.spiralOrder(v));
    }
	
    //Error test cases from leetcode.com
    {
        int a[][2] = {
            {2, 3}
        };
        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 1, 2);

        print_vector(solution.spiralOrder(v));
    }
	
	
	return 0;
}
