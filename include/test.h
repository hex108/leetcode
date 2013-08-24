#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Assigin an int array 'arr' to vector<int> 'vec'
#define INT_ARR_TO_VEC(vec, arr)  {\
    vec.clear(); \
    vec.insert(vec.end(), arr, arr + sizeof(arr) / sizeof(arr[0]));\
}

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

template <typename T>
void print_arr(T arr[], int n){
    cout << "[";

    for(int i = 0; i < n - 1; i ++){
        cout << arr[i] << ", ";
    }
    
    if(n >= 1)
        cout << arr[n - 1];
    
    cout << "]" << endl;
}

#endif
