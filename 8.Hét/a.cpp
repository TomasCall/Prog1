#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9}; 

    std::array<int, 10> ai={0,1,2,3,4,5,6,7,8,9};

    std::vector<int> vi={0,1,2,3,4,5,6,7,8,9};

    std::list<int> li={0,1,2,3,4,5,6,7,8,9};

    std::array<int, 10> ai2 = ai;
    std::vector<int> vi2 = vi;
    std::list<int> li2 = li;

    for (std::array<int, 10>::iterator p=ai2.begin();p!=ai2.end();p++)
    {
        *p+=2;
    }
    
    for (std::vector<int>::iterator p=vi2.begin();p!=vi2.end();p++)
    {
        *p+=3;
    }
    
    for (std::list<int>::iterator p=li2.begin();p!=li2.end();p++)
    {
        *p+=5;
    }

    my_copy(ai2.begin(), ai2.end(), vi2.begin());
    my_copy(li2.begin(), li2.end(), ai2.begin());

    std::vector<int>::iterator vit;
    vit = std::find(vi2.begin(), vi2.end(), 3);
    if (vit != vi2.end())
    {
        std::cout << "Keresett szam pozicioja: " <<vit-vi2.begin()<<std::endl;
    }
    else
    {
        std::cout << "Nincsben a vektorban"<<std::endl;
    }

    std::list<int>::iterator lit;
    lit = std::find(li2.begin(), li2.end(), 27);
    if (lit != li2.end())
    {
        int position=0;
        for (std::list<int>::iterator p=li2.begin();p!=lit;p++)
        {
           position++;
        }
        
        std::cout << "27 pozicioja:" << position << std::endl;
    }
    else
    {
        std::cout << "Nincs benne a listaban"<<std::endl;
    }
}