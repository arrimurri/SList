#include <string>

#ifndef ELEM_TYPE
#define ELEM_TYPE

namespace HTyo {

  class Elem {
    std::string contents;
    Elem *next;

    friend class SList;

    public:
    Elem(std::string s);
    Elem(const Elem&);
    ~Elem();

    Elem& operator=(const Elem&);

    std::string get_contents() const;

    Elem& get_next();
  };

}
#endif
