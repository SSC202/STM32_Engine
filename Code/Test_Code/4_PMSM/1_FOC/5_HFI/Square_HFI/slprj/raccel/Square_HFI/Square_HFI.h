#ifndef RTW_HEADER_Square_HFI_h_
#define RTW_HEADER_Square_HFI_h_
#ifndef Square_HFI_COMMON_INCLUDES_
#define Square_HFI_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Square_HFI_types.h"
#include "mwmathutil.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Square_HFI
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (92) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (32)   
#elif NCSTATES != 32
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T avkcbyy3ru [ 3 ] ; real_T ptas5mx2xx [ 3 ] ; real_T
iyvrnoncql ; real_T lz5lj5ytco ; real_T jielxbq1gv ; real_T fgw4v4wm4g ;
real_T ouiqfsyu43 ; real_T acjaxnsuyo ; real_T c1syzcnvq0 ; real_T kpb21alagy
; real_T ikmh2tfryy ; real_T ah0extvo4t ; real_T hqrlwn2gih ; real_T
jeobpjpcy3 ; real_T oy1uirggpc ; real_T lwjmxasb2z ; real_T ajtg2x2b41 ;
real_T logsazcj2d ; real_T hqgkqxg4zr ; real_T j5g3qzjurz ; real_T exsy54mv4x
; real32_T hnrjpbhtyb ; real32_T kif4jng5eq ; real32_T n4szfkmgux ; real32_T
fvwparn2lf ; real32_T lyy5l51j1r ; real32_T owirr1gzew ; real32_T modaikvwk2
; real32_T oekg5cjnsz ; real32_T ezk2tehwll ; real32_T haqol3cjgg ; real32_T
orihl2n4h3 ; real32_T cm34cwonv3 ; real32_T lknhr4vxtr ; real32_T cnm3x1s5lo
; real32_T ow4uvzz2pj ; real32_T k0o4fvzzy3 ; real32_T lit4m00nbl ; real32_T
mrd41buyxt ; real32_T pntkd2uyvv ; real32_T oxcrb4vtyb ; real32_T isprk1at5s
; real32_T c5jdvrisaz ; real32_T mu2g0xzmlu ; real32_T imeh0bgjnw ; real32_T
e0mzutezmn ; real32_T luh55v3bwu ; real32_T md15iiloqt ; real32_T krxowr1za1
; real32_T bwxxvrlgaj ; real32_T c1odu2gdtj ; real32_T ogxod1b2u3 ; real32_T
lqedrpdjvq ; real32_T hujs41lxa1 ; real32_T ij0emyqotr ; real32_T czad505sp3
; real32_T oy5uuprwrz ; real32_T hfw2v3eciw ; real32_T a1dv31bkl5 ; real32_T
fe5da5vw1v ; real32_T izwpvpxlts ; real32_T gpl4ohobjp ; real32_T b15ggaqysc
; real32_T fdhox1t1ny ; real32_T cxpc4e4kit ; real32_T oaogaf1p5f ; real32_T
j0ybbliyam ; real32_T lubu1u2ru4 ; real32_T kwir5smtvi ; real32_T nacsw2wv2y
; real32_T m0psoaixxy ; real32_T kybjyzwqma ; real32_T cqzn2b2kj2 ; real32_T
gs5kavedxi ; real32_T bt3fcv3v3w ; real32_T nk3bpfyhq2 ; real32_T oa4nu2h02a
; real32_T ll43tv0wht ; real32_T bvspyalpkj ; real32_T b2gfisg0eh ; real32_T
nkfg1ddf1g ; real32_T edmswnt5ng ; real32_T dpomenlimv ; real32_T ezlw3p4p00
; real32_T jzhluxfqhc ; real32_T e0rj1hvaeo ; real32_T jumrg4wdv0 ; real32_T
esnhg1urb0 ; real32_T kxtv0fhkws ; real32_T o1qptmrlo4 ; real32_T fd2nlplojn
; int16_T irpxyowq0z ; } B ; typedef struct { real_T ixn3ky1f2r ; real_T
hxrufsyg2z ; real_T bkcf3qca2q ; real_T ejqmpqbi05 ; struct { void *
LoggedData ; } ofbl3m3sl1 ; struct { void * LoggedData ; } ayei34apxt ;
struct { void * LoggedData ; } i21c1ummfn ; struct { void * TimePtr ; void *
DataPtr ; void * RSimInfoPtr ; } cwf0tqdxqc ; struct { void * LoggedData [ 2
] ; } nqgxcegx0u ; struct { void * LoggedData [ 2 ] ; } kvvzwyojpd ; struct {
void * LoggedData ; } mzzxvadqv1 ; struct { void * LoggedData ; } fcr4huss3o
; struct { void * LoggedData ; } jve5mdx5l2 ; struct { void * LoggedData [ 2
] ; } kd1p13on4q ; struct { void * LoggedData [ 2 ] ; } ig0wdpd3dd ; struct {
void * LoggedData ; } p1lafot4yj ; struct { void * LoggedData ; } lm2e0pu11e
; struct { void * LoggedData [ 2 ] ; } jcyl3yobx2 ; struct { void *
LoggedData ; } ba0latgw4c ; struct { void * LoggedData [ 3 ] ; } mmsqjiwtxv ;
struct { void * LoggedData [ 3 ] ; } ay1mkrwhhv ; struct { void * LoggedData
[ 2 ] ; } covfqhxwb4 ; struct { void * LoggedData ; } clho1gkq3g ; struct {
void * LoggedData ; } g2jykluzrf ; struct { void * LoggedData [ 2 ] ; }
onf2p44sos ; struct { void * LoggedData [ 2 ] ; } kdzdbp0elu ; struct { void
* LoggedData [ 2 ] ; } mf4mhacv0f ; struct { void * LoggedData [ 2 ] ; }
d12nd4hp5c ; struct { void * LoggedData [ 2 ] ; } buxg0rd2km ; struct { void
* LoggedData ; } gqxpdwvbmb ; struct { void * LoggedData [ 3 ] ; } b1yqmmv0dx
; struct { void * LoggedData [ 3 ] ; } bxzdhrbzyg ; struct { void *
LoggedData ; } oigfg0yqvv ; struct { void * LoggedData [ 2 ] ; } ezjujxm5pa ;
struct { void * LoggedData [ 2 ] ; } ltbinp4yyk ; struct { void * LoggedData
[ 3 ] ; } ifgghblkfu ; real32_T gkxlktnf2e ; real32_T bk0pvczvd4 ; real32_T
cfnq23qry5 ; real32_T fsiptkwftx ; real32_T cfwppspejc ; real32_T nxdrt45sme
; real32_T abzut1gmtw ; real32_T moosp1s1ah ; real32_T devpcih51d ; int32_T
afdxa4jpho ; struct { int_T PrevIndex ; } fjmelxecm4 ; int16_T prwdcgjlej ;
uint8_T eohtar5htx ; uint8_T estxwgqypi ; } DW ; typedef struct { real_T
lags33bb22 [ 3 ] ; real_T f13vaq3gr5 [ 3 ] ; real_T pgteej05bs [ 3 ] ; real_T
ejepwxaus4 [ 6 ] ; real_T hgersqr5ev [ 6 ] ; real_T ic5giadsig [ 6 ] ; real_T
ienzc5s5vc [ 3 ] ; real_T j1rganlm1m [ 2 ] ; } X ; typedef struct { real_T
lags33bb22 [ 3 ] ; real_T f13vaq3gr5 [ 3 ] ; real_T pgteej05bs [ 3 ] ; real_T
ejepwxaus4 [ 6 ] ; real_T hgersqr5ev [ 6 ] ; real_T ic5giadsig [ 6 ] ; real_T
ienzc5s5vc [ 3 ] ; real_T j1rganlm1m [ 2 ] ; } XDot ; typedef struct {
boolean_T lags33bb22 [ 3 ] ; boolean_T f13vaq3gr5 [ 3 ] ; boolean_T
pgteej05bs [ 3 ] ; boolean_T ejepwxaus4 [ 6 ] ; boolean_T hgersqr5ev [ 6 ] ;
boolean_T ic5giadsig [ 6 ] ; boolean_T ienzc5s5vc [ 3 ] ; boolean_T
j1rganlm1m [ 2 ] ; } XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real32_T _CurrKi2f2Square_HFI_sldd_ ; real32_T
_CurrKpd2f2Square_HFI_sldd_ ; real32_T _CurrKpq2f2Square_HFI_sldd_ ; real32_T
_PLL_Kd2f2Square_HFI_sldd_ ; real32_T _PLL_Ki2f2Square_HFI_sldd_ ; real32_T
_Pn2f2Square_HFI_sldd_ ; real32_T _Rs2f2Square_HFI_sldd_ ; real32_T
_flux2f2Square_HFI_sldd_ ; real32_T _spd_ki2f2Square_HFI_sldd_ ; real32_T
_spd_kp2f2Square_HFI_sldd_ ; real_T Int1_L ; real_T Int1_Ts ; real_T Int1_U ;
real_T InteriorPMSM_idq0 [ 2 ] ; real_T InteriorPMSM_mechanical [ 3 ] ;
real_T InteriorPMSM_omega_init ; real_T InteriorPMSM_theta_init ; real32_T
PIDController3_InitialConditionForIntegrator ; real32_T
PIDController2_InitialConditionForIntegrator ; real32_T InteriorPMSM_Ldq [ 2
] ; real32_T PIDController1_LowerSaturationLimit ; real32_T
PIDController3_LowerSaturationLimit ; real32_T
PIDController2_LowerSaturationLimit ; real32_T
PIDController1_UpperSaturationLimit ; real32_T
PIDController3_UpperSaturationLimit ; real32_T
PIDController2_UpperSaturationLimit ; int16_T
PIDController1_InitialConditionForIntegrator ; real_T AnalogFilterDesign_A_pr
[ 5 ] ; real_T AnalogFilterDesign_B_pr ; real_T AnalogFilterDesign_C_pr ;
real_T AnalogFilterDesign_InitialCondition ; real_T AnalogFilterDesign1_A_pr
[ 5 ] ; real_T AnalogFilterDesign1_B_pr ; real_T AnalogFilterDesign1_C_pr ;
real_T AnalogFilterDesign1_InitialCondition ; real_T AnalogFilterDesign2_A_pr
[ 5 ] ; real_T AnalogFilterDesign2_B_pr ; real_T AnalogFilterDesign2_C_pr ;
real_T AnalogFilterDesign2_InitialCondition ; real_T AnalogFilterDesign3_A_pr
[ 11 ] ; real_T AnalogFilterDesign3_B_pr ; real_T AnalogFilterDesign3_C_pr ;
real_T AnalogFilterDesign3_InitialCondition ; real_T AnalogFilterDesign4_A_pr
[ 11 ] ; real_T AnalogFilterDesign4_B_pr ; real_T AnalogFilterDesign4_C_pr ;
real_T AnalogFilterDesign4_InitialCondition ; real_T AnalogFilterDesign5_A_pr
[ 11 ] ; real_T AnalogFilterDesign5_B_pr ; real_T AnalogFilterDesign5_C_pr ;
real_T AnalogFilterDesign5_InitialCondition ; real_T
AnalogFilterDesign1_A_pr_h0kmy5bicq [ 5 ] ; real_T
AnalogFilterDesign1_B_pr_ew5a2lr4t2 ; real_T
AnalogFilterDesign1_C_pr_ch4mm2g3zc ; real_T
AnalogFilterDesign1_InitialCondition_k3v143gesi ; real_T PulseGenerator_Amp ;
real_T PulseGenerator_Period ; real_T PulseGenerator_Duty ; real_T
PulseGenerator_PhaseDelay ; real_T AnalogFilterDesign_A_pr_esqpqjprtf [ 3 ] ;
real_T AnalogFilterDesign_B_pr_l5d4110w1d ; real_T
AnalogFilterDesign_C_pr_d2lrbbjghc ; real_T
AnalogFilterDesign_InitialCondition_pqqwkiff0r ; real_T Gain2_Gain ; real_T
Gain3_Gain ; real_T Constant_Value ; real_T Constant_Value_e4jyxae25b ;
real_T Constant_Value_prx0zmzuez ; real_T Constant1_Value ; real_T
DiscreteTimeIntegrator3_gainval ; real_T DiscreteTimeIntegrator3_UpperSat ;
real_T DiscreteTimeIntegrator3_LowerSat ; real_T
DiscreteTimeIntegrator3_gainval_o2siosbbdr ; real_T
DiscreteTimeIntegrator3_UpperSat_njveboaopq ; real_T
DiscreteTimeIntegrator3_LowerSat_acpnkz2txi ; real_T Gain2_Gain_bufpac5tbs ;
real_T Gain3_Gain_e1nr0mavjq ; real_T Gain1_Gain ; real_T Gain4_Gain ; real_T
DiscreteTimeIntegrator_gainval ; real_T DiscreteTimeIntegrator_UpperSat ;
real_T DiscreteTimeIntegrator_LowerSat ; real_T Gain1_Gain_owsv2iwqia ;
real_T Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T Gain_Gain
; real_T FromWs_Time0 [ 5 ] ; real_T FromWs_Data0 [ 5 ] ; real_T
Gain2_Gain_lgyufe3n3y ; real_T Gain_Gain_n3c5iuh2qk ; real_T
Gain1_Gain_cuaiqtkau5 ; real_T Gain4_Gain_dum3dkp5wn ; real_T
Gain2_Gain_m2442d4sfc ; real_T Gain3_Gain_baedkupsze ; real_T
Constant1_Value_cec3dpoe5t ; real_T Constant3_Value ; real_T Constant5_Value
; real_T Constant1_Value_fuoewzrkks ; real_T Constant2_Value ; real_T
Constant1_Value_p1324vfsr3 ; real_T Constant1_Value_db5wbste14 ; real_T
Constant1_Value_arpzt5qlzk ; real_T Constant2_Value_iedxtooqmk ; real_T
Constant2_Value_ombtisyb12 ; real_T Constant1_Value_i5c5nfcqn0 ; real_T
Constant1_Value_ghv5aa4po2 ; real_T Constant1_Value_dlowd15ti4 ; real_T
Constant2_Value_cfaqape04n ; real_T Constant2_Value_puzy4v1jc3 ; real_T
Constant2_Value_bmnavpjpcf ; real32_T Constant1_Value_fpaq0utenz ; real32_T
Constant1_Value_pe5vj0iriy ; real32_T Gain_Gain_oneshwnrhn ; real32_T
Gain1_Gain_d0pmjscvt0 ; real32_T Gain2_Gain_c5zyi33wrb ; real32_T
Gain_Gain_nggjdhdyc1 ; real32_T Gain1_Gain_dhl1phxitf ; real32_T
DiscreteTimeIntegrator1_gainval ; real32_T DiscreteTimeIntegrator1_IC ;
real32_T Gain2_Gain_nyrqrcnyqt ; real32_T Integrator_gainval ; real32_T
Integrator_gainval_gqdjj5igji ; real32_T
DiscreteTimeIntegrator_gainval_k25juj44ov ; real32_T
DiscreteTimeIntegrator_IC ; real32_T ASwitch_Threshold ; real32_T
Gain_Gain_gt5xi45qct ; real32_T Gain1_Gain_cpamektdhq ; real32_T
BSwitch_Threshold ; real32_T CSwitch_Threshold ; real32_T
Gain1_Gain_d2r1btvvwg ; real32_T Gain1_Gain_o051fegvds ; real32_T
Gain2_Gain_fpelshvuq5 ; real32_T Gain_Gain_bpfw2sk42p ; real32_T
Gain2_Gain_crytncxhkk ; real32_T Gain_Gain_lsczmwd1h2 ; real32_T
Gain1_Gain_j1zbr4lzxq ; real32_T Switch_Threshold ; real32_T
Gain_Gain_hfbnedsnqk ; real32_T Switch1_Threshold ; real32_T
Gain2_Gain_mqqw0m41vg ; real32_T Gain_Gain_dd1zo3e4je ; real32_T
Constant1_Value_pfphbi3aj2 ; real32_T Constant_Value_fad045x02c ; real32_T
Clamping_zero_Value ; real32_T Constant2_Value_n4cnemylwa ; real32_T
Clamping_zero_Value_n2or5cqygv ; real32_T Constant3_Value_lzmoq4j5e0 ;
real32_T Constant1_Value_l2ipogf1kx ; real32_T
RateTransition_InitialCondition ; real32_T RateTransition1_InitialCondition ;
real32_T RateTransition2_InitialCondition ; real32_T
RateTransition8_InitialCondition ; real32_T RateTransition3_InitialCondition
; real32_T Constant_Value_pspbithpw4 ; real32_T Constant_Value_ah0pp224du ;
real32_T Switch_Threshold_buydduua1q ; real32_T Constant1_Value_a1crlzduby ;
real32_T Constant2_Value_e5cors3m1f ; real32_T Constant3_Value_fveq5hyrqd ;
uint32_T AnalogFilterDesign_A_ir [ 5 ] ; uint32_T AnalogFilterDesign_A_jc [ 4
] ; uint32_T AnalogFilterDesign_B_ir ; uint32_T AnalogFilterDesign_B_jc [ 2 ]
; uint32_T AnalogFilterDesign_C_ir ; uint32_T AnalogFilterDesign_C_jc [ 4 ] ;
uint32_T AnalogFilterDesign1_A_ir [ 5 ] ; uint32_T AnalogFilterDesign1_A_jc [
4 ] ; uint32_T AnalogFilterDesign1_B_ir ; uint32_T AnalogFilterDesign1_B_jc [
2 ] ; uint32_T AnalogFilterDesign1_C_ir ; uint32_T AnalogFilterDesign1_C_jc [
4 ] ; uint32_T AnalogFilterDesign2_A_ir [ 5 ] ; uint32_T
AnalogFilterDesign2_A_jc [ 4 ] ; uint32_T AnalogFilterDesign2_B_ir ; uint32_T
AnalogFilterDesign2_B_jc [ 2 ] ; uint32_T AnalogFilterDesign2_C_ir ; uint32_T
AnalogFilterDesign2_C_jc [ 4 ] ; uint32_T AnalogFilterDesign3_A_ir [ 11 ] ;
uint32_T AnalogFilterDesign3_A_jc [ 7 ] ; uint32_T AnalogFilterDesign3_B_ir ;
uint32_T AnalogFilterDesign3_B_jc [ 2 ] ; uint32_T AnalogFilterDesign3_C_ir ;
uint32_T AnalogFilterDesign3_C_jc [ 7 ] ; uint32_T AnalogFilterDesign4_A_ir [
11 ] ; uint32_T AnalogFilterDesign4_A_jc [ 7 ] ; uint32_T
AnalogFilterDesign4_B_ir ; uint32_T AnalogFilterDesign4_B_jc [ 2 ] ; uint32_T
AnalogFilterDesign4_C_ir ; uint32_T AnalogFilterDesign4_C_jc [ 7 ] ; uint32_T
AnalogFilterDesign5_A_ir [ 11 ] ; uint32_T AnalogFilterDesign5_A_jc [ 7 ] ;
uint32_T AnalogFilterDesign5_B_ir ; uint32_T AnalogFilterDesign5_B_jc [ 2 ] ;
uint32_T AnalogFilterDesign5_C_ir ; uint32_T AnalogFilterDesign5_C_jc [ 7 ] ;
uint32_T AnalogFilterDesign1_A_ir_hrenrgccbq [ 5 ] ; uint32_T
AnalogFilterDesign1_A_jc_lbh1btnh5f [ 4 ] ; uint32_T
AnalogFilterDesign1_B_ir_fpqzlg1kvc ; uint32_T
AnalogFilterDesign1_B_jc_ghy2lei3av [ 2 ] ; uint32_T
AnalogFilterDesign1_C_ir_ft0xxxbkg4 ; uint32_T
AnalogFilterDesign1_C_jc_bi43o0wxhg [ 4 ] ; uint32_T
AnalogFilterDesign_A_ir_dogadco1zw [ 3 ] ; uint32_T
AnalogFilterDesign_A_jc_odmcc04tok [ 3 ] ; uint32_T
AnalogFilterDesign_B_ir_c20unw4tq1 ; uint32_T
AnalogFilterDesign_B_jc_jbvp1zaaeo [ 2 ] ; uint32_T
AnalogFilterDesign_C_ir_kzmexqw5ri ; uint32_T
AnalogFilterDesign_C_jc_e5mtimz5tp [ 3 ] ; int16_T Constant1_Value_odajvcsv3r
; int16_T Clamping_zero_Value_gmmqgeo1e4 ; int8_T Constant_Value_jxwhvocfhb ;
int8_T Constant2_Value_i2m45uwk2o ; int8_T Constant3_Value_bymcbl0414 ;
int8_T Constant4_Value ; int8_T Constant_Value_jhbksipzdc ; int8_T
Constant2_Value_j12qjlnlzg ; int8_T Constant3_Value_gvheyotvnt ; int8_T
Constant4_Value_hfhut001zy ; int8_T Constant_Value_oqmhouwrxr ; int8_T
Constant2_Value_gdlubdifra ; int8_T Constant3_Value_nanqjpbqvw ; int8_T
Constant4_Value_ge5isbbxow ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_Square_HFI_GetDWork ( ) ; extern void
mr_Square_HFI_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_Square_HFI_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Square_HFI_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
