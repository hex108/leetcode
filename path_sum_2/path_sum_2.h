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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void add_val_to_path(vector<vector<int> > &path, int val){
        vector<vector<int> >::iterator iter;
        for(iter = path.begin(); iter != path.end(); iter++){
            iter->push_back(val);
        }
    }

    vector<vector<int> > getReversePath(TreeNode *root, int sum){
        vector<vector<int> > path;

        if(root == NULL)
            return path;

        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                vector<int> tmp;
                tmp.push_back(root->val);
                path.push_back(tmp);
            }
            return path;
        }

        int remain = sum - root->val;

        if(root->left){
            vector<vector<int> > left_path = getReversePath(root->left, remain);
            path.insert(path.end(), left_path.begin(), left_path.end());
        }

        if(root->right){
            vector<vector<int> > right_path = getReversePath(root->right, remain);
            path.insert(path.end(), right_path.begin(), right_path.end());
        }
        
        add_val_to_path(path, root->val);

        return path;
    }

    void reverse_path(vector<vector<int> > &path){
        vector<vector<int> >::iterator iter;
        for(iter = path.begin(); iter != path.end(); iter++){
            reverse(iter->begin(), iter->end());
        }
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > path = getReversePath(root, sum);
        reverse_path(path);

        return path;
    }
};
