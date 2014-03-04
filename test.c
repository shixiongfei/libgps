
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
