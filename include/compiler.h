/**********************************************
    > File Name: compiler.h
    > Author: Luting Wang
    > Mail: 2457348692@qq.com 
    > Created Time: Mon Sep 23 15:12:22 2019
 **********************************************/

#ifndef COMPILER_H
#define COMPILER_H

#include <fstream>
#include "InputFile.h"
#include "Symbol.h"

#define debug 0

extern InputFile input;
extern std::ofstream logger, err;

namespace lexer {
	void getsym(void);
	void traceback(const symbol::Symbol&);
}

namespace grammar {
	void parse(void);
}

#endif /* COMPILER_H */