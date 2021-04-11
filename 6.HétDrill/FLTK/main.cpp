#ifndef FLTK_GUARD
#define FLTK_GUARD 1
#include "FL/Fl.h"
#include "FL/Fl_Box.h"
#include "FL/Fl_Window.h"

#endif
int main()
{
    Fl_Window window(200,200,"Window title");
    Fl_Box box(0,0,200,200,"Hey, I mean Hello world!");
    window.show();
    return Fl::run();
}
