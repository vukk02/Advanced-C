


#include "../Header/staff.hpp"
#include "../Header/menu.hpp"
#include "../Header/manager.hpp"


void staff::resizeTables(int newsize)
{
    tables.resize(newsize);
}
void staff::setnumtable(int num)
{
    this->numtable = num;
}
string staff::getstatus(int num)
{
    return tables[num].status;
}
int staff::getnumtable()
{
    return this->numtable;
}

void staff::setmenu( list<dish>menu1 )
{
    this->menu = menu1;
}
void staff::order()
{
    cout<<"   Order\n\n";
    tables[numtable].status="x";
    int a = 0;
    int option;
    int id,price;
    string name;
    int num;
    int i=0,j=0;
    again:
    cout<<"STT\tID\tName\tPrice"<<endl;
    for(dish &item : menu)
    {
        cout<<++a<<"\t"<<item.getid()<<"\t"<<item.getname()<<"\t"<<item.getprice()<<endl;
    }
    a=0;
    cout<<"----------"<<endl;
    cout<<"Please enter id of dish: ";cin >>id;
    cout<<"STT\tID\tName\tPrice"<<endl;
    for(dish &item : menu)
    {   
        if(item.getid() == id)
        {
            cout<<++a<<"\t"<<item.getid()<<"\t"<<item.getname()<<"\t"<<item.getprice()<<endl;
            name = item.getname();
            price = item.getprice();
            i++;
        }
    }
    a=0;
    if( i==0)
    {
        cout<<"ID not found"<<endl;
        goto next;
    }
    i=0;
    
    cout<<"----------"<<endl;
    cout<<"Please enter number of dish : ";cin>>num;
    for(Order &item : tables[numtable].ta)
    {
        if(item.di.getname()==name)
        {
            item.num = num;
            j++;
        }
        
    }
    if(j==0)
    {
        Order o;
        o.di.setid(id);
        o.di.setname(name);
        o.di.setprice(price);
        o.num = num;
        tables[numtable].ta.push_back(o);
    }
    j=0;

    cout<<"STT\tID\tName\tPrice\tNumber"<<endl;
    for(Order &item : tables[numtable].ta)
    {
        if(item.di.getid()==id)
        {
            cout<<++a<<"\t"<<item.di.getid()<<"\t"<<item.di.getname()<<"\t"<<item.di.getprice()<<"\t"<<item.num<<endl;
        }
        
    }
    
    a=0;
    next:
    cout<<"Do you want to order another dish ?"<<endl;
    PRINT_MENU("Order another dish","Back");
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break) 
    );
}

void staff::cancle()
{
    cout<<"   Cancle\n\n";
    int a = 0;
    int option;
    int id,price;
    string name;
    int num;
    int i=0,j=0;
    list<Order>::iterator it;

    again:

    cout<<"STT\tID\tName\tPrice\tNumber"<<endl;
    for(Order &item : tables[numtable].ta)
    {
        cout<<++a<<"\t"<<item.di.getid()<<"\t"<<item.di.getname()<<"\t"<<item.di.getprice()<<"\t"<<item.num<<endl;
            
    }
    cout<<"---------------"<<endl;
    a=0;
    cout<<"Please enter id of dish: ";cin >>id;
    for(it = tables[numtable].ta.begin(); it != tables[numtable].ta.end(); ++it)
    {
        if(it->di.getid()==id)
        {   
            cout<<"STT\tID\tName\tPrice\tNumber"<<endl;
            cout<<++a<<"\t"<<it->di.getid()<<"\t"<<it->di.getname()<<"\t"<<it->di.getprice()<<"\t"<<it->num<<endl;
            cout<<"Please enter number of dish : ";cin>>num;
            it->num = it->num - num;
            if (it->num<=0)
            {
                tables[numtable].ta.erase(it);
            }
            cout<<"--------------"<<endl;
            cout<<"Cancle successful"<<endl;
            goto next;
        }
        
    }
    next:
    cout<<"Do you want to cancle another dish ?"<<endl;
    PRINT_MENU("Cancle another dish","Back");
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break) 
    );
    
}
void staff::list_ordered()
{
    cout<<"   List of ordered\n\n";
    int a=0;
    int option;
    cout<<"STT\tID\tName\tPrice\tNumber"<<endl;
    for(Order &item : tables[numtable].ta)
    {
        cout<<++a<<"\t"<<item.di.getid()<<"\t"<<item.di.getname()<<"\t"<<item.di.getprice()<<"\t"<<item.num<<endl;
            
    }
    cout<<"---------------"<<endl;
    cout<<"0. Back"<<endl;
    cout<<"Please select function"<<endl;
    cout<<"-----------"<<endl;
    cin>>option;

}

void staff::checkout()
{
    cout<<"   List of ordered\n\n";
    int a=0;
    int option;
    int sum=0;
    int t=0;
    cout<<"STT\tID\tName\tPrice\tNumber"<<endl;
    for(Order &item : tables[numtable].ta)
    {
        cout<<++a<<"\t"<<item.di.getid()<<"\t"<<item.di.getname()<<"\t"<<item.di.getprice()<<"\t"<<item.num<<endl;
        sum = sum + item.di.getprice()*item.num;
    }
    cout<<"---------------"<<endl;
    t = sum*110/100;
    cout<<"Sum: "<<sum<<endl;
    cout<<"VAT: 10%"<<endl;
    cout<<"Total cost: "<<t<<endl;

    PRINT_MENU("Checkout","Back");
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto checkout)
        CASE_OPTION(0, goto end) 
    );
    checkout:
    tables[numtable].ta.clear();
    tables[numtable].status = "o";
    cout<<"Checkout successful"<<endl;
    end:;
    
}
