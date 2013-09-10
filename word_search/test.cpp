#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "word_search.h"

using namespace std;

void arr_of_arr_to_vec(vector<vector<char> > &v, char *a, int row, int column){
    v.clear();

    for(int i = 0; i < row; i ++){
        vector<char> tmp;
        for(int j = 0; j < column; j ++){
            tmp.push_back(*(a + i * column + j));
        }
        v.push_back(tmp);
    }
}

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
