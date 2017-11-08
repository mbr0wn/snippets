#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <iostream>
#include <map>
#include <vector>

namespace {
    template <typename T>
    std::vector<std::string> _get_keys(T key_bearing_iterable)
    {
        std::vector<std::string> sections;
        for (const auto& node : key_bearing_iterable) {
            sections.push_back(node.first);
        }
        return sections;
    }
}

class ini_file
{
public:
    ini_file(const std::string path)
    {
        boost::property_tree::ini_parser::read_ini("test.ini", _pt);
    }

    template <typename T>
    T get(const std::string &node)
    {
        return _pt.get<T>(node);
    }

    std::vector<std::string> get_sections()
    {
        try {
            return _get_keys(_pt);
        } catch (const boost::property_tree::ptree_bad_path &) {
            return std::vector<std::string>{};
        }
    }

    std::vector<std::string> get_keys(const std::string &section)
    {
        try {
            return _get_keys(_pt.get_child(section));
        } catch (const boost::property_tree::ptree_bad_path &) {
            return std::vector<std::string>{};
        }
    }

    template <typename T>
    T get_value(
            const std::string &section,
            const std::string &key,
            const T &def=T()
    ) {
        try {
            return _pt.get_child(section).get<T>(key, def);
        } catch (const boost::property_tree::ptree_bad_path &) {
            return def;
        }
    }

private:
    boost::property_tree::ptree _pt;
};


int main(void)
{
    ini_file I("test.ini");

    for (const auto& i : I.get_sections()) {
        std::cout << i << std::endl;
    }

    std::cout << "===" << std::endl;

    for (const auto& i : I.get_keys("section1")) {
        std::cout << i << std::endl;
    }

    std::cout << "===" << std::endl;

    for (const auto& i : I.get_keys("sectionX")) {
        std::cout << i << std::endl;
    }

    std::cout << "===" << std::endl;
    std::cout << I.get_value<std::string>("section1", "foo", "DEFAULT") << std::endl;
    std::cout << I.get_value<std::string>("section1", "fooX", "DEFAULT") << std::endl;

    std::cout << "===" << std::endl;

    std::cout << I.get<std::string>("section1.foo") << std::endl;
    std::cout << I.get<std::string>("section2.apple") << std::endl;

    return 0;
}
