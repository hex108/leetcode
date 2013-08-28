#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "insert_interval.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        // {[1,5], [6,9]}
        Interval a(1, 3), b(6, 9);
        Interval inserted(2, 5);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);

        print_vector(solution.insert(v, inserted));
    }
	
    {
        // {[1,2], [3,10], [12,16]}
        Interval a(1, 2), b(3, 5), c(6, 7), d(8,10), e(12, 16);
        Interval inserted(4, 9);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);

        print_vector(solution.insert(v, inserted));
    }
	
    {
        // {[-2,0], [1,3], [6,9]}
        Interval a(1, 3), b(6, 9);
        Interval inserted(-2, 0);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);

        print_vector(solution.insert(v, inserted));
    }
	
    {
        // {[1,3], [6,9], [10,12]}
        Interval a(1, 3), b(6, 9);
        Interval inserted(10, 12);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);

        print_vector(solution.insert(v, inserted));
    }
	
    //Error test cases from leetcode.com
    {
        // {[0,5], [7,16]}
        Interval a(0, 5), b(9, 12);
        Interval inserted(7, 16);
        vector<Interval> v;
        v.push_back(a);
        v.push_back(b);

        print_vector(solution.insert(v, inserted));
    }
	
	
	return 0;
}
