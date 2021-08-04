#include<iostream>
using namespace std;
class Foo
{
public:
    // single parameter constructor, can be used as an implicit conversion
    Foo (int foo) : m_foo (foo)             // this means m_foo=foo;    --- mention Explicit keyword before Foo
    {
    }

    int GetFoo () { return m_foo; }

private:
    int m_foo;
};

//Here's a simple function that takes a Foo object:

void DoBar (Foo foo)            // object foo declared which calls the constructor
{
    int i = foo.GetFoo ();
}

//and here's where the DoBar function is called:

int main ()
{
    DoBar (42);
}

/*the argument is not a Foo object, but an int. However, there exists a constructor
 for Foo that takes an int so this constructor can be used to convert the parameter to the correct type.

The compiler is allowed to do this once for each parameter.

Prefixing the explicit keyword to the constructor prevents the compiler from using that constructor for implicit conversions.
 Adding it to the above class will create a compiler error at the function call DoBar (42).
It is now necessary to call for conversion explicitly with DoBar (Foo (42))*/