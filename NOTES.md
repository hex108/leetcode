# Some thought about algorithm
*Algorithm* is important, and *implementation* is also very important(e.g. Partition List).

## How to analyze problemom
### Understand the problem
### Basic methods
* Split the problem to smaller problem
  Split it to smaller problem. But how to split is also a problem. 
  
  e.g. Palindrome Palindrome II.

* Recursion
  After split problem, we usually use recursion if the child problem is similar to the parent problem. 

## How to make programe faster?
### Record
Record values that need computed many times. It could change the complexity of the algorithm. If not using record, it will exceed time limit.

e.g. Palindrome Palindrome II; Distinct Subsequences; Edit Distance.

*But* we should implement it effecively.
e.g. Interleaving String.

### Hash
Hash is very very helpful. It could save much time.

e.g. Two Sum; Longest Consecutive Sequence.

## Tricks
### Fast and slow pointer
Currently, it has been used in rotating list and checking whether a chain list is a loop, e.g. Rotate List; Remove Nth Node From End Of List.

# Specific problems

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
