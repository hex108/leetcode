#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "merge_intervals.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        Interval a(1, 3), b(2, 6), c(8, 10), d(15,18);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);

        print_vector(solution.merge(v));
    }
	
    {
        Interval a(1, 3), b(2, 6), c(6, 10), d(9,18);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);

        print_vector(solution.merge(v));
    }
	
    //Error test cases from leetcode.com
    {
        Interval a(1, 4), b(2, 3);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);

        print_vector(solution.merge(v));
    }
	
	
	return 0;
}
