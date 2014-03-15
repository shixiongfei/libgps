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

