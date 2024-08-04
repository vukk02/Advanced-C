#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define in(x,value) cout<<x; cin>>this->value;
#define out(x,value) cout<<x<<this->value<<endl;

class service
{
public:
    virtual void performService()  = 0;
};
class oilchange: public service
{
public:
    void performService() override;
};
class tirerotation: public service
{
    void performService() override;
};
void oilchange::performService()
{
    cout<<"thay dau"<<endl;

}
void tirerotation::performService()
{
    cout<<"quay lop"<<endl;

}
class car
{
private:
    string model;
    int year;
    vector<service*>services;
public:
    void displayInfo() ;
    void inputInfo();
    void addService(service* service);
    void performServices() ;

};
void car::inputInfo()
{
   
    in("model: ",model);
    in("year: ",year);
    
}
void car::displayInfo()
{
    
    out("model: ",model);
    out("year: ",year);
}
void car::addService(service* service)
{
    services.push_back(service);
}
void car::performServices()
{
    for(service *item: services)
    {
        item->performService();
    }
}


int main()
{
    car c;
    service *s;
    tirerotation t;
    oilchange o;
    s=&t;
    c.addService(s);
    s=&o;
    c.addService(s);
    c.performServices();
    return 0;
}