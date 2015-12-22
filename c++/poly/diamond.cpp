#include <iostream>

using namespace std;

class A
{
public:
    A() { cout << "--A--" << endl; }; // For virtual inheritance
    A(int x) { cout << "A() " << x << endl; };
};

class B : public virtual A
{
public:
    B(int x) /* : A(x) */ { cout << "B() " << x << endl; }; // A() is not called here
};

class C : public virtual A
{
public:
    C(int x) : A(x) { cout << "C() " << x << endl; }; // ...or here. Even if it's not called further down!
};

class D : public B, public C
{
public:
    //D(int x) : B(x), C(x) { cout << "D() " << x << endl; }; // Won't work
    D(int x) : A(x), B(x), C(x) { cout << "D() " << x << endl; }; // Won't work
};

int main()
{
    D d(5);
    return 0;
}

