#include "RequestProcessor.hpp"

std::string RequestProcessor::executeCgi(const t_uri_comps &uri)
{
	std::string raw_html;
	std::string raw_cgi_output;
	std::string err_output;

	std::string exec_path = uri.path;
	std::cout << "exec_path: " << exec_path << '\n';
	SysCall::access(exec_path, X_OK);

	int filedes[2], stderr_filedes[2];

	SysCall::pipe(filedes);
	SysCall::pipe(stderr_filedes);

	std::vector<char *> cgi_env;
	std::string path_info_env_var = "PATH_INFO=" + uri.path_info;
	std::string query_string_env_var = "QUERY_STRING=" + uri.query_str;
	cgi_env.push_back(const_cast<char *>(path_info_env_var.c_str()));
	cgi_env.push_back(const_cast<char *>(query_string_env_var.c_str()));
	cgi_env.push_back(NULL);

    pid_t child_pid;
    if ((child_pid = SysCall::fork()) == 0) {
        SysCall::dup2(filedes[1], STDOUT_FILENO);
        SysCall::dup2(stderr_filedes[1], STDERR_FILENO);
        SysCall::close(filedes[0]);
        SysCall::close(stderr_filedes[0]);
        SysCall::execve(exec_path.c_str(), NULL, cgi_env.data());
        exit(EXIT_FAILURE);
    } 
	else {
        SysCall::close(filedes[1]);
        SysCall::close(stderr_filedes[1]);

        int status;
        SysCall::waitpid(child_pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
            raw_cgi_output = readFull(filedes[0]);
        } else {
            err_output = readFull(stderr_filedes[0]);
			SysCall::close(filedes[0]);
			SysCall::close(stderr_filedes[0]);
            throw std::runtime_error("CGI Script error: " + err_output);
        }
    }
	SysCall::close(filedes[0]);
	SysCall::close(stderr_filedes[0]);
	std::cout << "raw_cgi_output: " << raw_cgi_output << '\n';
	return raw_cgi_output;
}
