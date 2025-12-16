#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";

	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 0;
	static const long BUILD  = 23;
	static const long REVISION  = 86;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 82;
	#define RC_FILEVERSION 0,0,23,86
	#define RC_FILEVERSION_STRING "0, 0, 23, 86\0"
	static const char FULLVERSION_STRING [] = "0.0.23.86";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 0;

}
#endif //VERSION_H
