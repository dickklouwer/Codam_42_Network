#ifndef STRING_UTILS__HPP
#define STRING_UTILS__HPP

/* C/C++ Libs */
#include <vector>
#include <string>

std::string strip(const std::string &input, std::string strip_chars);
std::vector<std::string> tokenize(const std::string &input,
								  const std::string &delimiter,
								  std::size_t max_count = -1);
std::string readFull(int fd);
std::string joinPath(std::vector<std::string> paths, std::string delimeter);
#endif