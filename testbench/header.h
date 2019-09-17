/**
 *  @file       header.h
 *  @brief      Header testbench for C++ code
 *
 *  @author     Gemuele Aludino
 *  @date       17 Sep 2019
 */

#ifndef HEADER_H
#define HEADER_H

#include <iostream>

/**
 *  :: is a scope-resolution operator, used to access variables/classes/etc.
 *  from a particular namespace.
 *
 *  For example, std is the C++ standard namespace.
 *  It is advisable to use namespaces (like how you would use packages in Java),
 *  to avoid name-clashing. This example does not include the use of a namespace
 *  for class person, but you can create one like this:
 *  
 *  namespace foo {
 *      class bar {
 *          // content    
 *      };
 *  }
 */

/**
 *  @class  person
 *  @brief  Sample class to describe C++ syntax
 */
class person {
public:
    person();                                   /**< default constructor */
    person(std::string name, uint32_t age);     /**< parameterized constructor */
    person(const person& p);                    /**< copy constructor */
    ~person();                                  /**< destructor */

    std::string get_name();                     /**< accessor */
    uint32_t get_age();                         /**< accessor */

    void set_name(std::string);                 /**< mutator */
    void set_age(uint32_t age);                 /**< mutator */

    bool operator==(const person&p);            /**< op-overload, equality */
    int operator<(const person&p);              /**< op-overload, comparator */
    void operator=(const person&p);             /**< op-overload, assignment */
    
    /**< op-overload - friend keyword allows a class (in this case, the std::ostream class),
         to access private/protected fields. (essentially breaks encapsulation) */
    friend std::ostream& operator<<(std::ostream& os, const person& p);
private:
    std::string name;
    uint32_t age;
};

#endif /* HEADER_H */

