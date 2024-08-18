


#include "../Header/manager.hpp"
#include "../Header/menu.hpp"
#include "../Header/staff.hpp"
#include "../Header/dish.hpp"



list<dish> manager::getMenu()
{
    return menu;
}
void manager::settable()
{  
    cout<<"   Set up number of table\n\n";
    int option;
    int num;
    again:
    cout<<"Enter number of table: ";
    cin>>num;
    this->table = num;
    cout<<"----------"<<endl;
    cout<<"Set up successful"<<endl;
    PRINT_MENU("Back","Exit");
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break) 
    );

}
int manager::gettable()
{
    return this->table;
}
void manager::adddish()
{
    cout<<"   Add new dish\n\n";
    int option;
    int price;
    string name;
    again:
    cout<<"Enter name: ";cin>>name;
    cout<<"Enter price: ";cin>>price;
    dish a;
    a.setname(name);
    a.setprice(price);
    menu.push_back(a);
    cout<<"-----------";
    cout<<"Information of dish:"<<endl;
    cout<<"STT\tID\tName\tPrice"<<endl;
    cout<<"1\t"<<a.getid()<<"\t"<<a.getname()<<"\t"<<a.getprice()<<endl;
    cout<<"Add dish successful"<<endl;
    cout<<"Do you want to add another dish ?"<<endl;
    PRINT_MENU("Add another dish","Back");
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break) 
    );

}
void manager::updatedish()
{
    cout<<"   Update dish\n\n";
    int option;
    int price;
    string name;
    int id;
    int i;
    int num=0;
    again:
    i=0;
    cout<<"STT\tID\tName\tPrice"<<endl;
    for(dish &item : menu)
    {
        cout<<++num<<"\t"<<item.getid()<<"\t"<<item.getname()<<"\t"<<item.getprice()<<endl;
    }
    cout<<"Please enter id of dish you want to fix: ";cin>>id;
    cout<<"------------"<<endl;
    num=0;
    for(dish &item :this->menu)
    {
        if( item.getid() == id )
        {
            i++;
            cout<<"STT\tID\tName\tPrice"<<endl;
            cout<<"1\t"<<item.getid()<<"\t"<<item.getname()<<"\t"<<item.getprice()<<endl;
            cout<<"Enter new price: ";cin>>price;
            item.setprice(price);
            cout<<"Update successful"<<endl;
        }
    }
    if( i==0)
    {
        cout<<"ID not found"<<endl;
    }
    cout<<"Do you want to update another dish ?"<<endl;
    PRINT_MENU("Update another dish","Back");
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break) 
    );



}
void manager::deletedish()
{
    cout<<"   Delete dish\n\n";
    int option;
    int price;
    string name;
    int id;
    int i;
    int num=0;
    list<dish>::iterator it;
    again:
    i=0;
    cout<<"STT\tID\tName\tPrice"<<endl;
    for(dish &item : menu)
    {
        cout<<++num<<"\t"<<item.getid()<<"\t"<<item.getname()<<"\t"<<item.getprice()<<endl;
    }
    cout<<"Please enter id of dish you want to delete: ";cin>>id;
    cout<<"------------"<<endl;
    num=0;
    for (it = menu.begin(); it != menu.end(); ++it)
    {
        if (it->getid() == id)
        {
            i++;
            menu.erase(it);
            cout<<"Delete successful"<<endl;
            cout<<"--------"<<endl;
            goto next;
            
        }
    }
    next:
    if( i==0)
    {
        cout<<"ID not found"<<endl;
    }
    i=0;
    cout<<"Do you want to delete another dish ?"<<endl;
    PRINT_MENU("Delete another dish","Back");
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break) 
    );
}
void manager::list_dish()
{
    cout<<"   List of dishes\n\n";
    int num = 0;
    int option;
    cout<<"STT\tID\tName\tPrice"<<endl;
    for(dish &item : menu)
    {
        cout<<++num<<"\t"<<item.getid()<<"\t"<<item.getname()<<"\t"<<item.getprice()<<endl;
    }
    cout<<"0. Back"<<endl;
    cout<<"Please select function"<<endl;
    cout<<"-----------"<<endl;
    cin>>option;
}
