#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "surrounded_regions.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char a[][4] = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
        };

        vector<vector<char> > v;
        arr_of_arr_to_vec(v, a[0], 4, 4);

        solution.solve(v);
        print_vector_vector(v);
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
