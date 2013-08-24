#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "merge_sorted_array.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    int a1[100] = {1, 6, 9};
    int b1[] = {2, 4, 7};
    solution.merge(a1, 3, b1, 3);
    print_arr(a1, 6);
	
    int a2[100] = {9, 6, 1};
    int b2[] = {7, 4, 2};
    solution.merge(a2, 3, b2, 3);
    print_arr(a2, 6);
	
    int a3[100] = {1, 6, 9};
    int b3[] = {7, 4, 2};
    solution.merge(a3, 3, b3, 3);
    print_arr(a3, 6);
	
    int a4[100] = {9, 6, 1};
    int b4[] = {2, 4, 7};
    solution.merge(a4, 3, b4, 3);
    print_arr(a4, 6);
	
    //Error test cases from leetcode.com
    /* Just a mismatch, I use a >= b, the system use a > b.
     */
    int a5[100] = {1};
    int b5[] = {2};
    solution.merge(a5, 1, b5, 1);
    print_arr(a5, 2);
	
    int a6[100] = {};
    int b6[] = {1, 2, 3 ,4 , 5};
    solution.merge(a6, 0, b6, 5);
    print_arr(a6, 5);
	
	return 0;
}
