/*
 g++ main.cpp -o main `fltk-config --ldflags --use-images`

*/
#include "fltk.h"
int main()
{
    Fl_Window window(200,200,"Window title");
    Fl_Box box(0,0,200,200,"Hey, I mean Hello world!");
    window.show();
    return Fl::run();
}
