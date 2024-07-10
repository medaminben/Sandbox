#include <Sandbox/Tools/Tools.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>
#include <filesystem>
namespace test_Tools {
    static std::string data_dir ="data/test_sandbox_Tools/";
}

// // Test case names must start with the name of the executable they are
// // contained in, in this case, "test_core"
TEST (test_Tools_Result, get_proper_result) {
    const auto fp = test_Tools::data_dir + "csvFile.csv";
    auto res = St::parse_csv_file(fp, ";");


    const auto testResult = res();
    for(const auto& row : testResult) {
        for(const auto& field : row)
            std::cout << field << " ";
        
        std::cout << "\n";
    };

    EXPECT_EQ(res.isError(), false);  
}

// TEST (test_Tools_Math, MultiplyReturnsCorrectResults) {
//     EXPECT_EQ(36, Sandbox::Tools::multiply(6,6));
// }
