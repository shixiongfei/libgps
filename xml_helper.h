
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
