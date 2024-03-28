#include "SysCall.hpp"
#include <iostream>

void SysCall::access(std::string path, int mode)
{
	if (::access(path.c_str(), mode) == -1)
		throw std::runtime_error("access error: " + STRERR);
}

int SysCall::socket(int domain, int type, int protocol)
{
	int fd = ::socket(domain, type, protocol);

	if (fd == -1)
		throw std::runtime_error("server socket error: " + STRERR);

	return fd;
}

int SysCall::fcntl(int fd, int cmd, int opt_arg1, int opt_arg2)
{
	int ret_val = ::fcntl(fd, cmd, opt_arg1, opt_arg2);

	if (ret_val == -1)
		throw std::runtime_error("fcntl error: " + STRERR);

	return ret_val;
}

int SysCall::setsockopt(int socket, int level, int option_name,
						const void *option_value, socklen_t option_len)
{
	int ret_val = ::setsockopt(socket, level, option_name, option_value, option_len);

	if (ret_val == -1)
		throw std::runtime_error("setsockopt error: " + STRERR);

	return ret_val;
}

int SysCall::close(int fd)
{
	int ret_val = ::close(fd);

	if (ret_val == -1)
		throw std::runtime_error("close error: " + STRERR);

	return ret_val;
}

int SysCall::bind(int socket, const struct sockaddr *address, socklen_t address_len)
{
	int ret_val = ::bind(socket, address, address_len);

	if (ret_val == -1)
	{
		SysCall::close(socket);
		throw std::runtime_error("bind error: " + STRERR);
	}
	return ret_val;
}

int SysCall::listen(int socket, int backlog)
{
	int ret_val = ::listen(socket, backlog);

	if (ret_val == -1)
	{
		SysCall::close(socket);
		throw std::runtime_error("listen error: " + STRERR);
	}

	return ret_val;
}

int SysCall::accept(int socket, struct sockaddr *address, socklen_t *address_len)
{
	int ret_val = ::accept(socket, address, address_len);

	if (ret_val == -1)
		throw std::runtime_error("accept error: " + STRERR);

	return ret_val;
}

int SysCall::poll(struct pollfd fds[], nfds_t nfds, int timeout)
{
	int ret_val = ::poll(fds, nfds, timeout);

	if (ret_val == -1)
		throw std::runtime_error("poll error: " + STRERR);

	return ret_val;
}

ssize_t SysCall::recv(int socket, void *buffer, size_t length, int flags)
{
	ssize_t ret_val = ::recv(socket, buffer, length, flags);

	if (ret_val == -1)
		throw std::runtime_error("recv error: " + STRERR);

	return ret_val;
}

ssize_t SysCall::send(int socket, const void *buffer, size_t length, int flags)
{
	ssize_t ret_val = ::send(socket, buffer, length, flags);

	if (ret_val == -1)
		throw std::runtime_error("send error: " + STRERR);

	return ret_val;
}

int SysCall::pipe(int fildes[2])
{
	int ret_val = ::pipe(fildes);

	if (ret_val == -1)
		throw std::runtime_error("pip error: " + STRERR);

	return ret_val;
}

pid_t SysCall::fork()
{
	pid_t ret_val = ::fork();

	if (ret_val == -1)
		throw std::runtime_error("fork error: " + STRERR);

	return ret_val;
}

int SysCall::execve(const char *path, char *const argv[], char *const envp[])
{
	int ret_val = ::execve(path, argv, envp);

	std::cout << "\nRETVAL: " << ret_val ;
	if (ret_val == -1)
		throw std::runtime_error("execve error: " + STRERR);

	return ret_val;
}

pid_t SysCall::waitpid(pid_t pid, int *stat_loc, int options)
{
	pid_t ret_val = ::waitpid(pid, stat_loc, options);

	if (ret_val == -1)
		throw std::runtime_error("waitpid error: " + STRERR);

	return ret_val;
}

ssize_t SysCall::read(int fildes, void *buf, size_t nbyte)
{
	ssize_t ret_val = ::read(fildes, buf, nbyte);

	if (ret_val == -1)
		throw std::runtime_error("read error: " + STRERR);

	return ret_val;
}

ssize_t SysCall::write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t ret_val = ::write(fildes, buf, nbyte);

	if (ret_val == -1)
		throw std::runtime_error("write error: " + STRERR);

	return ret_val;
}

int SysCall::open(const char *path, int oflag, int permission_flags)
{
	int ret_val = ::open(path, oflag, permission_flags);

	if (ret_val == -1)
		throw std::runtime_error("open error: " + STRERR);

	return ret_val;
}

#include <iostream>

DIR *SysCall::opendir(std::string filename)
{
	DIR *dir_stream = ::opendir(filename.c_str());
	std::cout << "fname: " << filename << "\n";
	if (dir_stream == NULL)
		throw std::runtime_error("opendir error: " + STRERR);

	return dir_stream;
}

struct dirent *SysCall::readdir(DIR *dirp)
{
	errno = 0;
	struct dirent *dirent = ::readdir(dirp);

	if (dirent == NULL && errno != 0)
		throw std::runtime_error("readdir error: " + STRERR);

	return dirent;
}

std::vector<struct dirent *> SysCall::listdir(DIR *dirp)
{
	std::vector<struct dirent *> dirents;

	struct dirent *dirent;
	while ((dirent = SysCall::readdir(dirp)) != NULL)
		dirents.push_back(dirent);

	return dirents;
}

int SysCall::dup2(int oldfd, int newfd)
{
	int ret_val = ::dup2(oldfd, newfd);

	if (ret_val == -1)
		throw std::runtime_error("dup2 error: " + STRERR);

	return ret_val;
}