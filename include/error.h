/**********************************************
    > File Name: error.h
    > Author: Luting Wang
    > Mail: 2457348692@qq.com 
    > Created Time: Fri Nov 15 16:24:54 2019
 **********************************************/

#ifdef ERRORS_H
	#error global error.h cannot exist with local
#endif /* ERRORS_H */

#ifndef ERROR_H
#define ERROR_H

namespace error {
	extern bool happened;

	enum class Code {
		LEX, REDEF, NODEF,
		MISMATCHED_ARG_NUM, MISMATCHED_ARG_TYPE, MISMATCHED_COND_TYPE,
		ILLEGAL_RET_WITH_VAL, ILLEGAL_RET_WITHOUT_VAL, ILLEGAL_IND, ILLEGAL_ASSIGN, 
		MISSING_SEMICN, MISSING_RPARENT, MISSING_RBRACK, MISSING_WHILE, 
		EXPECTED_LITERAL, UNEXPECTED_EOF
	};

	void raise(Code);
}

#endif /* ERROR_H */
