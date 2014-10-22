#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

using namespace boost::property_tree;

int main()
{
	ptree pt;
	read_xml("test.xml", pt);

	// Just reading nodes is quite simple: 
	std::cout << pt.get<std::string>("container.name") << std::endl;

	// Providing a default value gets rid of having to
	// provide a type:
	std::cout << pt.get("container.notthere", 0) << std::endl;

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("container.ids")) {
		// value_type is a pair. v.first is std::string:
		std::cout << v.first << ": ";
		// v.second is a ptree again:
		std::cout << v.second.data() << std::endl;
		// Attributes are in a special node:
		if (not v.second.count("<xmlattr>")) {
			continue;
		}
		BOOST_FOREACH(ptree::value_type &attr, v.second.get_child("<xmlattr>")) {
			std::cout << "    " << attr.first << ": " << attr.second.data() << std::endl;
		}
	}

	return 0;
}
