#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
void print_vector(vector<T> v){
    cout << "["; 

    bool first = true;

    for(typename vector<T>::iterator iter = v.begin(); iter != v.end(); iter ++){
        if(!first)
            cout << ", ";
        first = false;

        cout << *iter;
    }
    cout << "]," << endl;
}

template <typename T>
void print_vector_vector(vector<vector<T> > v) {
    cout << "{" << endl;
    for(typename vector<vector<T> >::iterator iter = v.begin(); iter != v.end(); iter ++){
        cout << "\t";
        print_vector(*iter);
    }
    cout << "}" << endl;
}

#endif
