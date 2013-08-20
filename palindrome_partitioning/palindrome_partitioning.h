/* How to solve it?
 * For these similar problem, I could just use recursion to solve. Is there
 * any other methods?
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
    bool is_palindorme(string s) {
        for(size_t i = 0, j = s.size() - 1; i < j; i ++, j--){
            if(s[i] != s[j])
                return false;
        }

        return true;
    }

    void add_to_each(vector<vector<string> > &v, string s) {
        if(v.size() == 0){
            vector<string> tmp;
            tmp.push_back(s);
            v.push_back(tmp);
            return;
        }

        for(vector<vector<string> >::iterator iter = v.begin(); iter != v.end(); iter++)
            iter->push_back(s);
    }

    // Each vector<string> needs be reversed for the return value.
    vector<vector<string> > do_partition(string s) {
        vector<vector<string> > partitioned_strs;

        if(s.size() == 0)
            return partitioned_strs;

        for(size_t size = 1; size <= s.size(); size ++){
            string sub_str = s.substr(0, size);
            vector<vector<string> > tmp;

            if(is_palindorme(sub_str)){
                tmp = do_partition(s.substr(size));
                add_to_each(tmp, sub_str);
            }
            partitioned_strs.insert(partitioned_strs.end(), tmp.begin(), tmp.end());
        }

        return partitioned_strs;
    }

    void reverse_each_vector(vector<vector<string> > &v) {
        for(vector<vector<string> >::iterator iter = v.begin(); iter != v.end(); iter++)
            reverse(iter->begin(), iter->end());
    }
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > partitioned_strs = do_partition(s);
        
        reverse_each_vector(partitioned_strs);

        return partitioned_strs;
    }
};
