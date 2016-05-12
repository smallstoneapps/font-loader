PEBBLE_HEADERS=tests/include

CC=gcc
ifeq ($(TRAVIS), true)
CFLAGS=-std=c99
else
CFLAGS=-std=c11
endif
CINCLUDES=-I "$(PEBBLE_HEADERS)" -I tests/ -I include/

TEST_FILES=tests/font-loader.c
SRC_FILES=src/c/font-loader.c
TEST_EXTRAS=tests/src/pebble.c
LIB_FILES=

all: test

test:
	@$(CC) $(CFLAGS) $(CINCLUDES) $(TEST_FILES) $(SRC_FILES) $(LIB_FILES) $(TEST_EXTRAS) -o tests/run
	@tests/run
	@rm tests/run
	@printf "\x1B[0m"
