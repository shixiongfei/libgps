libgps
======

A very simple GPX/KML track file loader library. It's written in C.

##The library features:

* Simple interface
* Time string matching coordinate
* Works on most POSIX-like systems (including Linux, Mac OS X, etc.)
* Support Windows (including Cygwin, MinGW, and Visual Studio)

##Sample Code

	struct GPSData* gps_test = load_gpsfile("sample.gpx");
	if ( gps_test ) {
		const char query_time[] = {"2009-10-17 18:37:28"};
		struct GPSPoint* p = gps_match(gps_test, query_time);
		if ( p ) {
			printf("%s [At] (%lf, %lf, %lf)\n", query_time, p->x, p->y, p->z);
		}		
		gpsfile_free(gps_test);
	}
