#ifndef TESTCLASS_TYPE
#define TESTCLASS_TYPE

namespace HTyo {
  
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

    std::string report();

    private:
    void double_and_copy_error_array();
  };
}

#endif
