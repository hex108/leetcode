#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "word_search.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char a[][4] = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };

        vector<vector<char> > v;
        arr_of_arr_to_vec(v, a[0], 3, 4);

        cout << solution.exist(v, "ABCCED") << endl;
        cout << solution.exist(v, "SEE") << endl;
        cout << solution.exist(v, "ABCB") << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
