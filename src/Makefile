BUILD_PATH=../bin/
CC=gcc
CFLAGS=-g -Wall -Wextra -Werror
EXTRAFLAGS=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector 
TARGETS=get_single_chars selfmade_portable_fflush

all: check rebuild

build: clean $(TARGETS)

rebuild: clean_all  $(TARGETS) clean

%: %.c  
	$(CC) $(CFLAGS) $< -o  $(BUILD_PATH)$@ 
	$(CC) $(CFLAGS) $(EXTRAFLAGS) $< -o  $(BUILD_PATH)$@_extra


clean_all:
	rm -rf *.o *.a *.so $(BUILD_PATH)*
	
clean:
	rm -rf *.o *.a

check:
	clang-format -n *.c
#	clang-format -n *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h




