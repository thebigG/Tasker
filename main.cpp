#include "Person.h"
#include "square.h"
#include <vector>
using std::vector;
using std::cout;
using std::cin;
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
    vector<double> temps;
    for(double temp;cin>>temp;)
    {
        temps.push_back(temp);
    }
    double sum = 0;
    for (double item: temps)
    {
        sum += item;
    }
    sort(temps);
    cout<<"Average:"<<sum/(temps.size())<<"\n";
    cout<<"Median:"<<temps[temps.size()/2];
    
    return 0;
}
