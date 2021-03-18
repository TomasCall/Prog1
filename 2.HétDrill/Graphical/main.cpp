/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
try
{
    /* code */
    using namespace Graph_lib;

    Point point {100,100};

    Simple_window win{point,800,600,"Hello World"};
    //x axis 
    Point x_start{30,200};
    int x_length=300;
    int x_notches=5;
    Axis xa{Axis::x,x_start,x_length,x_notches,"x axis"};

    //y axis
    Point y_start{30,400};
    int y_length=280;
    int y_notches=10;
    Axis ya{Axis::y,y_start,y_length,y_notches,"y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);

    //Graphing a function
    double start_sine=0;
    double end_sine=100;
    Point start_sine_point{20,150};
    int num_of_points=1000;
    double sine_x_scale=50;
    double sine_y_scale=50;
    Function sine{sin,start_sine,end_sine,start_sine_point,num_of_points,sine_x_scale,sine_y_scale};

    //Polygon
    Polygon poly;
    poly.add(Point{200,250});
    poly.add(Point{300,150});
    poly.add(Point{500,300});
    poly.set_color(Color::dark_red);
    poly.set_style(Line_style::dashdotdot);

    //Rectangle
    Point rectangle_start{400,400};
    int rectangle_width=150;
    int ractangle_height=80;
    Rectangle r{rectangle_start,150,60};

    //Rectangle polyline
    Closed_polyline poly_rect;
    poly_rect.add(Point{150,60});
    poly_rect.add(Point{250,60});
    poly_rect.add(Point{250,110});
    poly_rect.add(Point{150,110});
    poly_rect.add(Point{60,90});

    //Fill
    r.set_fill_color(Color::magenta);
    poly.set_style(Line_style(Line_style::dashdot,10));
    poly_rect.set_style(Line_style(Line_style::dashdotdot,20));
    poly_rect.set_fill_color(Color::dark_magenta);

    //Text
    Text t{Point{150,150},"Hello graphical world"};
    t.set_font(Font::times_bold);
    t.set_font_size(40);

    //Image
    Image ii{Point{300,30},"badge.jpg"};
    //ii.move(100,200);

    //Circle
    Circle c(Point{100,200},80);
    Mark m{Point{100,200},'x'};


    ostringstream oss;
    oss<<"screen size:"<<x_max()<<"*"<<y_max()<<" ; windows size:"<<win.x_max()<<"*"<<win.y_max();
    Text sizes{Point{100,20},oss.str()};

    //win attach-ok
    win.set_label("Canvas#2");
    win.attach(xa);
    win.wait_for_button();
    win.set_label("Canvas#3");
    win.attach(ya);
    win.wait_for_button();
    win.set_label("Canvas#4");
    win.attach(sine);
    win.wait_for_button();
    win.set_label("Canvas#5");
    win.attach(poly);
    win.wait_for_button();
    win.set_label("Canvas#6");
    win.attach(poly_rect);
    win.wait_for_button();
    win.set_label("Canvas#7");
    win.attach(r);
    win.wait_for_button();
    win.set_label("Canvas#8");
    win.attach(t);
    win.wait_for_button();
    win.set_label("Canvas#10");
    win.attach(ii);
    win.attach(c);
    win.attach(m);
    win.attach(sizes);
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