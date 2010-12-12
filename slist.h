#ifndef SLIST_TYPE
#define SLIST_TYPE

#include "elem.h"

namespace HTyo {

  class SList {
    Elem *front;

    public:
    SList();
    SList(const SList&);
    ~SList();

    SList& operator=(const SList&);

    std::string get_front();
    void push_front(std::string);
    std::string pop_front();
    void insert_after(int);
    std::string erase_after(int);

    void reverse();
    void swap(SList);
  };

  class HTyoException { 
    std::string error;

    public:
    HTyoException(std::string s);

    ~HTyoException(); 

    std::string get_error();
  };

};
#endif
