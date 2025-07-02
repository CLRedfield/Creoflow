/*
 * Creoflow 核心库
 * 版权所有 2008-2016 Florian Rival (Florian.Rival@gmail.com)。保留所有权利。
 * 本项目基于 MIT 许可证发布。
 */

#ifndef COMMONTOOLS_H
#define COMMONTOOLS_H
#include <algorithm>
#include <cmath>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "Utf8/utf8.h"

#ifdef __GNUC__
    #define GD_DEPRECATED    __attribute__((deprecated))
#else
    #define GD_DEPRECATED
#endif

namespace gd
{

inline double Pi()
{
    return 3.141592653589793238;
}

#ifdef __GNUC__
/**
 * 将数字四舍五入到最接近的整数
 * \ingroup CommonProgrammingTools
 */
inline int Round(float x)
{
    return round(x);
}
#else
/**
 * 将数字四舍五入到最接近的整数
 * \ingroup CommonProgrammingTools
 */
inline double Round( double d )
{
    return ( d >= 0 ? floor(d+0.5) : ceil(d-0.5) );
}
#endif

}

#endif // COMMONTOOLS_H
