#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "rotate_image.h"

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

        print_vector_vector(v);
        solution.rotate(v);
        cout << "=>" << endl;
        print_vector_vector(v);
    }
	
    {
        int a[][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 4, 4);

        print_vector_vector(v);
        solution.rotate(v);
        cout << "=>" << endl;
        print_vector_vector(v);
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
