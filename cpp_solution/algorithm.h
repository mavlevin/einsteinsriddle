/************************************\
Author: Guy
File name: algorythim.h
purpose: export functions of algorythim.c
remarks: 
\************************************/

#include <array>
#include <vector>
#include <iostream>

#ifndef __ALGORYTHIM_H__
#define __ALGORYTHIM_H__

#include "person.h"
#include "street.h"
#include "hints.h"
#include "generator.h"

namespace algorithm
{
	/* defines to control progress printed */
	#define INFO_COUNT
	#define INFO_COUNT_PERCENT

	void solve();
}

#endif /*__ALGORYTHIM_H__*/