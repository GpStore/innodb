#include "mem0pool.h"

#ifdef UNIV_INLINE
#include "mem0pool.ic"
#endif

#include "sync0sync.h"
#include "ut0mem.h"
#include "ut0lst.h"
#include "ut0byte.h"

#define MEM_AREA_FREE 1
#define MEM_AREA_MIN_SIZE (2 * sizeof(struct mem_area_struct))

struct mem_pool_struct {
  byte *buf;
  ulint size;
  ulint reserved;
  mutex_t mutex;
  UT_LIST_BASE_NODE_T(mem_area_t) free_list[64];
}

mem_pool_t* mem_comm_pool = NULL;
ulint mem_out_of_mem_err_msg_count = 0;

UNIV_INLINE
ulint
mem_area_get_size(
  mem_area_t *area)
{
  return(area->size_size_and_free & ~MEM_AREA_FREE);  
}

UNIV_INLINE
void
mem_area_set_size(
  mem_area_t* area,
  ulint size)
{
  area->size_and_free = (area->size_and_free & MEM_AREA_FREE) | size;
}

UNIV_INLINE
ibool 
mem_area_get_free(
  mem_area_t* area)
{
  return (area->size_and_free & MEM_AREA_FREE);
}

UNIV_INLINE
void
mem_area_set_free(
  mem_area_t *area,
  ibool free)
{
  area->size_and_free = (area->size_and_free & ~MEM_AREA_FREE) | free;
}

mem_pool_t*
mem_pool_create（
  ulint size)
{
  mem_pool_t* pool;
  mem_area_t* area;
  ulint i;
  ulint used;
  pool = ut_maloc(sizeof(mem_pool_t));
  pool_buf = ut_malloc(size);
  pool_size = size;
  
  mutex_create(&(pool->mutex));
  mutex_set_level(&(pool->mutex), SYNC_MEM_POOL);
  
  for(i = 0; i < 64; i++) {
    UT_LIST_INIT(pool->free_list[i]);
  }
  used = 0;
  while(size - used >= MEM_AREA_MIN_SIZE) {
    i = ut_2_log(size - used);
    if (ut_2_exp(i) > size - used) {
      i--;
    }
    
  }
}
