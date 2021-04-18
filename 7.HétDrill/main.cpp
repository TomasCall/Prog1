#include "std_lib_facilities.h"

template<typename T>struct S
{
    private:
        T val;
    public:
        S():val(T()){};
        S(T d):val(d){};
        T& get();
        const T& get() const;
        void set(const T& d);
        T& operator=(const T&);
};

template<typename T> T& S<T>::get()
{
    return val;
}

template<typename T> void S<T>::set(const T& d)
{
    val=d;
}

template<typename T> T& S<T>::operator=(const T& d)
{
    val=d;
    return val;
}

template<typename T> const T& S<T>::get()const
{
    return val;
}

template<typename T> istream& operator>>(istream& is,S<T>& ss)
{
    T v;
    cin>>v;
    if(!is)
    {
        return is;
    }
    ss=v;
    return is;
}

template<typename T> void readval(T& v)
{
    cin>>v;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) 
    {
        os << d[i];
        if (i<d.size()-1)
        {
            os << ',';
        } 
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is)
    {
        return is;
    }
    if (ch1!='{') 
    {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin>>temp>>ch2 && ch2==',') 
    {
        v_temp.push_back(temp);
    }
    if (ch2!='}') 
    {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp);
    d = v_temp;
}

int main()
{
    //Initalize
    S<int> s_int(5);
    S<double> s_double(2.5);
    S<string> s_string("aha");
    S<char> s_char('a');
    vector<int> a={0,1,2,3,4};
    S<vector<int>> s_vect_int(a);
    
    //Write
    cout<<"s_int:"<<s_int.get()<<endl;
    cout<<"s_double:"<<s_double.get()<<endl;
    cout<<"s_string:"<<s_string.get()<<endl;
    cout<<"s_char"<<s_char.get()<<endl;
    cout<<"s_vect_int:{";
    for(int i=0;i<s_vect_int.get().size();i++)
    {
        if(i!=s_vect_int.get().size()-1)
        {
            cout<<s_vect_int.get()[i]<<",";
        }
        else
        {
            cout<<s_vect_int.get()[i];
        }
    }

    cout<<"}"<<endl;

    s_int.set(3);
    s_double.set(0.567);
    s_string.set("AHAHAHA");
    s_char.set('b');
    //Write
    cout<<"s_int:"<<s_int.get()<<endl;
    cout<<"s_double:"<<s_double.get()<<endl;
    cout<<"s_string:"<<s_string.get()<<endl;
    cout<<"s_char"<<s_char.get()<<endl;
    cout<<"s_vect_int:{";
    for(int i=0;i<s_vect_int.get().size();i++)
    {
        if(i!=s_vect_int.get().size()-1)
        {
            cout<<s_vect_int.get()[i]<<",";
        }
        else
        {
            cout<<s_vect_int.get()[i];
        }
    }
    cout<<"}"<<endl;

    s_int=45;
    s_double=56;
    s_string="C++";
    s_char='c';
    s_vect_int={0,11,1};
    //Write
    cout<<"s_int:"<<s_int.get()<<endl;
    cout<<"s_double:"<<s_double.get()<<endl;
    cout<<"s_string:"<<s_string.get()<<endl;
    cout<<"s_char"<<s_char.get()<<endl;
    cout<<"s_vect_int:{";
    for(int i=0;i<s_vect_int.get().size();i++)
    {
        if(i!=s_vect_int.get().size()-1)
        {
            cout<<s_vect_int.get()[i]<<",";
        }
        else
        {
            cout<<s_vect_int.get()[i];
        }
    }
    cout<<"}"<<endl;

    cout<<"s_int:";
    readval(s_int);
    cout<<"s_double:";
    readval(s_double);
    cout<<"s_string";
    readval(s_string);
    cout<<"s_char:";
    readval(s_char);

    cout<<endl;
    cout<<"s_vect_int:";
    readval(s_vect_int);
    cout<<endl;
    cout<<"s_vect_int:"<<s_vect_int.get()<<endl;
    return 0;
}