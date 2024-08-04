#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define in(x,value) cout<<x; cin>>this->value;
#define out(x,value) cout<<x<<this->value<<endl;

class vehicle
{
protected:
    string model;
    int year;
public:
    virtual void displayInfo()  = 0;
    virtual void inputInfo() = 0;
};
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


int main()
{
    vector<vehicle*>data;
    car se;
    truck truck;
    data.push_back(&se);
    data.push_back(&truck);
    for(vehicle *item: data)
    {
        item->inputInfo();
        item->displayInfo();
    }
    return 0;
}