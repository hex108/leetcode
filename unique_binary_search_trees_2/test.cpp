#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "unique_binary_search_trees_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 3;
        vector<TreeNode *> trees = solution.generateTrees(n);

        for(size_t i = 0; i < trees.size(); i ++){
            char tmp[40];
            sprintf(tmp, "%u", i);
            string s = string(tmp);
            draw_tree(trees[i], s + ".dot");
        }
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
