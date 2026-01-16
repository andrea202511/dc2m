#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";

	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 90;
	static const long BUILD  = 11;
	static const long REVISION  = 37;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 512;
	#define RC_FILEVERSION 0,90,11,37
	#define RC_FILEVERSION_STRING "0, 90, 11, 37\0"
	static const char FULLVERSION_STRING [] = "0.90.11.37";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 0;

}
#endif //VERSION_H
