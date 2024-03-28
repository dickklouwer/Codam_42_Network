#ifndef SYSCALL__HPP
#define SYSCALL__HPP

/* C/C++ Libs */
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <poll.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdexcept>
#include <sys/types.h>
#include <sys/wait.h>

/* Webserv */
#include "errors.hpp"

class SysCall
{
public:
	static void access(std::string path, int mode);
	static int socket(int domain, int type, int protocol);
	static int fcntl(int fd, int cmd, int opt_arg1, int opt_arg2);
	static int setsockopt(int socket, int level, int option_name,
						  const void *option_value, socklen_t option_len);
	static int bind(int socket, const struct sockaddr *address, socklen_t address_len);
	static int listen(int socket, int backlog);
	static int accept(int socket, struct sockaddr *address, socklen_t *address_len);
	static int poll(struct pollfd fds[], nfds_t nfds, int timeout);
	static ssize_t recv(int socket, void *buffer, size_t length, int flags);
	static ssize_t send(int socket, const void *buffer, size_t length, int flags);
	static int pipe(int fildes[2]);
	static int execve(const char *path, char *const argv[], char *const envp[]);
	static pid_t waitpid(pid_t pid, int *stat_loc, int options);
	static ssize_t read(int fildes, void *buf, size_t nbyte);
	static ssize_t write(int fildes, const void *buf, size_t nbyte);
	static int open(const char *path, int oflag, int permission_flags);
	static pid_t fork();
	static DIR *opendir(std::string filename);
	static struct dirent *readdir(DIR *dirp);
	static std::vector<struct dirent *> listdir(DIR *dirp);
	static int dup2(int oldfd, int newfd);
	static int close(int fd);
};

#endif
