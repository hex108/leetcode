#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "set_matrix_zeroes.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[][4] = {
            {1, 0, 0, 1},
            {0, 1, 1, 1},
            {1, 1, 1, 1}
        };
        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 3, 4);

        solution.setZeroes(v);
        print_vector_vector(v);
    }
	
    //Error test cases from leetcode.com
    {
        // column_record is not clear at the beginning.
        int a[][3] = {
            {2147483647, 2, 9},
            {2, 6, 7},
            {1, 8, 8},
            {5, 0, 1},
            {9, 6, 0},
        };
        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 5, 3);

        solution.setZeroes(v);
        print_vector_vector(v);
    }
	
	
	return 0;
}
