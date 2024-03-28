#include "RequestProcessor.hpp"

void RequestProcessor::uploadFiles(const FormData &form_data)
{
	for (t_form_data filedata : form_data.getFormData())
	{
		std::string filename = filedata.overhead.content_disposition.at("filename");
		std::cout << "\n\n" << filename << "\n\n";
		std::string path = "srv/www/uploads/" + filename;

		int fd = SysCall::open(path.c_str(), O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);

		std::size_t size = filedata.payload.length();
		SysCall::write(fd, filedata.payload.c_str(), size);
		SysCall::close(fd);
	}
}
