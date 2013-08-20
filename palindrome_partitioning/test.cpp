#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "palindrome_partitioning.h"

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
    string str = "aab";
    print_vector_vector(solution.partition(str));
	
    str = "a";
    print_vector_vector(solution.partition(str));
	
    str = "";
    print_vector_vector(solution.partition(str));
	
    //Error test cases
    str = "bb";
    print_vector_vector(solution.partition(str));
	
	return 0;
}
