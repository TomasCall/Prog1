/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;
	/*
    int xmax = 1280;
    int ymax = 720;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{200,200}, 100, 50};

	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{200,400}, "Hello graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{100,100}, "badge.jpg"};

	Circle c {Point{700,700}, 100};

	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);

    win.wait_for_button();
	*/
	Point tl{100,100};
	int x_max=1280;
	int y_max=720;

	int x_orig=x_max/2;
	int y_orig=y_max/2;

	int r_min=-11;
	int r_max=11;

	int n_points=400;

	Simple_window win {tl,1280,720,"Hello World!"};
	
	//Polygon poly;
	/*
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	*/
	Point origo{x_orig,y_orig};

	int x_length=x_max-40;
	int y_length=y_max-40;

	int x_scale=30;
	int y_scale=30;

	Function s(one,r_min,r_max,origo,n_points,x_scale,y_scale);

	Function sq(square,r_min,r_max,origo,n_points,x_scale,y_scale);

	Function cos_func ( [] (double x) { return cos(x); },r_min, r_max, origo, n_points, x_scale, y_scale);

	Axis x {Axis::x,Point{20,y_orig},x_length,x_length/x_scale,"x"};
	Axis y {Axis::y,Point{x_orig,y_length+20},y_length,x_length/x_scale,"y"};
	//win.attach(poly);

	Rectangle r{Point{200,200},100,50};
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dashdotdot,4));

	Text t {Point{200,400},"Sageyooooo!"};
	t.set_font(Font::times_bold);
	t.set_font_size(50);
	
	Image ii{Point{100,100},"badge.jpg"};

	Circle c{Point{400,400},50};
	win.attach(c);
	win.attach(r);
	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(ii);
	win.attach(t);
	win.attach(c);
	win.wait_for_button();

}
