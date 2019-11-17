/**********************************************
    > File Name: BasicBlock.cpp
    > Author: Luting Wang
    > Mail: 2457348692@qq.com 
    > Created Time: Fri Nov  8 09:40:40 2019
 **********************************************/

#include <cassert>
#include <set>
#include <vector>
#include "midcode/MidCode.h"
#include "midcode/BasicBlock.h"

const std::vector<const MidCode*>& BasicBlock::midcodes(void) const {
    return _midcodes;
}

bool BasicBlock::dirty(void) const {
    return _dirty;
}

BasicBlock::BasicBlock(void) {}

BasicBlock::BasicBlock(const std::vector<const MidCode*>::const_iterator first,
        const std::vector<const MidCode*>::const_iterator last) :
    _midcodes(first, last) {}

BasicBlock::~BasicBlock(void) {
    assert(!_dirty);
}

void BasicBlock::_proceed(BasicBlock* const successor) {
	_succ.insert(successor);
	successor->_prec.insert(this);
}

void BasicBlock::_unlink(void) {
    assert(isolated());
    for (auto successor : _succ) {
        successor->_prec.erase(this);
    }
}

bool BasicBlock::isFuncCall(void) const {
	return _midcodes.back()->is(MidCode::Instr::CALL);
}

bool BasicBlock::isolated(void) const {
    return _prec.empty();
}
