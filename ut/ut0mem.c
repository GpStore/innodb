#include "ut0mem.h"

#ifdef UNIV_NONINL
#include "ut0mem.ic"
#endif

#include "mem0mem.h" //需要调mem_alloc

//分配内存n字节
void*
ut_malloc(ulint n) 
{
  void *ret;
  ret = malloc(n);
  if (ret == NULL) {
    fprintf("Innobase: Fatal Error,cannot allocate memory, cannot contuinue, check increase the swap file of your os\n");
    exit(1);
  }
  return(ret);
}

//连接两个字符串操作
char *
ut_str_catenate(
  char *str1,
  char *str2)
{
  ulint len1;
  ulint len2;
  char *str;
  len1 = ut_strlen(str1);
  len2 = ut_strlen(str2);
  str = mem_alloc(len1 + len2 + 1);
  ut_memcpy(str, str1, len1);
  ut_memcpy(str, str1, len2);
  str[len1 + len2 + 1] = '\0';
  return(str);
}
