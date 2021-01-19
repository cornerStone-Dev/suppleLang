// suppleLang.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NDEBUG
#include <assert.h>
#include "suppleLang.h"

typedef union Data {
	u64  u;
	s64  s;
	f64  f;
	u8  *b;
} Data;

typedef struct Token {
	u64  data;
	u32  lineNumber;
	u32  length;
} Token;

typedef struct tokenData {
	u8  *string;
	u64  data;
} tokenData;

typedef struct terminalData {
	u8  *siblings;
	u32  lineNumber;
	u32  stringLength;
	u8  *children;
} terminalData;

typedef struct context {
	u8  *string;
	u32  stringLength;
	u32  lineNumber;
} context;

typedef struct Pair {
	u64 x;
	u64 y;
} Pair;

enum {
	TOK_NUMERIC,
	TOK_SUBTRACT,
};

static inline u64
getLower32(u64 x) __attribute__((always_inline));

static inline u64
getLower32(u64 x)
{
	return x & 0xFFFFFFFF;
}

static inline u64
getUpper32(u64 x) __attribute__((always_inline));

static inline u64
getUpper32(u64 x)
{
	return x >> 32;
}

static inline u64
moveToUpper32(u64 x)
{
	return x << 32;
}

static inline u64
moveToUpper16(u64 x)
{
	return x << 48;
}

#include "suppleLangGram.c"
#include "suppleLangLex.c"



























