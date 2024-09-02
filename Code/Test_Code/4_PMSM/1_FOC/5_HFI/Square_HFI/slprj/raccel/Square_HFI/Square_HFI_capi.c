#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Square_HFI_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 18
#endif
#ifndef SS_INT64
#define SS_INT64 19
#endif
#else
#include "builtin_typeid_types.h"
#include "Square_HFI.h"
#include "Square_HFI_capi.h"
#include "Square_HFI_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Square_HFI/Data Type Conversion1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 1 , 0 , TARGET_STRING ( "Square_HFI/Data Type Conversion2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"Square_HFI/Data Type Conversion3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 3 , 0 , TARGET_STRING ( "Square_HFI/Gain1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING ( "Square_HFI/Mod" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"Square_HFI/Rate Transition" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 6 , 0 , TARGET_STRING ( "Square_HFI/Rate Transition1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"Square_HFI/Rate Transition2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 }
, { 8 , 0 , TARGET_STRING ( "Square_HFI/Rate Transition3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"Square_HFI/Rate Transition8" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 }
, { 10 , 0 , TARGET_STRING ( "Square_HFI/Average-Value Inverter/Product" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"Square_HFI/Average-Value Inverter/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 2 } , { 12 , 0 , TARGET_STRING ( "Square_HFI/Signal Builder/FromWs" )
, TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 13 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 3 } , { 14 , 3 , TARGET_STRING ( "Square_HFI/FOC_Mode/HFI_Mode/Add2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 15 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/AntiPark/Add" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 16 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/AntiPark/Add1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 17 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/Sum1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 3 } , { 18 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/Sum7" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 3 } , { 19 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_AntiPark/Add" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 20 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_AntiPark/Add1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 21 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Clark/Gain2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 22 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Clark/Add2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 23 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Park/Add" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 3 } , { 24 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Park/Add1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 3 } , { 25 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Park/Trigonometric Function" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 26 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Park/Trigonometric Function1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 27 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Data Type Conversion3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 28 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion1" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 1 } , { 29 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion10" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 1 } , { 30 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion11" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 31 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion12" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 1 } , { 32 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 33 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 34 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion4" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 35 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion5" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 1 } , { 36 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion6" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 37 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion7" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 1 } , { 38 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion8" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 1 } , { 39 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Data Type Conversion9" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 40 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/PD/Product" ) , TARGET_STRING ( "" ) , 0 , 1 ,
0 , 0 , 3 } , { 41 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Park/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 3 } , { 42 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Park/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 3 } , { 43 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Park/Trigonometric Function" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 44 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Park/Trigonometric Function1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 45 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Data Type Conversion1" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 3 } , { 46 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time Integrator" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 47 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 48 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 3 } , { 49 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 3 } , { 50 , 3 , TARGET_STRING ( "Square_HFI/FOC_Mode/HFI_Mode/Pre/Mod"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 51 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 3 } , { 52 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Vector Concatenate"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 0 } , { 53 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Ta Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 54 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Tb Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 55 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Tc Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 56 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Divide" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 57 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Divide1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 58 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Divide2" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 59 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/Add" ) , TARGET_STRING ( ""
) , 0 , 1 , 0 , 0 , 1 } , { 60 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/T4 Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 61 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/T6 Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 62 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 63 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 64 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/X_Y_Z_Caculator/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 65 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/X_Y_Z_Caculator/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 66 , 3 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/X_Y_Z_Caculator/Product2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 67 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 68 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Index Vector1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 69 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Index Vector2"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 70 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Divide"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 71 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Add"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 72 , 3 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 1 } , { 73 , 3 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 74 , 3 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 75 , 3 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 76 , 3 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 77 , 3 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 78 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 79 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 80 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Add"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 81 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 82 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Add"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 83 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 84 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 85 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Index Vector2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 86 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 87 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 88 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 89 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Index Vector1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 90 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 91 , 0 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 92 , TARGET_STRING ( "Square_HFI/Interior PMSM" )
, TARGET_STRING ( "Ldq" ) , 0 , 2 , 0 } , { 93 , TARGET_STRING (
"Square_HFI/Interior PMSM" ) , TARGET_STRING ( "mechanical" ) , 1 , 3 , 0 } ,
{ 94 , TARGET_STRING ( "Square_HFI/Interior PMSM" ) , TARGET_STRING ( "idq0"
) , 1 , 2 , 0 } , { 95 , TARGET_STRING ( "Square_HFI/Interior PMSM" ) ,
TARGET_STRING ( "theta_init" ) , 1 , 0 , 0 } , { 96 , TARGET_STRING (
"Square_HFI/Interior PMSM" ) , TARGET_STRING ( "omega_init" ) , 1 , 0 , 0 } ,
{ 97 , TARGET_STRING ( "Square_HFI/Constant" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 98 , TARGET_STRING ( "Square_HFI/Constant1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING ( "Square_HFI/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 100 , TARGET_STRING (
"Square_HFI/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 101 ,
TARGET_STRING ( "Square_HFI/Gain1" ) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 }
, { 102 , TARGET_STRING ( "Square_HFI/Rate Transition" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 103 , TARGET_STRING (
"Square_HFI/Rate Transition1" ) , TARGET_STRING ( "InitialCondition" ) , 0 ,
0 , 0 } , { 104 , TARGET_STRING ( "Square_HFI/Rate Transition2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 105 , TARGET_STRING (
"Square_HFI/Rate Transition3" ) , TARGET_STRING ( "InitialCondition" ) , 0 ,
0 , 0 } , { 106 , TARGET_STRING ( "Square_HFI/Rate Transition8" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 107 , TARGET_STRING (
"Square_HFI/Average-Value Inverter/Constant" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 108 , TARGET_STRING (
"Square_HFI/Average-Value Inverter/Gain" ) , TARGET_STRING ( "Gain" ) , 1 , 0
, 0 } , { 109 , TARGET_STRING (
"Square_HFI/Average-Value Inverter/Saturation2" ) , TARGET_STRING (
"UpperLimit" ) , 1 , 0 , 0 } , { 110 , TARGET_STRING (
"Square_HFI/Average-Value Inverter/Saturation2" ) , TARGET_STRING (
"LowerLimit" ) , 1 , 0 , 0 } , { 111 , TARGET_STRING (
"Square_HFI/Average-Value Inverter/Switch" ) , TARGET_STRING ( "Threshold" )
, 0 , 0 , 0 } , { 112 , TARGET_STRING ( "Square_HFI/Signal Builder/FromWs" )
, TARGET_STRING ( "Time0" ) , 1 , 4 , 0 } , { 113 , TARGET_STRING (
"Square_HFI/Signal Builder/FromWs" ) , TARGET_STRING ( "Data0" ) , 1 , 4 , 0
} , { 114 , TARGET_STRING ( "Square_HFI/FOC_Mode/HFI_Mode/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pulse Generator" ) , TARGET_STRING (
"Amplitude" ) , 1 , 0 , 0 } , { 116 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pulse Generator" ) , TARGET_STRING ( "Period" )
, 1 , 0 , 0 } , { 117 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pulse Generator" ) , TARGET_STRING (
"PulseWidth" ) , 1 , 0 , 0 } , { 118 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pulse Generator" ) , TARGET_STRING (
"PhaseDelay" ) , 1 , 0 , 0 } , { 119 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Clark/Gain" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 120 , TARGET_STRING ( "Square_HFI/FOC_Mode/HFI_Mode/Clark/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Clark/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 122 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 2 , 0 , 1 } , { 123 ,
TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 124 ,
TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 125 ,
TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 126 ,
TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 127 ,
TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 128 ,
TARGET_STRING ( "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Clark/Gain" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 130 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Clark/Gain1" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 131 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/HFI_Clark/Gain2" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 132 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"A_pr" ) , 1 , 1 , 0 } , { 133 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"A_ir" ) , 3 , 1 , 0 } , { 134 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"A_jc" ) , 3 , 1 , 0 } , { 135 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 136 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 137 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 138 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 139 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 140 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"C_jc" ) , 3 , 1 , 0 } , { 141 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog Filter Design" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 142 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"A_pr" ) , 1 , 4 , 0 } , { 143 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"A_ir" ) , 3 , 4 , 0 } , { 144 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"A_jc" ) , 3 , 6 , 0 } , { 145 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 146 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 147 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 148 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 149 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 150 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"C_jc" ) , 3 , 6 , 0 } , { 151 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 152 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"A_pr" ) , 1 , 4 , 0 } , { 153 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"A_ir" ) , 3 , 4 , 0 } , { 154 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"A_jc" ) , 3 , 6 , 0 } , { 155 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 156 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 157 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 158 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 159 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 160 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"C_jc" ) , 3 , 6 , 0 } , { 161 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design1" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 162 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"A_pr" ) , 1 , 4 , 0 } , { 163 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"A_ir" ) , 3 , 4 , 0 } , { 164 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"A_jc" ) , 3 , 6 , 0 } , { 165 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 166 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 167 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 168 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 169 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 170 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"C_jc" ) , 3 , 6 , 0 } , { 171 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design2" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 172 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"A_pr" ) , 1 , 7 , 0 } , { 173 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"A_ir" ) , 3 , 7 , 0 } , { 174 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"A_jc" ) , 3 , 8 , 0 } , { 175 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 176 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 177 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 178 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 179 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 180 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"C_jc" ) , 3 , 8 , 0 } , { 181 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design3" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 182 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"A_pr" ) , 1 , 7 , 0 } , { 183 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"A_ir" ) , 3 , 7 , 0 } , { 184 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"A_jc" ) , 3 , 8 , 0 } , { 185 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 186 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 187 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 188 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 189 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 190 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"C_jc" ) , 3 , 8 , 0 } , { 191 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design4" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 192 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"A_pr" ) , 1 , 7 , 0 } , { 193 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"A_ir" ) , 3 , 7 , 0 } , { 194 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"A_jc" ) , 3 , 8 , 0 } , { 195 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 196 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 197 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 198 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 199 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 200 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"C_jc" ) , 3 , 8 , 0 } , { 201 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog Filter Design5" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 202 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/PD/Constant" ) , TARGET_STRING ( "Value" ) , 1
, 0 , 0 } , { 203 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Constant2" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 204 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time Integrator" ) , TARGET_STRING
( "gainval" ) , 0 , 0 , 0 } , { 205 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time Integrator" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 206 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time Integrator1" ) ,
TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 207 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 208 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"A_pr" ) , 1 , 4 , 0 } , { 209 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"A_ir" ) , 3 , 4 , 0 } , { 210 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"A_jc" ) , 3 , 6 , 0 } , { 211 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"B_pr" ) , 1 , 0 , 0 } , { 212 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"B_ir" ) , 3 , 0 , 0 } , { 213 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"B_jc" ) , 3 , 5 , 0 } , { 214 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"C_pr" ) , 1 , 0 , 0 } , { 215 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"C_ir" ) , 3 , 0 , 0 } , { 216 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"C_jc" ) , 3 , 6 , 0 } , { 217 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog Filter Design1" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 0 } , { 218 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Constant" ) , TARGET_STRING ( "Value" ) ,
1 , 0 , 0 } , { 219 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Gain" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 220 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 221 ,
TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 222 ,
TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 223 ,
TARGET_STRING ( "Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 224 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 225 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Duty_Caculator/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 226 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/Constant" ) , TARGET_STRING
( "Value" ) , 1 , 0 , 0 } , { 227 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/Constant1" ) ,
TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 228 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 229 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 230 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/Gain2" ) , TARGET_STRING (
"Gain" ) , 1 , 0 , 0 } , { 231 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/Gain3" ) , TARGET_STRING (
"Gain" ) , 1 , 0 , 0 } , { 232 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/ A Switch" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 233 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/ B Switch" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 234 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/Sector_Select/ C Switch" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 235 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 236 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/Gain1" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 237 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/Gain2" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 238 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/Switch" ) , TARGET_STRING
( "Threshold" ) , 0 , 0 , 0 } , { 239 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/T4_T6_Caculator/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/X_Y_Z_Caculator/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 241 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/X_Y_Z_Caculator/Gain1" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 242 , TARGET_STRING (
"Square_HFI/FOC_Mode/HFI_Mode/SVPWM/X_Y_Z_Caculator/Gain2" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 243 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1"
) , TARGET_STRING ( "Ts" ) , 1 , 0 , 0 } , { 244 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1"
) , TARGET_STRING ( "U" ) , 1 , 0 , 0 } , { 245 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1"
) , TARGET_STRING ( "L" ) , 1 , 0 , 0 } , { 246 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 247 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Constant3"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 248 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Constant5"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 249 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Discrete-Time Integrator"
) , TARGET_STRING ( "gainval" ) , 1 , 0 , 0 } , { 250 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Discrete-Time Integrator"
) , TARGET_STRING ( "UpperSaturationLimit" ) , 1 , 0 , 0 } , { 251 ,
TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Discrete-Time Integrator"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 1 , 0 , 0 } , { 252 ,
TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 253 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 254 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform/Gain"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 255 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform/Gain1"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 256 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform/Gain2"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 257 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform/Gain3"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 258 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform/Gain4"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 259 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform/Gain1"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 260 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform/Gain2"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 261 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform/Gain3"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 262 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform/Gain4"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 263 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Gain2"
) , TARGET_STRING ( "Gain" ) , 1 , 0 , 0 } , { 264 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 265 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 266 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 267 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 268 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 269 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 270 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 271 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 272 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 273 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 274 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 275 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 276 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 277 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 278 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 279 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 280 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 281 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 282 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 283 , TARGET_STRING (
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 284 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 285 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 286 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 287 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Discrete-Time Integrator3"
) , TARGET_STRING ( "gainval" ) , 1 , 0 , 0 } , { 288 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Discrete-Time Integrator3"
) , TARGET_STRING ( "UpperSaturationLimit" ) , 1 , 0 , 0 } , { 289 ,
TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Discrete-Time Integrator3"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 1 , 0 , 0 } , { 290 ,
TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 291 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Discrete-Time Integrator3"
) , TARGET_STRING ( "gainval" ) , 1 , 0 , 0 } , { 292 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Discrete-Time Integrator3"
) , TARGET_STRING ( "UpperSaturationLimit" ) , 1 , 0 , 0 } , { 293 ,
TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Discrete-Time Integrator3"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 1 , 0 , 0 } , { 294 ,
TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 295 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 296 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 297 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 298 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 299 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 300 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 301 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 302 , TARGET_STRING (
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 303 , TARGET_STRING (
"_CurrKi2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 304 , TARGET_STRING (
"_CurrKpd2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 305 , TARGET_STRING (
"_CurrKpq2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 306 , TARGET_STRING (
"_PLL_Kd2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 307 , TARGET_STRING (
"_PLL_Ki2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 308 , TARGET_STRING (
"_Pn2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 309 , TARGET_STRING (
"_Rs2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 310 , TARGET_STRING (
"_flux2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 311 , TARGET_STRING (
"_spd_ki2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 312 , TARGET_STRING (
"_spd_kp2f2Square_HFI_sldd_" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } }
;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . oekg5cjnsz , & rtB . ezk2tehwll ,
& rtB . haqol3cjgg , & rtB . kif4jng5eq , & rtB . hnrjpbhtyb , & rtB .
n4szfkmgux , & rtB . fvwparn2lf , & rtB . lyy5l51j1r , & rtB . modaikvwk2 , &
rtB . owirr1gzew , & rtB . ptas5mx2xx [ 0 ] , & rtB . orihl2n4h3 , & rtB .
iyvrnoncql , & rtB . oaogaf1p5f , & rtB . cxpc4e4kit , & rtB . kybjyzwqma , &
rtB . cqzn2b2kj2 , & rtB . j0ybbliyam , & rtB . nacsw2wv2y , & rtB .
gpl4ohobjp , & rtB . b15ggaqysc , & rtB . oy5uuprwrz , & rtB . lqedrpdjvq , &
rtB . a1dv31bkl5 , & rtB . fe5da5vw1v , & rtB . hfw2v3eciw , & rtB .
czad505sp3 , & rtB . fdhox1t1ny , & rtB . lwjmxasb2z , & rtB . ajtg2x2b41 , &
rtB . ogxod1b2u3 , & rtB . logsazcj2d , & rtB . mu2g0xzmlu , & rtB .
c5jdvrisaz , & rtB . imeh0bgjnw , & rtB . hqgkqxg4zr , & rtB . bwxxvrlgaj , &
rtB . jeobpjpcy3 , & rtB . oy1uirggpc , & rtB . c1odu2gdtj , & rtB .
hqrlwn2gih , & rtB . md15iiloqt , & rtB . krxowr1za1 , & rtB . luh55v3bwu , &
rtB . e0mzutezmn , & rtB . j5g3qzjurz , & rtB . bt3fcv3v3w , & rtB .
hujs41lxa1 , & rtB . oa4nu2h02a , & rtB . izwpvpxlts , & rtB . ij0emyqotr , &
rtB . nk3bpfyhq2 , & rtB . avkcbyy3ru [ 0 ] , & rtB . jzhluxfqhc , & rtB .
jumrg4wdv0 , & rtB . kxtv0fhkws , & rtB . e0rj1hvaeo , & rtB . o1qptmrlo4 , &
rtB . esnhg1urb0 , & rtB . exsy54mv4x , & rtB . nkfg1ddf1g , & rtB .
edmswnt5ng , & rtB . dpomenlimv , & rtB . ezlw3p4p00 , & rtB . b2gfisg0eh , &
rtB . bvspyalpkj , & rtB . ll43tv0wht , & rtB . acjaxnsuyo , & rtB .
c1syzcnvq0 , & rtB . kpb21alagy , & rtB . lz5lj5ytco , & rtB . jielxbq1gv , &
rtB . irpxyowq0z , & rtB . lubu1u2ru4 , & rtB . gs5kavedxi , & rtB .
m0psoaixxy , & rtB . fd2nlplojn , & rtB . kwir5smtvi , & rtB . cm34cwonv3 , &
rtB . ikmh2tfryy , & rtB . fgw4v4wm4g , & rtB . ah0extvo4t , & rtB .
ouiqfsyu43 , & rtB . lknhr4vxtr , & rtB . cnm3x1s5lo , & rtB . ow4uvzz2pj , &
rtB . k0o4fvzzy3 , & rtB . lit4m00nbl , & rtB . mrd41buyxt , & rtB .
pntkd2uyvv , & rtB . oxcrb4vtyb , & rtB . isprk1at5s , & rtP .
InteriorPMSM_Ldq [ 0 ] , & rtP . InteriorPMSM_mechanical [ 0 ] , & rtP .
InteriorPMSM_idq0 [ 0 ] , & rtP . InteriorPMSM_theta_init , & rtP .
InteriorPMSM_omega_init , & rtP . Constant_Value_ah0pp224du , & rtP .
Constant1_Value_a1crlzduby , & rtP . Constant2_Value_e5cors3m1f , & rtP .
Constant3_Value_fveq5hyrqd , & rtP . Gain1_Gain_owsv2iwqia , & rtP .
RateTransition_InitialCondition , & rtP . RateTransition1_InitialCondition ,
& rtP . RateTransition2_InitialCondition , & rtP .
RateTransition3_InitialCondition , & rtP . RateTransition8_InitialCondition ,
& rtP . Constant_Value_pspbithpw4 , & rtP . Gain_Gain , & rtP .
Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
Switch_Threshold_buydduua1q , & rtP . FromWs_Time0 [ 0 ] , & rtP .
FromWs_Data0 [ 0 ] , & rtP . Constant1_Value_pfphbi3aj2 , & rtP .
PulseGenerator_Amp , & rtP . PulseGenerator_Period , & rtP .
PulseGenerator_Duty , & rtP . PulseGenerator_PhaseDelay , & rtP .
Gain_Gain_oneshwnrhn , & rtP . Gain1_Gain_d0pmjscvt0 , & rtP .
Gain2_Gain_c5zyi33wrb , & rtP . PIDController1_InitialConditionForIntegrator
, & rtP . PIDController1_UpperSaturationLimit , & rtP .
PIDController1_LowerSaturationLimit , & rtP .
PIDController2_InitialConditionForIntegrator , & rtP .
PIDController2_UpperSaturationLimit , & rtP .
PIDController2_LowerSaturationLimit , & rtP . Constant_Value_fad045x02c , &
rtP . Gain_Gain_nggjdhdyc1 , & rtP . Gain1_Gain_dhl1phxitf , & rtP .
Gain2_Gain_nyrqrcnyqt , & rtP . AnalogFilterDesign_A_pr_esqpqjprtf [ 0 ] , &
rtP . AnalogFilterDesign_A_ir_dogadco1zw [ 0 ] , & rtP .
AnalogFilterDesign_A_jc_odmcc04tok [ 0 ] , & rtP .
AnalogFilterDesign_B_pr_l5d4110w1d , & rtP .
AnalogFilterDesign_B_ir_c20unw4tq1 , & rtP .
AnalogFilterDesign_B_jc_jbvp1zaaeo [ 0 ] , & rtP .
AnalogFilterDesign_C_pr_d2lrbbjghc , & rtP .
AnalogFilterDesign_C_ir_kzmexqw5ri , & rtP .
AnalogFilterDesign_C_jc_e5mtimz5tp [ 0 ] , & rtP .
AnalogFilterDesign_InitialCondition_pqqwkiff0r , & rtP .
AnalogFilterDesign_A_pr [ 0 ] , & rtP . AnalogFilterDesign_A_ir [ 0 ] , & rtP
. AnalogFilterDesign_A_jc [ 0 ] , & rtP . AnalogFilterDesign_B_pr , & rtP .
AnalogFilterDesign_B_ir , & rtP . AnalogFilterDesign_B_jc [ 0 ] , & rtP .
AnalogFilterDesign_C_pr , & rtP . AnalogFilterDesign_C_ir , & rtP .
AnalogFilterDesign_C_jc [ 0 ] , & rtP . AnalogFilterDesign_InitialCondition ,
& rtP . AnalogFilterDesign1_A_pr [ 0 ] , & rtP . AnalogFilterDesign1_A_ir [ 0
] , & rtP . AnalogFilterDesign1_A_jc [ 0 ] , & rtP . AnalogFilterDesign1_B_pr
, & rtP . AnalogFilterDesign1_B_ir , & rtP . AnalogFilterDesign1_B_jc [ 0 ] ,
& rtP . AnalogFilterDesign1_C_pr , & rtP . AnalogFilterDesign1_C_ir , & rtP .
AnalogFilterDesign1_C_jc [ 0 ] , & rtP . AnalogFilterDesign1_InitialCondition
, & rtP . AnalogFilterDesign2_A_pr [ 0 ] , & rtP . AnalogFilterDesign2_A_ir [
0 ] , & rtP . AnalogFilterDesign2_A_jc [ 0 ] , & rtP .
AnalogFilterDesign2_B_pr , & rtP . AnalogFilterDesign2_B_ir , & rtP .
AnalogFilterDesign2_B_jc [ 0 ] , & rtP . AnalogFilterDesign2_C_pr , & rtP .
AnalogFilterDesign2_C_ir , & rtP . AnalogFilterDesign2_C_jc [ 0 ] , & rtP .
AnalogFilterDesign2_InitialCondition , & rtP . AnalogFilterDesign3_A_pr [ 0 ]
, & rtP . AnalogFilterDesign3_A_ir [ 0 ] , & rtP . AnalogFilterDesign3_A_jc [
0 ] , & rtP . AnalogFilterDesign3_B_pr , & rtP . AnalogFilterDesign3_B_ir , &
rtP . AnalogFilterDesign3_B_jc [ 0 ] , & rtP . AnalogFilterDesign3_C_pr , &
rtP . AnalogFilterDesign3_C_ir , & rtP . AnalogFilterDesign3_C_jc [ 0 ] , &
rtP . AnalogFilterDesign3_InitialCondition , & rtP . AnalogFilterDesign4_A_pr
[ 0 ] , & rtP . AnalogFilterDesign4_A_ir [ 0 ] , & rtP .
AnalogFilterDesign4_A_jc [ 0 ] , & rtP . AnalogFilterDesign4_B_pr , & rtP .
AnalogFilterDesign4_B_ir , & rtP . AnalogFilterDesign4_B_jc [ 0 ] , & rtP .
AnalogFilterDesign4_C_pr , & rtP . AnalogFilterDesign4_C_ir , & rtP .
AnalogFilterDesign4_C_jc [ 0 ] , & rtP . AnalogFilterDesign4_InitialCondition
, & rtP . AnalogFilterDesign5_A_pr [ 0 ] , & rtP . AnalogFilterDesign5_A_ir [
0 ] , & rtP . AnalogFilterDesign5_A_jc [ 0 ] , & rtP .
AnalogFilterDesign5_B_pr , & rtP . AnalogFilterDesign5_B_ir , & rtP .
AnalogFilterDesign5_B_jc [ 0 ] , & rtP . AnalogFilterDesign5_C_pr , & rtP .
AnalogFilterDesign5_C_ir , & rtP . AnalogFilterDesign5_C_jc [ 0 ] , & rtP .
AnalogFilterDesign5_InitialCondition , & rtP . Constant_Value , & rtP .
Constant2_Value_n4cnemylwa , & rtP .
DiscreteTimeIntegrator_gainval_k25juj44ov , & rtP . DiscreteTimeIntegrator_IC
, & rtP . DiscreteTimeIntegrator1_gainval , & rtP .
DiscreteTimeIntegrator1_IC , & rtP . AnalogFilterDesign1_A_pr_h0kmy5bicq [ 0
] , & rtP . AnalogFilterDesign1_A_ir_hrenrgccbq [ 0 ] , & rtP .
AnalogFilterDesign1_A_jc_lbh1btnh5f [ 0 ] , & rtP .
AnalogFilterDesign1_B_pr_ew5a2lr4t2 , & rtP .
AnalogFilterDesign1_B_ir_fpqzlg1kvc , & rtP .
AnalogFilterDesign1_B_jc_ghy2lei3av [ 0 ] , & rtP .
AnalogFilterDesign1_C_pr_ch4mm2g3zc , & rtP .
AnalogFilterDesign1_C_ir_ft0xxxbkg4 , & rtP .
AnalogFilterDesign1_C_jc_bi43o0wxhg [ 0 ] , & rtP .
AnalogFilterDesign1_InitialCondition_k3v143gesi , & rtP .
Constant_Value_e4jyxae25b , & rtP . Gain_Gain_dd1zo3e4je , & rtP .
PIDController3_InitialConditionForIntegrator , & rtP .
PIDController3_UpperSaturationLimit , & rtP .
PIDController3_LowerSaturationLimit , & rtP . Gain_Gain_hfbnedsnqk , & rtP .
Gain1_Gain_d2r1btvvwg , & rtP . Gain2_Gain_mqqw0m41vg , & rtP .
Constant_Value_prx0zmzuez , & rtP . Constant1_Value , & rtP .
Gain_Gain_gt5xi45qct , & rtP . Gain1_Gain_cpamektdhq , & rtP . Gain2_Gain , &
rtP . Gain3_Gain , & rtP . ASwitch_Threshold , & rtP . BSwitch_Threshold , &
rtP . CSwitch_Threshold , & rtP . Gain_Gain_lsczmwd1h2 , & rtP .
Gain1_Gain_j1zbr4lzxq , & rtP . Gain2_Gain_crytncxhkk , & rtP .
Switch_Threshold , & rtP . Switch1_Threshold , & rtP . Gain_Gain_bpfw2sk42p ,
& rtP . Gain1_Gain_o051fegvds , & rtP . Gain2_Gain_fpelshvuq5 , & rtP .
Int1_Ts , & rtP . Int1_U , & rtP . Int1_L , & rtP .
Constant1_Value_cec3dpoe5t , & rtP . Constant3_Value , & rtP .
Constant5_Value , & rtP . DiscreteTimeIntegrator_gainval , & rtP .
DiscreteTimeIntegrator_UpperSat , & rtP . DiscreteTimeIntegrator_LowerSat , &
rtP . Constant1_Value_l2ipogf1kx , & rtP . Constant3_Value_lzmoq4j5e0 , & rtP
. Gain_Gain_n3c5iuh2qk , & rtP . Gain1_Gain_cuaiqtkau5 , & rtP .
Gain2_Gain_m2442d4sfc , & rtP . Gain3_Gain_baedkupsze , & rtP .
Gain4_Gain_dum3dkp5wn , & rtP . Gain1_Gain , & rtP . Gain2_Gain_bufpac5tbs ,
& rtP . Gain3_Gain_e1nr0mavjq , & rtP . Gain4_Gain , & rtP .
Gain2_Gain_lgyufe3n3y , & rtP . Clamping_zero_Value_gmmqgeo1e4 , & rtP .
Constant_Value_jxwhvocfhb , & rtP . Constant1_Value_odajvcsv3r , & rtP .
Constant2_Value_i2m45uwk2o , & rtP . Constant3_Value_bymcbl0414 , & rtP .
Constant4_Value , & rtP . Clamping_zero_Value , & rtP .
Constant_Value_jhbksipzdc , & rtP . Constant1_Value_fpaq0utenz , & rtP .
Constant2_Value_j12qjlnlzg , & rtP . Constant3_Value_gvheyotvnt , & rtP .
Constant4_Value_hfhut001zy , & rtP . Integrator_gainval_gqdjj5igji , & rtP .
Clamping_zero_Value_n2or5cqygv , & rtP . Constant_Value_oqmhouwrxr , & rtP .
Constant1_Value_pe5vj0iriy , & rtP . Constant2_Value_gdlubdifra , & rtP .
Constant3_Value_nanqjpbqvw , & rtP . Constant4_Value_ge5isbbxow , & rtP .
Integrator_gainval , & rtP . Constant1_Value_fuoewzrkks , & rtP .
Constant2_Value , & rtP . Constant1_Value_p1324vfsr3 , & rtP .
DiscreteTimeIntegrator3_gainval , & rtP . DiscreteTimeIntegrator3_UpperSat ,
& rtP . DiscreteTimeIntegrator3_LowerSat , & rtP . Constant1_Value_i5c5nfcqn0
, & rtP . DiscreteTimeIntegrator3_gainval_o2siosbbdr , & rtP .
DiscreteTimeIntegrator3_UpperSat_njveboaopq , & rtP .
DiscreteTimeIntegrator3_LowerSat_acpnkz2txi , & rtP .
Constant1_Value_db5wbste14 , & rtP . Constant1_Value_arpzt5qlzk , & rtP .
Constant2_Value_iedxtooqmk , & rtP . Constant2_Value_ombtisyb12 , & rtP .
Constant1_Value_ghv5aa4po2 , & rtP . Constant1_Value_dlowd15ti4 , & rtP .
Constant2_Value_cfaqape04n , & rtP . Constant2_Value_puzy4v1jc3 , & rtP .
Constant2_Value_bmnavpjpcf , & rtP . _CurrKi2f2Square_HFI_sldd_ , & rtP .
_CurrKpd2f2Square_HFI_sldd_ , & rtP . _CurrKpq2f2Square_HFI_sldd_ , & rtP .
_PLL_Kd2f2Square_HFI_sldd_ , & rtP . _PLL_Ki2f2Square_HFI_sldd_ , & rtP .
_Pn2f2Square_HFI_sldd_ , & rtP . _Rs2f2Square_HFI_sldd_ , & rtP .
_flux2f2Square_HFI_sldd_ , & rtP . _spd_ki2f2Square_HFI_sldd_ , & rtP .
_spd_kp2f2Square_HFI_sldd_ , } ; static int32_T * rtVarDimsAddrMap [ ] = { (
NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "float" ,
"real32_T" , 0 , 0 , sizeof ( real32_T ) , ( uint8_T ) SS_SINGLE , 0 , 0 , 0
} , { "double" , "real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE
, 0 , 0 , 0 } , { "short" , "int16_T" , 0 , 0 , sizeof ( int16_T ) , (
uint8_T ) SS_INT16 , 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 ,
sizeof ( uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0 } , { "signed char" ,
"int8_T" , 0 , 0 , sizeof ( int8_T ) , ( uint8_T ) SS_INT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 3 , 1 , 1 , 2 , 1 , 3 , 5 , 1 , 2 , 1 , 4 , 1 , 11 , 1 , 7 , 1 } ;
static const real_T rtcapiStoredFloats [ ] = { 0.0001 , 0.0 , 1.0E-9 ,
1.073741824 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) ,
( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , { ( const void
* ) & rtcapiStoredFloats [ 3 ] , ( const void * ) & rtcapiStoredFloats [ 1 ]
, rtwCAPI_FIX_UNIFORM_SCALING , 16 , - 30 , ( boolean_T ) 1 } } ; static
const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0
} , { ( NULL ) , ( NULL ) , 3 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , (
uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 92 , rtRootInputs , 0 , rtRootOutputs , 0 } , {
rtBlockParameters , 211 , rtModelParameters , 10 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 141128117U , 3368571104U , 3117770537U ,
2825097179U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * Square_HFI_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Square_HFI_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Square_HFI_host_InitializeDataMapInfo ( Square_HFI_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
