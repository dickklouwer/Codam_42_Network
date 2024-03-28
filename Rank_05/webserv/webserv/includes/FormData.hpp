#ifndef FORMDATA__HPP
#define FORMDATA__HPP

/* C/C++ Libs */
#include <string>
#include <map>
#include <vector>
#include <iostream>

/* Webserv */
#include "string_utils.hpp"
#include "consts.hpp"

typedef struct s_form_overhead
{
	std::string raw_overhead;
	std::map<std::string, std::string> raw_headers;
	std::map<std::string, std::string> content_disposition;
	std::string content_type;

} t_form_overhead;

typedef struct s_form_data
{
	t_form_overhead overhead;
	std::string payload;
} t_form_data;

class FormData
{
private:
	std::string raw_data;
	std::vector<t_form_data> form_data;

public:
	FormData();
	FormData(const std::string &data, const std::map<std::string, std::string> &headers);
	FormData(const FormData &obj);
	FormData operator=(const FormData &obj);
	~FormData();

	std::vector<std::string> tokenizeFormData(const std::string &data, std::string &form_id);

public:
	const std::vector<t_form_data> &getFormData() const;

private:
	t_form_overhead parseFormOverhead(const std::string &raw_overhead);
};

#endif
