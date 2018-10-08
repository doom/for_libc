
SRC			=	$(wildcard src/*/*.c)

SHARED_OBJ		=	$(patsubst src/%.c, build/shared/%.o, $(SRC))

STATIC_OBJ		=	$(patsubst src/%.c, build/static/%.o, $(SRC))

TESTS_SRC		=	$(wildcard tests/tests-*.c) \
				$(wildcard tests/test_helpers/*.c)

SHARED_LIB		=	libfor_libc.so

STATIC_LIB		=	libfor_libc-static.a

TESTS			=	for_libc-tests

CPPFLAGS		=	-isystem include -isystem include/x86_64
CFLAGS			=	-Wall -Wextra -nostdinc -nostdlib -fno-builtin -O3 -std=gnu11

build/shared/%.o:	src/%.c
			@mkdir -p $(shell dirname $@)
			$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) -fPIC $<

build/static/%.o:	src/%.c
			@mkdir -p $(shell dirname $@)
			$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

all:			$(SHARED_LIB) $(STATIC_LIB)

$(STATIC_LIB):		$(STATIC_OBJ)
			ar rcs $(STATIC_LIB) $(STATIC_OBJ)

$(SHARED_LIB):		$(SHARED_OBJ)
			$(CC) -shared -o $(SHARED_LIB) $(SHARED_OBJ)

$(TESTS):		$(STATIC_LIB)
			$(CC) $(TESTS_SRC) $(CPPFLAGS) $(CFLAGS) -Itests/ -o $(TESTS) -L. -lfor_libc-static

tests:			$(TESTS)

clean:
			@$(RM) -r build $(STATIC_LIB) $(SHARED_LIB) $(TESTS)

re:			clean all

.PHONY:			all clean re
