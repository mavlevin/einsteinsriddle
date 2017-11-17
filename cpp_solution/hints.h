/************************************\
Author: Guy
File name: hints.h
purpose: export functions of hints.c
remarks: 
\************************************/

#include <functional>
#include <array>

#ifndef __HINTS_H__
#define __HINTS_H__

#include "street.h"

namespace hints
{
	bool run_hints(street::Street &street);
}

#endif /*__HINTS_H__*/