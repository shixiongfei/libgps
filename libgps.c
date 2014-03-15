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

#include "libgps.h"
#include "xml_helper.h"
#include "gpx_loader.h"
#include "kml_loader.h"


struct GPSData* load_gpsfile(const char* filename) {
	struct GPSData* d = (struct GPSData*)calloc(1, sizeof(struct GPSData));

	const char* ext = strrchr(filename, '.');

	if ( !stricmp(ext, ".gpx") ) {
		d->group = gpx_loader(filename);
	}

	if ( !stricmp(ext, ".kml") ) {
		d->group = kml_loader(filename);
	}

	if ( d->group ) {
		struct GPSGroup* g_offset = d->group;

		struct GPSGroup* st = NULL;
		struct GPSGroup* et = NULL;

		while ( g_offset ) {
			if ( !st || tmcmp(g_offset->start_time, st->start_time) < 0 ) {
				st = g_offset;
			}		
			if ( !et || tmcmp(g_offset->end_time, et->end_time) > 0 ) {
				et = g_offset;
			}

			d->number += g_offset->number;

			g_offset = g_offset->next;
		}

		if ( st ) {
			strncpy(d->start_time, st->start_time, sizeof(d->start_time));
		}

		if ( et ) {
			strncpy(d->end_time, et->end_time, sizeof(d->end_time));
		}
	}

	return d;
}


void gpsfile_free(struct GPSData* gps_data) {
	while ( gps_data->group ) {
		struct GPSGroup* group = gps_data->group;
		gps_data->group = gps_data->group->next;

		while ( group->point ) {
			struct GPSPoint* point = group->point;
			group->point = group->point->next;
			free(point);
		}
		free(group);
	}
	free(gps_data);
}


struct GPSPoint* gps_match(struct GPSData* gps_data, const char* time) {
	if ( tmcmp(time, gps_data->start_time) >= 0 ) {
		if ( tmcmp(time, gps_data->end_time) <= 0 ) {

			struct GPSGroup* g_offset = gps_data->group;

			while ( g_offset ) {

				if ( tmcmp(time, g_offset->start_time) >= 0 ) {
					if ( tmcmp(time, g_offset->end_time) <= 0 ) {

						struct GPSPoint* p_offset = g_offset->point;

						while ( p_offset ) {
							if ( tmcmp(time, p_offset->time) <= 0 ) {
								return p_offset;
							}
							p_offset = p_offset->next;
						}
					}
				}
				g_offset = g_offset->next;
			}
		}
	}
	return NULL;
}


