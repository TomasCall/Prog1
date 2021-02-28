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
    //01
    Simple_window win{point,800,1000,"Hello World"};
    //02
    //Grid datas
    int x_size=800;
    int y_size=800;
    int x_grid=100;
    int y_grid=100;
    //Grid making
    Lines grid;
    //Columns
    for(int x=x_grid;x<x_size;x+=x_grid)
    {
        grid.add(Point{x,0},Point{x,y_size});
    }
    //Rows
    int lowest_y=900;
    for(int y=y_grid;y<lowest_y;y+=y_grid)
    {
        grid.add(Point{0,y},Point{x_size,y});
    }
    //Win attach
    win.attach(grid);
    win.wait_for_button();

    //03
    int counter=0;
    int rect_x=0;
    int rect_y=0;
    Vector_ref<Rectangle> rectangles;
    while(counter<8)
    {
        rectangles.push_back(new Rectangle{Point{rect_x,rect_y},100,100});
        rect_x+=100;
        rect_y+=100;
        counter++;
    }
    for(int i=0;i<rectangles.size();i++)
    {
       rectangles[i].set_fill_color(Color::red);
       rectangles[i].set_color(Color::invisible);
       win.attach(rectangles[i]);
    }
    win.wait_for_button();
    //04
    Vector_ref<Image> images;
    for(int i=200;i<800;i+=200)
    {
        images.push_back(new Image{Point{0,i},"aaa.gif"});
    }
    for(int i=0;i<images.size();i++)
    {
        win.attach(images[i]);
    }
    //win.attach(a);
    win.wait_for_button();
    //05
    int image_counter=1;
    Image movable_image{Point{0,0},"h.gif"};
    win.attach(movable_image);
    win.wait_for_button();
    while (image_counter<64)
    {
        if (image_counter%8==0)
        {   
            movable_image.move(-700,100);
            win.wait_for_button();
        }
        else
        {
            movable_image.move(100,0);
            win.wait_for_button();
        }
        image_counter++;
    }
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