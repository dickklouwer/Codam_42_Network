#include "Log.hpp"

const std::string Log::getMsec()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	std::string msec = std::to_string(tv.tv_usec / 1000);

	switch (msec.length())
	{
		case 1:
			msec = "0" + msec;
	}

	return msec;
}

const std::string Log::getTime()
{
	char str_repr[128];
	const char *fmt = "%H:%M:%S";

	std::string time_str;

	std::time_t now = std::time(NULL);
	std::strftime(str_repr, sizeof(str_repr), fmt, std::localtime(&now));

	std::string msec = getMsec();

	time_str = std::string(str_repr) + "." + msec;

	return time_str;
}

void Log::logMsg(std::string msg, int fd)
{
	std::string log_time = Log::getTime();

	std::string server_name;

	if (fd == FD_UNDEF)
	{
		std::printf("[%s]\t%s\t%-4s %s\n", log_time.c_str(), server_name.c_str(), "-", msg.c_str());
	}
	else
	{
		std::string s_fd = std::to_string(fd);
		std::printf("[%s]\t%s\t%-4s %s\n", log_time.c_str(), server_name.c_str(), s_fd.c_str(), msg.c_str());
	}
}