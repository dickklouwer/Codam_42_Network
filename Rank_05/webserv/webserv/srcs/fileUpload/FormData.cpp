#include "FormData.hpp"

FormData::FormData() {}

FormData::FormData(const FormData &obj)
	: raw_data(obj.raw_data),
	  form_data(obj.form_data)
{
}

FormData FormData::operator=(const FormData &obj)
{
	raw_data = obj.raw_data;
	form_data = obj.form_data;
	return *this;
}

t_form_overhead FormData::parseFormOverhead(const std::string &raw_overhead)
{
	t_form_overhead overhead;
	overhead.raw_overhead = raw_overhead;

	std::vector<std::string> raw_headers_comps = tokenize(overhead.raw_overhead, CRLF);

	for (std::string raw_header : raw_headers_comps)
	{
		std::vector<std::string> header_comps = tokenize(raw_header, HEADER_SEP);
		if (header_comps.size() != 2)
			throw std::runtime_error("overhead header parse error");
		overhead.raw_headers[header_comps[0]] = strip(header_comps[1], " ");
	}
	std::vector<std::string> content_disposition_comps = tokenize(overhead.raw_headers.at("Content-Disposition"), SEMICOL);

	for (std::string content_disposition_val : content_disposition_comps)
	{
		std::vector<std::string> content_disposition_val_comps = tokenize(content_disposition_val, "=");
		if (content_disposition_val_comps.size() == 1)
			overhead.content_disposition["data_type"] = strip(content_disposition_val_comps[0], " ");
		else if (content_disposition_val_comps.size() == 2)
		{
			std::string k = strip(content_disposition_val_comps[0], " ");
			std::string v = strip(content_disposition_val_comps[1], "\"");
			overhead.content_disposition[k] = v;
		}
		else
			throw std::runtime_error("Content-Disposition parse error");
	}

	overhead.content_type = overhead.raw_headers.at("Content-Type");
	return overhead;
}

std::vector<std::string> FormData::tokenizeFormData(const std::string &data, std::string &form_boundary)
{
	std::string form_boundary_start = "--" + form_boundary;
	std::string form_boundary_end = form_boundary_start + "--";

	std::string raw_form_data = data.substr(0, data.find(form_boundary_end));
	std::vector<std::string> form_data_comps = tokenize(raw_form_data, form_boundary_start);

	std::vector<std::string>::iterator it;
	for (it = form_data_comps.begin(); it != form_data_comps.end(); it++)
	{
		if (it->find("Content-Disposition") == NPOS)
			it = form_data_comps.erase(it);
	}
	return form_data_comps;
}

const std::vector<t_form_data> &FormData::getFormData() const
{
	return form_data;
}

FormData::FormData(const std::string &data, const std::map<std::string, std::string> &headers)
{
	raw_data = data;
	std::string content_type_field_val = headers.at("Content-Type");
	const std::string boundary_key = "boundary=";
	std::size_t boundary_pos = content_type_field_val.find(boundary_key);

	if (boundary_pos != NPOS)
	{
		std::string boundary = content_type_field_val.substr(boundary_pos + boundary_key.length());
		if (boundary.length() > 70)
			throw std::runtime_error("form boundary too long: '" + boundary + "'");
		std::vector<std::string> raw_form_data_comps = tokenizeFormData(data, boundary);

		for (std::string raw_form_data : raw_form_data_comps)
		{
			raw_form_data = strip(raw_form_data, WHTSPC);
			std::vector<std::string> raw_form_comps = tokenize(raw_form_data, TWO_CRLF);
			if (raw_form_comps.size() != 2)
				throw std::runtime_error("form parse error\n");

			t_form_overhead overhead = parseFormOverhead(raw_form_comps[0]);
			std::string payload = raw_form_comps[1];

			for (std::pair<std::string, std::string> rh : overhead.raw_headers)
			{
				std::cout << rh.first << ": " << rh.second << "\n";
			}

			for (std::pair<std::string, std::string> cd : overhead.content_disposition)
			{
				std::cout << cd.first << ": " << cd.second << "\n";
			}
			std::cout << "content_type: " << overhead.content_type << "\n\n";

			form_data.push_back((t_form_data){overhead, payload});
		}
	}
}

FormData::~FormData() {}