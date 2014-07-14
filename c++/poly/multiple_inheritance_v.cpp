#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>


class BaseVirtual : boost::noncopyable
{
public:
    typedef boost::shared_ptr<BaseVirtual> sptr;

    virtual void print_A() = 0;
    virtual void print_B() = 0;
};

//               Needs virtual inheritance
class BaseImpl : virtual public BaseVirtual
{
public:
    BaseImpl(int x) : A(x), B(x*2)
    {}
    ~BaseImpl();

    void print_A() { std::cout << A << std::endl; };
    void print_B() { std::cout << B << std::endl; };

protected:
    int A;
    int B;
};
BaseImpl::~BaseImpl() {}


//                     Needs virtual inheritance
class DerivedVirtual : virtual public BaseVirtual
{
public:
    typedef boost::shared_ptr<DerivedVirtual> sptr;
};

class DerivedImpl : public DerivedVirtual, public BaseImpl
{
public:
    DerivedImpl(int x) : BaseImpl(x), C(x*3) {};

    // print_B is different, print_A the same!
    void print_B() {
        BaseImpl::print_B(); // We can reuse stuff from BaseImpl
        std::cout << "  C==" << C << std::endl;
    };

private:
    int C;
};


BaseVirtual::sptr make(int x, bool make_derived=false)
{
    if (make_derived) {
        return BaseVirtual::sptr(new DerivedImpl(x));
        //return BaseVirtual::sptr(new BaseImpl(x));
    } else {
        return BaseVirtual::sptr(new BaseImpl(x));
    }
}


int main()
{
    BaseVirtual::sptr ptr1 = make(5);
    std::cout << "Base, print_A:" << std::endl;
    ptr1->print_A();
    std::cout << "Base, print_B:" << std::endl;
    ptr1->print_B();

    BaseVirtual::sptr ptr2 = make(5, true);
    std::cout << "Base, print_A:" << std::endl;
    ptr2->print_A();
    std::cout << "Base, print_B:" << std::endl;
    ptr2->print_B();

    return 0;
}
// vim: sw=4 et:
