
/*
 * simple GPS info loader for C.
 * GPX/KML track file supported.
 *
 * License: LGPL
 * Copyright (c) 2013 Jenson Sze
 * Email: jenson.sze@gmail.com
 */

#ifndef __LIB_GPS_H__
#define __LIB_GPS_H__

#include <stddef.h>
#include <time.h>


#ifdef __cplusplus
extern "C" {
#endif


	typedef struct GPSPoint {
		double					x, y, z;
		char					time[20];
		struct GPSPoint*		next;
	}GPSPoint;

	typedef struct GPSGroup {
		struct GPSPoint*		point;
		int						number;
		char					start_time[20];
		char					end_time[20];
		struct GPSGroup*		next;
	}GPSGroup;

	typedef struct GPSData {
		struct GPSGroup*		group;
		int						number;
		char					start_time[20];
		char					end_time[20];
	}GPSData;


	/* read gps(gpx/kml) file. */
	extern struct GPSData* load_gpsfile(const char* filename);

	/* free gps file object */
	extern void gpsfile_free(struct GPSData* gps_data);

	/* match best point with time */
	extern struct GPSPoint* gps_match(struct GPSData* gps_data, const char* time);


#ifdef __cplusplus
}	/* extern "C" */
#endif

#endif	/* __LIB_GPS_H__ */

