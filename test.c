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

#include <stdio.h>
#include "libgps.h"


int main(int argc, char* argv[]) {

	char* test_file[] = {	"sample.gpx", "sample.kml", NULL	};
	struct GPSData* gps_test = load_gpsfile(test_file[1]);

	if ( gps_test ) {
		struct GPSGroup* g = gps_test->group;
		struct GPSPoint* p = gps_match(gps_test, "2009-10-17 18:37:28");

		printf("GPS Begin: %s, End: %s. %i Points.\n", gps_test->start_time, gps_test->end_time, gps_test->number);

		if ( p ) {
			printf(" 2009-10-17 18:37:28 [At] (%lf, %lf, %lf)\n", p->x, p->y, p->z);
		}

		p = gps_match(gps_test, "2009-08-17 23:33:08");
		if ( p ) {
			printf(" 2009-08-17 23:33:08 [At] (%lf, %lf, %lf)\n", p->x, p->y, p->z);
		}
		printf("\n");

		while ( g ) {
			p = g->point;

			printf(" GPS Group Begin: %s, End: %s. %i Points.\n", g->start_time, g->end_time, g->number);

			while ( p ) {
				printf("  %s [At] (%lf, %lf, %lf)\n", p->time, p->x, p->y, p->z);
				p = p->next;
			}

			g = g->next;
		}

		gpsfile_free(gps_test);
	}

	printf("Press <Enter> Key to Continue.");
	getchar();

	return 0;
}
