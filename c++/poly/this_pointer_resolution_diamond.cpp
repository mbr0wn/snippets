#include <iostream>

class A
{
public:
    A() {}; virtual ~A() {};

    //virtual void print_this() { std::cout << "A" << std::endl; }
    virtual void print_this() = 0;
};

class print0r
{
public:
    print0r(A* A_ptr) : _A_ptr(A_ptr) {};

    void print() { _A_ptr->print_this(); };

    void check_B();
    void check_C();
    void check_D();

    A* _A_ptr;
};

class B : virtual public A
{
public:
    B() : A() { _print0r = new print0r(this); };
    virtual ~B() {};

    void call_printor() { _print0r->print(); };
    print0r* _print0r;
};

class C : virtual public A
{
public:
    C() : A() {};
    virtual ~C() {};
    virtual void print_this() { std::cout << "C" << std::endl; }
};

class D : public B, public C
{
public:
    D() : A(), B(), C() {};
    virtual ~D() {};

    void check_B() { _print0r->check_B(); };
    void check_C() { _print0r->check_C(); };
    void check_D() { _print0r->check_D(); };
};

void print0r::check_B() { if (dynamic_cast<B*>(_A_ptr)) std::cout << "Yep, it's B." << std::endl; };
void print0r::check_C() { if (dynamic_cast<C*>(_A_ptr)) std::cout << "Yep, it's C." << std::endl; };
void print0r::check_D() { if (dynamic_cast<D*>(_A_ptr)) std::cout << "Yep, it's D." << std::endl; };

int main(int argc, const char *argv[])
{
    D D_inst;
    D_inst.call_printor();
    D_inst.check_B();
    D_inst.check_C();
    D_inst.check_D();
    return 0;
}
