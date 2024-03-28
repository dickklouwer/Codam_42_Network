
#include "ConfigTypes.hpp"

int ConfigType::getInt()
{
	throw std::invalid_argument("getInt() is the wrong conversion type of ConfigType");
}

std::string ConfigType::getString()
{
	throw std::invalid_argument("getString() is the wrong conversion type of ConfigType");
}

ConfigInt::ConfigInt(int val)
{
	_int_val = val;
}

int	ConfigInt::getInt()
{
	return _int_val;
}

ConfigInt::~ConfigInt() {}

ConfigStr::ConfigStr(std::string val)
{
	_str_val = val;
}

std::string ConfigStr::getString()
{
	return (_str_val);
}

ConfigStr::~ConfigStr() {}
