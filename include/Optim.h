/**********************************************
    > File Name: Optim.h
    > Author: Luting Wang
    > Mail: 2457348692@qq.com 
    > Created Time: Wed Nov  6 22:11:33 2019
 **********************************************/

#ifndef OPTIM_H
#define OPTIM_H

#include <map>
#include <string>

class MidCode;
class BasicBlock;

namespace symtable {
    class Entry;
	class FuncTable;
}

class VarMatch;

const symtable::FuncTable* _calledFunc(const BasicBlock* const);

class Optim {
    static void _cleanFuncs(void);
    static void _cleanBlocks(symtable::FuncTable* const);
    static void _cleanLabels(symtable::FuncTable* const);
public:
	static void clean(void);
    
private:
    static const symtable::FuncTable* _repaceBlock(BasicBlock* const);
public:
	static bool inlineExpan(void);
    
	static bool commonExprElim(void);
    
private:
    static bool _constProp(const MidCode*&);
    static bool _varProp(const MidCode*&, VarMatch&);
public:
	static bool symProp(void);
    
	static bool peephole(void);
};

#endif /* OPTIM_H */
