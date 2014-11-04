#ifndef ut0mem.h
#define ut0mem.h

#include "univ.i"
#include <string.h>
#include <stdlib.h>

UNIV_INLINE
void *
ut_memcpy(void* dest, void* sour, ulint n);

UNIV_INLINE
void *
ut_memmove(void* dest, void* sour, ulint n);

UNIV_INLINE
void *
ut_memcmp(void* str1, void* str2, ulint n);

UNIV_INLINE
void *
ut_malloc(ulint n);

UNIV_INLINE
void *
ut_free(void* ptr);

UNIV_INLINE
void *
ut_strcpy(char* dest, char* sour);

UNIV_INLINE
void *
ut_strlen(char* str);

UNIV_INLINE
void *
ut_strcmp(char* str1, char* str2);

UNIV_INLINE
void *
ut_catenate(char* str1, char *str2);



#endif
