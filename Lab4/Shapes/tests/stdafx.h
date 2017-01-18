// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702) // To disable 4702 warning in boost
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string/replace.hpp>

#include "../Shapes/CPoint.h"
#include "../Shapes/CLineSegment.h"
#include "../Shapes/CTriangle.h"
#include "../Shapes/CRectangle.h"
#include "../Shapes/CCircle.h"
#include "../Shapes/CRemoteControl.h"

// TODO: reference additional headers your program requires here