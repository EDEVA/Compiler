/**********************************************
    > File Name: Const.cpp
    > Author: Luting Wang
    > Mail: 2457348692@qq.com 
    > Created Time: Sat Sep 28 10:45:46 2019
 **********************************************/

#include <cassert>
#include <string>
#include "compiler.h"
#include "basics.h"
#include "Const.h"
#include "Expr.h"
#include "symtable.h"
#include "error.h"
using lexer::getsym;

// <const def> ::= int<iden>=<integer>{,<iden>=<integer>}|char<iden>=<char>{,<iden>=<char>}
void Const::def(void) {
	// do not use `basics::typeId` or it will read a sym
	assert(sym.is(symbol::RESERVED, symbol::INTTK|symbol::CHARTK));
	bool isInt = sym.numIs(symbol::INTTK); 

	// recursively identify identifier and its value
	std::string idenName;
	do {
		getsym();
		assert(sym.is(symbol::IDENFR));
		idenName = sym.str;

		getsym();
		assert(sym.is(symbol::DELIM, symbol::ASSIGN));

		getsym();
		int num = sym.ch;
		if (!isInt && sym.is(symbol::CHARCON)) { getsym(); }
		// error happens if symbol is char or the value is not an integer
		else if (!isInt || !Expr::integer(num)) {
			err << error::EXPECTED_LITERAL << std::endl;
			// jump to the next ',' or ';'
			while (!sym.is(symbol::DELIM, symbol::COMMA|symbol::SEMICN)) {
				getsym();
			}
		}
		table.pushSym(idenName, true, isInt, num); 
	} while (sym.is(symbol::DELIM, symbol::COMMA));
}

// <const dec> ::= {const<const def>;}
void Const::dec(void) {
	while (sym.is(symbol::RESERVED, symbol::CONSTTK)) {
		getsym();
		def();
		error::assertSymIsSEMICN();
	}
}

