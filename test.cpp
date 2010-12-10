#include <iostream>

#include "elem.h"
#include "testclass.h"

void testElem(HTyo::TestClass&);

int main() {
  std::cout << "Testing started" << std::endl;

  HTyo::TestClass test(1);
  testElem(test);

  std::cout << test.report() << std::endl;

  return 0;
}

void testElem(HTyo::TestClass& test) {
  using HTyo::Elem;
  using std::cout;
  using std::endl;

  // A new element should have the constructed string, and next should point to the 0 pointer address.
  Elem a("Hello World");

  test(a.get_contents() == "Hello World", "Elem string should be 'Hello World'");
}
