#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";

	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 98;
	static const long BUILD  = 22;
	static const long REVISION  = 0;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 567;
	#define RC_FILEVERSION 0,98,22,0
	#define RC_FILEVERSION_STRING "0, 98, 22, 0\0"
	static const char FULLVERSION_STRING [] = "0.98.22.0";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 0;

}
#endif //VERSION_H
