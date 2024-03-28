#pragma once
#ifndef CONFIG_TYPES
#define CONFIG_TYPES

/* C/C++ Libs */
#include <vector>
#include <string>
#include <iostream>

class ConfigType
{
private:
public:
	virtual int getInt();
	virtual std::string getString();
};

class ConfigInt : public ConfigType
{
private:
	int _int_val;

public:
	ConfigInt(int val);
	int getInt();
	~ConfigInt();
};

class ConfigStr : public ConfigType
{
private:
	std::string _str_val;

public:
	ConfigStr(std::string val);
	std::string getString();
	std::string getData();
	~ConfigStr();
};

class ConfigVecStr : public ConfigType
{
	std::vector<std::string> vec_str_val;
};

#endif
