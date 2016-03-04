#include <iostream>

class A
{
public:
    A() {};
    virtual ~A() {};

    virtual void print_this() { std::cout << "A" << std::endl; }
};

class print0r
{
public:
    print0r(A* A_ptr) : _A_ptr(A_ptr) {};

    void print() { _A_ptr->print_this(); };

    void check_C();

    A* _A_ptr;
};

class B : public A
{
public:
    B() : A() { _print0r = new print0r(this); };
    virtual ~B() {};

    virtual void print_this() { std::cout << "B" << std::endl; }

    void call_printor() { _print0r->print(); };
    void check_C() { _print0r->check_C(); };

    print0r* _print0r;
};

class C : public B
{
public:
    C() : B() {};
    virtual ~C() {};

    virtual void print_this() { std::cout << "C" << std::endl; }
};


void print0r::check_C() { if (dynamic_cast<C*>(_A_ptr)) std::cout << "Yep, it's C." << std::endl; };

int main(int argc, const char *argv[])
{
    C C_inst;
    C_inst.call_printor();
    C_inst.check_C();
    return 0;
}
