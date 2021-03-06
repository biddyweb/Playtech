/*
 * @description This method takes in a string and an int.  It copies whats in the string
 * into a fixed buffer of length 10.  However, if the user can control the integer
 * argument, bad things can happen. :)
 *
 * To get this to compile, you may need to modify the path to jni.h.  You can do this by:
 * 1. Right click on the project, goto properties
 * 2. Expand Configuration Properties, Goto C/C++, and click General
 * 3. Look for the "Additional Include Directories".
 * 4. Add the path to the jni.h and supporting files. (You should only have to add 2)
 * 
 * In addition, you need the Java JDK.
 * 
 * */

#include "stdafx.h"

/* The function name has to be "encoded";
 * I autogenerated the function name using javah.
 * Basically, it follows the encoding process on this webpage:
 * http://java.sun.com/javase/6/docs/technotes/guides/jni/spec/design.html
 */
JNIEXPORT jstring JNICALL Java_testcases_CWE111_1Unsafe_1JNI_console_CWE111_1Unsafe_1JNI_1_1console_101_test(
	JNIEnv *jenv, 
	jobject jobj, 
	jstring str, 
	jint length
	)
{
	char result[10];

	const char *mfile = (jenv)->GetStringUTFChars(str, NULL);

	strncpy(result, mfile, length);
	result[length] = '\0';

	(jenv)->ReleaseStringUTFChars(str, mfile);

	return (jenv)->NewStringUTF(result);
}
