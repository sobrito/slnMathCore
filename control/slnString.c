/*
 * slnString.c
 *
 *  Created on: 13/08/2013
 *      Author: silenobrito
 */
#include <control/slnString.h>
#include <sys/types.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdio.h>

char * slnStringFromLongLong(long long a) {
    char tmp[BUFFER_STRING_NUMBER_CONVERSION];
    memset(tmp, '\0', sizeof (char) * BUFFER_STRING_NUMBER_CONVERSION);
    sprintf(tmp, "%ll", a);
    return strdup(tmp);
}

char * slnStringFromLong(long a) {
    char tmp[BUFFER_STRING_NUMBER_CONVERSION];
    memset(tmp, '\0', sizeof (char) * BUFFER_STRING_NUMBER_CONVERSION);
    sprintf(tmp, "%l", a);
    return strdup(tmp);
}

char * slnStringFromInterger(int a) {
    char tmp[BUFFER_STRING_NUMBER_CONVERSION];
    memset(tmp, '\0', sizeof (char) * BUFFER_STRING_NUMBER_CONVERSION);
    sprintf(tmp, "%i", a);
    return strdup(tmp);
}

char * slnStringFromDouble(double a) {
    char tmp[BUFFER_STRING_NUMBER_CONVERSION];
    memset(tmp, '\0', sizeof (char) * BUFFER_STRING_NUMBER_CONVERSION);
    sprintf(tmp, "%lf", a);
    return strdup(tmp);
}

char * slnStringFromFloat(float a) {
    char tmp[BUFFER_STRING_NUMBER_CONVERSION];
    memset(tmp, '\0', sizeof (char) * BUFFER_STRING_NUMBER_CONVERSION);
    sprintf(tmp, "%f", a);
    return strdup(tmp);
}

char * slnStringPadLeft(char *str, char c, int length) {
    char *out = NULL;
    size_t len = str == NULL ? 0 : strlen(str);
    size_t strLen = len > length ? len : length + 1;

    /**
     * Se n�o for necess�rio completar a String
     */
    if (len == strLen) {
        return str == NULL ? NULL : strdup(str);
    }
    /**
     * Se for necess�rio completar a String
     */
    if ((out = (char *) malloc(sizeof (*out) * strLen)) == NULL) {
        perror("malloc");
        return NULL;
    }
    memset(out, c, strLen);
    memcpy(out, str, strlen(str));
    out[strLen - 1] = '\0';

    return out;
}

/**
 * Completa a string com um caratere espec�fico at� chegar a quantidade de cacteres desejado
 */
char * slnStringPadRight(char *str, char c, int length) {
    char *out = NULL;
    size_t len = str == NULL ? 0 : strlen(str);
    size_t strLen = len > length ? len : length + 1;

    /**
     * Se n�o for necess�rio completar a String
     */
    if (len == strLen) {
        return str == NULL ? NULL : strdup(str);
    }
    /**
     * Se for necess�rio completar a String
     */
    if ((out = (char *) malloc(sizeof (*out) * strLen)) == NULL) {
        perror("malloc");
        return NULL;
    }
    memset(out, c, strLen);
    memcpy(out + (strLen - length - 1), str, strlen(str));
    out[strLen - 1] = '\0';

    return out;
}

char * slnStringFormat(char *format, ...) {
    va_list args;
    regmatch_t match;
    regex_t reg_args;
    size_t len = 0;
    char error[BUFFER_STRING_MESSAGE];
    char *tmp = NULL;
    char *text_args = "(^%([a-z0-9\\.]+))|([\\s]%([a-z0-9\\.]+))";
    int start = 0;
    int i;
    
    if ((i = regcomp(&reg_args, text_args, REG_EXTENDED | REG_ICASE)) != 0) {
        regerror(i, &reg_args, error, BUFFER_STRING_MESSAGE);
        fprintf(stderr, error);
        return NULL;
    }

    len = strlen(format);

    for (i = 0; regexec(&reg_args, text_args + start, REG_EXTENDED | REG_ICASE, &match, 0) == 0; i++) {
        len += BUFFER_STRING_NUMBER_CONVERSION;
        start += match.rm_eo;
    }

    if ((tmp = (char *) malloc((sizeof *tmp) * len)) == NULL) {
        perror("malloc");
        return NULL;
    }

    va_start(args, format);
    vsprintf(tmp, format, args);
    perror(tmp);
    va_end(args);
    return tmp;
}

int slnStringInit(struct slnString *s) {
    if (s == NULL) {
        return EXIT_FAILURE;
    }
    s->fromInterger = slnStringFromInterger;
    s->fromLongLong = slnStringFromLongLong;
    s->fromDouble = slnStringFromDouble;
    s->fromFloat = slnStringFromFloat;
    s->fromLong = slnStringFromLong;
    s->padRight = slnStringPadRight;
    s->padLeft = slnStringPadLeft;
    s->format = slnStringFormat;
    return EXIT_SUCCESS;
}

int string_init() {
    return slnStringInit(&String);
}
