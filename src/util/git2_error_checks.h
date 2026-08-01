#ifndef INCLUDE_error_checks_h__
#define INCLUDE_error_checks_h__

/**
 * Check a pointer allocation result, returning -1 if it failed.
 */
#define GIT_ERROR_CHECK_ALLOC(ptr) do { \
    if ((ptr) == NULL) { return -1; } \
    } while(0)

/**
 * Check a buffer allocation result, returning -1 if it failed.
 */
#define GIT_ERROR_CHECK_ALLOC_STR(buf) do { \
    if ((void *)(buf) == NULL || git_str_oom(buf)) { return -1; } \
    } while(0)

/**
 * Check a return value and propagate result if non-zero.
 */
#define GIT_ERROR_CHECK_ERROR(code) \
    do { int _err = (code); if (_err) return _err; } while (0)

#endif /* INCLUDE_error_checks_h__ */