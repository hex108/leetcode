/* Notes:
 *
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

#include "test.h"
using namespace std;

class Solution {
    vector<int> get_column(vector<vector<int> > &matrix, int column){
        vector<int> v;

        for(size_t i = 0; i < matrix.size(); i ++)
            v.push_back(matrix[i][column]);

        return v;
    }

    // return the first index that v[index] >= target
    int binary_search(vector<int> &v, int target){
        int low = 0, high = v.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(v[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int size = matrix.size();
        if(size == 0)
            return false;

        vector<int> first_column = get_column(matrix, 0);
        int row = binary_search(first_column, target);

        if(row < size && first_column[row] == target)
            return true;

        row --; 
        if(row < 0)
            return false;

        int column = binary_search(matrix[row], target);
        
        if(column >= (int)matrix[row].size() || matrix[row][column] != target)
            return false;
        else
            return true;
    }
};
