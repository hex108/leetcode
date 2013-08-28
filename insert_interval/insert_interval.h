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
    int find_place_to_insert(vector<Interval> &intervals, Interval newInterval){
        int new_start = newInterval.start;
        int low = 0, high = intervals.size() - 1;

        while(low < high){
            int mid = low + (high - low) / 2;
            int mid_start = intervals[mid].start;

            if(mid_start > new_start)
                high = mid - 1;
            else if(mid_start < new_start)
                low = mid + 1;
            else
                return mid;
        }

        // cout << "low : " << low << endl;
        if(low != 0 && intervals[low - 1].start <= new_start
                && intervals[low - 1].end >= new_start)
            return low - 1;
        else if(intervals[low].end < new_start)
            return low + 1;
        else
            return low;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> inserted_intervals;
        if(intervals.empty()){
            inserted_intervals.push_back(newInterval);
            return inserted_intervals;
        }
        
        int place = find_place_to_insert(intervals, newInterval);
        //cout << "place : " << place << endl;
        int new_end = newInterval.end;

        inserted_intervals.assign(intervals.begin(), intervals.begin() + place);
        if(place != (int)intervals.size() && intervals[place].start < newInterval.start){
            newInterval.start = intervals[place].start ;
        }
        size_t i;
        for(i = place; i < intervals.size(); i ++){
            if(new_end < intervals[i].start)
                break;
            if(new_end < intervals[i].end){
                newInterval.end = intervals[i].end;
            }
        }
        inserted_intervals.push_back(newInterval);
        inserted_intervals.insert(inserted_intervals.end(), intervals.begin() + i, intervals.end());

        return inserted_intervals;
    }
};
