/**
 *  @file       source.cpp
 *  @brief      Header source file for C++ code
 *
 *  @author     Gemuele Aludino
 *  @date       17 Sep 2019
 */

#include "header.h"

/**
 *  @brief  Default constructor, initializes fields to default values
 */ 
person::person() {
    name = "";
    age = 0;

    std::cout << "default constructor called" << std::endl;
}

/**
 *  @brief  Parameterized constructor, initializes fields to specified values
 *
 *  @param[in]  name    a person's full name
 *  @param[in]  age     integer of positive magnitude, representing a person's age
 */
person::person(std::string name, uint32_t age) {
    this->name = name;
    this->age = age;

    std::cout << "parameterized constructor called" << std::endl;
}

/**
 *  @brief  Destructor, releases dynamically-allocated resources (if applicable)
 *          when instance goes out of scope
 */
person::~person() {
    std::cout << "destructor called" << std::endl;
}

/**
 *  @brief  Accessor, retrieves name field
 *
 *  @return a copy of the name field
 */
std::string person::get_name() {
    return name;
}

/**
 *  @brief  Accessor, retrieves age field
 *  
 *  @return a copy of the age field
 */
uint32_t person::get_age() {
    return age;
}

/**
 *  @brief  Mutator, sets name field
 *
 *  @param[in]  name    a person's full name
 */
void person::set_name(std::string name) {
    this->name = name;
}

/**
 *  @brief  Mutator, sets age field
 *
 *  @param[in]  age     integer of positive magnitude, representing a person's age
 */
void person::set_age(uint32_t age) {
    this->age = age;
}

/**
 *  @brief  Operator overload, tests for equality (equal field values)
 *
 *  @param[in]  p   reference to person
 *
 *  @return     true if name and age match that of p, false otherwise
 */
bool person::operator==(const person& p) {
    return name == p.name && age == p.age;
}

/**
 *  @brief  Operator overload, compares ages
 *
 *  @param[in]  p   reference to person
 *
 *  @return     0 if ages are equal, 
 *              less than 0 if age is less than p.age,
 *              greater than 0 if age is greater than p.age
 */
int person::operator<(const person&p) {
    return (int)(age - p.age);
}

/**
 *  @brief  Operator overload, assigns p's values to current object
 *
 *  @param[in]  p   reference to person
 */
void person::operator=(const person& p) {
    name = p.name;
    age = p.age;
}

/**
 *  @brief  Operator overload, prints p's values to output stream
 *
 *  @param[in]  os  reference to ostream
 *  @param[in]  p   reference to person
 *
 *  @return     ostream - string representation of person
 *
 *  ostream has been made a 'friend' of person, allowing it
 *  to access the fields of class person for this function.
 */
std::ostream& operator<<(std::ostream& os, const person& p) {
    os << "Name: " << p.name << "\n" << "Age: " << p.age << std::endl;
    return os;
}

