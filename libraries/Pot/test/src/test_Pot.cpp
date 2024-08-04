#include <Sandbox/Pot/Pot.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>

// Test case names must start with the name of the executable they are
// contained in, in this case, "test_core"
TEST (test_Pot_Math, AnswerIsCorrect) {
    EXPECT_EQ(Sandbox::Pot::get_the_answer(), 42U);
}

TEST (test_Pot_Math, MultiplyReturnsCorrectResults) {
    EXPECT_EQ(36, Sandbox::Pot::multiply(6,6));
}
