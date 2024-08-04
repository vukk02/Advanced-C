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
class vehicle
{
protected:
    string model;
    int year;
    vector<service*>services;
public:
    virtual void displayInfo() = 0;
    virtual void inputInfo() = 0;
    void addService(service* service);
    void performServices() ;

};

void vehicle::addService(service* service)
{
    services.push_back(service);
}
void vehicle::performServices()
{
    for(service *item: services)
    {
        item->performService();
    }
}

class car: public vehicle
{
private:
    int a;
public:
    void displayInfo()  override;
    void inputInfo() override; 
};
class truck: public vehicle
{
private:
    int b;
public:
    void displayInfo()  override;
    void inputInfo() override; 
};
class motorcycle: public vehicle
{
private:
    int b;
public:
    void displayInfo()  override;
    void inputInfo() override; 
};
void car::inputInfo()
{
    in("a: ",a);
    in("model: ",model);
    in("year: ",year);
    
}
void car::displayInfo()
{
    out("a: ",a);
    out("model: ",model);
    out("year: ",year);
}
void truck::inputInfo()
{
    in("b: ",b);
    in("model: ",model);
    in("year: ",year);
    
}
void truck::displayInfo()
{
    out("b: ",b);
    out("model: ",model);
    out("year: ",year);
}
void motorcycle::inputInfo()
{
    in("b: ",b);
    in("model: ",model);
    in("year: ",year);
    
}
void motorcycle::displayInfo()
{
    out("b: ",b);
    out("model: ",model);
    out("year: ",year);
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