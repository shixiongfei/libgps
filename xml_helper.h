/*
  Copyright (c) 2014 Jenson Shi <jenson.shixf@gmail.com>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
  
        http://shixf.com/
*/

#ifndef __XML_HELPER_H__
#define __XML_HELPER_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "libmxml/mxml.h"


#ifdef __cplusplus
extern "C" {
#endif


	#ifdef _MSC_VER
		#define stricmp			_stricmp
	#else	/* _MSC_VER	*/
		#define stricmp			strcasecmp
	#endif	/* _MSC_VER	*/


	#define DBL_CMP(a, b)			( fabs(a - b) < DBL_EPSILON )
	#define FLT_CMP(a, b)			( fabsf(a - b) < FLT_EPSILON )


	extern mxml_node_t* xml_load(const char* filename);

	extern void xml_close(mxml_node_t* tree);

	extern char* gpxtime_to_exiftime(char et[20], const char* gt);

	extern int tmcmp(const char* left, const char* right);


#ifdef __cplusplus
}	/* extern "C" */
#endif

#endif	/* __XML_HELPER_H__ */
