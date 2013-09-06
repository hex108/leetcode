# Some thought about algorithm
*Algorithm* is important, and *implementation* is also very important(e.g. Partition List).

## How to analyze problemom
### Understand the problem
### How to estimate the least complexity of algorithm for the problem
I have not figured not it yet. But you could see the article [why is quicksort so quick](http://mindhacks.cn/2008/06/13/why-is-quicksort-so-quick/) first.

### Basic methods
* Split the problem to smaller problem
  Split it to smaller problem. But how to split is also a problem. 
  
  e.g. Palindrome Palindrome II.

* Recursion
  After split problem, we usually use recursion if the child problem is similar to the parent problem. 

## How to make programe faster?
### Record
Record values that need computed many times. It could change the complexity of the algorithm. If not using record, it will exceed time limit.

e.g. Palindrome Palindrome II; Distinct Subsequences; Edit Distance; Pow.

*But* we should implement it effecively.
e.g. Interleaving String.

### Hash
Hash is very very helpful. It could save much time.

e.g. Two Sum; Longest Consecutive Sequence.

### heap
maximum heap and minimum heap.

e.g. Merge K Sorted Lists. 

### Reduce compare times

e.g. Longest Common Prefix. 

## How to write correct program
Please refer to the book <\<Programming Pearls\>> Part I Column 4(Writing Correct Programs). Then you could understand how to set/compare low and high in quick sort and binary search algorithm.

## Tricks
### Fast and slow pointer
Currently, it has been used in rotating list and checking whether a chain list is a loop, e.g. Rotate List; Remove Nth Node From End Of List.

### Dummy node
It is useful when you might delete the head of a node list, e.g. Reverse Linked List II; Remove Duplicates From Sorted List II.

# Specific problems
Some problems could be tried again. e.g. Wildcard Matching; Longest Substring Without Repeating Characters.

## Palindrome Partitioning II
Write programe more effectively. It *matters*.

e.g.

    for(size_t i = 0; i < need_cut.size(); i ++){
        if(isPalindrome(s, need_cut[i], len - 1)){
            return n; 
        }
        size_t start = need_cut[i];
        for(size_t j = start; j < len - 1; j ++){
            if(record[j + 1] != 0 && isPalindrome(s, start, j)){
                tmp.push_back(j + 1);
                record[j + 1] = 0;
            }
        }
    }
    
=>

    for(size_t i = 0; i < need_cut.size(); i ++){
        if(isPalindrome(s, need_cut[i], len - 1)){
            return n; 
        }
    }

    for(size_t i = 0; i < need_cut.size(); i ++){
        size_t start = need_cut[i];
        for(size_t j = start; j < len - 1; j ++){
            if(record[j + 1] != 0 && isPalindrome(s, start, j)){
                tmp.push_back(j + 1);
                record[j + 1] = 0;
            }
        }
    }
    
## Longest Consecutive Sequence
I usually use bit map to solve the problem. And I have already recognized the solution will be very inefficient when the range of the element in the array is very large, e.g. {-200000, 200000}. Today I think I could use map to solve it suddenly. Finally I solve the problem. What a big surprise!

## Interleaving String
Implement record effectively. According to index1 and index2, we could get index3 because the equation `(s1.size() - index1 + s2.size() - index2) == (s3.size() - index3)` must be true. So we could use `recored[index1][index2]` instead of `record[index1][index2][index3]` to record.

## Merge Sorted Array
Classify every situation, e.g. m == 0, n == 0.

## Partition List
It is very senstive to the effective implementation of every operation, not just complexity of algorithm.

## Remove Duplicates From Sorted List II
Use a dummy node and set its member 'next' point to head. It is one of questions in my interview one year ago.

## Search In Rotated Sorted Array II
I have not figured out why linear search does not exceed the time limit!

## Median Of Two Sorted Arrays
It is a very good practice to deduce the program step by step.

## Climbing Stairs
I have never thinked that the equation `f(n) = f(n - 1) + f(n - 2)` could be used in my program.

## 3Sum
Please note the following *error* code.

    vector<int> v;
    for(size_t i = v.size() - 1; i >= 0; i --){  // i whose type is 'size_t' will always be non-negative.
        ...
    }
    
## 4Sum
Write program very effectively and carefully. You could use `git diff` to see the difference.

## Permutation Sequence
It is a useful trick using `remain_num` in code.

## Next Permutation
Please understand what is the expected permutation first.

## Implement StrStr
KMP is always a little hard to write right at one time. Glibc  has another implementation in the file string/strstr.c.

## Minimum Window Substring
Use `deque` and `map`. It is a little hard. If the question becomes "Given a string S and a string T, find the minimum window in S which will contain all the characters(that same characters are contained once is OK) in T in complexity O(n).", it will be more easy, using `map` is just OK.

## Pow(x, n)
Use record. Please notice corner cases: n < 0; n = -2147483648(the smallest negative int).
