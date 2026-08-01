/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_git2_util_h__
#define INCLUDE_git2_util_h__

#if !defined(LIBGIT2_NO_FEATURES_H)
# include "git2_features.h"
#endif

#include "git2/common.h"
#include "git2/sys/errors.h"
#include "cc-compat.h"

typedef struct git_str git_str;

#include "git2_compiler_attrs.h"

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include "git2_platform.h"
#include "git2/types.h"
#include "git2/errors.h"
#include "thread.h"
#include "integer.h"
#include "assert_safe.h"

#include "posix.h"

#include "git2_buffer_config.h"

#include "git2_error_checks.h"

#include "git2_overflow_checks.h"

#include "util.h"
#include "ctype_compat.h"

#endif
