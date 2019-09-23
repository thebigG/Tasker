#include "Person.h"
#include "square.h"
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::out_of_range;
int main()
{
    // Person my_person("John", 34, "Jeans");
    // printf("Name,%s",my_person.get_name().c_str());
    // Square sq(12,12);
    // sq.get_area();
    // Shape *p = &sq;

    // Sqaure *ps = new Square(24, 24);
    // printf("value for area:%d", ((Square*)ps)->get_area());
    // vector<int> nums = {2,4,8};
    // for(int y: nums)
    // {
    // cout<<"vector squared-->" <<y*y<<"\n";
    // }
    // vector<int> loop_vector = {};
    // for( int i= 0;i<32;i++)
    // {
    //     loop_vector.push_back(i+1);
    // }
    // for(int i =0 ;i<loop_vector.size();i++)
    // {
    //     cout<<"vectoring:"<<loop_vector[i]<<"\n";
    // }
    // cout<<"first element:"<<nums[0]<<"\n"<<"Second element:"<<nums[1];
    // vector<double> temps;
    // for(double temp;cin>>temp;)
    // {
    //     temps.push_back(temp);
    // }
    // double sum = 0;
    // for (double item: temps)
    // {
    //     sum += item;
    // }
    // sort(temps);
    // cout<<"Average:"<<sum/(temps.size())<<"\n";
    // cout<<"Median:"<<temps[temps.size()/2];
    // vector<string> disliked_list = {"floss", "bleach"};
    // vector<string> words;
    // for(string str;cin>>str;)
    // {
    //     for(string s:disliked_list)
    //     {
    //         if(s == str)
    //         {
    //             cout<<"BLEEP. I don't like that word!";
    //             return -1;
    //         }
    //     }
    //     words.push_back(str);
    // }


    /*
    Calculator v1.0
    -------------------------------
    */
    // cout<< "Please enter expression: (+, -):";
    // cout<<"Add an 'x' to mark the end of an expression";
    // int left_val = 0;
    // int right_val = 0;
    // char op = 0;
    // int result = 0;
    // cin>>left_val;
    // if(!cin)
    // {
    //     perror("cin:");
    //     return -1;
    // }
    // else
    // {
    //     cout<<"No errors?";
    //     return 0;
    // }
    // if (op =='+')
    // {
    //     result = left_val + right_val;
    // }
    // else if(op =='-')
    // {
    //     result  =  left_val - right_val;
    // }
    // cout<<"Result "<< result << "\n";
    //execption handling
    //<--------------------------------------->
    /*
    int g  = 100;
    vector<int> nums(10);
    try{
        // nums.at(1) = 2000;
     g = nums.at(1);
}
catch(out_of_range)
{
    cerr<<"Out of range!";
        return -1;
}
    cout<<g;
    */
    double input;
    cout<<"Enter a double:";
    cin>>input;
    if(!cin)
    {
        cerr<<"cin error";
        return -1;
    }
    return 0;
}
