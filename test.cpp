#include <iostream>

#include "elem.h"

void testElem();

int main() {
  testElem();
  return 0;
}

void testElem() {
  using HTyo::Elem;
  using std::cout;
  using std::endl;

  // A new element should have the constructed string, and next should point to the 0 pointer address.
  Elem a("Hello World");

  cout << a.get_contents() << endl;

}
