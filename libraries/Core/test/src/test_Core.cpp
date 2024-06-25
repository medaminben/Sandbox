#include <Sandbox/Core/Core.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>

// Test case names must start with the name of the executable they are
// contained in, in this case, "test_core"
TEST (test_Core_Math, AnswerIsCorrect) {
    EXPECT_EQ(Sandbox::Core ::get_the_answer(), 42U);
}

TEST (test_Core_Math, MultiplyReturnsCorrectResults) {
    EXPECT_EQ(36, Sandbox::Core::multiply(6,6));
}
