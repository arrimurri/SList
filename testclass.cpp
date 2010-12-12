#include <string>
#include <iostream>

#include "testclass.h"

namespace HTyo {
  
  TestClass::TestClass(int max_error_count)
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

  void TestClass::operator()(bool pred, std::string const& s) {
    test(pred, s);
  }

  void TestClass::test(bool pred, std::string const& s) {
    // If the buffer of errors is full, double the array size
    if(count_errors >= array_size) {
      double_and_copy_error_array();
    }

    // If the test returns false, then add description of test
    if(!pred) {
      error_array[count_errors] = s;
      ++count_errors;
    }
  }

  void TestClass::double_and_copy_error_array() {
    std::cout << "Int the doubling thingie" << std::endl;
    int new_size = array_size * 2;
    std::string *new_array = new std::string[new_size];
    
    // Copy old array to new array
    for (int i = 0; i < array_size; i++) {
      new_array[i] = error_array[i];
    }

    array_size = new_size;

    // Delete the old version of the error_array
    std::string *tmp = error_array;
    error_array = new_array;
    delete[] tmp;
  }

  std::string TestClass::report() {
    if(count_errors == 0) {
      return "All tests passed";
    }

    std::string a("");
    for(int i = 0; i < count_errors; ++i) {
      a += "Test with the following description failed:\n";
      a += "\t" + error_array[i] + "\n";
    }

    return a;
  }
}
