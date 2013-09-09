/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
    int get_capacity(vector<int> &height, int left, int right){
        int h = height[left] <= height[right]? height[left] : height[right];

        return h * (right - left);
    }

public:
    int maxArea(vector<int> &height) {
        /* 'max_water' is the max capacity that containers could hold.
         * 'max_left' is corresponding container's left sides's index
         * in 'height', and 'max_right' corresponds right side.
         */
        int max_water = 0, max_left = 0, max_right = 0;

        int end = (int)height.size() - 1;
        // left side of the container
        for(int left = 0; left < end; left ++){
            /* If height[left] < height[max_left], there could be a right index
             * satifies capacity of [left, right] >= container of [max_left, 
             * any index] becuase [max_left, right] must > [left, right].
             */
            if(height[left] < height[max_left])
                continue;

            max_right = end;
            int water = get_capacity(height, left, max_right);

            // right side of the container
            for(int right = end - 1; right > left; right --){
                if(height[right] <= height[max_right])
                    continue;

                int tmp = get_capacity(height, left, right);
                if(tmp > water){
                    max_right = right;
                    max_left = left;
                    water = tmp;
                }
            }

            if(water > max_water)
                max_water = water;
        }

        return max_water;
    }
};
