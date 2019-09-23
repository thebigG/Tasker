#ifndef HEADER_H
#define HEADER_H
#include<iostream>
using std::string;

class Person
{
public:
    string  clothes;
    void set_age(int new_age)
        {
            age = new_age;
        }
    int get_age()
        {
            return age;
        }
    void set_name(string new_name)
    {
        name = new_name;
    }
    string get_name()
    {
        return name;
    }
    Person(string new_name, unsigned int new_age, string new_clothes)
    {
        set_age(new_age);
        set_name(new_name);
        clothes = new_clothes;
    }

private:
    unsigned int age;
    string name;


};


#endif
