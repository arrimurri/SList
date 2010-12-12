#include <iostream>

#include "elem.h"
#include "slist.h"
#include "testclass.h"

void testElem(HTyo::TestClass&);
void testSList(HTyo::TestClass&);

int main() {
  std::cout << "Testing started" << std::endl;

  HTyo::TestClass test(1);
  testElem(test);
  testSList(test);

  std::cout << test.report() << std::endl;

  return 0;
}

void testSList(HTyo::TestClass& test) {
  using HTyo::SList;
  using HTyo::Elem;

  SList l;

  try {
    // Getting front of empty list should throw EmptyListException exception
    std::string ret = l.get_front();
  }
  catch (HTyo::HTyoException& e ) {
    // Do nothing
  }
  
  std::string first_elem("First Elem");
  std::string second_elem("Second Elem");
  std::string third_elem("Third Elem");
  l.push_front(first_elem);
  test(l.get_front() == first_elem, "The first elem of the list should containthe string 'First Elem'");
  l.push_front(second_elem);
  test(l.get_front() == second_elem, "The first elem of the list should contain the string 'Second Elem'");
  l.push_front(third_elem);
  test(l.get_front() == third_elem, "The first elem of the list should contain the string 'Third Elem'");
}

void testElem(HTyo::TestClass& test) {
  using HTyo::Elem;

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
