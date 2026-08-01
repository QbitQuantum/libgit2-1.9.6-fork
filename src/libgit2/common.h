/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_common_h__
#define INCLUDE_common_h__

#include "git2_util.h"
#include "errors.h"

/*
* Include the declarations for deprecated functions; this ensures
* that they're decorated with the proper extern/visibility attributes.
*/
#include "git2/attr.h"
#include "git2/config.h"
#include "git2/common.h"
#include "git2/blame.h"
#include "git2/buffer.h"
#include "git2/checkout.h"
#include "git2/cherrypick.h"
#include "git2/clone.h"
#include "git2/describe.h"
#include "git2/diff.h"
#include "git2/errors.h"
#include "git2/filter.h"
#include "git2/index.h"
#include "git2/indexer.h"
#include "git2/merge.h"
#include "git2/object.h"
#include "git2/proxy.h"
#include "git2/refs.h"
#include "git2/rebase.h"
#include "git2/remote.h"
#include "git2/trace.h"
#include "git2/repository.h"
#include "git2/revert.h"
#include "git2/revparse.h"
#include "git2/stash.h"
#include "git2/status.h"
#include "git2/submodule.h"
#include "git2/worktree.h"
#include "git2/credential.h"
#include "git2/credential_helpers.h"
#include "posix.h"

/**
 * Initialize a structure with a version.
 */
GIT_INLINE(void) git__init_structure(void *structure, size_t len, unsigned int version)
{
	memset(structure, 0, len);
	*((int*)structure) = version;
}
#define GIT_INIT_STRUCTURE(S,V) git__init_structure(S, sizeof(*S), V)

#define GIT_INIT_STRUCTURE_FROM_TEMPLATE(PTR,VERSION,TYPE,TPL) do { \
	TYPE _tmpl = TPL; \
	GIT_ERROR_CHECK_VERSION(&(VERSION), _tmpl.version, #TYPE);      \
	memcpy((PTR), &_tmpl, sizeof(_tmpl)); } while (0)

/**
 * Check a versioned structure for validity
 */
GIT_INLINE(int) git_error__check_version(const void *structure, unsigned int expected_max, const char *name)
{
	unsigned int actual;

	if (!structure)
		return 0;

	actual = *(const unsigned int*)structure;
	if (actual > 0 && actual <= expected_max)
		return 0;

	git_error_set(GIT_ERROR_INVALID, "invalid version %d on %s", actual, name);
	return -1;
}
#define GIT_ERROR_CHECK_VERSION(S,V,N) if (git_error__check_version(S,V,N) < 0) return -1

#endif
