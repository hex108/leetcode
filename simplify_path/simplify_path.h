/* Notes:
 *
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

#include "test.h"
using namespace std;

class Solution {
    void pop_dir(string &path){
        if(path.size() == 0)
            return;

        int i;
        for(i = path.size() - 1; i >= 0; i --){
            if(!is_part_of_name(path[i]))
                break;
        }

        path.resize(i); // remove last "/dir_name"
    }

    bool is_part_of_name(char c){
        return c != '/';
    }

public:
    string simplifyPath(string path) {
        string simplified_path;

        for(size_t i = 0; i < path.size(); i ++){
            char c = path[i];
            if(c == '/')
                continue;
            
            int start = i;
            while(i < path.size() && is_part_of_name(path[i]))
                i ++;

            string s = path.substr(start, i - start);

            if(s == ".")
                continue;
            else if(s == "..")
                pop_dir(simplified_path);
            else
                simplified_path.append("/" + path.substr(start, i - start));
        }

        if(simplified_path.size() == 0 && path.size() != 0)
            simplified_path = "/";

        return simplified_path;
    }
};

/* Memory Limit Exceed.
class Solution {
public:
    string simplifyPath(string path) {
        string simplified_path;
        deque<string> dirs;

        for(size_t i = 0; i < path.size(); i ++){
            char c = path[i];
            if(c == '/')
                continue;
            
            if(c == '.'){
                if(i + 1 < path.size() && path[i + 1] == '.'){
                    if(dirs.size() > 0)
                        dirs.pop_back();
                    else
                        return "";
                }
            }else{
                int start = i;
                while(isalnum(path[i]))
                    i ++;
                
                dirs.push_back(path.substr(start, i - start));
                i --;
            }
        }

        for(size_t i = 0; i < dirs.size(); i ++)
            simplified_path.append("/" + dirs[i]);

        return simplified_path;
    }
};
*/
