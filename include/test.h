#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
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

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void draw_element(TreeLinkNode *root, ofstream &os){
    if(root == NULL)
        return;

    if(root->left)
        os << "    " << root->val << " -> " << root->left->val << endl;

    if(root->right)
        os << "    " << root->val << " -> " << root->right->val << endl;

    if(root->next)
        os << "    " << root->val << " -> " << root->next->val << endl;

    draw_element(root->left, os);
    draw_element(root->right, os);
}

template<typename T>
int draw_tree(T *root, string filename){
    ofstream outfile(filename.c_str());

    if( !outfile ){
        cout << "error : unable to open outputfile " << filename << endl;
        return -1;
    }

    outfile << "digraph tree_node{" << endl;
    outfile << "    size=\"8,5\"" << endl;
    outfile << "    node [shape = circle];" << endl;
    
    draw_element(root, outfile);    

    outfile << "}" << endl;

    return 0;
}

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Use the template function 'draw_tree': int draw_tree(T *, string).
// And overload the function 'draw_element'
void draw_element(TreeNode *root, ofstream &os){
    if(root == NULL)
        return;

    if(root->left)
        os << "    " << root->val << " -> " << root->left->val << endl;

    if(root->right)
        os << "    " << root->val << " -> " << root->right->val << endl;

    draw_element(root->left, os);
    draw_element(root->right, os);
}

#endif
