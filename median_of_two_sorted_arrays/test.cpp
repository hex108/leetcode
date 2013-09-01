#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "median_of_two_sorted_arrays.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int A[] = {1, 8, 10, 15, 20};
        int B[] = {2, 8, 11, 12, 23, 24}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }
	
    {
        int A[] = {1, 8, 10, 15, 20, 21};
        int B[] = {2, 8, 11, 12, 23, 24}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }

    {
        int A[] = {1, 8};
        int B[] = {2, 8, 11, 12, 23, 24}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }

    {
        int A[] = {1};
        int B[] = {2, 8, 11, 12, 23, 24}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }

    //Error test cases from leetcode.com
    {
        int A[] = {1, 2, 3};
        int B[] = {1, 2}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }

    {
        int A[] = {1, 2, 2};
        int B[] = {1, 2, 3}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }

    {
        int A[] = {2};
        int B[] = {1, 3, 4}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }

    {
        int A[] = {1, 2, 5, 6};
        int B[] = {3, 4, 7, 8, 9, 10}; 
        cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])) << endl;
    }

	
	return 0;
}
