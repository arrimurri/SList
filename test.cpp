#include <iostream>
#include <sstream>

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

}

void testSList(HTyo::TestClass& test) {
  using HTyo::SList;
  using HTyo::Elem;
  using HTyo::SListIter;

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

  std::string to_be_popped("to be popped");
  l.push_front(to_be_popped);
  test(l.pop_front() == to_be_popped, "pop_front should pop the first element in the list");
  
  // Test that the list is again empty
  catched = false;
  try {
    // Getting front of empty list should throw EmptyListException exception
    std::string ret = l.pop_front();
  }
  catch (HTyo::HTyoException& e ) {
    catched = true;
  }
  if(!catched) {
    test.set_error("Popping front of empty list should throw HTyoException");
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

  // Multiple tests for SList::insert_after()
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

  catched = false;
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

  // Tests for erase_after
  SList list;
  list.push_front("first");
  list.push_front("second");
  list.push_front("third");
  list.push_front("fourth");

  std::string test_string("");
  test_string = list.erase_after(0); // Should be the same as pop_front()
  test(test_string == "fourth", "Erasing with a index 0 should pop the first element");
  list.push_front("fourth");
  test(list.erase_after(1) == "third", "Erasing the second argument should now yield a 3");
  test(list.erase_after(2) == "first", "Erasing the last argument should now yield a 1");

  int i = 0;
  for(SListIter s = list.begin(); s != list.end(); ++s) {
    ++i;
  }
  test(i == 2, "The list should now contain 2 elements");

  catched = false;
  try {
    std::string error = list.erase_after(2);
  }
  catch (HTyo::HTyoException& e ) {
    catched = true;
  }
  if(!catched) {
    test.set_error("Erasing after the last element should throw an HTyoException");
  }

  // Tests for the swap function
  SList swap1;
  SList swap2;

  swap1.push_front("First");
  swap1.push_front("Second");
  swap1.push_front("Third");
  swap2.push_front("First2");
  swap2.push_front("Second2");
  swap2.push_front("Third2");

  swap2.swap(swap1);
  test(swap1.pop_front() == "Third2", "The list contents should have been swapped");
  test(swap1.pop_front() == "Second2", "The list contents should have been swapped");
  test(swap1.pop_front() == "First2", "The list contents should have been swapped");
  test(swap2.pop_front() == "Third", "The list contents should have been swapped");
  test(swap2.pop_front() == "Second", "The list contents should have been swapped");
  test(swap2.pop_front() == "First", "The list contents should have been swapped");

  // Tests for reverse function
  SList reverse;
  reverse.push_front("First");
  reverse.push_front("Second");
  reverse.push_front("Third");

  reverse.reverse();
  test(reverse.pop_front() == "First", "The elements in the list should be in reverse order");
  test(reverse.pop_front() == "Second", "The elements in the list should be in reverse order");
  test(reverse.pop_front() == "Third", "The elements in the list should be in reverse order");

  // Testing the output
  SList going_out;
  going_out.push_front("First");
  going_out.push_front("Second");
  going_out.push_front("Third");
  std::ostringstream a;
  a << going_out;
  test(a.str() == "{ Third Second First }", "Testing output of SList");

  // Testing input
  SList coming_in;
  std::istringstream in("{ First Second Third }");
  in >> coming_in;
  test(coming_in.pop_front() == "Third", "Testing input of SLists");
  test(coming_in.pop_front() == "Second", "Testing input of SLists");
  test(coming_in.pop_front() == "First", "Testing input of SLists");
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
