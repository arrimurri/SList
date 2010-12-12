#include <iostream>
#include <string>

#include "slist.h"
#include "elem.h"

namespace HTyo {
  
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
      Elem *next = front->next;
      while(next != 0) {
        Elem tmp = *next;
        delete next;
        next = tmp.next;
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

  // Implementation of the general Exception
  HTyoException::HTyoException(std::string s)
    : error(s) { }

  HTyoException::~HTyoException() { }

  std::string HTyoException::get_error() {
    return error;
  }
}
