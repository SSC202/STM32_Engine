#include "Square_HFI.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "Square_HFI_private.h"
#include "rt_logging_mmi.h"
#include "Square_HFI_capi.h"
#include "Square_HFI_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.8 (R2022b) 13-May-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { int_T is ; boolean_T tmp ; rtDW .
eohtar5htx = 1U ; if ( ssIsFirstInitCond ( rtS ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . eohtar5htx = ( uint8_T ) !
tmp ; } else { rtDW . eohtar5htx = 1U ; } } rtDW . hxrufsyg2z = rtP .
InteriorPMSM_theta_init ; rtDW . estxwgqypi = 1U ; if ( ssIsFirstInitCond (
rtS ) ) { tmp = slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . estxwgqypi = ( uint8_T ) !
tmp ; } else { rtDW . estxwgqypi = 1U ; } } rtDW . ejqmpqbi05 = rtP .
InteriorPMSM_omega_init ; rtDW . cfwppspejc = rtP .
RateTransition_InitialCondition ; rtDW . nxdrt45sme = rtP .
RateTransition1_InitialCondition ; rtDW . abzut1gmtw = rtP .
RateTransition2_InitialCondition ; rtDW . moosp1s1ah = rtP .
RateTransition8_InitialCondition ; rtDW . devpcih51d = rtP .
RateTransition3_InitialCondition ; rtX . lags33bb22 [ 0 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . f13vaq3gr5 [ 0 ] = rtP .
AnalogFilterDesign1_InitialCondition ; rtX . pgteej05bs [ 0 ] = rtP .
AnalogFilterDesign2_InitialCondition ; rtX . lags33bb22 [ 1 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . f13vaq3gr5 [ 1 ] = rtP .
AnalogFilterDesign1_InitialCondition ; rtX . pgteej05bs [ 1 ] = rtP .
AnalogFilterDesign2_InitialCondition ; rtX . lags33bb22 [ 2 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . f13vaq3gr5 [ 2 ] = rtP .
AnalogFilterDesign1_InitialCondition ; rtX . pgteej05bs [ 2 ] = rtP .
AnalogFilterDesign2_InitialCondition ; for ( is = 0 ; is < 6 ; is ++ ) { rtX
. ejepwxaus4 [ is ] = rtP . AnalogFilterDesign3_InitialCondition ; rtX .
hgersqr5ev [ is ] = rtP . AnalogFilterDesign4_InitialCondition ; rtX .
ic5giadsig [ is ] = rtP . AnalogFilterDesign5_InitialCondition ; } rtDW .
gkxlktnf2e = rtP . DiscreteTimeIntegrator1_IC ; rtX . ienzc5s5vc [ 0 ] = rtP
. AnalogFilterDesign1_InitialCondition_k3v143gesi ; rtX . ienzc5s5vc [ 1 ] =
rtP . AnalogFilterDesign1_InitialCondition_k3v143gesi ; rtX . ienzc5s5vc [ 2
] = rtP . AnalogFilterDesign1_InitialCondition_k3v143gesi ; rtX . j1rganlm1m
[ 0 ] = rtP . AnalogFilterDesign_InitialCondition_pqqwkiff0r ; rtX .
j1rganlm1m [ 1 ] = rtP . AnalogFilterDesign_InitialCondition_pqqwkiff0r ;
rtDW . prwdcgjlej = rtP . PIDController1_InitialConditionForIntegrator ; rtDW
. bk0pvczvd4 = rtP . PIDController3_InitialConditionForIntegrator ; rtDW .
cfnq23qry5 = rtP . PIDController2_InitialConditionForIntegrator ; rtDW .
fsiptkwftx = rtP . DiscreteTimeIntegrator_IC ; } void MdlStart ( void ) { {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtDW . afdxa4jpho = 0 ; rtB . n4szfkmgux = rtP .
RateTransition_InitialCondition ; rtB . fvwparn2lf = rtP .
RateTransition1_InitialCondition ; rtB . lyy5l51j1r = rtP .
RateTransition2_InitialCondition ; rtB . owirr1gzew = rtP .
RateTransition8_InitialCondition ; rtB . modaikvwk2 = rtP .
RateTransition3_InitialCondition ; { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 5 ; fromwksInfo -> time
= ( double * ) rtP . FromWs_Time0 ; rtDW . cwf0tqdxqc . TimePtr = fromwksInfo
-> time ; rtDW . cwf0tqdxqc . DataPtr = fromwksInfo -> data ; rtDW .
cwf0tqdxqc . RSimInfoPtr = fromwksInfo ; } rtDW . fjmelxecm4 . PrevIndex = 0
; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T c4vaviz4dp ;
real_T clwa0ehpcd ; real_T esbfypgcb1 ; real_T ewibbafrki ; real_T g551rf0zlu
; real_T goacxbnaqe_idx_0 ; real_T goacxbnaqe_idx_1 ; real_T goacxbnaqe_idx_2
; real_T ixpmah5gbt ; real_T kqjvqq54rw ; real_T llpdcgqzdy ; real_T
o0hgmfnzg2 ; real_T pgpzevb5rr ; int32_T ci ; real32_T bo5x2udat5 ; real32_T
frfcrvlu3k ; real32_T g4s2wbjq2i ; real32_T gp31ms5ogx ; real32_T hn4nda5y0a
; real32_T im1ypk45bp ; real32_T l5vmkrcylz ; real32_T lfad5o30c5 ; real32_T
nnotgsinza ; uint32_T ri ; int16_T fxtirdbxfd ; int8_T tmp ; int8_T tmp_p ;
if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( rtDW . eohtar5htx != 0 ) { rtDW .
ixn3ky1f2r = rtB . ikmh2tfryy ; if ( rtDW . ixn3ky1f2r >= rtP .
DiscreteTimeIntegrator3_UpperSat ) { rtDW . ixn3ky1f2r = rtP .
DiscreteTimeIntegrator3_UpperSat ; } else if ( rtDW . ixn3ky1f2r <= rtP .
DiscreteTimeIntegrator3_LowerSat ) { rtDW . ixn3ky1f2r = rtP .
DiscreteTimeIntegrator3_LowerSat ; } } if ( rtDW . ixn3ky1f2r >= rtP .
DiscreteTimeIntegrator3_UpperSat ) { rtDW . ixn3ky1f2r = rtP .
DiscreteTimeIntegrator3_UpperSat ; } else if ( rtDW . ixn3ky1f2r <= rtP .
DiscreteTimeIntegrator3_LowerSat ) { rtDW . ixn3ky1f2r = rtP .
DiscreteTimeIntegrator3_LowerSat ; } ewibbafrki = rtDW . ixn3ky1f2r ; if (
rtDW . hxrufsyg2z >= rtP . Int1_L ) { if ( rtDW . hxrufsyg2z <= rtP . Int1_U
) { clwa0ehpcd = rtDW . hxrufsyg2z ; } else { clwa0ehpcd = rtDW . hxrufsyg2z
- rtP . Constant3_Value_lzmoq4j5e0 ; } } else { clwa0ehpcd = rtDW .
hxrufsyg2z + rtP . Constant1_Value_l2ipogf1kx ; } muDoubleScalarSinCos ( rtP
. _Pn2f2Square_HFI_sldd_ * clwa0ehpcd , & esbfypgcb1 , & llpdcgqzdy ) ; if (
rtDW . estxwgqypi != 0 ) { rtDW . bkcf3qca2q = rtB . ah0extvo4t ; if ( rtDW .
bkcf3qca2q >= rtP . DiscreteTimeIntegrator3_UpperSat_njveboaopq ) { rtDW .
bkcf3qca2q = rtP . DiscreteTimeIntegrator3_UpperSat_njveboaopq ; } else if (
rtDW . bkcf3qca2q <= rtP . DiscreteTimeIntegrator3_LowerSat_acpnkz2txi ) {
rtDW . bkcf3qca2q = rtP . DiscreteTimeIntegrator3_LowerSat_acpnkz2txi ; } }
if ( rtDW . bkcf3qca2q >= rtP . DiscreteTimeIntegrator3_UpperSat_njveboaopq )
{ rtDW . bkcf3qca2q = rtP . DiscreteTimeIntegrator3_UpperSat_njveboaopq ; }
else if ( rtDW . bkcf3qca2q <= rtP .
DiscreteTimeIntegrator3_LowerSat_acpnkz2txi ) { rtDW . bkcf3qca2q = rtP .
DiscreteTimeIntegrator3_LowerSat_acpnkz2txi ; } kqjvqq54rw = rtDW .
bkcf3qca2q ; c4vaviz4dp = rtDW . ixn3ky1f2r * llpdcgqzdy - rtDW . bkcf3qca2q
* esbfypgcb1 ; rtB . avkcbyy3ru [ 0 ] = c4vaviz4dp ; o0hgmfnzg2 = rtDW .
ixn3ky1f2r * esbfypgcb1 + rtDW . bkcf3qca2q * llpdcgqzdy ; pgpzevb5rr = rtP .
Gain2_Gain_bufpac5tbs * c4vaviz4dp + rtP . Gain3_Gain_e1nr0mavjq * o0hgmfnzg2
; rtB . avkcbyy3ru [ 1 ] = pgpzevb5rr ; ixpmah5gbt = rtP . Gain1_Gain *
c4vaviz4dp + rtP . Gain4_Gain * o0hgmfnzg2 ; rtB . avkcbyy3ru [ 2 ] =
ixpmah5gbt ; rtB . hnrjpbhtyb = muSingleScalarMod ( ( real32_T ) ( rtP .
_Pn2f2Square_HFI_sldd_ * clwa0ehpcd ) , rtP . Constant2_Value_e5cors3m1f ) ;
o0hgmfnzg2 = rtDW . ejqmpqbi05 ; rtB . kif4jng5eq = ( real32_T ) ( rtP .
Gain1_Gain_owsv2iwqia * rtDW . ejqmpqbi05 ) ; } if ( ssIsSampleHit ( rtS , 1
, 0 ) && ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . n4szfkmgux = rtDW .
cfwppspejc ; rtB . fvwparn2lf = rtDW . nxdrt45sme ; rtB . lyy5l51j1r = rtDW .
abzut1gmtw ; rtB . owirr1gzew = rtDW . moosp1s1ah ; rtB . modaikvwk2 = rtDW .
devpcih51d ; } g551rf0zlu = 0.0 ; for ( ri = rtP . AnalogFilterDesign_C_jc [
0U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 1U ] ; ri ++ ) { g551rf0zlu +=
rtP . AnalogFilterDesign_C_pr * rtX . lags33bb22 [ 0U ] ; } for ( ri = rtP .
AnalogFilterDesign_C_jc [ 1U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 2U ] ;
ri ++ ) { g551rf0zlu += rtP . AnalogFilterDesign_C_pr * rtX . lags33bb22 [ 1U
] ; } for ( ri = rtP . AnalogFilterDesign_C_jc [ 2U ] ; ri < rtP .
AnalogFilterDesign_C_jc [ 3U ] ; ri ++ ) { g551rf0zlu += rtP .
AnalogFilterDesign_C_pr * rtX . lags33bb22 [ 2U ] ; } rtB . c5jdvrisaz = (
real32_T ) g551rf0zlu ; g551rf0zlu = 0.0 ; for ( ri = rtP .
AnalogFilterDesign1_C_jc [ 0U ] ; ri < rtP . AnalogFilterDesign1_C_jc [ 1U ]
; ri ++ ) { g551rf0zlu += rtP . AnalogFilterDesign1_C_pr * rtX . f13vaq3gr5 [
0U ] ; } for ( ri = rtP . AnalogFilterDesign1_C_jc [ 1U ] ; ri < rtP .
AnalogFilterDesign1_C_jc [ 2U ] ; ri ++ ) { g551rf0zlu += rtP .
AnalogFilterDesign1_C_pr * rtX . f13vaq3gr5 [ 1U ] ; } for ( ri = rtP .
AnalogFilterDesign1_C_jc [ 2U ] ; ri < rtP . AnalogFilterDesign1_C_jc [ 3U ]
; ri ++ ) { g551rf0zlu += rtP . AnalogFilterDesign1_C_pr * rtX . f13vaq3gr5 [
2U ] ; } rtB . mu2g0xzmlu = ( real32_T ) g551rf0zlu ; g551rf0zlu = 0.0 ; for
( ri = rtP . AnalogFilterDesign2_C_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign2_C_jc [ 1U ] ; ri ++ ) { g551rf0zlu += rtP .
AnalogFilterDesign2_C_pr * rtX . pgteej05bs [ 0U ] ; } for ( ri = rtP .
AnalogFilterDesign2_C_jc [ 1U ] ; ri < rtP . AnalogFilterDesign2_C_jc [ 2U ]
; ri ++ ) { g551rf0zlu += rtP . AnalogFilterDesign2_C_pr * rtX . pgteej05bs [
1U ] ; } for ( ri = rtP . AnalogFilterDesign2_C_jc [ 2U ] ; ri < rtP .
AnalogFilterDesign2_C_jc [ 3U ] ; ri ++ ) { g551rf0zlu += rtP .
AnalogFilterDesign2_C_pr * rtX . pgteej05bs [ 2U ] ; } rtB . imeh0bgjnw = (
real32_T ) g551rf0zlu ; im1ypk45bp = rtP . Gain_Gain_oneshwnrhn * rtB .
c5jdvrisaz - ( rtB . mu2g0xzmlu + rtB . imeh0bgjnw ) * rtP .
Gain1_Gain_d0pmjscvt0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
e0mzutezmn = muSingleScalarCos ( rtB . owirr1gzew ) ; rtB . luh55v3bwu =
muSingleScalarSin ( rtB . owirr1gzew ) ; } lfad5o30c5 = ( rtB . mu2g0xzmlu -
rtB . imeh0bgjnw ) * rtP . Gain2_Gain_c5zyi33wrb ; rtB . md15iiloqt =
im1ypk45bp * rtB . e0mzutezmn + lfad5o30c5 * rtB . luh55v3bwu ; rtB .
krxowr1za1 = lfad5o30c5 * rtB . e0mzutezmn - im1ypk45bp * rtB . luh55v3bwu ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } g551rf0zlu = 0.0 ; for ( ci = 0 ; ci
< 6 ; ci ++ ) { for ( ri = rtP . AnalogFilterDesign3_C_jc [ ( uint32_T ) ci ]
; ri < rtP . AnalogFilterDesign3_C_jc [ ( uint32_T ) ci + 1U ] ; ri ++ ) {
g551rf0zlu += rtP . AnalogFilterDesign3_C_pr * rtX . ejepwxaus4 [ ( uint32_T
) ci ] ; } } rtB . bwxxvrlgaj = ( real32_T ) g551rf0zlu ; g551rf0zlu = 0.0 ;
for ( ci = 0 ; ci < 6 ; ci ++ ) { for ( ri = rtP . AnalogFilterDesign4_C_jc [
( uint32_T ) ci ] ; ri < rtP . AnalogFilterDesign4_C_jc [ ( uint32_T ) ci +
1U ] ; ri ++ ) { g551rf0zlu += rtP . AnalogFilterDesign4_C_pr * rtX .
hgersqr5ev [ ( uint32_T ) ci ] ; } } rtB . c1odu2gdtj = ( real32_T )
g551rf0zlu ; g551rf0zlu = 0.0 ; for ( ci = 0 ; ci < 6 ; ci ++ ) { for ( ri =
rtP . AnalogFilterDesign5_C_jc [ ( uint32_T ) ci ] ; ri < rtP .
AnalogFilterDesign5_C_jc [ ( uint32_T ) ci + 1U ] ; ri ++ ) { g551rf0zlu +=
rtP . AnalogFilterDesign5_C_pr * rtX . ic5giadsig [ ( uint32_T ) ci ] ; } }
rtB . ogxod1b2u3 = ( real32_T ) g551rf0zlu ; rtB . lqedrpdjvq = rtP .
Gain_Gain_nggjdhdyc1 * rtB . bwxxvrlgaj - ( rtB . c1odu2gdtj + rtB .
ogxod1b2u3 ) * rtP . Gain1_Gain_dhl1phxitf ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . hujs41lxa1 = rtDW . gkxlktnf2e ; rtB . ij0emyqotr =
muSingleScalarMod ( rtB . hujs41lxa1 , rtP . Constant2_Value_n4cnemylwa ) ;
rtB . czad505sp3 = muSingleScalarCos ( rtB . ij0emyqotr ) ; rtB . hfw2v3eciw
= muSingleScalarSin ( rtB . ij0emyqotr ) ; } rtB . oy5uuprwrz = ( rtB .
c1odu2gdtj - rtB . ogxod1b2u3 ) * rtP . Gain2_Gain_nyrqrcnyqt ; rtB .
a1dv31bkl5 = rtB . lqedrpdjvq * rtB . czad505sp3 + rtB . oy5uuprwrz * rtB .
hfw2v3eciw ; rtB . fe5da5vw1v = rtB . oy5uuprwrz * rtB . czad505sp3 - rtB .
lqedrpdjvq * rtB . hfw2v3eciw ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
g551rf0zlu = 0.0 ; for ( ri = rtP . AnalogFilterDesign1_C_jc_bi43o0wxhg [ 0U
] ; ri < rtP . AnalogFilterDesign1_C_jc_bi43o0wxhg [ 1U ] ; ri ++ ) {
g551rf0zlu += rtP . AnalogFilterDesign1_C_pr_ch4mm2g3zc * rtX . ienzc5s5vc [
0U ] ; } for ( ri = rtP . AnalogFilterDesign1_C_jc_bi43o0wxhg [ 1U ] ; ri <
rtP . AnalogFilterDesign1_C_jc_bi43o0wxhg [ 2U ] ; ri ++ ) { g551rf0zlu +=
rtP . AnalogFilterDesign1_C_pr_ch4mm2g3zc * rtX . ienzc5s5vc [ 1U ] ; } for (
ri = rtP . AnalogFilterDesign1_C_jc_bi43o0wxhg [ 2U ] ; ri < rtP .
AnalogFilterDesign1_C_jc_bi43o0wxhg [ 3U ] ; ri ++ ) { g551rf0zlu += rtP .
AnalogFilterDesign1_C_pr_ch4mm2g3zc * rtX . ienzc5s5vc [ 2U ] ; } rtB .
izwpvpxlts = 30.0F / ( 3.14159274F * rtP . _Pn2f2Square_HFI_sldd_ ) * (
real32_T ) g551rf0zlu ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { g551rf0zlu = (
rtDW . afdxa4jpho < rtP . PulseGenerator_Duty ) && ( rtDW . afdxa4jpho >= 0 )
? rtP . PulseGenerator_Amp : 0.0 ; if ( rtDW . afdxa4jpho >= rtP .
PulseGenerator_Period - 1.0 ) { rtDW . afdxa4jpho = 0 ; } else { rtDW .
afdxa4jpho ++ ; } im1ypk45bp = muSingleScalarCos ( rtB . ij0emyqotr ) ;
lfad5o30c5 = muSingleScalarSin ( rtB . ij0emyqotr ) ; rtB . gpl4ohobjp = (
real32_T ) g551rf0zlu * im1ypk45bp - rtP . Constant1_Value_pfphbi3aj2 *
lfad5o30c5 ; rtB . b15ggaqysc = ( real32_T ) g551rf0zlu * lfad5o30c5 + rtP .
Constant1_Value_pfphbi3aj2 * im1ypk45bp ; } rtB . hqrlwn2gih =
muDoubleScalarSin ( ssGetT ( rtS ) * rtP . Constant_Value ) * rtB .
fe5da5vw1v ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } g551rf0zlu = 0.0 ; for
( ri = rtP . AnalogFilterDesign_C_jc_e5mtimz5tp [ 0U ] ; ri < rtP .
AnalogFilterDesign_C_jc_e5mtimz5tp [ 1U ] ; ri ++ ) { g551rf0zlu += rtP .
AnalogFilterDesign_C_pr_d2lrbbjghc * rtX . j1rganlm1m [ 0U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_e5mtimz5tp [ 1U ] ; ri < rtP .
AnalogFilterDesign_C_jc_e5mtimz5tp [ 2U ] ; ri ++ ) { g551rf0zlu += rtP .
AnalogFilterDesign_C_pr_d2lrbbjghc * rtX . j1rganlm1m [ 1U ] ; } rtB .
fdhox1t1ny = ( real32_T ) g551rf0zlu ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . cxpc4e4kit = rtB . owirr1gzew - rtB . ij0emyqotr ; } rtB . oaogaf1p5f =
rtB . modaikvwk2 - rtB . izwpvpxlts ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
} rtB . j0ybbliyam = rtP . Constant_Value_fad045x02c - rtB . md15iiloqt ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { nnotgsinza = rtP .
_CurrKpd2f2Square_HFI_sldd_ / 100.0F * rtB . j0ybbliyam + ( real32_T ) rtDW .
prwdcgjlej * 1.0E-9F ; if ( nnotgsinza > rtP .
PIDController1_UpperSaturationLimit ) { rtB . lubu1u2ru4 = rtP .
PIDController1_UpperSaturationLimit ; } else if ( nnotgsinza < rtP .
PIDController1_LowerSaturationLimit ) { rtB . lubu1u2ru4 = rtP .
PIDController1_LowerSaturationLimit ; } else { rtB . lubu1u2ru4 = nnotgsinza
; } g4s2wbjq2i = muSingleScalarCos ( rtB . owirr1gzew ) ; l5vmkrcylz = rtB .
lubu1u2ru4 * g4s2wbjq2i ; bo5x2udat5 = rtP . Constant3_Value_fveq5hyrqd - rtB
. modaikvwk2 ; hn4nda5y0a = rtP . _spd_kp2f2Square_HFI_sldd_ * bo5x2udat5 +
rtDW . bk0pvczvd4 ; if ( hn4nda5y0a > rtP .
PIDController3_UpperSaturationLimit ) { rtB . kwir5smtvi = rtP .
PIDController3_UpperSaturationLimit ; } else if ( hn4nda5y0a < rtP .
PIDController3_LowerSaturationLimit ) { rtB . kwir5smtvi = rtP .
PIDController3_LowerSaturationLimit ; } else { rtB . kwir5smtvi = hn4nda5y0a
; } } rtB . nacsw2wv2y = rtB . kwir5smtvi - rtB . krxowr1za1 ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { im1ypk45bp = rtP .
_CurrKpq2f2Square_HFI_sldd_ / 100.0F * rtB . nacsw2wv2y + rtDW . cfnq23qry5 ;
if ( im1ypk45bp > rtP . PIDController2_UpperSaturationLimit ) { rtB .
m0psoaixxy = rtP . PIDController2_UpperSaturationLimit ; } else if (
im1ypk45bp < rtP . PIDController2_LowerSaturationLimit ) { rtB . m0psoaixxy =
rtP . PIDController2_LowerSaturationLimit ; } else { rtB . m0psoaixxy =
im1ypk45bp ; } gp31ms5ogx = muSingleScalarSin ( rtB . owirr1gzew ) ; rtB .
kybjyzwqma = l5vmkrcylz - rtB . m0psoaixxy * gp31ms5ogx ; frfcrvlu3k = rtB .
kybjyzwqma + rtB . gpl4ohobjp ; rtB . cqzn2b2kj2 = rtB . lubu1u2ru4 *
gp31ms5ogx + rtB . m0psoaixxy * g4s2wbjq2i ; gp31ms5ogx = rtB . cqzn2b2kj2 +
rtB . b15ggaqysc ; if ( nnotgsinza > rtP .
PIDController1_UpperSaturationLimit ) { nnotgsinza -= rtP .
PIDController1_UpperSaturationLimit ; } else if ( nnotgsinza >= rtP .
PIDController1_LowerSaturationLimit ) { nnotgsinza = 0.0F ; } else {
nnotgsinza -= rtP . PIDController1_LowerSaturationLimit ; } lfad5o30c5 =
muSingleScalarFloor ( rtP . _CurrKi2f2Square_HFI_sldd_ / 100.0F * rtB .
j0ybbliyam ) ; if ( muSingleScalarIsNaN ( lfad5o30c5 ) || muSingleScalarIsInf
( lfad5o30c5 ) ) { lfad5o30c5 = 0.0F ; } else { lfad5o30c5 =
muSingleScalarRem ( lfad5o30c5 , 65536.0F ) ; } fxtirdbxfd = ( int16_T ) (
lfad5o30c5 < 0.0F ? ( int32_T ) ( int16_T ) - ( int16_T ) ( uint16_T ) -
lfad5o30c5 : ( int32_T ) ( int16_T ) ( uint16_T ) lfad5o30c5 ) ; if (
nnotgsinza > rtP . Clamping_zero_Value_gmmqgeo1e4 ) { tmp = rtP .
Constant_Value_jxwhvocfhb ; } else { tmp = rtP . Constant2_Value_i2m45uwk2o ;
} if ( fxtirdbxfd > rtP . Clamping_zero_Value_gmmqgeo1e4 ) { tmp_p = rtP .
Constant3_Value_bymcbl0414 ; } else { tmp_p = rtP . Constant4_Value ; } if (
( rtP . Clamping_zero_Value_gmmqgeo1e4 != nnotgsinza ) && ( tmp == tmp_p ) )
{ rtB . irpxyowq0z = rtP . Constant1_Value_odajvcsv3r ; } else { rtB .
irpxyowq0z = fxtirdbxfd ; } if ( im1ypk45bp > rtP .
PIDController2_UpperSaturationLimit ) { nnotgsinza = im1ypk45bp - rtP .
PIDController2_UpperSaturationLimit ; } else if ( im1ypk45bp >= rtP .
PIDController2_LowerSaturationLimit ) { nnotgsinza = 0.0F ; } else {
nnotgsinza = im1ypk45bp - rtP . PIDController2_LowerSaturationLimit ; }
g4s2wbjq2i = rtP . _CurrKi2f2Square_HFI_sldd_ / 100.0F * rtB . nacsw2wv2y ;
if ( nnotgsinza > rtP . Clamping_zero_Value ) { tmp = rtP .
Constant_Value_jhbksipzdc ; } else { tmp = rtP . Constant2_Value_j12qjlnlzg ;
} if ( g4s2wbjq2i > rtP . Clamping_zero_Value ) { tmp_p = rtP .
Constant3_Value_gvheyotvnt ; } else { tmp_p = rtP .
Constant4_Value_hfhut001zy ; } if ( ( rtP . Clamping_zero_Value != nnotgsinza
) && ( tmp == tmp_p ) ) { rtB . gs5kavedxi = rtP . Constant1_Value_fpaq0utenz
; } else { rtB . gs5kavedxi = g4s2wbjq2i ; } rtB . jeobpjpcy3 = rtB .
n4szfkmgux ; rtB . oy1uirggpc = rtB . n4szfkmgux ; rtB . lwjmxasb2z = rtB .
fvwparn2lf ; rtB . ajtg2x2b41 = rtB . fvwparn2lf ; rtB . logsazcj2d = rtB .
lyy5l51j1r ; rtB . hqgkqxg4zr = rtB . lyy5l51j1r ; rtB . bt3fcv3v3w = rtDW .
fsiptkwftx ; } rtB . nk3bpfyhq2 = rtP . _PLL_Kd2f2Square_HFI_sldd_ * rtB .
fdhox1t1ny + rtB . bt3fcv3v3w ; rtB . j5g3qzjurz = rtB . nk3bpfyhq2 ; rtB .
oa4nu2h02a = rtP . _PLL_Ki2f2Square_HFI_sldd_ * rtB . fdhox1t1ny ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { nnotgsinza = rtP . Gain_Gain_gt5xi45qct *
frfcrvlu3k ; g4s2wbjq2i = rtP . Gain1_Gain_cpamektdhq * gp31ms5ogx ; if (
gp31ms5ogx > rtP . ASwitch_Threshold ) { g551rf0zlu = rtP .
Constant_Value_prx0zmzuez ; } else { g551rf0zlu = rtP . Constant1_Value ; }
if ( nnotgsinza - g4s2wbjq2i > rtP . BSwitch_Threshold ) { goacxbnaqe_idx_0 =
rtP . Constant_Value_prx0zmzuez ; } else { goacxbnaqe_idx_0 = rtP .
Constant1_Value ; } if ( ( 0.0F - nnotgsinza ) - g4s2wbjq2i > rtP .
CSwitch_Threshold ) { goacxbnaqe_idx_1 = rtP . Constant_Value_prx0zmzuez ; }
else { goacxbnaqe_idx_1 = rtP . Constant1_Value ; } rtB . exsy54mv4x = ( rtP
. Gain2_Gain * goacxbnaqe_idx_0 + g551rf0zlu ) + rtP . Gain3_Gain *
goacxbnaqe_idx_1 ; nnotgsinza = rtP . Gain1_Gain_d2r1btvvwg * rtP .
Constant1_Value_a1crlzduby ; g4s2wbjq2i = rtP . Gain1_Gain_o051fegvds *
frfcrvlu3k ; l5vmkrcylz = rtP . Gain2_Gain_fpelshvuq5 * gp31ms5ogx ;
frfcrvlu3k = rtP . Gain_Gain_bpfw2sk42p * rtP . Constant1_Value_a1crlzduby /
rtP . Constant_Value_ah0pp224du ; rtB . ll43tv0wht = ( l5vmkrcylz -
g4s2wbjq2i ) * frfcrvlu3k ; rtB . bvspyalpkj = ( g4s2wbjq2i + l5vmkrcylz ) *
frfcrvlu3k ; g4s2wbjq2i = rtP . Gain2_Gain_crytncxhkk * rtB . ll43tv0wht ;
rtB . b2gfisg0eh = gp31ms5ogx * frfcrvlu3k ; gp31ms5ogx = rtP .
Gain_Gain_lsczmwd1h2 * rtB . b2gfisg0eh ; frfcrvlu3k = rtP .
Gain1_Gain_j1zbr4lzxq * rtB . bvspyalpkj ; switch ( ( int32_T ) rtB .
exsy54mv4x ) { case 1 : rtB . nkfg1ddf1g = rtB . ll43tv0wht ; break ; case 2
: rtB . nkfg1ddf1g = rtB . bvspyalpkj ; break ; case 3 : rtB . nkfg1ddf1g =
g4s2wbjq2i ; break ; case 4 : rtB . nkfg1ddf1g = gp31ms5ogx ; break ; case 5
: rtB . nkfg1ddf1g = rtB . b2gfisg0eh ; break ; default : rtB . nkfg1ddf1g =
frfcrvlu3k ; break ; } switch ( ( int32_T ) rtB . exsy54mv4x ) { case 1 : rtB
. edmswnt5ng = rtB . bvspyalpkj ; break ; case 2 : rtB . edmswnt5ng =
gp31ms5ogx ; break ; case 3 : rtB . edmswnt5ng = rtB . b2gfisg0eh ; break ;
case 4 : rtB . edmswnt5ng = rtB . ll43tv0wht ; break ; case 5 : rtB .
edmswnt5ng = frfcrvlu3k ; break ; default : rtB . edmswnt5ng = g4s2wbjq2i ;
break ; } frfcrvlu3k = rtP . Constant1_Value_a1crlzduby / ( rtB . nkfg1ddf1g
+ rtB . edmswnt5ng ) ; g4s2wbjq2i = ( rtB . nkfg1ddf1g + rtB . edmswnt5ng ) -
rtP . Constant1_Value_a1crlzduby ; if ( g4s2wbjq2i > rtP . Switch_Threshold )
{ rtB . dpomenlimv = rtB . nkfg1ddf1g * frfcrvlu3k ; } else { rtB .
dpomenlimv = rtB . nkfg1ddf1g ; } gp31ms5ogx = rtP . Gain_Gain_hfbnedsnqk *
rtB . dpomenlimv ; if ( g4s2wbjq2i > rtP . Switch1_Threshold ) { rtB .
ezlw3p4p00 = frfcrvlu3k * rtB . edmswnt5ng ; } else { rtB . ezlw3p4p00 = rtB
. edmswnt5ng ; } l5vmkrcylz = rtP . Gain2_Gain_mqqw0m41vg * rtB . ezlw3p4p00
; frfcrvlu3k = ( nnotgsinza + gp31ms5ogx ) - l5vmkrcylz ; g4s2wbjq2i = (
nnotgsinza - gp31ms5ogx ) - l5vmkrcylz ; gp31ms5ogx = ( nnotgsinza +
gp31ms5ogx ) + l5vmkrcylz ; switch ( ( int32_T ) rtB . exsy54mv4x ) { case 1
: rtB . jzhluxfqhc = frfcrvlu3k ; break ; case 2 : rtB . jzhluxfqhc =
g4s2wbjq2i ; break ; case 3 : rtB . jzhluxfqhc = g4s2wbjq2i ; break ; case 4
: rtB . jzhluxfqhc = gp31ms5ogx ; break ; case 5 : rtB . jzhluxfqhc =
gp31ms5ogx ; break ; default : rtB . jzhluxfqhc = frfcrvlu3k ; break ; } rtB
. e0rj1hvaeo = rtB . jzhluxfqhc / rtP . Constant1_Value_a1crlzduby ; switch (
( int32_T ) rtB . exsy54mv4x ) { case 1 : rtB . jumrg4wdv0 = g4s2wbjq2i ;
break ; case 2 : rtB . jumrg4wdv0 = gp31ms5ogx ; break ; case 3 : rtB .
jumrg4wdv0 = frfcrvlu3k ; break ; case 4 : rtB . jumrg4wdv0 = frfcrvlu3k ;
break ; case 5 : rtB . jumrg4wdv0 = g4s2wbjq2i ; break ; default : rtB .
jumrg4wdv0 = gp31ms5ogx ; break ; } rtB . esnhg1urb0 = rtB . jumrg4wdv0 / rtP
. Constant1_Value_a1crlzduby ; switch ( ( int32_T ) rtB . exsy54mv4x ) { case
1 : rtB . kxtv0fhkws = gp31ms5ogx ; break ; case 2 : rtB . kxtv0fhkws =
frfcrvlu3k ; break ; case 3 : rtB . kxtv0fhkws = gp31ms5ogx ; break ; case 4
: rtB . kxtv0fhkws = g4s2wbjq2i ; break ; case 5 : rtB . kxtv0fhkws =
frfcrvlu3k ; break ; default : rtB . kxtv0fhkws = g4s2wbjq2i ; break ; } rtB
. o1qptmrlo4 = rtB . kxtv0fhkws / rtP . Constant1_Value_a1crlzduby ; if (
hn4nda5y0a > rtP . PIDController3_UpperSaturationLimit ) { hn4nda5y0a -= rtP
. PIDController3_UpperSaturationLimit ; } else if ( hn4nda5y0a >= rtP .
PIDController3_LowerSaturationLimit ) { hn4nda5y0a = 0.0F ; } else {
hn4nda5y0a -= rtP . PIDController3_LowerSaturationLimit ; } bo5x2udat5 *= rtP
. _spd_ki2f2Square_HFI_sldd_ ; if ( hn4nda5y0a > rtP .
Clamping_zero_Value_n2or5cqygv ) { tmp = rtP . Constant_Value_oqmhouwrxr ; }
else { tmp = rtP . Constant2_Value_gdlubdifra ; } if ( bo5x2udat5 > rtP .
Clamping_zero_Value_n2or5cqygv ) { tmp_p = rtP . Constant3_Value_nanqjpbqvw ;
} else { tmp_p = rtP . Constant4_Value_ge5isbbxow ; } if ( ( rtP .
Clamping_zero_Value_n2or5cqygv != hn4nda5y0a ) && ( tmp == tmp_p ) ) { rtB .
fd2nlplojn = rtP . Constant1_Value_pe5vj0iriy ; } else { rtB . fd2nlplojn =
bo5x2udat5 ; } goacxbnaqe_idx_0 = rtP . Constant_Value_e4jyxae25b - rtP .
Gain_Gain_dd1zo3e4je * rtB . e0rj1hvaeo ; if ( goacxbnaqe_idx_0 > rtP .
Saturation2_UpperSat ) { goacxbnaqe_idx_0 = rtP . Saturation2_UpperSat ; }
else if ( goacxbnaqe_idx_0 < rtP . Saturation2_LowerSat ) { goacxbnaqe_idx_0
= rtP . Saturation2_LowerSat ; } goacxbnaqe_idx_1 = rtP .
Constant_Value_e4jyxae25b - rtP . Gain_Gain_dd1zo3e4je * rtB . esnhg1urb0 ;
if ( goacxbnaqe_idx_1 > rtP . Saturation2_UpperSat ) { goacxbnaqe_idx_1 = rtP
. Saturation2_UpperSat ; } else if ( goacxbnaqe_idx_1 < rtP .
Saturation2_LowerSat ) { goacxbnaqe_idx_1 = rtP . Saturation2_LowerSat ; }
goacxbnaqe_idx_2 = rtP . Constant_Value_e4jyxae25b - rtP .
Gain_Gain_dd1zo3e4je * rtB . o1qptmrlo4 ; if ( goacxbnaqe_idx_2 > rtP .
Saturation2_UpperSat ) { goacxbnaqe_idx_2 = rtP . Saturation2_UpperSat ; }
else if ( goacxbnaqe_idx_2 < rtP . Saturation2_LowerSat ) { goacxbnaqe_idx_2
= rtP . Saturation2_LowerSat ; } g551rf0zlu = ( ( goacxbnaqe_idx_1 +
goacxbnaqe_idx_2 ) + goacxbnaqe_idx_0 ) * rtP . Gain_Gain ; rtB . ptas5mx2xx
[ 0 ] = ( goacxbnaqe_idx_0 - g551rf0zlu ) * rtB . orihl2n4h3 ; rtB .
ptas5mx2xx [ 1 ] = ( goacxbnaqe_idx_1 - g551rf0zlu ) * rtB . orihl2n4h3 ; rtB
. ptas5mx2xx [ 2 ] = ( goacxbnaqe_idx_2 - g551rf0zlu ) * rtB . orihl2n4h3 ; }
if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . oekg5cjnsz = ( real32_T )
ixpmah5gbt ; rtB . ezk2tehwll = ( real32_T ) pgpzevb5rr ; rtB . haqol3cjgg =
( real32_T ) c4vaviz4dp ; } { real_T * pDataValues = ( real_T * ) rtDW .
cwf0tqdxqc . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . cwf0tqdxqc
. TimePtr ; int_T currTimeIndex = rtDW . fjmelxecm4 . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . cwf0tqdxqc . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . fjmelxecm4 . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . iyvrnoncql =
pDataValues [ currTimeIndex ] ; } else { rtB . iyvrnoncql = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; rtB . iyvrnoncql = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB .
lz5lj5ytco = ( ( ( ( ewibbafrki * kqjvqq54rw * rtB . cm34cwonv3 + rtP .
_flux2f2Square_HFI_sldd_ * kqjvqq54rw ) * rtP . Gain2_Gain_lgyufe3n3y - rtB .
iyvrnoncql ) - o0hgmfnzg2 * rtB . kpb21alagy ) - rtB . c1syzcnvq0 *
muDoubleScalarSign ( o0hgmfnzg2 ) ) / rtB . acjaxnsuyo ; c4vaviz4dp = rtP .
_Pn2f2Square_HFI_sldd_ * o0hgmfnzg2 ; rtB . jielxbq1gv = rtP . Int1_Ts *
o0hgmfnzg2 + clwa0ehpcd ; clwa0ehpcd = ( rtP . Gain_Gain_n3c5iuh2qk * rtB .
ptas5mx2xx [ 0 ] + rtP . Gain1_Gain_cuaiqtkau5 * rtB . ptas5mx2xx [ 1 ] ) +
rtP . Gain4_Gain_dum3dkp5wn * rtB . ptas5mx2xx [ 2 ] ; pgpzevb5rr = rtP .
Gain2_Gain_m2442d4sfc * rtB . ptas5mx2xx [ 1 ] + rtP . Gain3_Gain_baedkupsze
* rtB . ptas5mx2xx [ 2 ] ; rtB . fgw4v4wm4g = ( ( clwa0ehpcd * llpdcgqzdy +
pgpzevb5rr * esbfypgcb1 ) / rtB . lknhr4vxtr + c4vaviz4dp * kqjvqq54rw * rtB
. cnm3x1s5lo / rtB . ow4uvzz2pj ) - ewibbafrki * rtP . _Rs2f2Square_HFI_sldd_
/ rtB . k0o4fvzzy3 ; rtB . ouiqfsyu43 = ( ( ( pgpzevb5rr * llpdcgqzdy -
clwa0ehpcd * esbfypgcb1 ) / rtB . lit4m00nbl - ewibbafrki * c4vaviz4dp * rtB
. mrd41buyxt / rtB . pntkd2uyvv ) - c4vaviz4dp * rtP .
_flux2f2Square_HFI_sldd_ / rtB . oxcrb4vtyb ) - kqjvqq54rw * rtP .
_Rs2f2Square_HFI_sldd_ / rtB . isprk1at5s ; } UNUSED_PARAMETER ( tid ) ; }
void MdlOutputsTID3 ( int_T tid ) { if ( rtP . Constant_Value_ah0pp224du >=
rtP . Switch_Threshold_buydduua1q ) { rtB . orihl2n4h3 = rtP .
Constant_Value_ah0pp224du ; } else { rtB . orihl2n4h3 = rtP .
Constant_Value_pspbithpw4 ; } rtB . acjaxnsuyo = rtP .
InteriorPMSM_mechanical [ ( int32_T ) rtP . Constant1_Value_cec3dpoe5t - 1 ]
; rtB . c1syzcnvq0 = rtP . InteriorPMSM_mechanical [ ( int32_T ) rtP .
Constant3_Value - 1 ] ; rtB . kpb21alagy = rtP . InteriorPMSM_mechanical [ (
int32_T ) rtP . Constant5_Value - 1 ] ; rtB . cm34cwonv3 = rtP .
InteriorPMSM_Ldq [ ( int32_T ) rtP . Constant1_Value_fuoewzrkks - 1 ] - rtP .
InteriorPMSM_Ldq [ ( int32_T ) rtP . Constant2_Value - 1 ] ; rtB . ikmh2tfryy
= rtP . InteriorPMSM_idq0 [ ( int32_T ) rtP . Constant1_Value_p1324vfsr3 - 1
] ; rtB . lknhr4vxtr = rtP . InteriorPMSM_Ldq [ ( int32_T ) rtP .
Constant1_Value_db5wbste14 - 1 ] ; rtB . cnm3x1s5lo = rtP . InteriorPMSM_Ldq
[ ( int32_T ) rtP . Constant1_Value_arpzt5qlzk - 1 ] ; rtB . ow4uvzz2pj = rtP
. InteriorPMSM_Ldq [ ( int32_T ) rtP . Constant2_Value_iedxtooqmk - 1 ] ; rtB
. k0o4fvzzy3 = rtP . InteriorPMSM_Ldq [ ( int32_T ) rtP .
Constant2_Value_ombtisyb12 - 1 ] ; rtB . ah0extvo4t = rtP . InteriorPMSM_idq0
[ ( int32_T ) rtP . Constant1_Value_i5c5nfcqn0 - 1 ] ; rtB . lit4m00nbl = rtP
. InteriorPMSM_Ldq [ ( int32_T ) rtP . Constant1_Value_ghv5aa4po2 - 1 ] ; rtB
. mrd41buyxt = rtP . InteriorPMSM_Ldq [ ( int32_T ) rtP .
Constant1_Value_dlowd15ti4 - 1 ] ; rtB . pntkd2uyvv = rtP . InteriorPMSM_Ldq
[ ( int32_T ) rtP . Constant2_Value_cfaqape04n - 1 ] ; rtB . oxcrb4vtyb = rtP
. InteriorPMSM_Ldq [ ( int32_T ) rtP . Constant2_Value_puzy4v1jc3 - 1 ] ; rtB
. isprk1at5s = rtP . InteriorPMSM_Ldq [ ( int32_T ) rtP .
Constant2_Value_bmnavpjpcf - 1 ] ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW .
eohtar5htx = 0U ; rtDW . ixn3ky1f2r += rtP . DiscreteTimeIntegrator3_gainval
* rtB . fgw4v4wm4g ; if ( rtDW . ixn3ky1f2r >= rtP .
DiscreteTimeIntegrator3_UpperSat ) { rtDW . ixn3ky1f2r = rtP .
DiscreteTimeIntegrator3_UpperSat ; } else if ( rtDW . ixn3ky1f2r <= rtP .
DiscreteTimeIntegrator3_LowerSat ) { rtDW . ixn3ky1f2r = rtP .
DiscreteTimeIntegrator3_LowerSat ; } rtDW . hxrufsyg2z = rtB . jielxbq1gv ;
rtDW . estxwgqypi = 0U ; rtDW . bkcf3qca2q += rtP .
DiscreteTimeIntegrator3_gainval_o2siosbbdr * rtB . ouiqfsyu43 ; if ( rtDW .
bkcf3qca2q >= rtP . DiscreteTimeIntegrator3_UpperSat_njveboaopq ) { rtDW .
bkcf3qca2q = rtP . DiscreteTimeIntegrator3_UpperSat_njveboaopq ; } else if (
rtDW . bkcf3qca2q <= rtP . DiscreteTimeIntegrator3_LowerSat_acpnkz2txi ) {
rtDW . bkcf3qca2q = rtP . DiscreteTimeIntegrator3_LowerSat_acpnkz2txi ; }
rtDW . ejqmpqbi05 += rtP . DiscreteTimeIntegrator_gainval * rtB . lz5lj5ytco
; if ( rtDW . ejqmpqbi05 >= rtP . DiscreteTimeIntegrator_UpperSat ) { rtDW .
ejqmpqbi05 = rtP . DiscreteTimeIntegrator_UpperSat ; } else if ( rtDW .
ejqmpqbi05 <= rtP . DiscreteTimeIntegrator_LowerSat ) { rtDW . ejqmpqbi05 =
rtP . DiscreteTimeIntegrator_LowerSat ; } rtDW . cfwppspejc = rtB .
haqol3cjgg ; rtDW . nxdrt45sme = rtB . ezk2tehwll ; rtDW . abzut1gmtw = rtB .
oekg5cjnsz ; rtDW . moosp1s1ah = rtB . hnrjpbhtyb ; rtDW . devpcih51d = rtB .
kif4jng5eq ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . gkxlktnf2e +=
rtP . DiscreteTimeIntegrator1_gainval * rtB . nk3bpfyhq2 ; rtDW . prwdcgjlej
+= rtB . irpxyowq0z ; rtDW . bk0pvczvd4 += rtP . Integrator_gainval * rtB .
fd2nlplojn ; rtDW . cfnq23qry5 += rtP . Integrator_gainval_gqdjj5igji * rtB .
gs5kavedxi ; rtDW . fsiptkwftx += rtP .
DiscreteTimeIntegrator_gainval_k25juj44ov * rtB . oa4nu2h02a ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID3 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
int_T is ; uint32_T ri ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot
-> lags33bb22 [ 0 ] = 0.0 ; _rtXdot -> lags33bb22 [ 1 ] = 0.0 ; _rtXdot ->
lags33bb22 [ 2 ] = 0.0 ; for ( ri = rtP . AnalogFilterDesign_A_jc [ 0U ] ; ri
< rtP . AnalogFilterDesign_A_jc [ 1U ] ; ri ++ ) { _rtXdot -> lags33bb22 [
rtP . AnalogFilterDesign_A_ir [ ri ] ] += rtP . AnalogFilterDesign_A_pr [ ri
] * rtX . lags33bb22 [ 0U ] ; } for ( ri = rtP . AnalogFilterDesign_A_jc [ 1U
] ; ri < rtP . AnalogFilterDesign_A_jc [ 2U ] ; ri ++ ) { _rtXdot ->
lags33bb22 [ rtP . AnalogFilterDesign_A_ir [ ri ] ] += rtP .
AnalogFilterDesign_A_pr [ ri ] * rtX . lags33bb22 [ 1U ] ; } for ( ri = rtP .
AnalogFilterDesign_A_jc [ 2U ] ; ri < rtP . AnalogFilterDesign_A_jc [ 3U ] ;
ri ++ ) { _rtXdot -> lags33bb22 [ rtP . AnalogFilterDesign_A_ir [ ri ] ] +=
rtP . AnalogFilterDesign_A_pr [ ri ] * rtX . lags33bb22 [ 2U ] ; } for ( ri =
rtP . AnalogFilterDesign_B_jc [ 0U ] ; ri < rtP . AnalogFilterDesign_B_jc [
1U ] ; ri ++ ) { _rtXdot -> lags33bb22 [ rtP . AnalogFilterDesign_B_ir ] +=
rtP . AnalogFilterDesign_B_pr * rtB . jeobpjpcy3 ; } _rtXdot -> f13vaq3gr5 [
0 ] = 0.0 ; _rtXdot -> f13vaq3gr5 [ 1 ] = 0.0 ; _rtXdot -> f13vaq3gr5 [ 2 ] =
0.0 ; for ( ri = rtP . AnalogFilterDesign1_A_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign1_A_jc [ 1U ] ; ri ++ ) { _rtXdot -> f13vaq3gr5 [ rtP .
AnalogFilterDesign1_A_ir [ ri ] ] += rtP . AnalogFilterDesign1_A_pr [ ri ] *
rtX . f13vaq3gr5 [ 0U ] ; } for ( ri = rtP . AnalogFilterDesign1_A_jc [ 1U ]
; ri < rtP . AnalogFilterDesign1_A_jc [ 2U ] ; ri ++ ) { _rtXdot ->
f13vaq3gr5 [ rtP . AnalogFilterDesign1_A_ir [ ri ] ] += rtP .
AnalogFilterDesign1_A_pr [ ri ] * rtX . f13vaq3gr5 [ 1U ] ; } for ( ri = rtP
. AnalogFilterDesign1_A_jc [ 2U ] ; ri < rtP . AnalogFilterDesign1_A_jc [ 3U
] ; ri ++ ) { _rtXdot -> f13vaq3gr5 [ rtP . AnalogFilterDesign1_A_ir [ ri ] ]
+= rtP . AnalogFilterDesign1_A_pr [ ri ] * rtX . f13vaq3gr5 [ 2U ] ; } for (
ri = rtP . AnalogFilterDesign1_B_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign1_B_jc [ 1U ] ; ri ++ ) { _rtXdot -> f13vaq3gr5 [ rtP .
AnalogFilterDesign1_B_ir ] += rtP . AnalogFilterDesign1_B_pr * rtB .
lwjmxasb2z ; } _rtXdot -> pgteej05bs [ 0 ] = 0.0 ; _rtXdot -> pgteej05bs [ 1
] = 0.0 ; _rtXdot -> pgteej05bs [ 2 ] = 0.0 ; for ( ri = rtP .
AnalogFilterDesign2_A_jc [ 0U ] ; ri < rtP . AnalogFilterDesign2_A_jc [ 1U ]
; ri ++ ) { _rtXdot -> pgteej05bs [ rtP . AnalogFilterDesign2_A_ir [ ri ] ]
+= rtP . AnalogFilterDesign2_A_pr [ ri ] * rtX . pgteej05bs [ 0U ] ; } for (
ri = rtP . AnalogFilterDesign2_A_jc [ 1U ] ; ri < rtP .
AnalogFilterDesign2_A_jc [ 2U ] ; ri ++ ) { _rtXdot -> pgteej05bs [ rtP .
AnalogFilterDesign2_A_ir [ ri ] ] += rtP . AnalogFilterDesign2_A_pr [ ri ] *
rtX . pgteej05bs [ 1U ] ; } for ( ri = rtP . AnalogFilterDesign2_A_jc [ 2U ]
; ri < rtP . AnalogFilterDesign2_A_jc [ 3U ] ; ri ++ ) { _rtXdot ->
pgteej05bs [ rtP . AnalogFilterDesign2_A_ir [ ri ] ] += rtP .
AnalogFilterDesign2_A_pr [ ri ] * rtX . pgteej05bs [ 2U ] ; } for ( ri = rtP
. AnalogFilterDesign2_B_jc [ 0U ] ; ri < rtP . AnalogFilterDesign2_B_jc [ 1U
] ; ri ++ ) { _rtXdot -> pgteej05bs [ rtP . AnalogFilterDesign2_B_ir ] += rtP
. AnalogFilterDesign2_B_pr * rtB . hqgkqxg4zr ; } for ( is = 0 ; is < 6 ; is
++ ) { _rtXdot -> ejepwxaus4 [ is ] = 0.0 ; } for ( is = 0 ; is < 6 ; is ++ )
{ for ( ri = rtP . AnalogFilterDesign3_A_jc [ ( uint32_T ) is ] ; ri < rtP .
AnalogFilterDesign3_A_jc [ ( uint32_T ) is + 1U ] ; ri ++ ) { _rtXdot ->
ejepwxaus4 [ rtP . AnalogFilterDesign3_A_ir [ ri ] ] += rtP .
AnalogFilterDesign3_A_pr [ ri ] * rtX . ejepwxaus4 [ ( uint32_T ) is ] ; } }
for ( ri = rtP . AnalogFilterDesign3_B_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign3_B_jc [ 1U ] ; ri ++ ) { _rtXdot -> ejepwxaus4 [ rtP .
AnalogFilterDesign3_B_ir ] += rtP . AnalogFilterDesign3_B_pr * rtB .
oy1uirggpc ; } for ( is = 0 ; is < 6 ; is ++ ) { _rtXdot -> hgersqr5ev [ is ]
= 0.0 ; } for ( is = 0 ; is < 6 ; is ++ ) { for ( ri = rtP .
AnalogFilterDesign4_A_jc [ ( uint32_T ) is ] ; ri < rtP .
AnalogFilterDesign4_A_jc [ ( uint32_T ) is + 1U ] ; ri ++ ) { _rtXdot ->
hgersqr5ev [ rtP . AnalogFilterDesign4_A_ir [ ri ] ] += rtP .
AnalogFilterDesign4_A_pr [ ri ] * rtX . hgersqr5ev [ ( uint32_T ) is ] ; } }
for ( ri = rtP . AnalogFilterDesign4_B_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign4_B_jc [ 1U ] ; ri ++ ) { _rtXdot -> hgersqr5ev [ rtP .
AnalogFilterDesign4_B_ir ] += rtP . AnalogFilterDesign4_B_pr * rtB .
ajtg2x2b41 ; } for ( is = 0 ; is < 6 ; is ++ ) { _rtXdot -> ic5giadsig [ is ]
= 0.0 ; } for ( is = 0 ; is < 6 ; is ++ ) { for ( ri = rtP .
AnalogFilterDesign5_A_jc [ ( uint32_T ) is ] ; ri < rtP .
AnalogFilterDesign5_A_jc [ ( uint32_T ) is + 1U ] ; ri ++ ) { _rtXdot ->
ic5giadsig [ rtP . AnalogFilterDesign5_A_ir [ ri ] ] += rtP .
AnalogFilterDesign5_A_pr [ ri ] * rtX . ic5giadsig [ ( uint32_T ) is ] ; } }
for ( ri = rtP . AnalogFilterDesign5_B_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign5_B_jc [ 1U ] ; ri ++ ) { _rtXdot -> ic5giadsig [ rtP .
AnalogFilterDesign5_B_ir ] += rtP . AnalogFilterDesign5_B_pr * rtB .
logsazcj2d ; } _rtXdot -> ienzc5s5vc [ 0 ] = 0.0 ; _rtXdot -> ienzc5s5vc [ 1
] = 0.0 ; _rtXdot -> ienzc5s5vc [ 2 ] = 0.0 ; for ( ri = rtP .
AnalogFilterDesign1_A_jc_lbh1btnh5f [ 0U ] ; ri < rtP .
AnalogFilterDesign1_A_jc_lbh1btnh5f [ 1U ] ; ri ++ ) { _rtXdot -> ienzc5s5vc
[ rtP . AnalogFilterDesign1_A_ir_hrenrgccbq [ ri ] ] += rtP .
AnalogFilterDesign1_A_pr_h0kmy5bicq [ ri ] * rtX . ienzc5s5vc [ 0U ] ; } for
( ri = rtP . AnalogFilterDesign1_A_jc_lbh1btnh5f [ 1U ] ; ri < rtP .
AnalogFilterDesign1_A_jc_lbh1btnh5f [ 2U ] ; ri ++ ) { _rtXdot -> ienzc5s5vc
[ rtP . AnalogFilterDesign1_A_ir_hrenrgccbq [ ri ] ] += rtP .
AnalogFilterDesign1_A_pr_h0kmy5bicq [ ri ] * rtX . ienzc5s5vc [ 1U ] ; } for
( ri = rtP . AnalogFilterDesign1_A_jc_lbh1btnh5f [ 2U ] ; ri < rtP .
AnalogFilterDesign1_A_jc_lbh1btnh5f [ 3U ] ; ri ++ ) { _rtXdot -> ienzc5s5vc
[ rtP . AnalogFilterDesign1_A_ir_hrenrgccbq [ ri ] ] += rtP .
AnalogFilterDesign1_A_pr_h0kmy5bicq [ ri ] * rtX . ienzc5s5vc [ 2U ] ; } for
( ri = rtP . AnalogFilterDesign1_B_jc_ghy2lei3av [ 0U ] ; ri < rtP .
AnalogFilterDesign1_B_jc_ghy2lei3av [ 1U ] ; ri ++ ) { _rtXdot -> ienzc5s5vc
[ rtP . AnalogFilterDesign1_B_ir_fpqzlg1kvc ] += rtP .
AnalogFilterDesign1_B_pr_ew5a2lr4t2 * rtB . j5g3qzjurz ; } _rtXdot ->
j1rganlm1m [ 0 ] = 0.0 ; _rtXdot -> j1rganlm1m [ 1 ] = 0.0 ; for ( ri = rtP .
AnalogFilterDesign_A_jc_odmcc04tok [ 0U ] ; ri < rtP .
AnalogFilterDesign_A_jc_odmcc04tok [ 1U ] ; ri ++ ) { _rtXdot -> j1rganlm1m [
rtP . AnalogFilterDesign_A_ir_dogadco1zw [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_esqpqjprtf [ ri ] * rtX . j1rganlm1m [ 0U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_odmcc04tok [ 1U ] ; ri < rtP .
AnalogFilterDesign_A_jc_odmcc04tok [ 2U ] ; ri ++ ) { _rtXdot -> j1rganlm1m [
rtP . AnalogFilterDesign_A_ir_dogadco1zw [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_esqpqjprtf [ ri ] * rtX . j1rganlm1m [ 1U ] ; } for (
ri = rtP . AnalogFilterDesign_B_jc_jbvp1zaaeo [ 0U ] ; ri < rtP .
AnalogFilterDesign_B_jc_jbvp1zaaeo [ 1U ] ; ri ++ ) { _rtXdot -> j1rganlm1m [
rtP . AnalogFilterDesign_B_ir_c20unw4tq1 ] += rtP .
AnalogFilterDesign_B_pr_l5d4110w1d * rtB . hqrlwn2gih ; } } void
MdlProjection ( void ) { } void MdlTerminate ( void ) { rt_FREE ( rtDW .
cwf0tqdxqc . RSimInfoPtr ) ; } static void mr_Square_HFI_cacheDataAsMxArray (
mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) ; static void mr_Square_HFI_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) {
mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_Square_HFI_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_Square_HFI_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_Square_HFI_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int
j , uint_T bitVal ) ; static void mr_Square_HFI_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( double )
bitVal ) ) ; } static uint_T mr_Square_HFI_extractBitFieldFromMxArray ( const
mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_Square_HFI_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_Square_HFI_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_Square_HFI_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Square_HFI_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_Square_HFI_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_Square_HFI_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_Square_HFI_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_Square_HFI_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_Square_HFI_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_Square_HFI_GetDWork ( ) { static const char *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW
= mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Square_HFI_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB )
, sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 18 ] = {
"rtDW.ixn3ky1f2r" , "rtDW.hxrufsyg2z" , "rtDW.bkcf3qca2q" , "rtDW.ejqmpqbi05"
, "rtDW.gkxlktnf2e" , "rtDW.bk0pvczvd4" , "rtDW.cfnq23qry5" ,
"rtDW.fsiptkwftx" , "rtDW.cfwppspejc" , "rtDW.nxdrt45sme" , "rtDW.abzut1gmtw"
, "rtDW.moosp1s1ah" , "rtDW.devpcih51d" , "rtDW.afdxa4jpho" ,
"rtDW.fjmelxecm4" , "rtDW.prwdcgjlej" , "rtDW.eohtar5htx" , "rtDW.estxwgqypi"
, } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 18 ,
rtdwDataFieldNames ) ; mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 0 ,
( const void * ) & ( rtDW . ixn3ky1f2r ) , sizeof ( rtDW . ixn3ky1f2r ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . hxrufsyg2z ) , sizeof ( rtDW . hxrufsyg2z ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . bkcf3qca2q ) , sizeof ( rtDW . bkcf3qca2q ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . ejqmpqbi05 ) , sizeof ( rtDW . ejqmpqbi05 ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . gkxlktnf2e ) , sizeof ( rtDW . gkxlktnf2e ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . bk0pvczvd4 ) , sizeof ( rtDW . bk0pvczvd4 ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . cfnq23qry5 ) , sizeof ( rtDW . cfnq23qry5 ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . fsiptkwftx ) , sizeof ( rtDW . fsiptkwftx ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . cfwppspejc ) , sizeof ( rtDW . cfwppspejc ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . nxdrt45sme ) , sizeof ( rtDW . nxdrt45sme ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
rtDW . abzut1gmtw ) , sizeof ( rtDW . abzut1gmtw ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
rtDW . moosp1s1ah ) , sizeof ( rtDW . moosp1s1ah ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
rtDW . devpcih51d ) , sizeof ( rtDW . devpcih51d ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & (
rtDW . afdxa4jpho ) , sizeof ( rtDW . afdxa4jpho ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & (
rtDW . fjmelxecm4 ) , sizeof ( rtDW . fjmelxecm4 ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & (
rtDW . prwdcgjlej ) , sizeof ( rtDW . prwdcgjlej ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & (
rtDW . eohtar5htx ) , sizeof ( rtDW . eohtar5htx ) ) ;
mr_Square_HFI_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & (
rtDW . estxwgqypi ) , sizeof ( rtDW . estxwgqypi ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_Square_HFI_SetDWork (
const mxArray * ssDW ) { ( void ) ssDW ; mr_Square_HFI_restoreDataFromMxArray
( ( void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ixn3ky1f2r ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . ixn3ky1f2r ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . hxrufsyg2z ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . hxrufsyg2z ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . bkcf3qca2q ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . bkcf3qca2q ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ejqmpqbi05 ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . ejqmpqbi05 ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . gkxlktnf2e ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . gkxlktnf2e ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . bk0pvczvd4 ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . bk0pvczvd4 ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . cfnq23qry5 ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . cfnq23qry5 ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . fsiptkwftx ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . fsiptkwftx ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . cfwppspejc ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . cfwppspejc ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . nxdrt45sme ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . nxdrt45sme ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . abzut1gmtw ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . abzut1gmtw ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . moosp1s1ah ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . moosp1s1ah ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . devpcih51d ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . devpcih51d ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . afdxa4jpho ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . afdxa4jpho ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . fjmelxecm4 ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . fjmelxecm4 ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . prwdcgjlej ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . prwdcgjlej ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . eohtar5htx ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . eohtar5htx ) ) ;
mr_Square_HFI_restoreDataFromMxArray ( ( void * ) & ( rtDW . estxwgqypi ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . estxwgqypi ) ) ; } } mxArray *
mr_Square_HFI_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 10 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , "Scope" , "Scope" , "Scope" , } ; static const char *
blockPath [ 10 ] = { "Square_HFI/Scope1" , "Square_HFI/Scope2" ,
"Square_HFI/Scope3" , "Square_HFI/FOC_Mode/HFI_Mode/Scope1" ,
"Square_HFI/FOC_Mode/HFI_Mode/Scope10" ,
"Square_HFI/FOC_Mode/HFI_Mode/Scope11" ,
"Square_HFI/FOC_Mode/HFI_Mode/Scope12" ,
"Square_HFI/FOC_Mode/HFI_Mode/Scope13" ,
"Square_HFI/FOC_Mode/HFI_Mode/Scope14" ,
"Square_HFI/FOC_Mode/HFI_Mode/Scope2" , } ; static const int reason [ 10 ] =
{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0
] < 10 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 32 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 384 ) ; ssSetNumBlockIO ( rtS , 92 ) ;
ssSetNumBlockParams ( rtS , 401 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 1.0E-9 ) ;
ssSetSampleTime ( rtS , 2 , 0.0001 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 141128117U ) ;
ssSetChecksumVal ( rtS , 1 , 3368571104U ) ; ssSetChecksumVal ( rtS , 2 ,
3117770537U ) ; ssSetChecksumVal ( rtS , 3 , 2825097179U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 24 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
Square_HFI_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "Square_HFI" ) ;
ssSetPath ( rtS , "Square_HFI" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 10.0 ) ; ssSetStepSize ( rtS , 1.0E-9 ) ; ssSetFixedStepSize ( rtS ,
1.0E-9 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 3 , 3 , 3 , 6 , 6 , 6 , 3 , 2
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 3 ,
3 , 3 , 6 , 6 , 6 , 3 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_SINGLE , SS_SINGLE , SS_SINGLE ,
SS_SINGLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog\nFilter Design" ,
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog\nFilter Design1" ,
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog\nFilter Design2" ,
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog\nFilter Design3" ,
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog\nFilter Design4" ,
"Square_HFI/FOC_Mode/HFI_Mode/LPF/Analog\nFilter Design5" ,
"Square_HFI/FOC_Mode/HFI_Mode/Pre/Analog\nFilter Design1" ,
"Square_HFI/FOC_Mode/HFI_Mode/LF/Analog\nFilter Design" ,
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Discrete-Time\nIntegrator3"
,
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Unit Delay"
,
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Discrete-Time\nIntegrator3"
,
 "Square_HFI/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Discrete-Time\nIntegrator"
, "Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time\nIntegrator1" ,
 "Square_HFI/FOC_Mode/HFI_Mode/Speed_PI_Controller/PID Controller3/Integrator/Discrete/Integrator"
,
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller2/Integrator/Discrete/Integrator"
, "Square_HFI/FOC_Mode/HFI_Mode/Pre/Discrete-Time\nIntegrator" ,
 "Square_HFI/FOC_Mode/HFI_Mode/Curr_PI_Controller/PID Controller1/Integrator/Discrete/Integrator"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_SINGLE , SS_SINGLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_SINGLE ,
SS_SINGLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_SINGLE , SS_SINGLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_SINGLE , SS_SINGLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 1 , SS_DOUBLE , SS_INT16 , 64 , 1 , 1 , 1.073741824 , - 30 , 0.0 }
} ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7
, 0 , 1 , 2 , 3 , 36 , 37 , 38 , 39 , 47 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 17 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 17 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . lags33bb22 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . f13vaq3gr5 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . pgteej05bs [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . ejepwxaus4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . hgersqr5ev [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . ic5giadsig [ 0 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . ienzc5s5vc [ 0 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . j1rganlm1m [ 0 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . ixn3ky1f2r ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtDW . hxrufsyg2z ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . bkcf3qca2q ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtDW . ejqmpqbi05 ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtDW . gkxlktnf2e ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtDW . bk0pvczvd4 ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtDW . cfnq23qry5 ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtDW . fsiptkwftx ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtDW . prwdcgjlej ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 32 ] ;
static ssNonContDerivSigInfo nonContDerivSigInfo [ 9 ] = { { 1 * sizeof (
real32_T ) , ( char * ) ( & rtB . bt3fcv3v3w ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . hqgkqxg4zr ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . logsazcj2d ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . ajtg2x2b41 ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . lwjmxasb2z ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . oy1uirggpc ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . jeobpjpcy3 ) , ( NULL ) } , { 1 * sizeof (
real32_T ) , ( char * ) ( & rtB . hfw2v3eciw ) , ( NULL ) } , { 1 * sizeof (
real32_T ) , ( char * ) ( & rtB . czad505sp3 ) , ( NULL ) } } ;
ssSetNumNonContDerivSigInfos ( rtS , 9 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode3" ) ; ssSetVariableStepSolver ( rtS , 0 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelUpdate ( rtS , MdlUpdate )
; ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS ,
INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 141128117U ) ;
ssSetChecksumVal ( rtS , 1 , 3368571104U ) ; ssSetChecksumVal ( rtS , 2 ,
3117770537U ) ; ssSetChecksumVal ( rtS , 3 , 2825097179U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 8 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Square_HFI_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_Square_HFI_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_Square_HFI_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
