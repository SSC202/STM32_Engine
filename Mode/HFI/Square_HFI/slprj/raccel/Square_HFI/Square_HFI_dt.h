#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , { "int16_T" , 17 , 2 } , {
"uint64_T" , 18 , 8 } , { "int64_T" , 19 , 8 } , { "uint_T" , 20 , 32 } , {
"char_T" , 21 , 8 } , { "uchar_T" , 22 , 8 } , { "time_T" , 23 , 8 } } ;
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T
) , sizeof ( uint64_T ) , sizeof ( int16_T ) , sizeof ( uint64_T ) , sizeof (
int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) ,
sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T"
, "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"int16_T" , "uint64_T" , "int64_T" , "uint_T" , "char_T" , "uchar_T" ,
"time_T" } ; static DataTypeTransition rtBTransitions [ ] = { { ( char_T * )
( & rtB . avkcbyy3ru [ 0 ] ) , 0 , 0 , 25 } , { ( char_T * ) ( & rtB .
hnrjpbhtyb ) , 1 , 0 , 70 } , { ( char_T * ) ( & rtB . irpxyowq0z ) , 4 , 0 ,
1 } , { ( char_T * ) ( & rtDW . ixn3ky1f2r ) , 0 , 0 , 4 } , { ( char_T * ) (
& rtDW . ofbl3m3sl1 . LoggedData ) , 11 , 0 , 55 } , { ( char_T * ) ( & rtDW
. gkxlktnf2e ) , 1 , 0 , 9 } , { ( char_T * ) ( & rtDW . afdxa4jpho ) , 6 , 0
, 1 } , { ( char_T * ) ( & rtDW . fjmelxecm4 . PrevIndex ) , 10 , 0 , 1 } , {
( char_T * ) ( & rtDW . prwdcgjlej ) , 17 , 0 , 1 } , { ( char_T * ) ( & rtDW
. eohtar5htx ) , 3 , 0 , 2 } } ; static DataTypeTransitionTable rtBTransTable
= { 10U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = {
{ ( char_T * ) ( & rtP . _CurrKi2f2Square_HFI_sldd_ ) , 1 , 0 , 10 } , { (
char_T * ) ( & rtP . Int1_L ) , 0 , 0 , 10 } , { ( char_T * ) ( & rtP .
PIDController3_InitialConditionForIntegrator ) , 1 , 0 , 10 } , { ( char_T *
) ( & rtP . PIDController1_InitialConditionForIntegrator ) , 17 , 0 , 1 } , {
( char_T * ) ( & rtP . AnalogFilterDesign_A_pr [ 0 ] ) , 0 , 0 , 139 } , { (
char_T * ) ( & rtP . Constant1_Value_fpaq0utenz ) , 1 , 0 , 49 } , { ( char_T
* ) ( & rtP . AnalogFilterDesign_A_ir [ 0 ] ) , 7 , 0 , 168 } , { ( char_T *
) ( & rtP . Constant1_Value_odajvcsv3r ) , 4 , 0 , 2 } , { ( char_T * ) ( &
rtP . Constant_Value_jxwhvocfhb ) , 2 , 0 , 12 } } ; static
DataTypeTransitionTable rtPTransTable = { 9U , rtPTransitions } ;
