/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

#include "buf.h"
#include "common.h"

int git_buf_sanitize(git_buf *buf)
{
	GIT_ASSERT_ARG(buf);

	if (buf->reserved > 0)
		buf->ptr[0] = '\0';
	else
		buf->ptr = git_str__initstr;

	buf->size = 0;
	return 0;
}

int git_buf_tostr(git_str *out, git_buf *buf)
{
	GIT_ASSERT_ARG(out);
	GIT_ASSERT_ARG(buf);

	if (git_buf_sanitize(buf) < 0)
		return -1;

	out->ptr = buf->ptr;
	out->asize = buf->reserved;
	out->size = buf->size;

	buf->ptr = git_str__initstr;
	buf->reserved = 0;
	buf->size = 0;

	return 0;
}

int git_buf_fromstr(git_buf *out, git_str *str)
{
	GIT_ASSERT_ARG(out);
	GIT_ASSERT_ARG(str);

	out->ptr = str->ptr;
	out->reserved = str->asize;
	out->size = str->size;

	str->ptr = git_str__initstr;
	str->asize = 0;
	str->size = 0;

	return 0;
}

void git_buf_dispose(git_buf *buf)
{
	if (!buf)
		return;

	if (buf->ptr != git_str__initstr)
		git__free(buf->ptr);

	buf->ptr = git_str__initstr;
	buf->reserved = 0;
	buf->size = 0;
}