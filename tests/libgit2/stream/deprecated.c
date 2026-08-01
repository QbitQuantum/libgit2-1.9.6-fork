#include "clar_libgit2.h"
#include "git2/sys/stream.h"
#include "streams/tls.h"
#include "streams/socket.h"
#include "stream.h"

void test_stream_deprecated__cleanup(void)
{
	cl_git_pass(git_stream_register(GIT_STREAM_TLS | GIT_STREAM_STANDARD, NULL));
}

void test_stream_deprecated__register_tls(void)
{

}
