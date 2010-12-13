#ifndef SLIST_TYPE
#define SLIST_TYPE

#include "elem.h"

namespace HTyo {
  
  class SList;
  class SListIter;
  class HTyoException;

  class SList {
    Elem *front;

    public:
    SList();
    SList(const SList&);
    ~SList();

    friend std::ostream& operator<<(std::ostream&, SList&);
    friend std::istream& operator>>(std::istream&, SList&);

    std::string get_front();
    void push_front(std::string);
    std::string pop_front();
    void insert_after(int, std::string);
    std::string erase_after(int);

    void reverse();
    void swap(SList&);

    SListIter begin();
    SListIter end();
  };

  class SListIter {
    Elem *pointer;

    public:
    SListIter(Elem *);
    SListIter(SListIter const&);
    ~SListIter();

    void operator++();
    void operator++(int);
    Elem& operator*();
    Elem *operator->();
    bool operator==(SListIter const&);
    bool operator!=(SListIter const&);

    Elem *get_pointer();
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
