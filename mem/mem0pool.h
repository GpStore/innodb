#ifndef mem0pool.h
#define mem0pool.h

#include "univ.i"
#include "os0file.h"
#include "ut0lst.h"

typedef struct mem_area_struct mem_area_t;
typedef struct mem_pool_struct mem_pool_t;

extern mem_pool_t* mem_comm_pool;

struct mem_area_struct {
  ulint size_and_free;
  UT_LIST_NODE_T(mem_area_t) free_list;
}

#define MEM_AREA_EXTRA_SIZE (sizeof(struct mem_area_struct))

mem_pool_t* mem_pool_create(ulint size);
void*       mem_area_alloc(ulint size, mem_pool_t* pool);
ulint       mem_pool_get_reserved(mem_pool_t *pool);
ibool       mem_pool_validate(mem_pool_t* pool);
void        mem_pool_print_info(FILE* outfile, mem_pool_t* pool);

#ifndef UNIV_INLINE
#include "mem0pool.ic"
#endif



#endif
