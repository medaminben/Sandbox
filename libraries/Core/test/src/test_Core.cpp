#include <Sandbox/Core/Core.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>


TEST(test_Core_result, result_properties) {
    auto result = Result<int, std::string>(5);
    EXPECT_EQ(result(), 5);
    EXPECT_EQ(result.isValue(), true);
    EXPECT_EQ(result.isError(), false);
}

TEST(test_Core_error, error_properties) {
    auto error  = Sc::Error<std::string>("error");
    auto result = Result<int,  Sc::Error<std::string>>(error);
     EXPECT_EQ(result.error()(), error());
     EXPECT_EQ(result.isValue(), false);
     EXPECT_EQ(result.isError(), true);
}