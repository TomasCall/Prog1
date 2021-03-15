/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
try
{
    
    using namespace Graph_lib;

    Point point {300,300};
    Simple_window win{point,600,600,"Function graphs"};
    Point x_start{100,300};
    int x_length=400;
    int x_notches=20;
    Axis xa{Axis::x,x_start,x_length,x_notches,"1==20pixels"};
    xa.set_color(Color::dark_red);
    xa.label.set_color(Color::dark_red);

    //y axis
    Point y_start{300,500};
    int y_length=400;
    int y_notches=20;
    Axis ya{Axis::y,y_start,y_length,y_notches,"1==20pixels"};
    ya.set_color(Color::dark_red);
    ya.label.set_color(Color::dark_red);

    win.attach(xa);
    win.attach(ya);

    win.wait_for_button();
    
    int r_min=-10;
    int r_max=100;
    Point orig{300,300};
    int number_of_points=400;
    int x_scale=20;
    int y_scale=20;

   /*
    Function s(one,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s);
    win.wait_for_button();
    */
   Function constant(one,r_min,r_max,orig,number_of_points,x_scale,y_scale);
   win.attach(constant);
   win.wait_for_button();
   Function slopeF(slope,r_min,r_max,orig,number_of_points,x_scale,y_scale);
   win.attach(slopeF);
   win.wait_for_button();
   Text slopeT{Point{100,420},"Text x/2"};
   win.attach(slopeT);
   win.wait_for_button();
   Function squareF(square,r_min,r_max,orig,number_of_points,x_scale,y_scale);
   win.attach(squareF);
   Function cosF(cos,r_min,r_max,orig,number_of_points,x_scale,y_scale);
   cosF.set_color(Color::blue);
   win.attach(cosF);
   win.wait_for_button();
   Function slopeCos(sloping_cos,r_min,r_max,orig,number_of_points,x_scale,y_scale);
   win.attach(slopeCos);
   win.wait_for_button();

}
catch(exception& e)
{
    cerr << e.what() <<endl;
    return 1;
}
catch(...)
{
    cerr << "Something bad happend"<<endl;
    return 2;
}