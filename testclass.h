#ifndef TESTCLASS_TYPE
#define TESTCLASS_TYPE

#include "slist.h"

namespace HTyo {
  
  /**
   * This is my simple but powerful testclass. This class has one test function 
   * which checks for equality. It also has the operator() defined, so that 
   * you can call the tests on the object.
   */
  class TestClass {
    int count_errors;
    std::string *error_array;
    int array_size;

    public:
    TestClass();
    TestClass(int);
    ~TestClass();

    void operator()(bool, std::string const&);
    void test(bool, std::string const&);
    void set_error(std::string);

    std::string report();

    private:
    void double_and_copy_error_array();
  };
}

#endif
