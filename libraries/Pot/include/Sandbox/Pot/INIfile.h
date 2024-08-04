#ifndef INI_FILE_H
#define INI_FILE_H
#include <string>
#include <string_view>
#include <vector>
#include <Sandbox/Core/Core.h>

namespace Sandbox { namespace Pot {
        /**
     * @brief iniFile 
     * 
     * ini files are widly used in windows system as a flat serialization of data
     * the format support sections comments and properties as variable value pair
     * as example
     * 
     * ;here a comment line 
     * [a sction]; a comment
     * #this a comment line too
     * a_variable = it can be whatever value # but here starts a comment
     * 
     */
    struct iniFile {
        // own containers
        struct Section { 

            struct Property{
                constexpr Property(std::string const& k,  std::string const& v) : _key(k),_value(v) {};
                constexpr std::string_view value() const { return _value; }
                constexpr std::string_view key()   const { return _key;   }
            private:
                std::string _key{}, _value{};
            };

            constexpr Section(std::string const& name = Sc::unknown): _label(name){};
            constexpr std::string_view label() const { return _label;      }
            constexpr auto        properties() const { return _properties; }
        private:
            std::string           _label{}; 
            std::vector<Property> _properties{};
        };
        std::vector<Section> sections{Section()};
        size_t               line_count{0}; 
    };
}}

#endif // INI_FILE_H