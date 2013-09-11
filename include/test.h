#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

// Assigin an int array 'arr' to vector<int> 'vec'
#define INT_ARR_TO_VEC(vec, arr)  {\
    vec.clear(); \
    vec.insert(vec.end(), arr, arr + sizeof(arr) / sizeof(arr[0]));\
}

template <typename T>
void arr_of_arr_to_vec(vector<vector<T> > &v, char *a, int row, int column){
    v.clear();

    for(int i = 0; i < row; i ++){
        vector<T> tmp;
        for(int j = 0; j < column; j ++){
            tmp.push_back(*(a + i * column + j));
        }
        v.push_back(tmp);
    }
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

// ListNode related 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list_node(ListNode *head){
    cout << "{";
    bool first = true;

    while(head){
        if(first == false){
            cout << ", " << head->val;
        }else{
            cout << head->val;
            first = false;
        }
        head = head->next;
    }
    cout << "}" << endl;
}

// Interval related
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

ostream &operator<<(ostream &os, Interval &val){
    os << "[" << val.start << ", " << val.end << "]";
    return os;
}

#endif
