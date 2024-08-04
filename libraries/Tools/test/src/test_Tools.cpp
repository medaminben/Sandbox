#include <Sandbox/Tools/Tools.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <regex>
#include <vector>
// control board ! undefine the test that you don't need to check by block
// useful to reduce compile time by discarding the archived tests
#define TEST_ARC   true
#if TEST_ARC
#define TEST_CSV   true 
#define TEST_REGEX true
#define TEST_INI   true
#endif

namespace test_Tools {
    static std::string data_dir ="../data/sandbox_tools/";
    
    bool inline print_matches(const std::string& str, const std::regex& reg) {
        bool result{false}; 
        std::smatch match;
        auto itor =  std::sregex_iterator(str.begin(), str.end(), reg);

        std::cout << std::boolalpha;
        for(;itor != std::sregex_iterator(); ++itor ) {
            if(!result) 
                result = true;            
            match = *itor;
            std::cout 
            << "the match is: "      << match.str()           << "\n"
            << "Found at position: " << match.position()      << "\n"
            << "the match suffix: "  << match.suffix().str()  << "\n"
            << "the match prefix: "  << match.prefix().str()  << "\n"
            << "\n"
            ;
        }
    return result;
}
    bool inline is_matching(std::string str, const std::regex& reg){
        std::smatch matches;
        if (std::regex_search(str, matches, reg)) {
            std::cout << std::boolalpha
            << "Is there a match:     " << matches.ready() << "\n"
            << "Are there no matches: " << matches.empty() << "\n"
            << "Number of matches:    " << matches.size()  << "\n"
            ;    
        }
        return matches.ready();
    }

}
#if TEST_CSV 
/// non regex tests
TEST (test_Tools_csv_parser, get_proper_result) {
    const auto fp = test_Tools::data_dir + "csvFile.csv";
    auto res = St::parse_csv_file(fp, ";");
    EXPECT_EQ(res.isError(), false);  
}
TEST (test_Tools_remove_line_breack, error_result) {
    auto result = St::remove_from_line_breack("");
    if(result.isError()) 
        std::cout << result.error() << "\n";     
    EXPECT_EQ(true, result.isError());
}
TEST (test_Tools_remove_line_breack, trancate_from_br_position) {
    auto result = St::remove_from_line_breack("this is the sentence with newline \n to be removed from here");
    EXPECT_EQ(0, result().compare("this is the sentence with newline "));
}
TEST (test_Tools_remove_white_space, trancate_from_ws_position) {
    auto result = St::remove_from_whitespace("this is the sentence with newline \n to be removed from here");
    EXPECT_EQ(0, result().compare("this"));
}
#endif

#if TEST_REGEX 

namespace test_Tools {
/// @brief //////////////////////////////////////////////////////////
// test data a one line string and a regex 
///////////////////////////////////////////////////////////////////
// Section :  asection is a marker that binds all the following keya under the same flag 
// A section is defined by a word in []
// This could be precieded and by any spaces and followed by any comment
// example: "        [this_is the_label_of_the section]    # and comment are nice when used properly"
//used to delete matches
static const std::string nothing = ""; 
//used to ignore extra spaces
static const std::string space   = " ";
static const std::string str2    = "    [this is a section]#";
static const std::string str21   = "    ;[this is not a section]";

static const std::string str3 = "this is not a commet  ;but this# ";
static const std::string str4 = "  this_is_a_k3y = the value c4n be any thing $ &<``";
// the comment pattern in regex: 
// starts by ; or # [;#] until the end or new line char \n
static const std::regex  comment      ( "[;#](.[^\\n]*)?" );
// the comment pattern in regex: 
// starts by spacees []*  and then the secton between brackets
static const std::regex  section      ( "^\\s*?\\[(.+?)]" );
// the prperty pattern in regex: 
// starts by maybe spaces \s*?  
// followoed by the key of the property \w+ 
// then maybe spaces \s*? before the assign symbol = 
// at this point fetch the value of the property any char other then ; #  or newline using .[^;#\\n]+ 
// after the value maybe comes a comment so that's why ([;#].*)?
// working example:
//     the_key   =     'the_value$'  ; here is a comment
static const std::regex  property     ( "^\\s*?(\\w+)\\s*?=\\s?(.[^;#\\n]+)([;#].*)?" );
}
///  regex tests

TEST (test_tools_regex_find_section, str2) {
    auto is_find_section_okay = test_Tools::is_matching(test_Tools::str2, test_Tools::section);
    EXPECT_EQ( is_find_section_okay, true); 
    is_find_section_okay      = test_Tools::print_matches(test_Tools::str2, test_Tools::section);
    EXPECT_EQ( is_find_section_okay, true); 
}

TEST (test_tools_regex_find_section, str21) {
    auto is_find_section_okay = test_Tools::is_matching(test_Tools::str21, test_Tools::section);
    is_find_section_okay      = test_Tools::print_matches(test_Tools::str21, test_Tools::section);
    EXPECT_EQ( is_find_section_okay, false); 
}
TEST (test_tools_regex_find_comment, str3) {
    auto is_find_comment_okay = test_Tools::is_matching(test_Tools::str3, test_Tools::comment);
    EXPECT_EQ( is_find_comment_okay, true); 
    is_find_comment_okay      = test_Tools::print_matches(test_Tools::str3, test_Tools::comment);
    EXPECT_EQ( is_find_comment_okay, true); 
}
TEST (test_tools_regex_find_comment, str4) {
    auto is_find_comment_okay = test_Tools::is_matching(test_Tools::str4, test_Tools::property);
    is_find_comment_okay      = test_Tools::print_matches(test_Tools::str4, test_Tools::property);
    EXPECT_EQ( is_find_comment_okay, true); 
}
TEST (test_Tools_remove_extra_whitespaces, space) {
    std::string a_long_String = "ljDLJLLKJHSDKJHSDLKJSDLJ     SHDLKJSHDLKJSHDLKJSHDLKJSHD2";
    const auto before_size = a_long_String.size();
    const auto reg = std::regex("\\s+");
    std::cout
    << "The string before: " << a_long_String << "\n"
    << "before mini:       " << before_size   << "\n";
    
    a_long_String = std::regex_replace(a_long_String, reg, test_Tools::space);
    a_long_String = std::regex_replace(a_long_String, reg, test_Tools::nothing);
    const auto after_size = a_long_String.size();
    std::cout 
    << "The string after:  " << a_long_String << "\n" 
    << "after:             " << after_size  << "\n"
    ;
    EXPECT_LT(after_size, before_size);
}

#endif

#if TEST_INI 
TEST(test_Tools_ini_parser, parsing_error){
    const auto fp = test_Tools::data_dir + "iniFile_ill.ini";
    auto res = St::parse_ini_file(fp);
    if(res.isError())
        std::cout << "\n Error parsing ini : " << res.error() << "\n"; 
    EXPECT_EQ(res.isError(), true);
}
TEST(test_Tools_ini_parser, parsed_data){
    const auto fp = test_Tools::data_dir + "iniFile.ini";
    auto res = St::parse_ini_file(fp);
    if(res.isValue()){
        const auto data = res();
        for(auto const& s: data.sections) {
            if(s.properties().size() == 0) // ignore empty sections
                continue;
            std::cout << "Section: " << s.label() <<"\n";
            for(auto const& p : s.properties()) 
                std::cout << "Property[key , value]: [" << p.key() <<" , "<< p.value() <<"]\n";
        }
    }
    EXPECT_EQ(res.isError(), false);
}
#endif
