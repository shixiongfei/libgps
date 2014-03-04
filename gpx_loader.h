
#ifndef __GPX_LOADER_H__
#define __GPX_LOADER_H__

#include "libgps.h"


#ifdef __cplusplus
extern "C" {
#endif


	/* read gpx file. */
	extern struct GPSGroup* gpx_loader(const char* filename);


#ifdef __cplusplus
}	/* extern "C" */
#endif

#endif	/* __GPX_LOADER_H__ */

