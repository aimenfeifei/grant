#ifndef _G_GLOBAL_H_
#define _G_GLOBAL_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>


#if defined (GRANT)
# define GRANTAPI __declspec(dllexport)
#else
# define GRANTAPI __delcspec(dllimport)
#endif

#ifndef int32
#define int32 int
#endif

#ifndef uint32
#define uint32 unsigned int
#endif






#endif // _G_GLOBAL_H
