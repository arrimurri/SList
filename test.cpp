#include <iostream>

#include "elem.h"
#include "slist.h"
#include "testclass.h"

void testElem(HTyo::TestClass&);
void testSList(HTyo::TestClass&);
void testSListIter(HTyo::TestClass&);

int main() {
  std::cout << "Testing started" << std::endl;

  HTyo::TestClass test(1);
  testElem(test);
  testSList(test);
  testSListIter(test);

  std::cout << test.report() << std::endl;

  return 0;
}

void testSListIter(HTyo::TestClass& test) {
  using HTyo::SList;
  using HTyo::SListIter;

  SList l;
  SListIter b = l.begin();
  SListIter e = l.end();
  test(b == e, "In an empty list the beginning and end should both point the to 0 (NULL)");

  l.push_front("1");
  l.push_front("2");
  l.push_front("3");

  SListIter bb = l.begin();
  SListIter bb2 = l.begin();
  bb++;
  ++bb2;
  test(bb == bb2, "post++ and pre++ should increment in the same way");

  b = l.begin();
  e = l.end();

  test(b != e, "In a list with elements, begin and end should not point to the same element");

  int i = 0;
  for(SListIter sli = l.begin(); sli != l.end(); ++sli) {
    ++i;
  }
  test(i == 3, "The iterator should have iterated over 3 elements");

  std::string inafter("I'm the inafter thingie");
  l.insert_after(1, inafter);
  SListIter sli = l.begin();
  ++sli;
  test(sli->get_contents() == inafter, "Now the second element should come from the insert_after function");

  std::string inafter2("I'm the inafter thingie #2");
  l.insert_after(4, inafter2);

  sli = l.begin();
  SListIter end = l.end();
  HTyo::Elem *prev = 0;
  while (sli != end) {
    prev = &(*sli);
    ++sli;
  }
  test(prev->get_contents() == inafter2, "The last element should have been added");
  test(sli == l.end(), "The element after the last element should be the end element 0 (NULL)");

  bool catched = false;
  try {
    std::string inafter3("This should not work");
    l.insert_after(8, inafter3);
  }
  catch (HTyo::HTyoException& e ) {
    catched = true;
  }
  if(!catched) {
    test.set_error("Inserting after the end of a list should throw HTyoException");
  }
}

void testSList(HTyo::TestClass& test) {
  using HTyo::SList;
  using HTyo::Elem;

  SList l;

  bool catched = false;
  try {
    // Getting front of empty list should throw EmptyListException exception
    std::string ret = l.get_front();
  }
  catch (HTyo::HTyoException& e ) {
    catched = true;
  }
  if(!catched) {
    test.set_error("Getting front of empty list should throw HTyoException");
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
