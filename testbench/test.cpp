/**
 *  @file       test.cpp
 *  @brief      Testbench for C++ code
 *
 *  @author     Gemuele Aludino
 *  @date       17 Sep 2019
 */

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <memory>

#include "header.h"

/**
 *  @brief  Execution begins here.
 *
 *  @param[in]  argc    Argument count
 *  @param[in]  argv    Command line arguments
 *
 *  @return     0 on success, else error
 *
 *  Compile and run with:
 *  g++ test.cpp source.cpp -o test; ./test;
 */
int main(int argc, const char *argv[]) {
    {
        person p("John Doe", 25);
        person q("jane doe", 18);
        p = q;
        std::cout << p << std::endl;
    } // p will have its destructor called when it goes out of scope.
    
    {
        // has one and only one owner.
        std::unique_ptr<person> pptr(new person("John Doe", 25));
        // memory is freed when it goes out of scope.
    }

    {   
        // reference-counted smart pointer,
        // used when one raw pointer is assigned to multiple "owners"
        std::shared_ptr<person> pptr_shared_0(new person("Jane Doe", 18));
        // memory is freed when all shared_ptrs go out of scope,
        // or they have relinquished ownership.

        std::shared_ptr<person> pptr_shared_1 = pptr_shared_0;
    }

    // don't do this -- this is "old" C++
    // person *pptr = new person("John Doe")
    // use pptr
    // delete pptr;
    // if you must use "naked" new, always call delete when done with it, like malloc/free.
    
    // new/delete have different variations for dynamically-allocated arrays:
    int *intarr = new int[256];
    delete[] intarr;    // dynamically-allocated arrays have their own delete operator


    std::vector<int> v;
    for (int i = 0; i < 32; i++) {
        v.push_back(i);
    }

    std::vector<int>::iterator it = v.begin();
    /**
     *  Iterators in C++ are designed to look like pointers.
     *  Dereferencing an iterator it is really an operator-overload
     *  to return the value at the iterator's current position.
     *  prefix/posfix increment/decrement advances/retracts the iterator
     *  respectively.
     */
    while (it != v.end()) {
        std::cout << "it: " << *(it++) << std::endl;
    }
    
    // note that end() refers to one-past-the-last element. (v[v.size()])
    std::vector<int>::iterator another_iterator = v.end();
    while (another_iterator != v.begin()) {
        std::cout << "another_iterator: " << *(--another_iterator) << std::endl;
    }

    return EXIT_SUCCESS;
}

