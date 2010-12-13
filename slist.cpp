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
    Elem *tmp = front;
    Elem ret = *tmp;
    front = front->next;
    delete tmp;
    return ret.get_contents();
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

  SListIter SList::begin() {
    SListIter s(front);
    return s;
  }

  SListIter SList::end() {
    SListIter s(0);
    return s;
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
