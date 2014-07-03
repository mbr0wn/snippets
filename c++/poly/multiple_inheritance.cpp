#include <iostream>

class A
{
  public:
	A() {};
	~A() {};

  protected:
	int attr_A;
};

class B
{
  public:
	B() {};
	~B() {};

  protected:
	int attr_B;
};


class C : public A, public B
{
 public:
	C() : A(), B()
	{
		attr_A = 1;
		attr_B = 2;
		attr_C = 3;
	}
	~C() {};

	void print_attrs()
	{
		std::cout << "A == " << attr_A << std::endl;
		std::cout << "B == " << attr_B << std::endl;
		std::cout << "C == " << attr_C << std::endl;
	};

 private:
	int attr_C;
};


int main()
{
	C c;
	c.print_attrs();
	return 0;
}
