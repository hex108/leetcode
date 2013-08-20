#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "TEST_FILE_H"

using namespace std;

void print_vector(vector<string> v){
    cout << "["; 

    bool first = true;

    for(vector<string>::iterator iter = v.begin(); iter != v.end(); iter ++){
        if(!first)
            cout << ", ";
        first = false;

        cout << "\"" << *iter << "\"";
    }
    cout << "]," << endl;
}

void print_vector_vector(vector<vector<string> > v) {
    cout << "{" << endl;
    for(vector<vector<string> >::iterator iter = v.begin(); iter != v.end(); iter ++){
        cout << "\t";
        print_vector(*iter);
    }
    cout << "}" << endl;
}

int main()
{
    Solution solution;
    
    //Test cases
	
    //Error test cases from leetcode.com
	
	return 0;
}
