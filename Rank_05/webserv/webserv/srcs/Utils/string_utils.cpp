#include "string_utils.hpp"
#include "SysCall.hpp"

std::string strip(const std::string &input, std::string strip_chars)
{
	std::size_t start = input.find_first_not_of(strip_chars);
	std::size_t end = input.find_last_not_of(strip_chars);

	if (start == std::string::npos || end == std::string::npos)
	{
		return "";
	}

	return input.substr(start, end - start + 1);
}

std::vector<std::string> tokenize(const std::string &input,
								  const std::string &delimiter,
								  std::size_t max_count)
{
	std::vector<std::string> tokens;
	std::string token;

	size_t pos = 0;
	size_t found;

	while ((found = input.find(delimiter, pos)) != std::string::npos && tokens.size() < max_count)
	{
		token = input.substr(pos, found - pos);
		tokens.push_back(token);
		pos = found + delimiter.size();
	}

	token = input.substr(pos);
	if (!token.empty())
	{
		tokens.push_back(token);
	}

	return tokens;
}

std::string readFull(int fd)
{
	char buff[10240];
	std::string output;

	int bytes_read;
	while ((bytes_read = SysCall::read(fd, buff, sizeof(buff))) != 0)
	{
		output += std::string(buff, bytes_read);
	}

	return output;
}

std::string joinPath(std::vector<std::string> paths, std::string delimeter)
{
    std::string joined_path;

    for (size_t i = 0; i < paths.size(); i++)
    {
        std::string stripped = strip(paths[i], "/");
        if (stripped != "")
            joined_path += stripped + delimeter;
    }

    if (paths.back() == "/" || paths.back().back() != '/')
    {
        joined_path.pop_back();
    }
    return joined_path;
}