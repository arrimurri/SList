#include <iostream>
#include <string>

#include "slist.h"
#include "elem.h"

namespace HTyo {
  class SListIter;
  class SList;
  class HTyoException;
  
  SList::SList() 
    : front(0) { }

  SList::SList(const SList& l)
    : front(new Elem(*l.front)) {
      
    Elem *tmp = front;
    while(tmp->next != 0) {
      tmp->next = new Elem(*tmp->next);
    }
  }

  SList::~SList() {
    if(front != 0) {
      SListIter begin = this->begin();
      SListIter end = this->end();
      while (begin != end) {
        delete &(*begin);
        ++begin;
      }
    }
  }

  std::string SList::get_front() {
    if(front == 0) {
      HTyoException exception("Front of list is empty");
      throw exception;
    }
    return front->get_contents();
  }

  void SList::push_front(std::string const s) {
    Elem *new_elem = new Elem(s);

    new_elem->next = front;
    front = new_elem;
  }

  std::string SList::pop_front() {
    std::string ret = this->get_front(); // throws exception if empty list
    Elem *tmp = front;
    front = front->next;
    delete tmp;
    return ret;
  }

  void SList::insert_after(int n, std::string s) {

    Elem *new_elem = new Elem(s);
    SListIter begin = this->begin();
    SListIter end = this->end();
    Elem *prev = 0;

    if(begin == end && n != 0) {
      HTyoException e("Index error when inserting into an empty list");
      throw e;
    }

    if(n == 0) {
      return this->push_front(s);
    }

    for(int i = 0; i < n; ++i) {
      if(begin == end) {
        HTyoException e("Index error when inserting after an element");
        throw e;
      }
      prev = &(*begin);
      ++begin;
    }

    prev->next = new_elem;
    try {
      new_elem->next = &(*begin);
    }
    catch (HTyo::HTyoException& e ) {
      new_elem->next = 0;
    }
  }

  std::string SList::erase_after(int n) {
    if(front == 0) {
      HTyoException e("Can not erase from an empty list");
      throw e;
    }

    if(n == 0) {
      return this->pop_front();
    }

    SListIter b = this->begin();
    SListIter e = this->end();
    Elem *prev = 0;

    for(int i = 0; i < n; ++i) {
      //std::cout << "In erase after"  << std::endl;
      //std::cout << &*b << std::endl;
      //std::cout << b->get_contents() << std::endl;
      if(b == e) {
        HTyoException e("Can not erase, index over bounds");
        throw e;
      }
      prev = &(*b);
      ++b;
    }

    prev->next = b->next;
    Elem ret = *b;
    delete &(*b);

    return ret.get_contents();
  }

  void SList::reverse() {
    SList tmp;
    Elem *tmp_elem = front;
    while(tmp_elem) {
      tmp.push_front(tmp_elem->get_contents());
      tmp_elem = tmp_elem->next;
    }
    tmp.swap(*this);
  }

  void SList::swap(SList& l) {
    Elem *tmp = front;
    front = l.front;
    l.front = tmp;
  }

  SListIter SList::begin() {
    SListIter s(front);
    return s;
  }

  SListIter SList::end() {
    SListIter s(0);
    return s;
  }

  std::ostream& operator<<(std::ostream& out, SList& l) {
    std::string a("");

    for(SListIter i = l.begin(); i != l.end(); ++i) {
      a += i->get_contents() + " ";
    }

    out << "{ ";
    out << a;
    out << "}";

    return out;
  }

  std::istream& operator>>(std::istream& in, SList& l) {
    std::string tmp;
    if(in >> tmp) {
      if(tmp != "{")
        return in;
    }
    while(in >> tmp) {
      if(tmp == "}")
        break;
      l.push_front(tmp);
    }

    return in;
  }

  // Implementation of the general Exception
  HTyoException::HTyoException(std::string s)
    : error(s) { }

  HTyoException::~HTyoException() { }

  std::string HTyoException::get_error() {
    return error;
  }

  // Implementation of the SListIter class
  SListIter::SListIter(Elem *a)
    : pointer(a) { }

  SListIter::SListIter(SListIter const& sli)
    : pointer(sli.pointer) { }

  SListIter::~SListIter() { }

  void SListIter::operator++() {
    pointer = pointer->next;
  }
  
  void SListIter::operator++(int) {
    operator++();
  }

  bool SListIter::operator==(SListIter const& other) {
    return pointer == other.pointer;
  }

  bool SListIter::operator!=(SListIter const& other) {
    return !(*this == other);
  }

  Elem& SListIter::operator*() {
    if(pointer == 0) {
      HTyoException e("Tried to dereference a null pointer");
      throw e;
    }
    return *pointer;
  }

  Elem *SListIter::operator->() {
    if(pointer == 0) {
      HTyoException e("Tried to dereference a null pointer");
      throw e;
    }
    return pointer;
  }

  Elem *SListIter::get_pointer() {
    return pointer;
  }
}
