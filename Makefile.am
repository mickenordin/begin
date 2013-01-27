AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}
CPPFLAGS=-D_FORTIFY_SOURCE=2
CXXFLAGS=-g -O2 -fstack-protector --param=ssp-buffer-size=4 -Wformat -Werror=format-security
FFLAGS=-g -O2
LDFLAGS=-Wl,-z,relro

bin_PROGRAMS = begin
begin_SOURCES = src/begin.hpp src/begin.cxx src/main.cxx

#dist_noinst_SCRIPTS = autogen.sh
