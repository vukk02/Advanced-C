#include <iostream>
#include <string>

using namespace std;


int sum(int a, int b)
{
    return a+b;
}
int sum(int a, int b, int c)
{
    return a+b+c;
}
double sum(double a, double b)
{
    return a+b;
}





int main()
{

    cout << "Sum: " << sum(1,2) << endl;
    cout << "Sum: " << sum(2.5,3.7) << endl;
    cout << "Sum: " << sum(1,2,3) << endl;

    return 0;
}

