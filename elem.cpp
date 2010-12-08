#include <iostream>
#include <string>

#include "elem.h"

namespace HTyo {

  Elem::Elem(std::string s)
    : contents(s), next(0) { }

  Elem::Elem(const Elem& e)
    : contents(e.contents), next(e.next) { }

  Elem::~Elem() { }

  Elem& Elem::operator=(const Elem& e) {
    contents = e.contents;
    next = e.next;

    return *this;
  }

  std::string Elem::get_contents() const {
    return contents;
  }

  Elem& Elem::get_next() {
    return *next;
  }

}
