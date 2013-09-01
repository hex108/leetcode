/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
    int find(int arr[], int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        if(arr[start] >= target)
            return start;
        else
            return -1;
    }

    int get_min_and_modify_index(int A[], int &start_A, int end_A, int B[], int &start_B, int end_B){
        if(start_A <= end_A && start_B <= end_B){
            if(A[start_A] < B[start_B])
                return A[start_A ++];
            else
                return B[start_B ++];
        }
        
        if(start_A <= end_A)
            return A[start_A ++];
        else
            return B[start_B ++];
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        /* Suppose we merge two sorted array A and B to a sorted array C, then:
         * If (m + n) % 2 == 0, (C[target] + C[target + 1]) / 2 is the median. 
         * If (m + n) % 2 == 1, C[target] is the median. 
         * Note: converting to long long to inprevent overflow.
         */
        int target = ((long long)m + (long long)n - 1)/ 2;
        int remain = target;

        int start_A = 0, end_A = m - 1;
        int start_B = 0, end_B = n - 1;

        while(remain && end_A >= start_A && end_B >= start_B){
            int len1 = (end_A - start_A) / 2;
            int mid_A = start_A + len1;
            int len2 = (end_B - start_B) / 2;
            int mid_B = start_B + len2;
            
            if(A[mid_A] <= B[start_B]){
                len1 ++;  // include A[mid_A]
                if(len1 <= remain){
                    remain = remain - len1;
                    start_A = mid_A + 1;
                }else{
                    start_A = start_A + remain;
                    remain = 0;
                    break;
                }
            }else if(B[mid_B] <= A[start_A]){
                len2 ++;
                if(len2 <= remain){
                    remain = remain - len2;
                    start_B = mid_B + 1;
                }else{
                    start_B = start_B + remain;
                    remain = 0;
                    break;
                }
            }else{ 
                if(A[mid_A] <= B[mid_B]){
                    int index = find(B, start_B, mid_B, A[mid_A]);
                    int tmp = len1 + (index - start_B);
                    if(tmp <= remain){
                        remain = remain - tmp;
                        start_A = mid_A;
                        start_B = index;
                    }else{
                        end_B = index;
                    }
                }else{
                    int index = find(A, start_A, mid_A, B[mid_B]);
                    int tmp = len2 + (index - start_A);
                    if(tmp <= remain){
                        remain = remain - tmp;
                        start_A = index;
                        start_B = mid_B;
                    }else{
                        end_A = index;
                    }
                }
            }
            /*
            cout << "target: " << target << ", remain: " << remain << endl; 
            cout << "A : ";
            print_arr(&A[start_A], end_A - start_A + 1);
            cout << "B : ";
            print_arr(&B[start_B], end_B - start_B + 1);
            */
        }
        
        while(remain && end_A >= start_A && end_B >= start_B){
            get_min_and_modify_index(A, start_A, end_A, B, start_B, end_B); 
            remain --;
        }

        if(remain){
            if(end_A >= start_A)
                start_A += remain;
            else
                start_B += remain;
        }

        double median; 
        median = get_min_and_modify_index(A, start_A, end_A, B, start_B, end_B); 
        
        if(((long long)m + (long long)n) % 2 == 0){
            int min = get_min_and_modify_index(A, start_A, end_A, B, start_B, end_B);
            median = (median + min) / 2;
        }

        return median;
    }
};
