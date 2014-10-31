#ifndef ut0lst.h
#define ut0lst.h
//基础节点信息，含节点个数统计信息，初始节点和尾部节点指针
#define UT_LIST_BASE_NODE_T(TYPE) \
struct {\
    ulint count;\
    TYPE* start;\
    TYPE* end;\
}\
//双向链表前后节点指针
#define UT_LIST_NODE_T(TYPE) \
struct {\
    TYPE* prev;\
    TYPE* next;\
}\
#define UT_LIST_INIT(BASE) \
{\
    (BASE).count = 0;\
    (BASE).start = NULL;\
    (BASE).end = NULL;\
}\
#define UT_LIST_ADD_FIRST(NAME, BASE, N)\
{\
    ((BASE).count)++;\
    ((N)->NAME).next = (BASE).start;\
    ((N)->NAME).prev = NULL;\
    if ((BASE).start != NULL) {\
        (((BASE).start)->NAME).prev = (N);\
    }\
    ((BASE).start) = (N);\
    if ((BASE).end == NULL) {\
        ((BASE).end) = (N);\
    }\
}\
#define UT_LIST_ADD_LAST(NAME, BASE, N) \
{\
    ((BASE).count)++;\
    ((N)->NAME).prev = (BASE).end;\
    ((N)->NAME).next =NULL;\
    if ((BASE).end != NULL) {\
        (((BASE).end)->NAME).next =(N);\
    }\
    (BASE).end =(N);\
    if ((BASE).start == NULL) {\
        (BASE).start = (N);\
    }\
}\
#define UT_LIST_INSERT_AFTER(NAME, BASE, NODE1, NODE2) \
{\
    ((BASE).count)++;\
    ((NODE2)->NAME).prev = (NODE1);\
    ((NODE2)->NAME).next = (NODE1->NAME).next;\
    if ((NODE1)->NAME).next != NULL) {\
        (((NODE1)->NAME).next)->NAME).prev = (NODE2);\
    }\
    ((NODE1)->NAME).next = (NODE2);\
    if ((BASE).end == NODE1) {\
        (BASE).end = NODE2;\
    }\
    
}\
#define UT_LIST_REMOVE(NAME, BASE, N) \
{\
    (BASE).count--;\
    
    if ((N)->NAME).prev != NULL) {\
        (((N)->NAME).prev)->NAME).next = ((N)->NAME).next;\
    } else {\
        (BASE)->start= ((N)->NAME).next;\
    }\
    if ((N)->NAME).next != NULL) {\
        (((N)->NAME).next)->NAME).prev = ((N)->NAME).prev;\
    } else {\
        (BASE)->end = ((N)->NAME).prev;\
    }\
}\
#define UT_LIST_GET_LEN(BASE) {\
    ((BASE).count)
}\
#define UT_LIST_GET_FIRST(BASE) {\
    ((BASE).start)
}\
#define UT_LIST_GET_LAST(BASE) {\
    ((BASE).end)
}\
#define UT_LIST_GET_NEXT(NAME, N) {\
    (((N)->NAME).next)
}\
#define UT_LIST_GET_PREV(NAME, N) {\
    (((N)->NAME).prev)
}\
#define UT_LIST_VALIDATE(NAME, TYPE, BASE) {\
    ulint index;\
    TYPE* node;\
    node = (BASE).start;\
    for (index = 0; index < (BASE).count; i++) {\
        node = (node->NAME).next;    
    }\
    ut_a(node == NULL);\
    node = (BASE).end;\
    for (index = (BASE).count - 1; index >= 0; i--) {\
        node = (node->NAME).prev;    
    }\
    ut_a(node == NULL);\
    
}\
#endif
