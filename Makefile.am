AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}
AM_CPPFLAGS=-D_FORTIFY_SOURCE=2
AM_CXXFLAGS=-g -O2 -fstack-protector --param=ssp-buffer-size=4 -Wformat -Werror=format-security
AM_FFLAGS=-g -O2
AM_LDFLAGS=-Wl,-z,relro

bin_PROGRAMS = begin
begin_SOURCES = src/begin.hpp src/begin.cxx src/main.cxx

#dist_noinst_SCRIPTS = autogen.sh
