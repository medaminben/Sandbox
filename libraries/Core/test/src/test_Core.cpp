#include <Sandbox/Core/Core.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>

TEST(test_Core_result, is_result) {
    auto result = Result<int, std::string>(5);
    EXPECT_EQ(result(), 5);
}
