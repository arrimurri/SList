#include "elem.h"

#ifndef SLIST_TYPE
#define SLIST_TYPE

namespace HTyo {

  class SList {
    Elem *elems;
    Elem *front;

    public:
    SList();
    SList(const SList&);
    ~SList();

    SList& operator=(const SList&);

    void push_front(std::string);
    std::string pop_front();
    void insert_after(int);
    std::string erase_after(int);

    void reverse();
    void swap(SList);
  };

};
#endif
