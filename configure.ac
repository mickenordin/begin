AC_INIT([begin], [0.1], [mik@elnord.in],
             [begin], [https://github.com/mickenordin/begin])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall no-define])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([boost/xpressive/xpressive.hpp], [],
    [AC_MSG_ERROR(You need the Boost Xpressive library.)])
AC_LANG_POP([C++])

