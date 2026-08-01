#ifndef INCLUDE_compiler_attrs_h__
#define INCLUDE_compiler_attrs_h__

/** Declare a function as always inlined. */
#if defined(_MSC_VER)
#define GIT_INLINE(type) static __inline type
#elif defined(__GNUC__)
#define GIT_INLINE(type) static __inline__ type
#else
#define GIT_INLINE(type) static type
#endif

/** Support for gcc/clang __has_builtin intrinsic */
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

/**
 * Declare that a function's return value must be used.
 *
 * Used mostly to guard against potential silent bugs at runtime. This is
 * recommended to be added to functions that:
 *
 * - Allocate / reallocate memory. This prevents memory leaks or errors where
 *   buffers are expected to have grown to a certain size, but could not be
 *   resized.
 * - Acquire locks. When a lock cannot be acquired, that will almost certainly
 *   cause a data race / undefined behavior.
 */
#if defined(__GNUC__)
#define GIT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#define GIT_WARN_UNUSED_RESULT
#endif

#if (defined(_WIN32)) && !defined(__CYGWIN__)
#define GIT_WIN32 1
#endif

#endif
