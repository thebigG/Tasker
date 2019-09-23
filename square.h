#include "Shape.h"
class Square:  public Shape
{
    private:
        int length;
        int width;
    public:
        Square(int new_width, int new_length)
        {
            length = new_length;
            width  = new_width;
        }
        int get_area()
        {
            return length*width;
        }
        int get_perimeter()
        {
            return length + width;
        }
        void set_length(int new_length)
        {
            length = new_length;
        }
        int get_length()
        {
            return length;
        }
        void set_width(int new_width)
        {
            width = new_width;
        }
        int get_width()
        {
            return width;
        }

};
