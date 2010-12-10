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

  Elem b = a;
  test(a.get_contents() == b.get_contents(), "Copied elem should have same contents");
  Elem *c = &(a.get_next());
  Elem *d = &(b.get_next());
  test(c == d, "Copied elem should have same next address");
  test(a.get_contents() == "Hello World", "Elem string should be 'Hello World'");
  Elem *ref = &(a.get_next());
  test(ref == 0, "Elem next should point to 0 (NULL) in the beginning");
}
