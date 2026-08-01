#ifndef INCLUDE_overflow_checks_h__
#define INCLUDE_overflow_checks_h__

/** Check for additive overflow, setting an error if would occur. */
#define GIT_ADD_SIZET_OVERFLOW(out, one, two) \
    (git__add_sizet_overflow(out, one, two) ? (git_error_set_oom(), 1) : 0)

/** Check for additive overflow, setting an error if would occur. */
#define GIT_MULTIPLY_SIZET_OVERFLOW(out, nelem, elsize) \
    (git__multiply_sizet_overflow(out, nelem, elsize) ? (git_error_set_oom(), 1) : 0)

/** Check for additive overflow, failing if it would occur. */
#define GIT_ERROR_CHECK_ALLOC_ADD(out, one, two) \
    if (GIT_ADD_SIZET_OVERFLOW(out, one, two)) { return -1; }

#define GIT_ERROR_CHECK_ALLOC_ADD3(out, one, two, three) \
    if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
        GIT_ADD_SIZET_OVERFLOW(out, *(out), three)) { return -1; }

#define GIT_ERROR_CHECK_ALLOC_ADD4(out, one, two, three, four) \
    if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
        GIT_ADD_SIZET_OVERFLOW(out, *(out), three) || \
        GIT_ADD_SIZET_OVERFLOW(out, *(out), four)) { return -1; }

#define GIT_ERROR_CHECK_ALLOC_ADD5(out, one, two, three, four, five) \
    if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
        GIT_ADD_SIZET_OVERFLOW(out, *(out), three) || \
        GIT_ADD_SIZET_OVERFLOW(out, *(out), four) || \
        GIT_ADD_SIZET_OVERFLOW(out, *(out), five)) { return -1; }

/** Check for multiplicative overflow, failing if it would occur. */
#define GIT_ERROR_CHECK_ALLOC_MULTIPLY(out, nelem, elsize) \
    if (GIT_MULTIPLY_SIZET_OVERFLOW(out, nelem, elsize)) { return -1; }

#endif /* INCLUDE_overflow_checks_h__ */