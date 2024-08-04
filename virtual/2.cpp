#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define in(x,value) cout<<x; cin>>this->value;
#define out(x,value) cout<<x<<this->value<<endl;

class engine
{
protected:
    string type;
public:
    virtual void displayInfo()  = 0;
};
class petroengine : public engine
{
public:
    void displayInfo()  override;
    petroengine();
};
class dieselengine : public engine
{
public:
    void displayInfo()  override;
    dieselengine();
};
petroengine::petroengine()
{
    this->type = "petro";
}
dieselengine::dieselengine()
{
    this->type = "diesel";
}
void petroengine::displayInfo()
{
    cout<<"engine: petro"<<endl;
}
void dieselengine:: displayInfo()
{
    cout<<"engine: diesel"<<endl;
}
class car
{
protected:
    string model;
    int year;
    engine* engine;
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
    int c;
    cout<<"Enter 1 is petro"<<endl;
    cout<<"Enter 2 is diesel"<<endl;
    cin>>c;
    if (c==1)
    {
        
        this->engine = new petroengine ;
    }
    else if( c==2)
    {
        
        this->engine = new petroengine;
    }
    
}
void sedan::displayInfo()
{
    out("a: ",a);
    out("model: ",model);
    out("year: ",year);
    engine->displayInfo();
}
void suv::inputInfo()
{
    in("b: ",b);
    in("model: ",model);
    in("year: ",year);
    int d;
    if (d==1)
    {
        
        this->engine = new petroengine ;
    }
    else if( d==2)
    {
        ;
        this->engine = new dieselengine ;
    }
    
}
void suv::displayInfo()
{
    out("b: ",b);
    out("model: ",model);
    out("year: ",year);
    engine->displayInfo();
}


int main()
{   
    petroengine p;
    dieselengine d;
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