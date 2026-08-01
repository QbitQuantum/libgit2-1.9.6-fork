#ifndef INCLUDE_platform_h__
#define INCLUDE_platform_h__

#ifdef GIT_WIN32

# include <io.h>
# include <direct.h>
# include <winsock2.h>
# include <windows.h>
# include <ws2tcpip.h>
# include "win32/msvc-compat.h"
# include "win32/mingw-compat.h"
# include "win32/win32-compat.h"
# include "win32/w32_common.h"
# include "win32/version.h"
# include "win32/error.h"
# ifdef GIT_THREADS
#  include "win32/thread.h"
# endif

#else

# include <unistd.h>
# include <strings.h>
# ifdef GIT_THREADS
#	include <pthread.h>
#	include <sched.h>
# endif

#define GIT_LIBGIT2_CALL
#define GIT_SYSTEM_CALL

#ifdef GIT_USE_STAT_ATIMESPEC
# define st_atim st_atimespec
# define st_ctim st_ctimespec
# define st_mtim st_mtimespec
#endif

# include <arpa/inet.h>

#endif

#endif