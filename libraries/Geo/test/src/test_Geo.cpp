#include <Sandbox/Geo/Geo.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>

// Test case names must start with the name of the executable they are
// contained in, in this case, "test_core"
TEST (test_Geo_Math, AnswerIsCorrect) {
    EXPECT_EQ(Sandbox::Geo::get_the_answer(), 42U);
}

TEST (test_Geo_Math, MultiplyReturnsCorrectResults) {
    EXPECT_EQ(36, Sandbox::Geo::multiply(6,6));
}
