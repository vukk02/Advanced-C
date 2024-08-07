#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define in(x,value) cout<<x; cin>>this->value;
#define out(x,value) cout<<x<<this->value<<endl;

class car
{
protected:
    string model;
    int year;
public:
    virtual void displayInfo()  = 0;
    virtual void inputInfo() = 0;
};
class sedan: public car
{
private:
    int a;
public:
    void displayInfo()  override;
    void inputInfo() override; 
};
class suv: public car
{
private:
    int b;
public:
    void displayInfo()  override;
    void inputInfo() override; 
};
void sedan::inputInfo()
{
    in("a: ",a);
    in("model: ",model);
    in("year: ",year);
    
}
void sedan::displayInfo()
{
    out("a: ",a);
    out("model: ",model);
    out("year: ",year);
}
void suv::inputInfo()
{
    in("b: ",b);
    in("model: ",model);
    in("year: ",year);
    
}
void suv::displayInfo()
{
    out("b: ",b);
    out("model: ",model);
    out("year: ",year);
}


int main()
{
    vector<car*>data;
    sedan se;
    suv suv;
    data.push_back(&se);
    data.push_back(&suv);
    for(car *item: data)
    {
        item->inputInfo();
        item->displayInfo();
    }
    return 0;
}