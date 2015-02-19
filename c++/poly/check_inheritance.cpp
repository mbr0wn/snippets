#include <boost/type_traits.hpp>
#include <iostream>
#include <typeinfo> // std::bad_cast

using namespace std;

class A
{
  public:
    A() {};
    virtual ~A() {};
};

class B
{
  public:
    B() {};
    virtual ~B() {};
};

class X
{
  public:
    X() {};
    virtual ~X() {};
};


class C : public A, public B
{
  public:
    C() : A(), B() {}
    virtual ~C() {}; // Virtual d'tor is required or dynamic_cast won't work

    template <typename T>
    bool is_a()
    {
        try {
            const T *conv_ptr = dynamic_cast<T*>(this);
            return (conv_ptr != NULL);
        } catch (bad_cast &e) {
            // This should never be thrown since we only convert
            // one pointer to another.
            return false;
        }
    }
};


int main()
{
    // Template programming:
    cout << "is C a B? " << ((boost::is_base_of<B, C>::value) ? "Yes" : "No") << endl;
    cout << "is C a X? " << ((boost::is_base_of<B, X>::value) ? "Yes" : "No") << endl;

    C c;
    cout << "is c a B? " << (c.is_a<B>() ? "Yes" : "No") << endl;
    cout << "is c a X? " << (c.is_a<X>() ? "Yes" : "No") << endl;

    return 0;
}

