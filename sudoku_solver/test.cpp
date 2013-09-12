#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "sudoku_solver.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        // true
        char arr[][9] = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
        };
        vector<vector<char> > v;
        arr_of_arr_to_vec(v, arr[0], 9, 9);

        solution.solveSudoku(v);
        print_vector_vector(v);
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
