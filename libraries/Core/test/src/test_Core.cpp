#include <Sandbox/Core/Core.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>

class string : public std::string {
    using std::string::string;
    using std::string::operator=;
    using std::string::operator[];
    using std::string::operator+=;
    using std::string::size;
    using std::string::empty;
};

TEST(test_Core_result, result_properties) {
    auto result = Result<int, string>(5);
    EXPECT_EQ(result(), 5);
    EXPECT_EQ(result.isValue(), true);
    EXPECT_EQ(result.isError(), false);
}

TEST(test_Core_error, error_properties) {
    auto error  = Sc::Error<string>("error");
    auto result = Result<int,  Sc::Error<string>>(error);
    EXPECT_STREQ(result.error().c_str(), error().c_str());
    EXPECT_EQ(result.isValue(), false);
    EXPECT_EQ(result.isError(), true);
}

TEST(test_Core_result_simple, simple_result_properties) {
    auto error  = Sc::Error<string>("error");
    auto result = Result<int>(error);
    EXPECT_STREQ(result.error().c_str(), error().c_str());
    EXPECT_EQ(result.isValue(), false);
    EXPECT_EQ(result.isError(), true);
}