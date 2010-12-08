#include <string>

#include "testclass.h"

namespace HTyo {
  
  TestClass::TestClass(const int max_error_count)
    :count_errors(0), array_size(max_error_count) {
      error_array = new std::string[array_size];
    }

  TestClass::TestClass()
    :count_errors(0), array_size(5) {
      error_array = new std::string[array_size];
    }

  TestClass::~TestClass() {
    delete[] error_array;
  }

  void TestClass::test(bool pred, std::string const& s) {
    if(!pred) {
      error_array[count_errors] = s;
      ++count_errors;
    }
  }

  TestError::TestError(const std::string& s)
    : error(s) { }

  TestError::~TestError() { }

  std::string TestError::get_error() {
    return error;
  }
}
