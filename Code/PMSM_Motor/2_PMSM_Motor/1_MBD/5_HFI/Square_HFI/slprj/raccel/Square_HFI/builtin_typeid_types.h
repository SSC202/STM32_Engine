#ifndef BUILTIN_TYPEID_TYPES_H
#define BUILTIN_TYPEID_TYPES_H
#ifndef BUILTIN_TYPEID_TYPES
#define BUILTIN_TYPEID_TYPES
typedef enum { SS_DOUBLE = 0 , SS_SINGLE = 1 , SS_INT8 = 2 , SS_UINT8 = 3 ,
SS_INT16 = 4 , SS_UINT16 = 5 , SS_INT32 = 6 , SS_UINT32 = 7 , SS_BOOLEAN = 8
} BuiltInDTypeId ;
#define SS_NUM_BUILT_IN_DTYPE          ((int)SS_BOOLEAN+1)
typedef int DTypeId ; typedef enum { SS_FCN_CALL = 9 , SS_INTEGER = 10 ,
SS_POINTER = 11 , SS_INTERNAL_DTYPE2 = 12 , SS_TIMER_UINT32_PAIR = 13 ,
SS_CONNECTION_TYPE = 14 } PreDefinedDTypeId ;
#endif
#endif
