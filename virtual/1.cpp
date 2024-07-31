#include <iostream>
#include <vector>
#include <string>

class Shape {
public:
    virtual void display() = 0; // Hàm thuần ảo
    
};

class Rectangle : public Shape {
public:
    void display() override {
        std::cout << "This is a rectangle." << std::endl;
    }
};

class Circle : public Shape {
public:
    void display() override {
        std::cout << "This is a circle." << std::endl;
    }
};

int main(){
    Rectangle rec;
    Circle cir;
    std::vector<Shape*> shape;
    shape.push_back(&rec);
    shape.push_back(&cir);
    for(int i = 0;i < shape.size();i++)
    {
        shape[i]->display();
    }
    for(Shape* i : shape)
    {
        i->display();
    }

    return 0;
}