#include <string>

#ifndef ELEM_TYPE
#define ELEM_TYPE

namespace HTyo {

  /**
   * This class is a container class for the SList class. This class 
   * only holds one element and a pointer to the next element. The
   * operations on this class is pretty self-explanatory.
   */
  class Elem {
    std::string contents;
    Elem *next;

    friend class SList;
    friend class SListIter;

    public:
    Elem();
    Elem(std::string s);
    Elem(const Elem&);
    ~Elem();

    Elem& operator=(const Elem&);

    std::string get_contents() const;

    Elem& get_next();
  };

}
#endif
