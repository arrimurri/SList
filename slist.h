#ifndef SLIST_TYPE
#define SLIST_TYPE

#include "elem.h"

namespace HTyo {
  
  
  class SList;
  class SListIter;
  class HTyoException;

  /**
   * This class is the main class for my SList implementation. This class only
   * has one private member, a pointer to the first element in the list. This 
   * implementation is pretty slimmed down, as it does not even have a size field.
   * 
   * Most of the functions in this class are self-explanatory, but for the
   * functions insert_after() and erase_after() you should note that doing 
   * something on the index 0 will push/erase in the front of the list. In
   * other words if these functions work with the index 0 they work exactly like
   * push_front and pop_front.
   */
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

  // Here are the operators for input and output.
  std::ostream& operator<<(std::ostream&, SList&);
  std::istream& operator>>(std::istream&, SList&);

  /**
   * This is the iterator of the SList. It has most of the standard iterator
   * features, so you can use it like a standard iterator
   */
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

  /**
   * This is a standard implementation of a Exception. As the assignment did not
   * want us to use almost anything out of the std lib, I did this dummy exception
   * to have something to throw.
   */
  class HTyoException { 
    std::string error;

    public:
    HTyoException(std::string s);

    ~HTyoException(); 

    std::string get_error();
  };

};
#endif
