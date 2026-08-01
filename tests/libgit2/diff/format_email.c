#include "clar.h"
#include "clar_libgit2.h"

#include "commit.h"
#include "diff.h"
#include "diff_generate.h"

static git_repository *repo;

void test_diff_format_email__initialize(void)
{
	repo = cl_git_sandbox_init("diff_format_email");
}

void test_diff_format_email__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_diff_format_email__simple(void)
{

}

void test_diff_format_email__with_message(void)
{

}


void test_diff_format_email__multiple(void)
{

}

void test_diff_format_email__exclude_marker(void)
{

}

void test_diff_format_email__invalid_no(void)
{

}

void test_diff_format_email__mode_change(void)
{

}

void test_diff_format_email__rename_add_remove(void)
{

}

void test_diff_format_email__multiline_summary(void)
{

}

void test_diff_format_email__binary(void)
{

}

