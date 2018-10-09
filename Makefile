
SRC			=	$(wildcard src/*/*.c)

SHARED_OBJ		=	$(patsubst src/%.c, build/shared/%.o, $(SRC))

STATIC_OBJ		=	$(patsubst src/%.c, build/static/%.o, $(SRC))

UT_SRC			=	$(wildcard lib/ut/src/*.c)

UT_OBJ			=	$(patsubst lib/ut/src/%.c, build/ut/%.o, $(UT_SRC))

TESTS_SRC		=	$(wildcard tests/tests-*.c)

SHARED_LIB		=	libfor_libc.so

STATIC_LIB		=	libfor_libc-static.a

TESTS_LIB		=	libut.a

TESTS			=	for_libc-tests

CPPFLAGS		=	-isystem include -isystem include/x86_64
CFLAGS			=	-Wall -Wextra -nostdinc -nostdlib -fno-builtin -O3 -std=gnu11

build/shared/%.o:	src/%.c
			@mkdir -p $(shell dirname $@)
			$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) -fPIC $<

build/static/%.o:	src/%.c
			@mkdir -p $(shell dirname $@)
			$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

build/ut/%.o:		lib/ut/src/%.c
			@mkdir -p $(shell dirname $@)
			$(CC) -c -o $@ $(CPPFLAGS) -Ilib/ut/include $(CFLAGS) $<

all:			$(SHARED_LIB) $(STATIC_LIB)

$(STATIC_LIB):		$(STATIC_OBJ)
			ar rcs $(STATIC_LIB) $(STATIC_OBJ)

$(SHARED_LIB):		$(SHARED_OBJ)
			$(CC) -shared -o $(SHARED_LIB) $(SHARED_OBJ)

$(TESTS_LIB):		$(STATIC_LIB) $(UT_OBJ)
			ar rcs $(TESTS_LIB) $(UT_OBJ)

$(TESTS):		$(STATIC_LIB) $(TESTS_LIB)
			$(CC) $(TESTS_SRC) $(CPPFLAGS) -Ilib/ut/include $(CFLAGS) -Itests/ -o $(TESTS) -L. -lfor_libc-static -lut

tests:			$(TESTS)

clean:
			@$(RM) -r build $(STATIC_LIB) $(SHARED_LIB) $(TESTS_LIB) $(TESTS)

re:			clean all

.PHONY:			all clean re
