#include "std_lib_facilities.h"

class B1
{
    public:
        virtual void vf()
        {
            cout<<"B1::vf()"<<endl;
        }
        void f()
        {
            cout<<"B1::f()"<<endl;
        }
};

class D1:public B1
{
    public:
        void vf() override{
            cout<<"D1::vf()"<<endl;
        }
        void f(){
            cout<<"D1::f()"<<endl;
        }
        virtual void pvf()
        {
            cout<<"D1::pvf()"<<endl;
        }
};
class D2:public D1{
    public:
        void pvf() override{
            cout<<"D2::pvf()"<<endl;
        }
};

class B2
{
    public:
        virtual void pvf(){
            cout<<"B2::pvf()"<<endl;
        }
};

class D21:public B2 
{
    string data="D21::pvf()";
    public:
        void pvf() override{
            cout<<data<<endl;
        }
};

class D22:public B2 
{
    int data=10;
    public:
        void pvf() override{
            cout<<data<<endl;
        }
};

void f(B2& b2ref){
    b2ref.pvf();
}

int main()
try{
    //01
    B1 b1;
    b1.vf();
    b1.f();
    //02
    D1 d1;
    d1.vf();
    d1.f();
    //03
    B1& b1Ref=d1;
    b1Ref.vf();
    b1Ref.f();
    //06
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();
    //07
    B2 b2;
    D21 d21;
    D22 d22;
    f(d21);
    f(d22);

    return 0;
}catch(exception& e)
{
    cerr << e.what() <<endl;
    return 1;
}
