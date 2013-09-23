/*
 * slnString.h
 *
 *  Created on: 13/08/2013
 *      Author: silenobrito
 */

#ifndef SLNSTRING_H_
#define SLNSTRING_H_

#ifdef	__cplusplus
extern "C" {
#endif

#define BUFFER_STRING_NUMBER_CONVERSION 32
#define BUFFER_STRING_MESSAGE           1024
struct slnString String;

struct slnString {
	char *(*fromLongLong)(long long);
	char *(*fromInterger)(int);
	char *(*fromDouble)(double);
	char *(*fromLong)(long);
	char *(*fromFloat)(float);
	char *(*padRight)(char *str, char c, int length);
	char *(*padLeft)(char *str, char c, int length);
	char *(*format)(char *format, ...);
};

int string_init();

#ifdef	__cplusplus
}
#endif

#endif /* SLNSTRING_H_ */
