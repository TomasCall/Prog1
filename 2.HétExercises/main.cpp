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

    Simple_window win{point,1000,900,"Hello World"};
    //01
    //Rectangle1
    Point rectangle_start1{400,700};
    int rectangle_width1=150;
    int rectangle_height1=80;
    Rectangle rectangle1{rectangle_start1,rectangle_width1,rectangle_height1};
    rectangle1.set_color(Color::blue);

    //Polygon1
    Polygon poly1;
    poly1.add(Point{100,50});
    poly1.add(Point{100,100});
    poly1.add(Point{200,100});
    poly1.add(Point{200,50});
    poly1.set_color(Color::red);

    //win attach
    win.attach(rectangle1);
    win.attach(poly1);
    win.label("01");
    win.wait_for_button();

    //02
    //Rectangle2
    Point rectangle_start2{400,20};
    int rectangle_width2=100;
    int rectangle_height2=30;
    Rectangle rectangle2{rectangle_start2,rectangle_width2,rectangle_height2};
    rectangle2.set_color(Color::magenta);
    //Text1
    Text text1{Point{400,40},"Howdy!"};
    text1.set_font(Font::times_bold);
    text1.set_font_size(20);

    //win attach
    win.attach(rectangle2);
    win.attach(text1);
    win.label("02");
    win.wait_for_button();

    //03
    //Text3
    Text text3{Point{20,150},"V"};
    text3.set_font(Font::times_bold);
    text3.set_font_size(20);
    text3.set_color(Color::green);

    //Text4
    Text text4{Point{40,150},"B"};
    text4.set_font(Font::times_bold);
    text4.set_font_size(20);
    text4.set_color(Color::magenta);

    //win attach
    win.attach(text3);
    win.attach(text4);
    win.label("03");
    win.wait_for_button();

    //04
    Vector_ref<Rectangle> vr;
	int w=50;
	for(int row=0;row<3;++row)
	{
		for(int col=0;col<3;col++)
		{
            int i=vr.size();
			vr.push_back(new Rectangle{Point{100+w*col,200+w*row},w,w});
			i%2==0?vr[i].set_fill_color(Color::red):vr[i].set_fill_color(Color::white);
			win.attach(vr[i]);
		}
	}
    win.label("04");
    win.wait_for_button();
	//05
    
    //Rectangle3
	Point rectangle_start3{50,200};
    int rectangle_width3=win.x_max();
    int rectangle_height3=win.y_max();
    Rectangle rectangle3{rectangle_start3,rectangle_width3,rectangle_height3};
    rectangle3.set_color(Color::black);

    //win attach
    win.label("05");
    win.attach(rectangle3);
    win.wait_for_button();

    //06

    //Shape
    Point shape_start{50,200};
    int shape_length=1000;
    int shape_notches=0;
    Axis line{Axis::x,shape_start,shape_length,shape_notches,"shape"};
    
    //win attach
    win.attach(line);
    win.label("06");
    win.wait_for_button();

    //07

    //Rectangle4
    Point rectangle_start4{500,200};
    int rectangle_width4=200;
    int rectangle_height4=200;
    Rectangle rectangle4{rectangle_start4,rectangle_width4,rectangle_height4};
    rectangle4.set_color(Color::yellow);
    rectangle4.set_fill_color(Color::yellow);

    //Polygon2
    Polygon poly2;
    poly2.add(Point{500,200});
    poly2.add(Point{600,100});
    poly2.add(Point{700,200});
    poly2.set_color(Color::red);
    poly2.set_fill_color(Color::red);

    //Rectangle5
    Point rectangle_start5{575,300};
    int rectangle_width5=50;
    int rectangle_height5=100;
    Rectangle rectangle5{rectangle_start5,rectangle_width5,rectangle_height5};
    rectangle5.set_color(Color::black);
    rectangle5.set_fill_color(Color::black);

    //Rectangle6
    Point rectangle_start6{500,100};
    int rectangle_width6=20;
    int rectangle_height6=100;
    Rectangle rectangle6{rectangle_start6,rectangle_width6,rectangle_height6};
    rectangle6.set_color(Color::black);
    rectangle6.set_fill_color(Color::black);

    //Rectangle7
    Point rectangle_start7{520,180};
    int rectangle_width7=20;
    int rectangle_height7=20;
    Rectangle rectangle7{rectangle_start7,rectangle_width7,rectangle_height7};
    rectangle7.set_color(Color::black);
    rectangle7.set_fill_color(Color::black);

    //Rectangle8
    Point rectangle_start8{520,300};
    int rectangle_width8=50;
    int rectangle_height8=50;
    Rectangle rectangle8{rectangle_start8,rectangle_width8,rectangle_height8};
    rectangle8.set_color(Color::blue);
    rectangle8.set_fill_color(Color::blue);

    //Rectangle9
    Point rectangle_start9{630,300};
    int rectangle_width9=50;
    int rectangle_height9=50;
    Rectangle rectangle9{rectangle_start9,rectangle_width9,rectangle_height9};
    rectangle9.set_color(Color::blue);
    rectangle9.set_fill_color(Color::blue);

    //win attach
    win.attach(rectangle4);
    win.attach(poly2);
    win.attach(rectangle5);
    win.attach(rectangle6);
    win.attach(rectangle7);
    win.attach(rectangle8);
    win.attach(rectangle9);
    win.label("07");
    win.wait_for_button();

    //08

    //Circle1
    Circle c1(Point{110,500},40);
    c1.set_color(Color::blue);
    c1.set_style(Line_style(Line_style::solid,5));
    //Circle2
    Circle c2(Point{200,500},40);
    c2.set_color(Color::black);
    c2.set_style(Line_style(Line_style::solid,5));
    //Circle3
    Circle c3(Point{290,500},40);
    c3.set_color(Color::red);
    c3.set_style(Line_style(Line_style::solid,5));
    //Circle4
    Circle c4(Point{155,540},40);
    c4.set_color(Color::yellow);
    c4.set_style(Line_style(Line_style::solid,5));
    //Circle5
    Circle c5(Point{245,540},40);
    c5.set_color(Color::dark_green);
    c5.set_style(Line_style(Line_style::solid,5));
    

    //win attach
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);
    win.label("08");
    win.wait_for_button();

    //09
    Image ii{Point{10,10},"badge.jpg"};
    win.attach(ii);
    win.set_label("badge.jpg");
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