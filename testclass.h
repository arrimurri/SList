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

    void test(bool, std::string const&);

    private:
    void double_and_copy_error_array();
  };

  class TestError {
    std::string error;

    public:
    TestError(const std::string&);
    ~TestError();

    std::string get_error();
  };
}

#endif
