#include "std_lib_facilities.h"


struct Person {
    Person() : first_n(""), second_n(""), a(0) { }
    Person(string fn, string sn, int age) :first_n(fn), second_n(sn), a(age)
    {
        string illegal_characters = ";:\"'[]*&^%$#@!";
        for (int i = 0; i<fn.size(); i++)
        {
            for (int j = 0; j<illegal_characters.size();j++)
            { 
                if (fn[i]==illegal_characters[j]) 
                {
                    error("Illegal character in the first name");
                }
            }
        }
        for (int i = 0; i<sn.size(); i++)
        {
            for (int j = 0; j<illegal_characters.size(); j++)
            {
                if (sn[i]==illegal_characters[j]) 
                {
                    error("Illegal character in the second name");
                }
            }
        }
        if (a<0 || a>=150) 
        {
            error("Age must be between 0 and 150");
        }
    }
    string first_name() const 
    { 
        return first_n;
    }
    string second_name() const 
    { 
        return second_n;
    }
    int age() const 
    { 
        return a; 
    }
private:
    string first_n;
    string second_n;
    int a;
};

istream& operator>>(istream& is, Person& p)
{

    string first_name, second_name;
    int age;
    is >> first_name >> second_name >> age;
    if (!is)
    {
        return is;
    }
    p = Person(first_name,second_name,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Name: " << p.first_name() << ' ' << p.second_name() << ", age: " << p.age();
}

int main()
try
{
    vector<Person> persons;
    Person person;
    while (cin>>person)
    {
        persons.push_back(person);
    }
    for (int i = 0; i<persons.size(); i++)
    {
        cout << persons[i] << endl;
    }
    return 0;
}
catch(exception& e)
{
    cerr<<e.what()<<endl;
    return 1;
}