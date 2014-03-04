
#ifndef __KML_LOADER_H__
#define __KML_LOADER_H__

#include "libgps.h"


#ifdef __cplusplus
extern "C" {
#endif


	/* read kml file. */
	extern struct GPSGroup* kml_loader(const char* filename);


#ifdef __cplusplus
}	/* extern "C" */
#endif

#endif	/* __KML_LOADER_H__ */

