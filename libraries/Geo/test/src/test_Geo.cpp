#include <Sandbox/Geo/Geo.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>

// Test case names must start with the name of the executable they are
// contained in, in this case, "test_core"
TEST (test_Geo_factorial, result) {
    // no use of Result<..> class cause it never fails
    auto result = Sg::factorial<5>::is;
    EXPECT_EQ(result,120);
}

TEST (test_Geo_bino_coef, error) {
    auto result = Sg::bino_coef<>(2,6);
    EXPECT_EQ(result.isError(),true);
}

TEST (test_Geo_bino_coef, result) {
    auto result = Sg::bino_coef<>(6,2);
    EXPECT_EQ(result(),15);
}
