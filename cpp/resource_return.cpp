#include <memory>

struct X
{
  int a[100];
  void foo() {}
};

typedef std::auto_ptr<X> RETURN;
//typedef X * RETURN;
//#define RETURN X*

RETURN Xfactory() // Resource ownership explicitely transferred to the caller.
{
    return RETURN(new RETURN::element_type); // Dynamically allocated instance
}
int main (void)
{
  //RETURN r;
  RETURN r = Xfactory();
  r->foo(); // Dynamically allocated instance of X does not leak here
  return 0;
}

