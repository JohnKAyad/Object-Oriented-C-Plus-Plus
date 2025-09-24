#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief prints elements in the vector and their memory locations
 * 
 * @param v - vector of integers
 * 
 */

 void printMemVec(const vector<int>& v) {
    printf("Vector - Each int is worth %lu bytes\n", sizeof(v[0]));
    for(size_t i = 0; i < v.size(); i++) {
        printf("Value: %i at memory location: %p\n", v[i], &v[i]);
    }
}

/**
 * @brief increments all elements in v by 10
 * 
 * @param v - address to a vector of integers
 */

 void incVecBy10(vector<int>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        v[i] += 10;
    }
 }

    int main() {
        const int SIZE = 5;
        
        vector<int> v(SIZE);
        for(int i = 0; i < SIZE; i++) {
            v[i] = 100 + i;
        }
    
        printf("Before Increment---------------\n");
        printMemVec(v);
        incVecBy10(v);
    
        printf("After Increment---------------\n");
        printMemVec(v);

        v.pop_back(); // remove last element
        
        printf("After Pop---------------\n");
        printMemVec(v);

        v.push_back(101); // add two elements to the end of the vector
        v.push_back(102);
        printf("After Push---------------\n");
        printMemVec(v);
    }
