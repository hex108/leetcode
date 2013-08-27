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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    static int cmp(const Interval &a, const Interval &b){
        if(a.start < b.start)
            return 1;
        else if(a.start == b.start)
            return a.end < b.end;
        else 
            return 0;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp); 

        vector<Interval> merged_intervals;
        vector<Interval>::iterator iter;
        for(iter = intervals.begin(); iter != intervals.end();){
            Interval cur = *iter; 
            iter ++;
            Interval next = *iter;
            while(iter != intervals.end()){
                if(cur.end < iter->start)
                    break;

                if(cur.end >= iter->start && cur.end <= iter->end)
                    cur.end = iter->end;

                iter ++;
            }

            merged_intervals.push_back(cur);
        }

        return merged_intervals;
    }
};
