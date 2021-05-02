#include "std_lib_facilities.h"

struct Item
{
    string name;
    int iid;
    double value;
    Item():name(),iid(0),value(0){}
    Item(string nam,int id,double val):name(nam),iid(id),value(val){}
};

istream& operator>>(istream& is,Item& it)
{
    string name;
    int iid;
    double value;
    is>>name>>iid>>value;
    if(!is)
    {
        return is;
    }
    it=Item(name,iid,value);
    return is;
}

bool sort_by_name(Item& a,Item& b)
{
return a.name<b.name;
}
bool sort_by_iid(Item& a,Item& b)
{
return a.iid<b.iid;
}
bool sort_by_value(const Item& a,Item& b)
{
return a.value<b.value;
}

void writev(vector<Item> vi)
{
    cout<<"---------------------------------------------------"<<endl;
    for (int i = 0; i < vi.size(); i++)
    {
        cout<<vi[i].name<<" "<<vi[i].iid<<" "<<vi[i].value<<endl;
    }
    cout<<"---------------------------------------------------"<<endl;
}
void writel(list<Item> li)
{
    list<Item>::iterator it;
    cout<<"---------------------------------------------------"<<endl;
    for (it=li.begin();it!=li.end();it++)
    {
        cout<<it->name<<" "<<it->iid<<" "<<it->value<<endl;
    }
    cout<<"---------------------------------------------------"<<endl;
}
class Find_by_name{
    string name;
    public:
        Find_by_name(const string& s): name(s){}
        bool operator()(const Item& it)const
        {
            return it.name==name;
        }
};
class Find_by_iid{
    int iid;
    public:
        Find_by_iid(const int& s): iid(s){}
        bool operator()(const Item& it)const
        {
            return it.iid==iid;
        }
};
void reading(map<string,int>& msi)
{
    string b;    
    int a;
    cin>>b>>a;
    msi.insert(pair<string,int>(b,a));

}
int main()
{
    //Vector
    vector<Item> vi;
    ifstream ifs("a.txt");
    if(!ifs)
    {
        error("Something bad happend");
    }
    Item item;
    while (ifs>>item)
    {
        vi.push_back(item);
    }
    ifs.close();
    writev(vi);
    sort(vi.begin(),vi.end(),sort_by_name);
    writev(vi);
    sort(vi.begin(),vi.end(),sort_by_iid);
    writev(vi);
    sort(vi.begin(),vi.end(),sort_by_value);
    reverse(vi.begin(),vi.end());
    writev(vi);

    vi.insert(vi.end(),Item("horse shoe",99,12.34));
    vi.insert(vi.end(),Item("Canon S400",9988,499.95));
    vector<Item>::iterator vi_iter=find_if(vi.begin(),vi.end(),Find_by_name("Paper"));
    vi.erase(vi_iter);
    vi_iter=find_if(vi.begin(),vi.end(),Find_by_name("Pencil"));
    vi.erase(vi_iter);
    writev(vi);

    vi_iter=find_if(vi.begin(),vi.end(),Find_by_iid(4));
    vi.erase(vi_iter);
    vi_iter=find_if(vi.begin(),vi.end(),Find_by_iid(5));
    vi.erase(vi_iter);
    writev(vi);
    //-------------------------------------------------------------------------
    //lista
    list<Item> li;
    ifstream ifsl("a.txt");
    if(!ifsl)
    {
        error("Something bad happend");
    }
    Item itemli;
    while (ifsl>>itemli)
    {
        li.insert(li.end(),itemli);
    }
    ifsl.close();

    writel(li);
    li.sort(sort_by_name);
    writel(li);
    li.sort(sort_by_iid);
    writel(li);
    li.sort(sort_by_value);
    reverse(li.begin(),li.end());
    writel(li);

    li.insert(li.end(),Item("horse shoe",99,12.34));
    li.insert(li.end(),Item("Canon S400",9988,499.95));
    list<Item>::iterator li_iter=find_if(li.begin(),li.end(),Find_by_name("Paper"));
    li.erase(li_iter);
    li_iter=find_if(li.begin(),li.end(),Find_by_name("Pencil"));
    li.erase(li_iter);
    writel(li);

    li_iter=find_if(li.begin(),li.end(),Find_by_iid(4));
    li.erase(li_iter);
    li_iter=find_if(li.begin(),li.end(),Find_by_iid(5));
    li.erase(li_iter);
    writel(li);
    //map
    map<string,int> msi;
    msi.insert(pair<string,int>("a",1));
    msi.insert(pair<string,int>("b",20));
    msi.insert(pair<string,int>("c",31));
    msi.insert(pair<string,int>("d",41));
    msi.insert(pair<string,int>("e",15));
    msi.insert(pair<string,int>("f",26));
    msi.insert(pair<string,int>("g",457));
    msi.insert(pair<string,int>("h",38));
    msi.insert(pair<string,int>("i",91));
    msi.insert(pair<string,int>("j",10));
    map<string,int>::iterator msiitr;
    for (msiitr=msi.begin();msiitr!=msi.end();msiitr++)
    {
        cout<<msiitr->first<<" "<<msiitr->second<<endl;
    }
    typedef map<string,int>::const_iterator msicitr;
    msicitr p=msi.begin();
    while (p!=msi.end())
    {
        p=msi.erase(p);
    }
    /*
    for (int i = 0; i < 2; i++)
    {
        reading(msi);
    }
    */
    for (msiitr=msi.begin();msiitr!=msi.end();msiitr++)
    {
        cout<<msiitr->first<<" "<<msiitr->second<<endl;
    }
    int sum=0;
    for (msiitr=msi.begin();msiitr!=msi.end();msiitr++)
    {
        sum+=msiitr->second;
    }
    cout<<"Sum:"<<sum<<endl;
    map<int,string> mis;
    for (msiitr=msi.begin();msiitr!=msi.end();msiitr++)
    {
        mis.insert(pair<int,string>(msiitr->second,msiitr->first));
    }
    //--------------------------------------------------------------
    //vector again
    vector<double> vd;
    ifstream ifsd("f.txt");
    if(!ifsd)
    {
        error("Something bad happend");
    }
    double d;
    while (ifsd>>d)
    {
        vd.push_back(d);
    }
    ifsd.close();
    for (int i=0;i<vd.size();i++)
    {
        cout<<vd[i]<<endl;
    }
    vector<int> vii;
    for (int i = 0; i < 16; i++)
    {
        vii.push_back(i);
    }
    for (int i = 0; i < vii.size(); i++)
    {
       cout<<vd[i]<<" "<<vii[i]<<endl;
    }
    double sumvd=0;
    for (int i = 0; i < vd.size(); i++)
    {
        sumvd+=vd[i];
    }
    cout<<"sumvd:"<<sumvd<<endl;
    int sumiid=0;
    for (int i = 0; i < vii.size(); i++)
    {
        sumiid=vii[i];
    }
    cout<<"Diff:"<<sumvd-sumiid<<endl;
    reverse(vd.begin(),vd.end());
    for (int i=0;i<vd.size();i++)
    {
        cout<<vd[i]<<endl;
    }
    cout<<"Avg:"<<sumvd/vd.size()<<endl;
    vector<double> vd2;
    for (int i=0;i<vd.size();i++)
    {
        if(vd[i]>=sumvd/vd.size())
        {
            vd2.push_back(vd[i]);
        }
    }
    sort(vd.begin(),vd.end());
    for (int i=0;i<vd.size();i++)
    {
        cout<<vd[i]<<endl;
    }
    return 0;
}