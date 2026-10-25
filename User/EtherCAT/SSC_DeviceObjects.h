/**
* \addtogroup SSC_Device SSC_Device
* @{
*/

/**
\file SSC_DeviceObjects
\author ET9300Utilities.ApplicationHandler (Version 1.3.6.0) | EthercatSSC@beckhoff.com

\brief SSC_Device specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : PDOChannel process data mapping
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | PDOChannel process data mapping
* @{
* \brief Object 0x1600 (PDOChannel process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7000.1<br>
* SubIndex 2 - Reference to 0x7000.2<br>
* SubIndex 3 - Reference to 0x7000.3<br>
* SubIndex 4 - Reference to 0x7000.4<br>
* SubIndex 5 - Reference to 0x7000.5<br>
* SubIndex 6 - Reference to 0x7000.6<br>
* SubIndex 7 - Reference to 0x7000.7<br>
* SubIndex 8 - Reference to 0x7000.8<br>
* SubIndex 9 - Reference to 0x7000.9<br>
* SubIndex 10 - Reference to 0x7000.10<br>
* SubIndex 11 - Reference to 0x7000.11<br>
* SubIndex 12 - Reference to 0x7000.12<br>
* SubIndex 13 - Reference to 0x7000.13<br>
* SubIndex 14 - Reference to 0x7000.14<br>
* SubIndex 15 - Reference to 0x7000.15<br>
* SubIndex 16 - Reference to 0x7000.16<br>
* SubIndex 17 - Reference to 0x7000.17<br>
* SubIndex 18 - Reference to 0x7000.18<br>
* SubIndex 19 - Reference to 0x7000.19<br>
* SubIndex 20 - Reference to 0x7000.20<br>
* SubIndex 21 - Reference to 0x7000.21<br>
* SubIndex 22 - Reference to 0x7000.22<br>
* SubIndex 23 - Reference to 0x7000.23<br>
* SubIndex 24 - Reference to 0x7000.24<br>
* SubIndex 25 - Reference to 0x7000.25<br>
* SubIndex 26 - Reference to 0x7000.26<br>
* SubIndex 27 - Reference to 0x7000.27<br>
* SubIndex 28 - Reference to 0x7000.28<br>
* SubIndex 29 - Reference to 0x7000.29<br>
* SubIndex 30 - Reference to 0x7000.30<br>
* SubIndex 31 - Reference to 0x7000.31<br>
* SubIndex 32 - Reference to 0x7000.32<br>
* SubIndex 33 - Reference to 0x7000.33<br>
* SubIndex 34 - Reference to 0x7000.34<br>
* SubIndex 35 - Reference to 0x7000.35<br>
* SubIndex 36 - Reference to 0x7000.36<br>
* SubIndex 37 - Reference to 0x7000.37<br>
* SubIndex 38 - Reference to 0x7000.38<br>
* SubIndex 39 - Reference to 0x7000.39<br>
* SubIndex 40 - Reference to 0x7000.40<br>
* SubIndex 41 - Reference to 0x7000.41<br>
* SubIndex 42 - Reference to 0x7000.42<br>
* SubIndex 43 - Reference to 0x7000.43<br>
* SubIndex 44 - Reference to 0x7000.44<br>
* SubIndex 45 - Reference to 0x7000.45<br>
* SubIndex 46 - Reference to 0x7000.46<br>
* SubIndex 47 - Reference to 0x7000.47<br>
* SubIndex 48 - Reference to 0x7000.48<br>
* SubIndex 49 - Reference to 0x7000.49<br>
* SubIndex 50 - Reference to 0x7000.50<br>
* SubIndex 51 - Reference to 0x7000.51<br>
* SubIndex 52 - Reference to 0x7000.52<br>
* SubIndex 53 - Reference to 0x7000.53<br>
* SubIndex 54 - Reference to 0x7000.54<br>
* SubIndex 55 - Reference to 0x7000.55<br>
* SubIndex 56 - Reference to 0x7000.56<br>
* SubIndex 57 - Reference to 0x7000.57<br>
* SubIndex 58 - Reference to 0x7000.58<br>
* SubIndex 59 - Reference to 0x7000.59<br>
* SubIndex 60 - Reference to 0x7000.60<br>
* SubIndex 61 - Reference to 0x7000.61<br>
* SubIndex 62 - Reference to 0x7000.62<br>
* SubIndex 63 - Reference to 0x7000.63<br>
* SubIndex 64 - Reference to 0x7000.64<br>
* SubIndex 65 - Reference to 0x7000.65<br>
* SubIndex 66 - Reference to 0x7000.66<br>
* SubIndex 67 - Reference to 0x7000.67<br>
* SubIndex 68 - Reference to 0x7000.68<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x7000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x7000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x7000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x7000.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x7000.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x7000.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x7000.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x7000.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x7000.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x7000.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x7000.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x7000.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x7000.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x7000.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x7000.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x7000.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x7000.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x7000.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x7000.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x7000.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x7000.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x7000.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x7000.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 - Reference to 0x7000.25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 - Reference to 0x7000.26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 - Reference to 0x7000.27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 - Reference to 0x7000.28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 - Reference to 0x7000.29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 - Reference to 0x7000.30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 - Reference to 0x7000.31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 - Reference to 0x7000.32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 - Reference to 0x7000.33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 - Reference to 0x7000.34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 - Reference to 0x7000.35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 - Reference to 0x7000.36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 - Reference to 0x7000.37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 - Reference to 0x7000.38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 - Reference to 0x7000.39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 - Reference to 0x7000.40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 - Reference to 0x7000.41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 - Reference to 0x7000.42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 - Reference to 0x7000.43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 - Reference to 0x7000.44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 - Reference to 0x7000.45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 - Reference to 0x7000.46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 - Reference to 0x7000.47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 - Reference to 0x7000.48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 - Reference to 0x7000.49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 - Reference to 0x7000.50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 - Reference to 0x7000.51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 - Reference to 0x7000.52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 - Reference to 0x7000.53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 - Reference to 0x7000.54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 - Reference to 0x7000.55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 - Reference to 0x7000.56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 - Reference to 0x7000.57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 - Reference to 0x7000.58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 - Reference to 0x7000.59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 - Reference to 0x7000.60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 - Reference to 0x7000.61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 - Reference to 0x7000.62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 - Reference to 0x7000.63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 - Reference to 0x7000.64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 - Reference to 0x7000.65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 - Reference to 0x7000.66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 - Reference to 0x7000.67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex68 - Reference to 0x7000.68 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "PDOChannel process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x7000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x7000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x7000.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x7000.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x7000.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x7000.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x7000.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x7000.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x7000.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x7000.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x7000.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x7000.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x7000.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x7000.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x7000.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x7000.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x7000.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x7000.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x7000.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x7000.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x7000.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x7000.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x7000.25 */
UINT32 SI26; /* Subindex26 - Reference to 0x7000.26 */
UINT32 SI27; /* Subindex27 - Reference to 0x7000.27 */
UINT32 SI28; /* Subindex28 - Reference to 0x7000.28 */
UINT32 SI29; /* Subindex29 - Reference to 0x7000.29 */
UINT32 SI30; /* Subindex30 - Reference to 0x7000.30 */
UINT32 SI31; /* Subindex31 - Reference to 0x7000.31 */
UINT32 SI32; /* Subindex32 - Reference to 0x7000.32 */
UINT32 SI33; /* Subindex33 - Reference to 0x7000.33 */
UINT32 SI34; /* Subindex34 - Reference to 0x7000.34 */
UINT32 SI35; /* Subindex35 - Reference to 0x7000.35 */
UINT32 SI36; /* Subindex36 - Reference to 0x7000.36 */
UINT32 SI37; /* Subindex37 - Reference to 0x7000.37 */
UINT32 SI38; /* Subindex38 - Reference to 0x7000.38 */
UINT32 SI39; /* Subindex39 - Reference to 0x7000.39 */
UINT32 SI40; /* Subindex40 - Reference to 0x7000.40 */
UINT32 SI41; /* Subindex41 - Reference to 0x7000.41 */
UINT32 SI42; /* Subindex42 - Reference to 0x7000.42 */
UINT32 SI43; /* Subindex43 - Reference to 0x7000.43 */
UINT32 SI44; /* Subindex44 - Reference to 0x7000.44 */
UINT32 SI45; /* Subindex45 - Reference to 0x7000.45 */
UINT32 SI46; /* Subindex46 - Reference to 0x7000.46 */
UINT32 SI47; /* Subindex47 - Reference to 0x7000.47 */
UINT32 SI48; /* Subindex48 - Reference to 0x7000.48 */
UINT32 SI49; /* Subindex49 - Reference to 0x7000.49 */
UINT32 SI50; /* Subindex50 - Reference to 0x7000.50 */
UINT32 SI51; /* Subindex51 - Reference to 0x7000.51 */
UINT32 SI52; /* Subindex52 - Reference to 0x7000.52 */
UINT32 SI53; /* Subindex53 - Reference to 0x7000.53 */
UINT32 SI54; /* Subindex54 - Reference to 0x7000.54 */
UINT32 SI55; /* Subindex55 - Reference to 0x7000.55 */
UINT32 SI56; /* Subindex56 - Reference to 0x7000.56 */
UINT32 SI57; /* Subindex57 - Reference to 0x7000.57 */
UINT32 SI58; /* Subindex58 - Reference to 0x7000.58 */
UINT32 SI59; /* Subindex59 - Reference to 0x7000.59 */
UINT32 SI60; /* Subindex60 - Reference to 0x7000.60 */
UINT32 SI61; /* Subindex61 - Reference to 0x7000.61 */
UINT32 SI62; /* Subindex62 - Reference to 0x7000.62 */
UINT32 SI63; /* Subindex63 - Reference to 0x7000.63 */
UINT32 SI64; /* Subindex64 - Reference to 0x7000.64 */
UINT32 SI65; /* Subindex65 - Reference to 0x7000.65 */
UINT32 SI66; /* Subindex66 - Reference to 0x7000.66 */
UINT32 SI67; /* Subindex67 - Reference to 0x7000.67 */
UINT32 SI68; /* Subindex68 - Reference to 0x7000.68 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 PDOChannelProcessDataMapping0x1600
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={68,0x70000108,0x70000208,0x70000308,0x70000408,0x70000508,0x70000608,0x70000708,0x70000808,0x70000908,0x70000A08,0x70000B08,0x70000C08,0x70000D08,0x70000E08,0x70000F08,0x70001008,0x70001108,0x70001208,0x70001308,0x70001408,0x70001508,0x70001608,0x70001708,0x70001808,0x70001908,0x70001A08,0x70001B08,0x70001C08,0x70001D08,0x70001E08,0x70001F08,0x70002008,0x70002108,0x70002208,0x70002308,0x70002408,0x70002508,0x70002608,0x70002708,0x70002808,0x70002908,0x70002A08,0x70002B08,0x70002C08,0x70002D08,0x70002E08,0x70002F08,0x70003008,0x70003108,0x70003208,0x70003308,0x70003408,0x70003508,0x70003608,0x70003708,0x70003808,0x70003908,0x70003A08,0x70003B08,0x70003C08,0x70003D08,0x70003E08,0x70003F08,0x70004008,0x70004108,0x70004208,0x70004308,0x70004408}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1605 : RMUIPDOChannel process data mapping
******************************************************************************/
/**
* \addtogroup 0x1605 0x1605 | RMUIPDOChannel process data mapping
* @{
* \brief Object 0x1605 (RMUIPDOChannel process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7050.1<br>
* SubIndex 2 - Reference to 0x7050.2<br>
* SubIndex 3 - Reference to 0x7050.3<br>
* SubIndex 4 - Reference to 0x7050.4<br>
* SubIndex 5 - Reference to 0x7050.5<br>
* SubIndex 6 - Reference to 0x7050.6<br>
* SubIndex 7 - Reference to 0x7050.7<br>
* SubIndex 8 - Reference to 0x7050.8<br>
* SubIndex 9 - Reference to 0x7050.9<br>
* SubIndex 10 - Reference to 0x7050.10<br>
* SubIndex 11 - Reference to 0x7050.11<br>
* SubIndex 12 - Reference to 0x7050.12<br>
* SubIndex 13 - Reference to 0x7050.13<br>
* SubIndex 14 - Reference to 0x7050.14<br>
* SubIndex 15 - Reference to 0x7050.15<br>
* SubIndex 16 - Reference to 0x7050.16<br>
* SubIndex 17 - Reference to 0x7050.17<br>
* SubIndex 18 - Reference to 0x7050.18<br>
* SubIndex 19 - Reference to 0x7050.19<br>
* SubIndex 20 - Reference to 0x7050.20<br>
* SubIndex 21 - Reference to 0x7050.21<br>
* SubIndex 22 - Reference to 0x7050.22<br>
* SubIndex 23 - Reference to 0x7050.23<br>
* SubIndex 24 - Reference to 0x7050.24<br>
* SubIndex 25 - Reference to 0x7050.25<br>
* SubIndex 26 - Reference to 0x7050.26<br>
* SubIndex 27 - Reference to 0x7050.27<br>
* SubIndex 28 - Reference to 0x7050.28<br>
* SubIndex 29 - Reference to 0x7050.29<br>
* SubIndex 30 - Reference to 0x7050.30<br>
* SubIndex 31 - Reference to 0x7050.31<br>
* SubIndex 32 - Reference to 0x7050.32<br>
* SubIndex 33 - Reference to 0x7050.33<br>
* SubIndex 34 - Reference to 0x7050.34<br>
* SubIndex 35 - Reference to 0x7050.35<br>
* SubIndex 36 - Reference to 0x7050.36<br>
* SubIndex 37 - Reference to 0x7050.37<br>
* SubIndex 38 - Reference to 0x7050.38<br>
* SubIndex 39 - Reference to 0x7050.39<br>
* SubIndex 40 - Reference to 0x7050.40<br>
* SubIndex 41 - Reference to 0x7050.41<br>
* SubIndex 42 - Reference to 0x7050.42<br>
* SubIndex 43 - Reference to 0x7050.43<br>
* SubIndex 44 - Reference to 0x7050.44<br>
* SubIndex 45 - Reference to 0x7050.45<br>
* SubIndex 46 - Reference to 0x7050.46<br>
* SubIndex 47 - Reference to 0x7050.47<br>
* SubIndex 48 - Reference to 0x7050.48<br>
* SubIndex 49 - Reference to 0x7050.49<br>
* SubIndex 50 - Reference to 0x7050.50<br>
* SubIndex 51 - Reference to 0x7050.51<br>
* SubIndex 52 - Reference to 0x7050.52<br>
* SubIndex 53 - Reference to 0x7050.53<br>
* SubIndex 54 - Reference to 0x7050.54<br>
* SubIndex 55 - Reference to 0x7050.55<br>
* SubIndex 56 - Reference to 0x7050.56<br>
* SubIndex 57 - Reference to 0x7050.57<br>
* SubIndex 58 - Reference to 0x7050.58<br>
* SubIndex 59 - Reference to 0x7050.59<br>
* SubIndex 60 - Reference to 0x7050.60<br>
* SubIndex 61 - Reference to 0x7050.61<br>
* SubIndex 62 - Reference to 0x7050.62<br>
* SubIndex 63 - Reference to 0x7050.63<br>
* SubIndex 64 - Reference to 0x7050.64<br>
* SubIndex 65 - Reference to 0x7050.65<br>
* SubIndex 66 - Reference to 0x7050.66<br>
* SubIndex 67 - Reference to 0x7050.67<br>
* SubIndex 68 - Reference to 0x7050.68<br>
* SubIndex 69 - Reference to 0x7050.69<br>
* SubIndex 70 - Reference to 0x7050.70<br>
* SubIndex 71 - Reference to 0x7050.71<br>
* SubIndex 72 - Reference to 0x7050.72<br>
* SubIndex 73 - Reference to 0x7050.73<br>
* SubIndex 74 - Reference to 0x7050.74<br>
* SubIndex 75 - Reference to 0x7050.75<br>
* SubIndex 76 - Reference to 0x7050.76<br>
* SubIndex 77 - Reference to 0x7050.77<br>
* SubIndex 78 - Reference to 0x7050.78<br>
* SubIndex 79 - Reference to 0x7050.79<br>
* SubIndex 80 - Reference to 0x7050.80<br>
* SubIndex 81 - Reference to 0x7050.81<br>
* SubIndex 82 - Reference to 0x7050.82<br>
* SubIndex 83 - Reference to 0x7050.83<br>
* SubIndex 84 - Reference to 0x7050.84<br>
* SubIndex 85 - Reference to 0x7050.85<br>
* SubIndex 86 - Reference to 0x7050.86<br>
* SubIndex 87 - Reference to 0x7050.87<br>
* SubIndex 88 - Reference to 0x7050.88<br>
* SubIndex 89 - Reference to 0x7050.89<br>
* SubIndex 90 - Reference to 0x7050.90<br>
* SubIndex 91 - Reference to 0x7050.91<br>
* SubIndex 92 - Reference to 0x7050.92<br>
* SubIndex 93 - Reference to 0x7050.93<br>
* SubIndex 94 - Reference to 0x7050.94<br>
* SubIndex 95 - Reference to 0x7050.95<br>
* SubIndex 96 - Reference to 0x7050.96<br>
* SubIndex 97 - Reference to 0x7050.97<br>
* SubIndex 98 - Reference to 0x7050.98<br>
* SubIndex 99 - Reference to 0x7050.99<br>
* SubIndex 100 - Reference to 0x7050.100<br>
* SubIndex 101 - Reference to 0x7050.101<br>
* SubIndex 102 - Reference to 0x7050.102<br>
* SubIndex 103 - Reference to 0x7050.103<br>
* SubIndex 104 - Reference to 0x7050.104<br>
* SubIndex 105 - Reference to 0x7050.105<br>
* SubIndex 106 - Reference to 0x7050.106<br>
* SubIndex 107 - Reference to 0x7050.107<br>
* SubIndex 108 - Reference to 0x7050.108<br>
* SubIndex 109 - Reference to 0x7050.109<br>
* SubIndex 110 - Reference to 0x7050.110<br>
* SubIndex 111 - Reference to 0x7050.111<br>
* SubIndex 112 - Reference to 0x7050.112<br>
* SubIndex 113 - Reference to 0x7050.113<br>
* SubIndex 114 - Reference to 0x7050.114<br>
* SubIndex 115 - Reference to 0x7050.115<br>
* SubIndex 116 - Reference to 0x7050.116<br>
* SubIndex 117 - Reference to 0x7050.117<br>
* SubIndex 118 - Reference to 0x7050.118<br>
* SubIndex 119 - Reference to 0x7050.119<br>
* SubIndex 120 - Reference to 0x7050.120<br>
* SubIndex 121 - Reference to 0x7050.121<br>
* SubIndex 122 - Reference to 0x7050.122<br>
* SubIndex 123 - Reference to 0x7050.123<br>
* SubIndex 124 - Reference to 0x7050.124<br>
* SubIndex 125 - Reference to 0x7050.125<br>
* SubIndex 126 - Reference to 0x7050.126<br>
* SubIndex 127 - Reference to 0x7050.127<br>
* SubIndex 128 - Reference to 0x7050.128<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1605[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7050.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x7050.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x7050.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x7050.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x7050.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x7050.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x7050.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x7050.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x7050.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x7050.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x7050.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x7050.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x7050.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x7050.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x7050.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x7050.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x7050.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x7050.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x7050.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x7050.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x7050.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x7050.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x7050.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x7050.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 - Reference to 0x7050.25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 - Reference to 0x7050.26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 - Reference to 0x7050.27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 - Reference to 0x7050.28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 - Reference to 0x7050.29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 - Reference to 0x7050.30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 - Reference to 0x7050.31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 - Reference to 0x7050.32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 - Reference to 0x7050.33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 - Reference to 0x7050.34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 - Reference to 0x7050.35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 - Reference to 0x7050.36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 - Reference to 0x7050.37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 - Reference to 0x7050.38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 - Reference to 0x7050.39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 - Reference to 0x7050.40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 - Reference to 0x7050.41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 - Reference to 0x7050.42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 - Reference to 0x7050.43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 - Reference to 0x7050.44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 - Reference to 0x7050.45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 - Reference to 0x7050.46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 - Reference to 0x7050.47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 - Reference to 0x7050.48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 - Reference to 0x7050.49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 - Reference to 0x7050.50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 - Reference to 0x7050.51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 - Reference to 0x7050.52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 - Reference to 0x7050.53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 - Reference to 0x7050.54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 - Reference to 0x7050.55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 - Reference to 0x7050.56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 - Reference to 0x7050.57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 - Reference to 0x7050.58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 - Reference to 0x7050.59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 - Reference to 0x7050.60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 - Reference to 0x7050.61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 - Reference to 0x7050.62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 - Reference to 0x7050.63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 - Reference to 0x7050.64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 - Reference to 0x7050.65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 - Reference to 0x7050.66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 - Reference to 0x7050.67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 - Reference to 0x7050.68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 - Reference to 0x7050.69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 - Reference to 0x7050.70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 - Reference to 0x7050.71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 - Reference to 0x7050.72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 - Reference to 0x7050.73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 - Reference to 0x7050.74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 - Reference to 0x7050.75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 - Reference to 0x7050.76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 - Reference to 0x7050.77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 - Reference to 0x7050.78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 - Reference to 0x7050.79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 - Reference to 0x7050.80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 - Reference to 0x7050.81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 - Reference to 0x7050.82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 - Reference to 0x7050.83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 - Reference to 0x7050.84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 - Reference to 0x7050.85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 - Reference to 0x7050.86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 - Reference to 0x7050.87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 - Reference to 0x7050.88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 - Reference to 0x7050.89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 - Reference to 0x7050.90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 - Reference to 0x7050.91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 - Reference to 0x7050.92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 - Reference to 0x7050.93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 - Reference to 0x7050.94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 - Reference to 0x7050.95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 - Reference to 0x7050.96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 - Reference to 0x7050.97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 - Reference to 0x7050.98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 - Reference to 0x7050.99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 - Reference to 0x7050.100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 - Reference to 0x7050.101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 - Reference to 0x7050.102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 - Reference to 0x7050.103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 - Reference to 0x7050.104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 - Reference to 0x7050.105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 - Reference to 0x7050.106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 - Reference to 0x7050.107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 - Reference to 0x7050.108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 - Reference to 0x7050.109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 - Reference to 0x7050.110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 - Reference to 0x7050.111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 - Reference to 0x7050.112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 - Reference to 0x7050.113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 - Reference to 0x7050.114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex115 - Reference to 0x7050.115 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex116 - Reference to 0x7050.116 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex117 - Reference to 0x7050.117 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex118 - Reference to 0x7050.118 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex119 - Reference to 0x7050.119 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex120 - Reference to 0x7050.120 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex121 - Reference to 0x7050.121 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex122 - Reference to 0x7050.122 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex123 - Reference to 0x7050.123 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex124 - Reference to 0x7050.124 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex125 - Reference to 0x7050.125 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex126 - Reference to 0x7050.126 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex127 - Reference to 0x7050.127 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex128 - Reference to 0x7050.128 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1605[] = "RMUIPDOChannel process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000"
"SubIndex 069\000"
"SubIndex 070\000"
"SubIndex 071\000"
"SubIndex 072\000"
"SubIndex 073\000"
"SubIndex 074\000"
"SubIndex 075\000"
"SubIndex 076\000"
"SubIndex 077\000"
"SubIndex 078\000"
"SubIndex 079\000"
"SubIndex 080\000"
"SubIndex 081\000"
"SubIndex 082\000"
"SubIndex 083\000"
"SubIndex 084\000"
"SubIndex 085\000"
"SubIndex 086\000"
"SubIndex 087\000"
"SubIndex 088\000"
"SubIndex 089\000"
"SubIndex 090\000"
"SubIndex 091\000"
"SubIndex 092\000"
"SubIndex 093\000"
"SubIndex 094\000"
"SubIndex 095\000"
"SubIndex 096\000"
"SubIndex 097\000"
"SubIndex 098\000"
"SubIndex 099\000"
"SubIndex 100\000"
"SubIndex 101\000"
"SubIndex 102\000"
"SubIndex 103\000"
"SubIndex 104\000"
"SubIndex 105\000"
"SubIndex 106\000"
"SubIndex 107\000"
"SubIndex 108\000"
"SubIndex 109\000"
"SubIndex 110\000"
"SubIndex 111\000"
"SubIndex 112\000"
"SubIndex 113\000"
"SubIndex 114\000"
"SubIndex 115\000"
"SubIndex 116\000"
"SubIndex 117\000"
"SubIndex 118\000"
"SubIndex 119\000"
"SubIndex 120\000"
"SubIndex 121\000"
"SubIndex 122\000"
"SubIndex 123\000"
"SubIndex 124\000"
"SubIndex 125\000"
"SubIndex 126\000"
"SubIndex 127\000"
"SubIndex 128\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7050.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7050.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x7050.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x7050.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x7050.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x7050.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x7050.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x7050.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x7050.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x7050.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x7050.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x7050.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x7050.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x7050.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x7050.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x7050.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x7050.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x7050.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x7050.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x7050.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x7050.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x7050.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x7050.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x7050.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x7050.25 */
UINT32 SI26; /* Subindex26 - Reference to 0x7050.26 */
UINT32 SI27; /* Subindex27 - Reference to 0x7050.27 */
UINT32 SI28; /* Subindex28 - Reference to 0x7050.28 */
UINT32 SI29; /* Subindex29 - Reference to 0x7050.29 */
UINT32 SI30; /* Subindex30 - Reference to 0x7050.30 */
UINT32 SI31; /* Subindex31 - Reference to 0x7050.31 */
UINT32 SI32; /* Subindex32 - Reference to 0x7050.32 */
UINT32 SI33; /* Subindex33 - Reference to 0x7050.33 */
UINT32 SI34; /* Subindex34 - Reference to 0x7050.34 */
UINT32 SI35; /* Subindex35 - Reference to 0x7050.35 */
UINT32 SI36; /* Subindex36 - Reference to 0x7050.36 */
UINT32 SI37; /* Subindex37 - Reference to 0x7050.37 */
UINT32 SI38; /* Subindex38 - Reference to 0x7050.38 */
UINT32 SI39; /* Subindex39 - Reference to 0x7050.39 */
UINT32 SI40; /* Subindex40 - Reference to 0x7050.40 */
UINT32 SI41; /* Subindex41 - Reference to 0x7050.41 */
UINT32 SI42; /* Subindex42 - Reference to 0x7050.42 */
UINT32 SI43; /* Subindex43 - Reference to 0x7050.43 */
UINT32 SI44; /* Subindex44 - Reference to 0x7050.44 */
UINT32 SI45; /* Subindex45 - Reference to 0x7050.45 */
UINT32 SI46; /* Subindex46 - Reference to 0x7050.46 */
UINT32 SI47; /* Subindex47 - Reference to 0x7050.47 */
UINT32 SI48; /* Subindex48 - Reference to 0x7050.48 */
UINT32 SI49; /* Subindex49 - Reference to 0x7050.49 */
UINT32 SI50; /* Subindex50 - Reference to 0x7050.50 */
UINT32 SI51; /* Subindex51 - Reference to 0x7050.51 */
UINT32 SI52; /* Subindex52 - Reference to 0x7050.52 */
UINT32 SI53; /* Subindex53 - Reference to 0x7050.53 */
UINT32 SI54; /* Subindex54 - Reference to 0x7050.54 */
UINT32 SI55; /* Subindex55 - Reference to 0x7050.55 */
UINT32 SI56; /* Subindex56 - Reference to 0x7050.56 */
UINT32 SI57; /* Subindex57 - Reference to 0x7050.57 */
UINT32 SI58; /* Subindex58 - Reference to 0x7050.58 */
UINT32 SI59; /* Subindex59 - Reference to 0x7050.59 */
UINT32 SI60; /* Subindex60 - Reference to 0x7050.60 */
UINT32 SI61; /* Subindex61 - Reference to 0x7050.61 */
UINT32 SI62; /* Subindex62 - Reference to 0x7050.62 */
UINT32 SI63; /* Subindex63 - Reference to 0x7050.63 */
UINT32 SI64; /* Subindex64 - Reference to 0x7050.64 */
UINT32 SI65; /* Subindex65 - Reference to 0x7050.65 */
UINT32 SI66; /* Subindex66 - Reference to 0x7050.66 */
UINT32 SI67; /* Subindex67 - Reference to 0x7050.67 */
UINT32 SI68; /* Subindex68 - Reference to 0x7050.68 */
UINT32 SI69; /* Subindex69 - Reference to 0x7050.69 */
UINT32 SI70; /* Subindex70 - Reference to 0x7050.70 */
UINT32 SI71; /* Subindex71 - Reference to 0x7050.71 */
UINT32 SI72; /* Subindex72 - Reference to 0x7050.72 */
UINT32 SI73; /* Subindex73 - Reference to 0x7050.73 */
UINT32 SI74; /* Subindex74 - Reference to 0x7050.74 */
UINT32 SI75; /* Subindex75 - Reference to 0x7050.75 */
UINT32 SI76; /* Subindex76 - Reference to 0x7050.76 */
UINT32 SI77; /* Subindex77 - Reference to 0x7050.77 */
UINT32 SI78; /* Subindex78 - Reference to 0x7050.78 */
UINT32 SI79; /* Subindex79 - Reference to 0x7050.79 */
UINT32 SI80; /* Subindex80 - Reference to 0x7050.80 */
UINT32 SI81; /* Subindex81 - Reference to 0x7050.81 */
UINT32 SI82; /* Subindex82 - Reference to 0x7050.82 */
UINT32 SI83; /* Subindex83 - Reference to 0x7050.83 */
UINT32 SI84; /* Subindex84 - Reference to 0x7050.84 */
UINT32 SI85; /* Subindex85 - Reference to 0x7050.85 */
UINT32 SI86; /* Subindex86 - Reference to 0x7050.86 */
UINT32 SI87; /* Subindex87 - Reference to 0x7050.87 */
UINT32 SI88; /* Subindex88 - Reference to 0x7050.88 */
UINT32 SI89; /* Subindex89 - Reference to 0x7050.89 */
UINT32 SI90; /* Subindex90 - Reference to 0x7050.90 */
UINT32 SI91; /* Subindex91 - Reference to 0x7050.91 */
UINT32 SI92; /* Subindex92 - Reference to 0x7050.92 */
UINT32 SI93; /* Subindex93 - Reference to 0x7050.93 */
UINT32 SI94; /* Subindex94 - Reference to 0x7050.94 */
UINT32 SI95; /* Subindex95 - Reference to 0x7050.95 */
UINT32 SI96; /* Subindex96 - Reference to 0x7050.96 */
UINT32 SI97; /* Subindex97 - Reference to 0x7050.97 */
UINT32 SI98; /* Subindex98 - Reference to 0x7050.98 */
UINT32 SI99; /* Subindex99 - Reference to 0x7050.99 */
UINT32 SI100; /* Subindex100 - Reference to 0x7050.100 */
UINT32 SI101; /* Subindex101 - Reference to 0x7050.101 */
UINT32 SI102; /* Subindex102 - Reference to 0x7050.102 */
UINT32 SI103; /* Subindex103 - Reference to 0x7050.103 */
UINT32 SI104; /* Subindex104 - Reference to 0x7050.104 */
UINT32 SI105; /* Subindex105 - Reference to 0x7050.105 */
UINT32 SI106; /* Subindex106 - Reference to 0x7050.106 */
UINT32 SI107; /* Subindex107 - Reference to 0x7050.107 */
UINT32 SI108; /* Subindex108 - Reference to 0x7050.108 */
UINT32 SI109; /* Subindex109 - Reference to 0x7050.109 */
UINT32 SI110; /* Subindex110 - Reference to 0x7050.110 */
UINT32 SI111; /* Subindex111 - Reference to 0x7050.111 */
UINT32 SI112; /* Subindex112 - Reference to 0x7050.112 */
UINT32 SI113; /* Subindex113 - Reference to 0x7050.113 */
UINT32 SI114; /* Subindex114 - Reference to 0x7050.114 */
UINT32 SI115; /* Subindex115 - Reference to 0x7050.115 */
UINT32 SI116; /* Subindex116 - Reference to 0x7050.116 */
UINT32 SI117; /* Subindex117 - Reference to 0x7050.117 */
UINT32 SI118; /* Subindex118 - Reference to 0x7050.118 */
UINT32 SI119; /* Subindex119 - Reference to 0x7050.119 */
UINT32 SI120; /* Subindex120 - Reference to 0x7050.120 */
UINT32 SI121; /* Subindex121 - Reference to 0x7050.121 */
UINT32 SI122; /* Subindex122 - Reference to 0x7050.122 */
UINT32 SI123; /* Subindex123 - Reference to 0x7050.123 */
UINT32 SI124; /* Subindex124 - Reference to 0x7050.124 */
UINT32 SI125; /* Subindex125 - Reference to 0x7050.125 */
UINT32 SI126; /* Subindex126 - Reference to 0x7050.126 */
UINT32 SI127; /* Subindex127 - Reference to 0x7050.127 */
UINT32 SI128; /* Subindex128 - Reference to 0x7050.128 */
} OBJ_STRUCT_PACKED_END
TOBJ1605;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1605 RMUIPDOChannelProcessDataMapping0x1605
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={128,0x70500108,0x70500208,0x70500308,0x70500408,0x70500508,0x70500608,0x70500708,0x70500808,0x70500908,0x70500A08,0x70500B08,0x70500C08,0x70500D08,0x70500E08,0x70500F08,0x70501008,0x70501108,0x70501208,0x70501308,0x70501408,0x70501508,0x70501608,0x70501708,0x70501808,0x70501908,0x70501A08,0x70501B08,0x70501C08,0x70501D08,0x70501E08,0x70501F08,0x70502008,0x70502108,0x70502208,0x70502308,0x70502408,0x70502508,0x70502608,0x70502708,0x70502808,0x70502908,0x70502A08,0x70502B08,0x70502C08,0x70502D08,0x70502E08,0x70502F08,0x70503008,0x70503108,0x70503208,0x70503308,0x70503408,0x70503508,0x70503608,0x70503708,0x70503808,0x70503908,0x70503A08,0x70503B08,0x70503C08,0x70503D08,0x70503E08,0x70503F08,0x70504008,0x70504108,0x70504208,0x70504308,0x70504408,0x70504508,0x70504608,0x70504708,0x70504808,0x70504908,0x70504A08,0x70504B08,0x70504C08,0x70504D08,0x70504E08,0x70504F08,0x70505008,0x70505108,0x70505208,0x70505308,0x70505408,0x70505508,0x70505608,0x70505708,0x70505808,0x70505908,0x70505A08,0x70505B08,0x70505C08,0x70505D08,0x70505E08,0x70505F08,0x70506008,0x70506108,0x70506208,0x70506308,0x70506408,0x70506508,0x70506608,0x70506708,0x70506808,0x70506908,0x70506A08,0x70506B08,0x70506C08,0x70506D08,0x70506E08,0x70506F08,0x70507008,0x70507108,0x70507208,0x70507308,0x70507408,0x70507508,0x70507608,0x70507708,0x70507808,0x70507908,0x70507A08,0x70507B08,0x70507C08,0x70507D08,0x70507E08,0x70507F08,0x70508008}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : PDIChannel process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | PDIChannel process data mapping
* @{
* \brief Object 0x1A00 (PDIChannel process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6000.1<br>
* SubIndex 2 - Reference to 0x6000.2<br>
* SubIndex 3 - Reference to 0x6000.3<br>
* SubIndex 4 - Reference to 0x6000.4<br>
* SubIndex 5 - Reference to 0x6000.5<br>
* SubIndex 6 - Reference to 0x6000.6<br>
* SubIndex 7 - Reference to 0x6000.7<br>
* SubIndex 8 - Reference to 0x6000.8<br>
* SubIndex 9 - Reference to 0x6000.9<br>
* SubIndex 10 - Reference to 0x6000.10<br>
* SubIndex 11 - Reference to 0x6000.11<br>
* SubIndex 12 - Reference to 0x6000.12<br>
* SubIndex 13 - Reference to 0x6000.13<br>
* SubIndex 14 - Reference to 0x6000.14<br>
* SubIndex 15 - Reference to 0x6000.15<br>
* SubIndex 16 - Reference to 0x6000.16<br>
* SubIndex 17 - Reference to 0x6000.17<br>
* SubIndex 18 - Reference to 0x6000.18<br>
* SubIndex 19 - Reference to 0x6000.19<br>
* SubIndex 20 - Reference to 0x6000.20<br>
* SubIndex 21 - Reference to 0x6000.21<br>
* SubIndex 22 - Reference to 0x6000.22<br>
* SubIndex 23 - Reference to 0x6000.23<br>
* SubIndex 24 - Reference to 0x6000.24<br>
* SubIndex 25 - Reference to 0x6000.25<br>
* SubIndex 26 - Reference to 0x6000.26<br>
* SubIndex 27 - Reference to 0x6000.27<br>
* SubIndex 28 - Reference to 0x6000.28<br>
* SubIndex 29 - Reference to 0x6000.29<br>
* SubIndex 30 - Reference to 0x6000.30<br>
* SubIndex 31 - Reference to 0x6000.31<br>
* SubIndex 32 - Reference to 0x6000.32<br>
* SubIndex 33 - Reference to 0x6000.33<br>
* SubIndex 34 - Reference to 0x6000.34<br>
* SubIndex 35 - Reference to 0x6000.35<br>
* SubIndex 36 - Reference to 0x6000.36<br>
* SubIndex 37 - Reference to 0x6000.37<br>
* SubIndex 38 - Reference to 0x6000.38<br>
* SubIndex 39 - Reference to 0x6000.39<br>
* SubIndex 40 - Reference to 0x6000.40<br>
* SubIndex 41 - Reference to 0x6000.41<br>
* SubIndex 42 - Reference to 0x6000.42<br>
* SubIndex 43 - Reference to 0x6000.43<br>
* SubIndex 44 - Reference to 0x6000.44<br>
* SubIndex 45 - Reference to 0x6000.45<br>
* SubIndex 46 - Reference to 0x6000.46<br>
* SubIndex 47 - Reference to 0x6000.47<br>
* SubIndex 48 - Reference to 0x6000.48<br>
* SubIndex 49 - Reference to 0x6000.49<br>
* SubIndex 50 - Reference to 0x6000.50<br>
* SubIndex 51 - Reference to 0x6000.51<br>
* SubIndex 52 - Reference to 0x6000.52<br>
* SubIndex 53 - Reference to 0x6000.53<br>
* SubIndex 54 - Reference to 0x6000.54<br>
* SubIndex 55 - Reference to 0x6000.55<br>
* SubIndex 56 - Reference to 0x6000.56<br>
* SubIndex 57 - Reference to 0x6000.57<br>
* SubIndex 58 - Reference to 0x6000.58<br>
* SubIndex 59 - Reference to 0x6000.59<br>
* SubIndex 60 - Reference to 0x6000.60<br>
* SubIndex 61 - Reference to 0x6000.61<br>
* SubIndex 62 - Reference to 0x6000.62<br>
* SubIndex 63 - Reference to 0x6000.63<br>
* SubIndex 64 - Reference to 0x6000.64<br>
* SubIndex 65 - Reference to 0x6000.65<br>
* SubIndex 66 - Reference to 0x6000.66<br>
* SubIndex 67 - Reference to 0x6000.67<br>
* SubIndex 68 - Reference to 0x6000.68<br>
* SubIndex 69 - Reference to 0x6000.69<br>
* SubIndex 70 - Reference to 0x6000.70<br>
* SubIndex 71 - Reference to 0x6000.71<br>
* SubIndex 72 - Reference to 0x6000.72<br>
* SubIndex 73 - Reference to 0x6000.73<br>
* SubIndex 74 - Reference to 0x6000.74<br>
* SubIndex 75 - Reference to 0x6000.75<br>
* SubIndex 76 - Reference to 0x6000.76<br>
* SubIndex 77 - Reference to 0x6000.77<br>
* SubIndex 78 - Reference to 0x6000.78<br>
* SubIndex 79 - Reference to 0x6000.79<br>
* SubIndex 80 - Reference to 0x6000.80<br>
* SubIndex 81 - Reference to 0x6000.81<br>
* SubIndex 82 - Reference to 0x6000.82<br>
* SubIndex 83 - Reference to 0x6000.83<br>
* SubIndex 84 - Reference to 0x6000.84<br>
* SubIndex 85 - Reference to 0x6000.85<br>
* SubIndex 86 - Reference to 0x6000.86<br>
* SubIndex 87 - Reference to 0x6000.87<br>
* SubIndex 88 - Reference to 0x6000.88<br>
* SubIndex 89 - Reference to 0x6000.89<br>
* SubIndex 90 - Reference to 0x6000.90<br>
* SubIndex 91 - Reference to 0x6000.91<br>
* SubIndex 92 - Reference to 0x6000.92<br>
* SubIndex 93 - Reference to 0x6000.93<br>
* SubIndex 94 - Reference to 0x6000.94<br>
* SubIndex 95 - Reference to 0x6000.95<br>
* SubIndex 96 - Reference to 0x6000.96<br>
* SubIndex 97 - Reference to 0x6000.97<br>
* SubIndex 98 - Reference to 0x6000.98<br>
* SubIndex 99 - Reference to 0x6000.99<br>
* SubIndex 100 - Reference to 0x6000.100<br>
* SubIndex 101 - Reference to 0x6000.101<br>
* SubIndex 102 - Reference to 0x6000.102<br>
* SubIndex 103 - Reference to 0x6000.103<br>
* SubIndex 104 - Reference to 0x6000.104<br>
* SubIndex 105 - Reference to 0x6000.105<br>
* SubIndex 106 - Reference to 0x6000.106<br>
* SubIndex 107 - Reference to 0x6000.107<br>
* SubIndex 108 - Reference to 0x6000.108<br>
* SubIndex 109 - Reference to 0x6000.109<br>
* SubIndex 110 - Reference to 0x6000.110<br>
* SubIndex 111 - Reference to 0x6000.111<br>
* SubIndex 112 - Reference to 0x6000.112<br>
* SubIndex 113 - Reference to 0x6000.113<br>
* SubIndex 114 - Reference to 0x6000.114<br>
* SubIndex 115 - Reference to 0x6000.115<br>
* SubIndex 116 - Reference to 0x6000.116<br>
* SubIndex 117 - Reference to 0x6000.117<br>
* SubIndex 118 - Reference to 0x6000.118<br>
* SubIndex 119 - Reference to 0x6000.119<br>
* SubIndex 120 - Reference to 0x6000.120<br>
* SubIndex 121 - Reference to 0x6000.121<br>
* SubIndex 122 - Reference to 0x6000.122<br>
* SubIndex 123 - Reference to 0x6000.123<br>
* SubIndex 124 - Reference to 0x6000.124<br>
* SubIndex 125 - Reference to 0x6000.125<br>
* SubIndex 126 - Reference to 0x6000.126<br>
* SubIndex 127 - Reference to 0x6000.127<br>
* SubIndex 128 - Reference to 0x6000.128<br>
* SubIndex 129 - Reference to 0x6000.129<br>
* SubIndex 130 - Reference to 0x6000.130<br>
* SubIndex 131 - Reference to 0x6000.131<br>
* SubIndex 132 - Reference to 0x6000.132<br>
* SubIndex 133 - Reference to 0x6000.133<br>
* SubIndex 134 - Reference to 0x6000.134<br>
* SubIndex 135 - Reference to 0x6000.135<br>
* SubIndex 136 - Reference to 0x6000.136<br>
* SubIndex 137 - Reference to 0x6000.137<br>
* SubIndex 138 - Reference to 0x6000.138<br>
* SubIndex 139 - Reference to 0x6000.139<br>
* SubIndex 140 - Reference to 0x6000.140<br>
* SubIndex 141 - Reference to 0x6000.141<br>
* SubIndex 142 - Reference to 0x6000.142<br>
* SubIndex 143 - Reference to 0x6000.143<br>
* SubIndex 144 - Reference to 0x6000.144<br>
* SubIndex 145 - Reference to 0x6000.145<br>
* SubIndex 146 - Reference to 0x6000.146<br>
* SubIndex 147 - Reference to 0x6000.147<br>
* SubIndex 148 - Reference to 0x6000.148<br>
* SubIndex 149 - Reference to 0x6000.149<br>
* SubIndex 150 - Reference to 0x6000.150<br>
* SubIndex 151 - Reference to 0x6000.151<br>
* SubIndex 152 - Reference to 0x6000.152<br>
* SubIndex 153 - Reference to 0x6000.153<br>
* SubIndex 154 - Reference to 0x6000.154<br>
* SubIndex 155 - Reference to 0x6000.155<br>
* SubIndex 156 - Reference to 0x6000.156<br>
* SubIndex 157 - Reference to 0x6000.157<br>
* SubIndex 158 - Reference to 0x6000.158<br>
* SubIndex 159 - Reference to 0x6000.159<br>
* SubIndex 160 - Reference to 0x6000.160<br>
* SubIndex 161 - Reference to 0x6000.161<br>
* SubIndex 162 - Reference to 0x6000.162<br>
* SubIndex 163 - Reference to 0x6000.163<br>
* SubIndex 164 - Reference to 0x6000.164<br>
* SubIndex 165 - Reference to 0x6000.165<br>
* SubIndex 166 - Reference to 0x6000.166<br>
* SubIndex 167 - Reference to 0x6000.167<br>
* SubIndex 168 - Reference to 0x6000.168<br>
* SubIndex 169 - Reference to 0x6000.169<br>
* SubIndex 170 - Reference to 0x6000.170<br>
* SubIndex 171 - Reference to 0x6000.171<br>
* SubIndex 172 - Reference to 0x6000.172<br>
* SubIndex 173 - Reference to 0x6000.173<br>
* SubIndex 174 - Reference to 0x6000.174<br>
* SubIndex 175 - Reference to 0x6000.175<br>
* SubIndex 176 - Reference to 0x6000.176<br>
* SubIndex 177 - Reference to 0x6000.177<br>
* SubIndex 178 - Reference to 0x6000.178<br>
* SubIndex 179 - Reference to 0x6000.179<br>
* SubIndex 180 - Reference to 0x6000.180<br>
* SubIndex 181 - Reference to 0x6000.181<br>
* SubIndex 182 - Reference to 0x6000.182<br>
* SubIndex 183 - Reference to 0x6000.183<br>
* SubIndex 184 - Reference to 0x6000.184<br>
* SubIndex 185 - Reference to 0x6000.185<br>
* SubIndex 186 - Reference to 0x6000.186<br>
* SubIndex 187 - Reference to 0x6000.187<br>
* SubIndex 188 - Reference to 0x6000.188<br>
* SubIndex 189 - Reference to 0x6000.189<br>
* SubIndex 190 - Reference to 0x6000.190<br>
* SubIndex 191 - Reference to 0x6000.191<br>
* SubIndex 192 - Reference to 0x6000.192<br>
* SubIndex 193 - Reference to 0x6000.193<br>
* SubIndex 194 - Reference to 0x6000.194<br>
* SubIndex 195 - Reference to 0x6000.195<br>
* SubIndex 196 - Reference to 0x6000.196<br>
* SubIndex 197 - Reference to 0x6000.197<br>
* SubIndex 198 - Reference to 0x6000.198<br>
* SubIndex 199 - Reference to 0x6000.199<br>
* SubIndex 200 - Reference to 0x6000.200<br>
* SubIndex 201 - Reference to 0x6000.201<br>
* SubIndex 202 - Reference to 0x6000.202<br>
* SubIndex 203 - Reference to 0x6000.203<br>
* SubIndex 204 - Reference to 0x6000.204<br>
* SubIndex 205 - Reference to 0x6000.205<br>
* SubIndex 206 - Reference to 0x6000.206<br>
* SubIndex 207 - Reference to 0x6000.207<br>
* SubIndex 208 - Reference to 0x6000.208<br>
* SubIndex 209 - Reference to 0x6000.209<br>
* SubIndex 210 - Reference to 0x6000.210<br>
* SubIndex 211 - Reference to 0x6000.211<br>
* SubIndex 212 - Reference to 0x6000.212<br>
* SubIndex 213 - Reference to 0x6000.213<br>
* SubIndex 214 - Reference to 0x6000.214<br>
* SubIndex 215 - Reference to 0x6000.215<br>
* SubIndex 216 - Reference to 0x6000.216<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x6000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x6000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x6000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x6000.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x6000.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x6000.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x6000.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x6000.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x6000.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x6000.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x6000.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x6000.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x6000.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x6000.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x6000.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x6000.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x6000.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x6000.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x6000.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x6000.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x6000.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x6000.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x6000.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 - Reference to 0x6000.25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 - Reference to 0x6000.26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 - Reference to 0x6000.27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 - Reference to 0x6000.28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 - Reference to 0x6000.29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 - Reference to 0x6000.30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 - Reference to 0x6000.31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 - Reference to 0x6000.32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 - Reference to 0x6000.33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 - Reference to 0x6000.34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 - Reference to 0x6000.35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 - Reference to 0x6000.36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 - Reference to 0x6000.37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 - Reference to 0x6000.38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 - Reference to 0x6000.39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 - Reference to 0x6000.40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 - Reference to 0x6000.41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 - Reference to 0x6000.42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 - Reference to 0x6000.43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 - Reference to 0x6000.44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 - Reference to 0x6000.45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 - Reference to 0x6000.46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 - Reference to 0x6000.47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 - Reference to 0x6000.48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 - Reference to 0x6000.49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 - Reference to 0x6000.50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 - Reference to 0x6000.51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 - Reference to 0x6000.52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 - Reference to 0x6000.53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 - Reference to 0x6000.54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 - Reference to 0x6000.55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 - Reference to 0x6000.56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 - Reference to 0x6000.57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 - Reference to 0x6000.58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 - Reference to 0x6000.59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 - Reference to 0x6000.60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 - Reference to 0x6000.61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 - Reference to 0x6000.62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 - Reference to 0x6000.63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 - Reference to 0x6000.64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 - Reference to 0x6000.65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 - Reference to 0x6000.66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 - Reference to 0x6000.67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 - Reference to 0x6000.68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 - Reference to 0x6000.69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 - Reference to 0x6000.70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 - Reference to 0x6000.71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 - Reference to 0x6000.72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 - Reference to 0x6000.73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 - Reference to 0x6000.74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 - Reference to 0x6000.75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 - Reference to 0x6000.76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 - Reference to 0x6000.77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 - Reference to 0x6000.78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 - Reference to 0x6000.79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 - Reference to 0x6000.80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 - Reference to 0x6000.81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 - Reference to 0x6000.82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 - Reference to 0x6000.83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 - Reference to 0x6000.84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 - Reference to 0x6000.85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 - Reference to 0x6000.86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 - Reference to 0x6000.87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 - Reference to 0x6000.88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 - Reference to 0x6000.89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 - Reference to 0x6000.90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 - Reference to 0x6000.91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 - Reference to 0x6000.92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 - Reference to 0x6000.93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 - Reference to 0x6000.94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 - Reference to 0x6000.95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 - Reference to 0x6000.96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 - Reference to 0x6000.97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 - Reference to 0x6000.98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 - Reference to 0x6000.99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 - Reference to 0x6000.100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 - Reference to 0x6000.101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 - Reference to 0x6000.102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 - Reference to 0x6000.103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 - Reference to 0x6000.104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 - Reference to 0x6000.105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 - Reference to 0x6000.106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 - Reference to 0x6000.107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 - Reference to 0x6000.108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 - Reference to 0x6000.109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 - Reference to 0x6000.110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 - Reference to 0x6000.111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 - Reference to 0x6000.112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 - Reference to 0x6000.113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 - Reference to 0x6000.114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex115 - Reference to 0x6000.115 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex116 - Reference to 0x6000.116 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex117 - Reference to 0x6000.117 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex118 - Reference to 0x6000.118 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex119 - Reference to 0x6000.119 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex120 - Reference to 0x6000.120 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex121 - Reference to 0x6000.121 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex122 - Reference to 0x6000.122 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex123 - Reference to 0x6000.123 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex124 - Reference to 0x6000.124 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex125 - Reference to 0x6000.125 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex126 - Reference to 0x6000.126 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex127 - Reference to 0x6000.127 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex128 - Reference to 0x6000.128 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex129 - Reference to 0x6000.129 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex130 - Reference to 0x6000.130 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex131 - Reference to 0x6000.131 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex132 - Reference to 0x6000.132 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex133 - Reference to 0x6000.133 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex134 - Reference to 0x6000.134 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex135 - Reference to 0x6000.135 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex136 - Reference to 0x6000.136 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex137 - Reference to 0x6000.137 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex138 - Reference to 0x6000.138 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex139 - Reference to 0x6000.139 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex140 - Reference to 0x6000.140 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex141 - Reference to 0x6000.141 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex142 - Reference to 0x6000.142 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex143 - Reference to 0x6000.143 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex144 - Reference to 0x6000.144 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex145 - Reference to 0x6000.145 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex146 - Reference to 0x6000.146 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex147 - Reference to 0x6000.147 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex148 - Reference to 0x6000.148 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex149 - Reference to 0x6000.149 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex150 - Reference to 0x6000.150 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex151 - Reference to 0x6000.151 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex152 - Reference to 0x6000.152 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex153 - Reference to 0x6000.153 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex154 - Reference to 0x6000.154 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex155 - Reference to 0x6000.155 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex156 - Reference to 0x6000.156 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex157 - Reference to 0x6000.157 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex158 - Reference to 0x6000.158 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex159 - Reference to 0x6000.159 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex160 - Reference to 0x6000.160 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex161 - Reference to 0x6000.161 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex162 - Reference to 0x6000.162 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex163 - Reference to 0x6000.163 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex164 - Reference to 0x6000.164 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex165 - Reference to 0x6000.165 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex166 - Reference to 0x6000.166 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex167 - Reference to 0x6000.167 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex168 - Reference to 0x6000.168 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex169 - Reference to 0x6000.169 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex170 - Reference to 0x6000.170 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex171 - Reference to 0x6000.171 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex172 - Reference to 0x6000.172 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex173 - Reference to 0x6000.173 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex174 - Reference to 0x6000.174 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex175 - Reference to 0x6000.175 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex176 - Reference to 0x6000.176 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex177 - Reference to 0x6000.177 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex178 - Reference to 0x6000.178 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex179 - Reference to 0x6000.179 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex180 - Reference to 0x6000.180 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex181 - Reference to 0x6000.181 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex182 - Reference to 0x6000.182 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex183 - Reference to 0x6000.183 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex184 - Reference to 0x6000.184 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex185 - Reference to 0x6000.185 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex186 - Reference to 0x6000.186 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex187 - Reference to 0x6000.187 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex188 - Reference to 0x6000.188 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex189 - Reference to 0x6000.189 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex190 - Reference to 0x6000.190 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex191 - Reference to 0x6000.191 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex192 - Reference to 0x6000.192 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex193 - Reference to 0x6000.193 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex194 - Reference to 0x6000.194 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex195 - Reference to 0x6000.195 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex196 - Reference to 0x6000.196 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex197 - Reference to 0x6000.197 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex198 - Reference to 0x6000.198 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex199 - Reference to 0x6000.199 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex200 - Reference to 0x6000.200 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex201 - Reference to 0x6000.201 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex202 - Reference to 0x6000.202 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex203 - Reference to 0x6000.203 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex204 - Reference to 0x6000.204 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex205 - Reference to 0x6000.205 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex206 - Reference to 0x6000.206 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex207 - Reference to 0x6000.207 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex208 - Reference to 0x6000.208 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex209 - Reference to 0x6000.209 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex210 - Reference to 0x6000.210 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex211 - Reference to 0x6000.211 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex212 - Reference to 0x6000.212 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex213 - Reference to 0x6000.213 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex214 - Reference to 0x6000.214 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex215 - Reference to 0x6000.215 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex216 - Reference to 0x6000.216 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "PDIChannel process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000"
"SubIndex 069\000"
"SubIndex 070\000"
"SubIndex 071\000"
"SubIndex 072\000"
"SubIndex 073\000"
"SubIndex 074\000"
"SubIndex 075\000"
"SubIndex 076\000"
"SubIndex 077\000"
"SubIndex 078\000"
"SubIndex 079\000"
"SubIndex 080\000"
"SubIndex 081\000"
"SubIndex 082\000"
"SubIndex 083\000"
"SubIndex 084\000"
"SubIndex 085\000"
"SubIndex 086\000"
"SubIndex 087\000"
"SubIndex 088\000"
"SubIndex 089\000"
"SubIndex 090\000"
"SubIndex 091\000"
"SubIndex 092\000"
"SubIndex 093\000"
"SubIndex 094\000"
"SubIndex 095\000"
"SubIndex 096\000"
"SubIndex 097\000"
"SubIndex 098\000"
"SubIndex 099\000"
"SubIndex 100\000"
"SubIndex 101\000"
"SubIndex 102\000"
"SubIndex 103\000"
"SubIndex 104\000"
"SubIndex 105\000"
"SubIndex 106\000"
"SubIndex 107\000"
"SubIndex 108\000"
"SubIndex 109\000"
"SubIndex 110\000"
"SubIndex 111\000"
"SubIndex 112\000"
"SubIndex 113\000"
"SubIndex 114\000"
"SubIndex 115\000"
"SubIndex 116\000"
"SubIndex 117\000"
"SubIndex 118\000"
"SubIndex 119\000"
"SubIndex 120\000"
"SubIndex 121\000"
"SubIndex 122\000"
"SubIndex 123\000"
"SubIndex 124\000"
"SubIndex 125\000"
"SubIndex 126\000"
"SubIndex 127\000"
"SubIndex 128\000"
"SubIndex 129\000"
"SubIndex 130\000"
"SubIndex 131\000"
"SubIndex 132\000"
"SubIndex 133\000"
"SubIndex 134\000"
"SubIndex 135\000"
"SubIndex 136\000"
"SubIndex 137\000"
"SubIndex 138\000"
"SubIndex 139\000"
"SubIndex 140\000"
"SubIndex 141\000"
"SubIndex 142\000"
"SubIndex 143\000"
"SubIndex 144\000"
"SubIndex 145\000"
"SubIndex 146\000"
"SubIndex 147\000"
"SubIndex 148\000"
"SubIndex 149\000"
"SubIndex 150\000"
"SubIndex 151\000"
"SubIndex 152\000"
"SubIndex 153\000"
"SubIndex 154\000"
"SubIndex 155\000"
"SubIndex 156\000"
"SubIndex 157\000"
"SubIndex 158\000"
"SubIndex 159\000"
"SubIndex 160\000"
"SubIndex 161\000"
"SubIndex 162\000"
"SubIndex 163\000"
"SubIndex 164\000"
"SubIndex 165\000"
"SubIndex 166\000"
"SubIndex 167\000"
"SubIndex 168\000"
"SubIndex 169\000"
"SubIndex 170\000"
"SubIndex 171\000"
"SubIndex 172\000"
"SubIndex 173\000"
"SubIndex 174\000"
"SubIndex 175\000"
"SubIndex 176\000"
"SubIndex 177\000"
"SubIndex 178\000"
"SubIndex 179\000"
"SubIndex 180\000"
"SubIndex 181\000"
"SubIndex 182\000"
"SubIndex 183\000"
"SubIndex 184\000"
"SubIndex 185\000"
"SubIndex 186\000"
"SubIndex 187\000"
"SubIndex 188\000"
"SubIndex 189\000"
"SubIndex 190\000"
"SubIndex 191\000"
"SubIndex 192\000"
"SubIndex 193\000"
"SubIndex 194\000"
"SubIndex 195\000"
"SubIndex 196\000"
"SubIndex 197\000"
"SubIndex 198\000"
"SubIndex 199\000"
"SubIndex 200\000"
"SubIndex 201\000"
"SubIndex 202\000"
"SubIndex 203\000"
"SubIndex 204\000"
"SubIndex 205\000"
"SubIndex 206\000"
"SubIndex 207\000"
"SubIndex 208\000"
"SubIndex 209\000"
"SubIndex 210\000"
"SubIndex 211\000"
"SubIndex 212\000"
"SubIndex 213\000"
"SubIndex 214\000"
"SubIndex 215\000"
"SubIndex 216\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x6000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x6000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x6000.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x6000.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x6000.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x6000.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x6000.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x6000.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x6000.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x6000.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x6000.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x6000.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x6000.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x6000.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x6000.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x6000.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x6000.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x6000.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x6000.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x6000.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x6000.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x6000.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x6000.25 */
UINT32 SI26; /* Subindex26 - Reference to 0x6000.26 */
UINT32 SI27; /* Subindex27 - Reference to 0x6000.27 */
UINT32 SI28; /* Subindex28 - Reference to 0x6000.28 */
UINT32 SI29; /* Subindex29 - Reference to 0x6000.29 */
UINT32 SI30; /* Subindex30 - Reference to 0x6000.30 */
UINT32 SI31; /* Subindex31 - Reference to 0x6000.31 */
UINT32 SI32; /* Subindex32 - Reference to 0x6000.32 */
UINT32 SI33; /* Subindex33 - Reference to 0x6000.33 */
UINT32 SI34; /* Subindex34 - Reference to 0x6000.34 */
UINT32 SI35; /* Subindex35 - Reference to 0x6000.35 */
UINT32 SI36; /* Subindex36 - Reference to 0x6000.36 */
UINT32 SI37; /* Subindex37 - Reference to 0x6000.37 */
UINT32 SI38; /* Subindex38 - Reference to 0x6000.38 */
UINT32 SI39; /* Subindex39 - Reference to 0x6000.39 */
UINT32 SI40; /* Subindex40 - Reference to 0x6000.40 */
UINT32 SI41; /* Subindex41 - Reference to 0x6000.41 */
UINT32 SI42; /* Subindex42 - Reference to 0x6000.42 */
UINT32 SI43; /* Subindex43 - Reference to 0x6000.43 */
UINT32 SI44; /* Subindex44 - Reference to 0x6000.44 */
UINT32 SI45; /* Subindex45 - Reference to 0x6000.45 */
UINT32 SI46; /* Subindex46 - Reference to 0x6000.46 */
UINT32 SI47; /* Subindex47 - Reference to 0x6000.47 */
UINT32 SI48; /* Subindex48 - Reference to 0x6000.48 */
UINT32 SI49; /* Subindex49 - Reference to 0x6000.49 */
UINT32 SI50; /* Subindex50 - Reference to 0x6000.50 */
UINT32 SI51; /* Subindex51 - Reference to 0x6000.51 */
UINT32 SI52; /* Subindex52 - Reference to 0x6000.52 */
UINT32 SI53; /* Subindex53 - Reference to 0x6000.53 */
UINT32 SI54; /* Subindex54 - Reference to 0x6000.54 */
UINT32 SI55; /* Subindex55 - Reference to 0x6000.55 */
UINT32 SI56; /* Subindex56 - Reference to 0x6000.56 */
UINT32 SI57; /* Subindex57 - Reference to 0x6000.57 */
UINT32 SI58; /* Subindex58 - Reference to 0x6000.58 */
UINT32 SI59; /* Subindex59 - Reference to 0x6000.59 */
UINT32 SI60; /* Subindex60 - Reference to 0x6000.60 */
UINT32 SI61; /* Subindex61 - Reference to 0x6000.61 */
UINT32 SI62; /* Subindex62 - Reference to 0x6000.62 */
UINT32 SI63; /* Subindex63 - Reference to 0x6000.63 */
UINT32 SI64; /* Subindex64 - Reference to 0x6000.64 */
UINT32 SI65; /* Subindex65 - Reference to 0x6000.65 */
UINT32 SI66; /* Subindex66 - Reference to 0x6000.66 */
UINT32 SI67; /* Subindex67 - Reference to 0x6000.67 */
UINT32 SI68; /* Subindex68 - Reference to 0x6000.68 */
UINT32 SI69; /* Subindex69 - Reference to 0x6000.69 */
UINT32 SI70; /* Subindex70 - Reference to 0x6000.70 */
UINT32 SI71; /* Subindex71 - Reference to 0x6000.71 */
UINT32 SI72; /* Subindex72 - Reference to 0x6000.72 */
UINT32 SI73; /* Subindex73 - Reference to 0x6000.73 */
UINT32 SI74; /* Subindex74 - Reference to 0x6000.74 */
UINT32 SI75; /* Subindex75 - Reference to 0x6000.75 */
UINT32 SI76; /* Subindex76 - Reference to 0x6000.76 */
UINT32 SI77; /* Subindex77 - Reference to 0x6000.77 */
UINT32 SI78; /* Subindex78 - Reference to 0x6000.78 */
UINT32 SI79; /* Subindex79 - Reference to 0x6000.79 */
UINT32 SI80; /* Subindex80 - Reference to 0x6000.80 */
UINT32 SI81; /* Subindex81 - Reference to 0x6000.81 */
UINT32 SI82; /* Subindex82 - Reference to 0x6000.82 */
UINT32 SI83; /* Subindex83 - Reference to 0x6000.83 */
UINT32 SI84; /* Subindex84 - Reference to 0x6000.84 */
UINT32 SI85; /* Subindex85 - Reference to 0x6000.85 */
UINT32 SI86; /* Subindex86 - Reference to 0x6000.86 */
UINT32 SI87; /* Subindex87 - Reference to 0x6000.87 */
UINT32 SI88; /* Subindex88 - Reference to 0x6000.88 */
UINT32 SI89; /* Subindex89 - Reference to 0x6000.89 */
UINT32 SI90; /* Subindex90 - Reference to 0x6000.90 */
UINT32 SI91; /* Subindex91 - Reference to 0x6000.91 */
UINT32 SI92; /* Subindex92 - Reference to 0x6000.92 */
UINT32 SI93; /* Subindex93 - Reference to 0x6000.93 */
UINT32 SI94; /* Subindex94 - Reference to 0x6000.94 */
UINT32 SI95; /* Subindex95 - Reference to 0x6000.95 */
UINT32 SI96; /* Subindex96 - Reference to 0x6000.96 */
UINT32 SI97; /* Subindex97 - Reference to 0x6000.97 */
UINT32 SI98; /* Subindex98 - Reference to 0x6000.98 */
UINT32 SI99; /* Subindex99 - Reference to 0x6000.99 */
UINT32 SI100; /* Subindex100 - Reference to 0x6000.100 */
UINT32 SI101; /* Subindex101 - Reference to 0x6000.101 */
UINT32 SI102; /* Subindex102 - Reference to 0x6000.102 */
UINT32 SI103; /* Subindex103 - Reference to 0x6000.103 */
UINT32 SI104; /* Subindex104 - Reference to 0x6000.104 */
UINT32 SI105; /* Subindex105 - Reference to 0x6000.105 */
UINT32 SI106; /* Subindex106 - Reference to 0x6000.106 */
UINT32 SI107; /* Subindex107 - Reference to 0x6000.107 */
UINT32 SI108; /* Subindex108 - Reference to 0x6000.108 */
UINT32 SI109; /* Subindex109 - Reference to 0x6000.109 */
UINT32 SI110; /* Subindex110 - Reference to 0x6000.110 */
UINT32 SI111; /* Subindex111 - Reference to 0x6000.111 */
UINT32 SI112; /* Subindex112 - Reference to 0x6000.112 */
UINT32 SI113; /* Subindex113 - Reference to 0x6000.113 */
UINT32 SI114; /* Subindex114 - Reference to 0x6000.114 */
UINT32 SI115; /* Subindex115 - Reference to 0x6000.115 */
UINT32 SI116; /* Subindex116 - Reference to 0x6000.116 */
UINT32 SI117; /* Subindex117 - Reference to 0x6000.117 */
UINT32 SI118; /* Subindex118 - Reference to 0x6000.118 */
UINT32 SI119; /* Subindex119 - Reference to 0x6000.119 */
UINT32 SI120; /* Subindex120 - Reference to 0x6000.120 */
UINT32 SI121; /* Subindex121 - Reference to 0x6000.121 */
UINT32 SI122; /* Subindex122 - Reference to 0x6000.122 */
UINT32 SI123; /* Subindex123 - Reference to 0x6000.123 */
UINT32 SI124; /* Subindex124 - Reference to 0x6000.124 */
UINT32 SI125; /* Subindex125 - Reference to 0x6000.125 */
UINT32 SI126; /* Subindex126 - Reference to 0x6000.126 */
UINT32 SI127; /* Subindex127 - Reference to 0x6000.127 */
UINT32 SI128; /* Subindex128 - Reference to 0x6000.128 */
UINT32 SI129; /* Subindex129 - Reference to 0x6000.129 */
UINT32 SI130; /* Subindex130 - Reference to 0x6000.130 */
UINT32 SI131; /* Subindex131 - Reference to 0x6000.131 */
UINT32 SI132; /* Subindex132 - Reference to 0x6000.132 */
UINT32 SI133; /* Subindex133 - Reference to 0x6000.133 */
UINT32 SI134; /* Subindex134 - Reference to 0x6000.134 */
UINT32 SI135; /* Subindex135 - Reference to 0x6000.135 */
UINT32 SI136; /* Subindex136 - Reference to 0x6000.136 */
UINT32 SI137; /* Subindex137 - Reference to 0x6000.137 */
UINT32 SI138; /* Subindex138 - Reference to 0x6000.138 */
UINT32 SI139; /* Subindex139 - Reference to 0x6000.139 */
UINT32 SI140; /* Subindex140 - Reference to 0x6000.140 */
UINT32 SI141; /* Subindex141 - Reference to 0x6000.141 */
UINT32 SI142; /* Subindex142 - Reference to 0x6000.142 */
UINT32 SI143; /* Subindex143 - Reference to 0x6000.143 */
UINT32 SI144; /* Subindex144 - Reference to 0x6000.144 */
UINT32 SI145; /* Subindex145 - Reference to 0x6000.145 */
UINT32 SI146; /* Subindex146 - Reference to 0x6000.146 */
UINT32 SI147; /* Subindex147 - Reference to 0x6000.147 */
UINT32 SI148; /* Subindex148 - Reference to 0x6000.148 */
UINT32 SI149; /* Subindex149 - Reference to 0x6000.149 */
UINT32 SI150; /* Subindex150 - Reference to 0x6000.150 */
UINT32 SI151; /* Subindex151 - Reference to 0x6000.151 */
UINT32 SI152; /* Subindex152 - Reference to 0x6000.152 */
UINT32 SI153; /* Subindex153 - Reference to 0x6000.153 */
UINT32 SI154; /* Subindex154 - Reference to 0x6000.154 */
UINT32 SI155; /* Subindex155 - Reference to 0x6000.155 */
UINT32 SI156; /* Subindex156 - Reference to 0x6000.156 */
UINT32 SI157; /* Subindex157 - Reference to 0x6000.157 */
UINT32 SI158; /* Subindex158 - Reference to 0x6000.158 */
UINT32 SI159; /* Subindex159 - Reference to 0x6000.159 */
UINT32 SI160; /* Subindex160 - Reference to 0x6000.160 */
UINT32 SI161; /* Subindex161 - Reference to 0x6000.161 */
UINT32 SI162; /* Subindex162 - Reference to 0x6000.162 */
UINT32 SI163; /* Subindex163 - Reference to 0x6000.163 */
UINT32 SI164; /* Subindex164 - Reference to 0x6000.164 */
UINT32 SI165; /* Subindex165 - Reference to 0x6000.165 */
UINT32 SI166; /* Subindex166 - Reference to 0x6000.166 */
UINT32 SI167; /* Subindex167 - Reference to 0x6000.167 */
UINT32 SI168; /* Subindex168 - Reference to 0x6000.168 */
UINT32 SI169; /* Subindex169 - Reference to 0x6000.169 */
UINT32 SI170; /* Subindex170 - Reference to 0x6000.170 */
UINT32 SI171; /* Subindex171 - Reference to 0x6000.171 */
UINT32 SI172; /* Subindex172 - Reference to 0x6000.172 */
UINT32 SI173; /* Subindex173 - Reference to 0x6000.173 */
UINT32 SI174; /* Subindex174 - Reference to 0x6000.174 */
UINT32 SI175; /* Subindex175 - Reference to 0x6000.175 */
UINT32 SI176; /* Subindex176 - Reference to 0x6000.176 */
UINT32 SI177; /* Subindex177 - Reference to 0x6000.177 */
UINT32 SI178; /* Subindex178 - Reference to 0x6000.178 */
UINT32 SI179; /* Subindex179 - Reference to 0x6000.179 */
UINT32 SI180; /* Subindex180 - Reference to 0x6000.180 */
UINT32 SI181; /* Subindex181 - Reference to 0x6000.181 */
UINT32 SI182; /* Subindex182 - Reference to 0x6000.182 */
UINT32 SI183; /* Subindex183 - Reference to 0x6000.183 */
UINT32 SI184; /* Subindex184 - Reference to 0x6000.184 */
UINT32 SI185; /* Subindex185 - Reference to 0x6000.185 */
UINT32 SI186; /* Subindex186 - Reference to 0x6000.186 */
UINT32 SI187; /* Subindex187 - Reference to 0x6000.187 */
UINT32 SI188; /* Subindex188 - Reference to 0x6000.188 */
UINT32 SI189; /* Subindex189 - Reference to 0x6000.189 */
UINT32 SI190; /* Subindex190 - Reference to 0x6000.190 */
UINT32 SI191; /* Subindex191 - Reference to 0x6000.191 */
UINT32 SI192; /* Subindex192 - Reference to 0x6000.192 */
UINT32 SI193; /* Subindex193 - Reference to 0x6000.193 */
UINT32 SI194; /* Subindex194 - Reference to 0x6000.194 */
UINT32 SI195; /* Subindex195 - Reference to 0x6000.195 */
UINT32 SI196; /* Subindex196 - Reference to 0x6000.196 */
UINT32 SI197; /* Subindex197 - Reference to 0x6000.197 */
UINT32 SI198; /* Subindex198 - Reference to 0x6000.198 */
UINT32 SI199; /* Subindex199 - Reference to 0x6000.199 */
UINT32 SI200; /* Subindex200 - Reference to 0x6000.200 */
UINT32 SI201; /* Subindex201 - Reference to 0x6000.201 */
UINT32 SI202; /* Subindex202 - Reference to 0x6000.202 */
UINT32 SI203; /* Subindex203 - Reference to 0x6000.203 */
UINT32 SI204; /* Subindex204 - Reference to 0x6000.204 */
UINT32 SI205; /* Subindex205 - Reference to 0x6000.205 */
UINT32 SI206; /* Subindex206 - Reference to 0x6000.206 */
UINT32 SI207; /* Subindex207 - Reference to 0x6000.207 */
UINT32 SI208; /* Subindex208 - Reference to 0x6000.208 */
UINT32 SI209; /* Subindex209 - Reference to 0x6000.209 */
UINT32 SI210; /* Subindex210 - Reference to 0x6000.210 */
UINT32 SI211; /* Subindex211 - Reference to 0x6000.211 */
UINT32 SI212; /* Subindex212 - Reference to 0x6000.212 */
UINT32 SI213; /* Subindex213 - Reference to 0x6000.213 */
UINT32 SI214; /* Subindex214 - Reference to 0x6000.214 */
UINT32 SI215; /* Subindex215 - Reference to 0x6000.215 */
UINT32 SI216; /* Subindex216 - Reference to 0x6000.216 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 PDIChannelProcessDataMapping0x1A00
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={216,0x60000108,0x60000208,0x60000308,0x60000408,0x60000508,0x60000608,0x60000708,0x60000808,0x60000908,0x60000A08,0x60000B08,0x60000C08,0x60000D08,0x60000E08,0x60000F08,0x60001008,0x60001108,0x60001208,0x60001308,0x60001408,0x60001508,0x60001608,0x60001708,0x60001808,0x60001908,0x60001A08,0x60001B08,0x60001C08,0x60001D08,0x60001E08,0x60001F08,0x60002008,0x60002108,0x60002208,0x60002308,0x60002408,0x60002508,0x60002608,0x60002708,0x60002808,0x60002908,0x60002A08,0x60002B08,0x60002C08,0x60002D08,0x60002E08,0x60002F08,0x60003008,0x60003108,0x60003208,0x60003308,0x60003408,0x60003508,0x60003608,0x60003708,0x60003808,0x60003908,0x60003A08,0x60003B08,0x60003C08,0x60003D08,0x60003E08,0x60003F08,0x60004008,0x60004108,0x60004208,0x60004308,0x60004408,0x60004508,0x60004608,0x60004708,0x60004808,0x60004908,0x60004A08,0x60004B08,0x60004C08,0x60004D08,0x60004E08,0x60004F08,0x60005008,0x60005108,0x60005208,0x60005308,0x60005408,0x60005508,0x60005608,0x60005708,0x60005808,0x60005908,0x60005A08,0x60005B08,0x60005C08,0x60005D08,0x60005E08,0x60005F08,0x60006008,0x60006108,0x60006208,0x60006308,0x60006408,0x60006508,0x60006608,0x60006708,0x60006808,0x60006908,0x60006A08,0x60006B08,0x60006C08,0x60006D08,0x60006E08,0x60006F08,0x60007008,0x60007108,0x60007208,0x60007308,0x60007408,0x60007508,0x60007608,0x60007708,0x60007808,0x60007908,0x60007A08,0x60007B08,0x60007C08,0x60007D08,0x60007E08,0x60007F08,0x60008008,0x60008108,0x60008208,0x60008308,0x60008408,0x60008508,0x60008608,0x60008708,0x60008808,0x60008908,0x60008A08,0x60008B08,0x60008C08,0x60008D08,0x60008E08,0x60008F08,0x60009008,0x60009108,0x60009208,0x60009308,0x60009408,0x60009508,0x60009608,0x60009708,0x60009808,0x60009908,0x60009A08,0x60009B08,0x60009C08,0x60009D08,0x60009E08,0x60009F08,0x6000A008,0x6000A108,0x6000A208,0x6000A308,0x6000A408,0x6000A508,0x6000A608,0x6000A708,0x6000A808,0x6000A908,0x6000AA08,0x6000AB08,0x6000AC08,0x6000AD08,0x6000AE08,0x6000AF08,0x6000B008,0x6000B108,0x6000B208,0x6000B308,0x6000B408,0x6000B508,0x6000B608,0x6000B708,0x6000B808,0x6000B908,0x6000BA08,0x6000BB08,0x6000BC08,0x6000BD08,0x6000BE08,0x6000BF08,0x6000C008,0x6000C108,0x6000C208,0x6000C308,0x6000C408,0x6000C508,0x6000C608,0x6000C708,0x6000C808,0x6000C908,0x6000CA08,0x6000CB08,0x6000CC08,0x6000CD08,0x6000CE08,0x6000CF08,0x6000D008,0x6000D108,0x6000D208,0x6000D308,0x6000D408,0x6000D508,0x6000D608,0x6000D708,0x6000D808}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A0F : RMDAPDIChannel process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A0F 0x1A0F | RMDAPDIChannel process data mapping
* @{
* \brief Object 0x1A0F (RMDAPDIChannel process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x60F0.1<br>
* SubIndex 2 - Reference to 0x60F0.2<br>
* SubIndex 3 - Reference to 0x60F0.3<br>
* SubIndex 4 - Reference to 0x60F0.4<br>
* SubIndex 5 - Reference to 0x60F0.5<br>
* SubIndex 6 - Reference to 0x60F0.6<br>
* SubIndex 7 - Reference to 0x60F0.7<br>
* SubIndex 8 - Reference to 0x60F0.8<br>
* SubIndex 9 - Reference to 0x60F0.9<br>
* SubIndex 10 - Reference to 0x60F0.10<br>
* SubIndex 11 - Reference to 0x60F0.11<br>
* SubIndex 12 - Reference to 0x60F0.12<br>
* SubIndex 13 - Reference to 0x60F0.13<br>
* SubIndex 14 - Reference to 0x60F0.14<br>
* SubIndex 15 - Reference to 0x60F0.15<br>
* SubIndex 16 - Reference to 0x60F0.16<br>
* SubIndex 17 - Reference to 0x60F0.17<br>
* SubIndex 18 - Reference to 0x60F0.18<br>
* SubIndex 19 - Reference to 0x60F0.19<br>
* SubIndex 20 - Reference to 0x60F0.20<br>
* SubIndex 21 - Reference to 0x60F0.21<br>
* SubIndex 22 - Reference to 0x60F0.22<br>
* SubIndex 23 - Reference to 0x60F0.23<br>
* SubIndex 24 - Reference to 0x60F0.24<br>
* SubIndex 25 - Reference to 0x60F0.25<br>
* SubIndex 26 - Reference to 0x60F0.26<br>
* SubIndex 27 - Reference to 0x60F0.27<br>
* SubIndex 28 - Reference to 0x60F0.28<br>
* SubIndex 29 - Reference to 0x60F0.29<br>
* SubIndex 30 - Reference to 0x60F0.30<br>
* SubIndex 31 - Reference to 0x60F0.31<br>
* SubIndex 32 - Reference to 0x60F0.32<br>
* SubIndex 33 - Reference to 0x60F0.33<br>
* SubIndex 34 - Reference to 0x60F0.34<br>
* SubIndex 35 - Reference to 0x60F0.35<br>
* SubIndex 36 - Reference to 0x60F0.36<br>
* SubIndex 37 - Reference to 0x60F0.37<br>
* SubIndex 38 - Reference to 0x60F0.38<br>
* SubIndex 39 - Reference to 0x60F0.39<br>
* SubIndex 40 - Reference to 0x60F0.40<br>
* SubIndex 41 - Reference to 0x60F0.41<br>
* SubIndex 42 - Reference to 0x60F0.42<br>
* SubIndex 43 - Reference to 0x60F0.43<br>
* SubIndex 44 - Reference to 0x60F0.44<br>
* SubIndex 45 - Reference to 0x60F0.45<br>
* SubIndex 46 - Reference to 0x60F0.46<br>
* SubIndex 47 - Reference to 0x60F0.47<br>
* SubIndex 48 - Reference to 0x60F0.48<br>
* SubIndex 49 - Reference to 0x60F0.49<br>
* SubIndex 50 - Reference to 0x60F0.50<br>
* SubIndex 51 - Reference to 0x60F0.51<br>
* SubIndex 52 - Reference to 0x60F0.52<br>
* SubIndex 53 - Reference to 0x60F0.53<br>
* SubIndex 54 - Reference to 0x60F0.54<br>
* SubIndex 55 - Reference to 0x60F0.55<br>
* SubIndex 56 - Reference to 0x60F0.56<br>
* SubIndex 57 - Reference to 0x60F0.57<br>
* SubIndex 58 - Reference to 0x60F0.58<br>
* SubIndex 59 - Reference to 0x60F0.59<br>
* SubIndex 60 - Reference to 0x60F0.60<br>
* SubIndex 61 - Reference to 0x60F0.61<br>
* SubIndex 62 - Reference to 0x60F0.62<br>
* SubIndex 63 - Reference to 0x60F0.63<br>
* SubIndex 64 - Reference to 0x60F0.64<br>
* SubIndex 65 - Reference to 0x60F0.65<br>
* SubIndex 66 - Reference to 0x60F0.66<br>
* SubIndex 67 - Reference to 0x60F0.67<br>
* SubIndex 68 - Reference to 0x60F0.68<br>
* SubIndex 69 - Reference to 0x60F0.69<br>
* SubIndex 70 - Reference to 0x60F0.70<br>
* SubIndex 71 - Reference to 0x60F0.71<br>
* SubIndex 72 - Reference to 0x60F0.72<br>
* SubIndex 73 - Reference to 0x60F0.73<br>
* SubIndex 74 - Reference to 0x60F0.74<br>
* SubIndex 75 - Reference to 0x60F0.75<br>
* SubIndex 76 - Reference to 0x60F0.76<br>
* SubIndex 77 - Reference to 0x60F0.77<br>
* SubIndex 78 - Reference to 0x60F0.78<br>
* SubIndex 79 - Reference to 0x60F0.79<br>
* SubIndex 80 - Reference to 0x60F0.80<br>
* SubIndex 81 - Reference to 0x60F0.81<br>
* SubIndex 82 - Reference to 0x60F0.82<br>
* SubIndex 83 - Reference to 0x60F0.83<br>
* SubIndex 84 - Reference to 0x60F0.84<br>
* SubIndex 85 - Reference to 0x60F0.85<br>
* SubIndex 86 - Reference to 0x60F0.86<br>
* SubIndex 87 - Reference to 0x60F0.87<br>
* SubIndex 88 - Reference to 0x60F0.88<br>
* SubIndex 89 - Reference to 0x60F0.89<br>
* SubIndex 90 - Reference to 0x60F0.90<br>
* SubIndex 91 - Reference to 0x60F0.91<br>
* SubIndex 92 - Reference to 0x60F0.92<br>
* SubIndex 93 - Reference to 0x60F0.93<br>
* SubIndex 94 - Reference to 0x60F0.94<br>
* SubIndex 95 - Reference to 0x60F0.95<br>
* SubIndex 96 - Reference to 0x60F0.96<br>
* SubIndex 97 - Reference to 0x60F0.97<br>
* SubIndex 98 - Reference to 0x60F0.98<br>
* SubIndex 99 - Reference to 0x60F0.99<br>
* SubIndex 100 - Reference to 0x60F0.100<br>
* SubIndex 101 - Reference to 0x60F0.101<br>
* SubIndex 102 - Reference to 0x60F0.102<br>
* SubIndex 103 - Reference to 0x60F0.103<br>
* SubIndex 104 - Reference to 0x60F0.104<br>
* SubIndex 105 - Reference to 0x60F0.105<br>
* SubIndex 106 - Reference to 0x60F0.106<br>
* SubIndex 107 - Reference to 0x60F0.107<br>
* SubIndex 108 - Reference to 0x60F0.108<br>
* SubIndex 109 - Reference to 0x60F0.109<br>
* SubIndex 110 - Reference to 0x60F0.110<br>
* SubIndex 111 - Reference to 0x60F0.111<br>
* SubIndex 112 - Reference to 0x60F0.112<br>
* SubIndex 113 - Reference to 0x60F0.113<br>
* SubIndex 114 - Reference to 0x60F0.114<br>
* SubIndex 115 - Reference to 0x60F0.115<br>
* SubIndex 116 - Reference to 0x60F0.116<br>
* SubIndex 117 - Reference to 0x60F0.117<br>
* SubIndex 118 - Reference to 0x60F0.118<br>
* SubIndex 119 - Reference to 0x60F0.119<br>
* SubIndex 120 - Reference to 0x60F0.120<br>
* SubIndex 121 - Reference to 0x60F0.121<br>
* SubIndex 122 - Reference to 0x60F0.122<br>
* SubIndex 123 - Reference to 0x60F0.123<br>
* SubIndex 124 - Reference to 0x60F0.124<br>
* SubIndex 125 - Reference to 0x60F0.125<br>
* SubIndex 126 - Reference to 0x60F0.126<br>
* SubIndex 127 - Reference to 0x60F0.127<br>
* SubIndex 128 - Reference to 0x60F0.128<br>
* SubIndex 129 - Reference to 0x60F0.129<br>
* SubIndex 130 - Reference to 0x60F0.130<br>
* SubIndex 131 - Reference to 0x60F0.131<br>
* SubIndex 132 - Reference to 0x60F0.132<br>
* SubIndex 133 - Reference to 0x60F0.133<br>
* SubIndex 134 - Reference to 0x60F0.134<br>
* SubIndex 135 - Reference to 0x60F0.135<br>
* SubIndex 136 - Reference to 0x60F0.136<br>
* SubIndex 137 - Reference to 0x60F0.137<br>
* SubIndex 138 - Reference to 0x60F0.138<br>
* SubIndex 139 - Reference to 0x60F0.139<br>
* SubIndex 140 - Reference to 0x60F0.140<br>
* SubIndex 141 - Reference to 0x60F0.141<br>
* SubIndex 142 - Reference to 0x60F0.142<br>
* SubIndex 143 - Reference to 0x60F0.143<br>
* SubIndex 144 - Reference to 0x60F0.144<br>
* SubIndex 145 - Reference to 0x60F0.145<br>
* SubIndex 146 - Reference to 0x60F0.146<br>
* SubIndex 147 - Reference to 0x60F0.147<br>
* SubIndex 148 - Reference to 0x60F0.148<br>
* SubIndex 149 - Reference to 0x60F0.149<br>
* SubIndex 150 - Reference to 0x60F0.150<br>
* SubIndex 151 - Reference to 0x60F0.151<br>
* SubIndex 152 - Reference to 0x60F0.152<br>
* SubIndex 153 - Reference to 0x60F0.153<br>
* SubIndex 154 - Reference to 0x60F0.154<br>
* SubIndex 155 - Reference to 0x60F0.155<br>
* SubIndex 156 - Reference to 0x60F0.156<br>
* SubIndex 157 - Reference to 0x60F0.157<br>
* SubIndex 158 - Reference to 0x60F0.158<br>
* SubIndex 159 - Reference to 0x60F0.159<br>
* SubIndex 160 - Reference to 0x60F0.160<br>
* SubIndex 161 - Reference to 0x60F0.161<br>
* SubIndex 162 - Reference to 0x60F0.162<br>
* SubIndex 163 - Reference to 0x60F0.163<br>
* SubIndex 164 - Reference to 0x60F0.164<br>
* SubIndex 165 - Reference to 0x60F0.165<br>
* SubIndex 166 - Reference to 0x60F0.166<br>
* SubIndex 167 - Reference to 0x60F0.167<br>
* SubIndex 168 - Reference to 0x60F0.168<br>
* SubIndex 169 - Reference to 0x60F0.169<br>
* SubIndex 170 - Reference to 0x60F0.170<br>
* SubIndex 171 - Reference to 0x60F0.171<br>
* SubIndex 172 - Reference to 0x60F0.172<br>
* SubIndex 173 - Reference to 0x60F0.173<br>
* SubIndex 174 - Reference to 0x60F0.174<br>
* SubIndex 175 - Reference to 0x60F0.175<br>
* SubIndex 176 - Reference to 0x60F0.176<br>
* SubIndex 177 - Reference to 0x60F0.177<br>
* SubIndex 178 - Reference to 0x60F0.178<br>
* SubIndex 179 - Reference to 0x60F0.179<br>
* SubIndex 180 - Reference to 0x60F0.180<br>
* SubIndex 181 - Reference to 0x60F0.181<br>
* SubIndex 182 - Reference to 0x60F0.182<br>
* SubIndex 183 - Reference to 0x60F0.183<br>
* SubIndex 184 - Reference to 0x60F0.184<br>
* SubIndex 185 - Reference to 0x60F0.185<br>
* SubIndex 186 - Reference to 0x60F0.186<br>
* SubIndex 187 - Reference to 0x60F0.187<br>
* SubIndex 188 - Reference to 0x60F0.188<br>
* SubIndex 189 - Reference to 0x60F0.189<br>
* SubIndex 190 - Reference to 0x60F0.190<br>
* SubIndex 191 - Reference to 0x60F0.191<br>
* SubIndex 192 - Reference to 0x60F0.192<br>
* SubIndex 193 - Reference to 0x60F0.193<br>
* SubIndex 194 - Reference to 0x60F0.194<br>
* SubIndex 195 - Reference to 0x60F0.195<br>
* SubIndex 196 - Reference to 0x60F0.196<br>
* SubIndex 197 - Reference to 0x60F0.197<br>
* SubIndex 198 - Reference to 0x60F0.198<br>
* SubIndex 199 - Reference to 0x60F0.199<br>
* SubIndex 200 - Reference to 0x60F0.200<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A0F[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x60F0.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x60F0.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x60F0.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x60F0.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x60F0.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x60F0.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x60F0.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x60F0.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x60F0.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x60F0.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x60F0.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x60F0.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x60F0.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x60F0.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x60F0.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x60F0.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x60F0.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x60F0.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x60F0.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x60F0.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x60F0.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x60F0.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x60F0.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x60F0.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 - Reference to 0x60F0.25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 - Reference to 0x60F0.26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 - Reference to 0x60F0.27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 - Reference to 0x60F0.28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 - Reference to 0x60F0.29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 - Reference to 0x60F0.30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 - Reference to 0x60F0.31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 - Reference to 0x60F0.32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 - Reference to 0x60F0.33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 - Reference to 0x60F0.34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 - Reference to 0x60F0.35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 - Reference to 0x60F0.36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 - Reference to 0x60F0.37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 - Reference to 0x60F0.38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 - Reference to 0x60F0.39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 - Reference to 0x60F0.40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 - Reference to 0x60F0.41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 - Reference to 0x60F0.42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 - Reference to 0x60F0.43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 - Reference to 0x60F0.44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 - Reference to 0x60F0.45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 - Reference to 0x60F0.46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 - Reference to 0x60F0.47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 - Reference to 0x60F0.48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 - Reference to 0x60F0.49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 - Reference to 0x60F0.50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 - Reference to 0x60F0.51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 - Reference to 0x60F0.52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 - Reference to 0x60F0.53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 - Reference to 0x60F0.54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 - Reference to 0x60F0.55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 - Reference to 0x60F0.56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 - Reference to 0x60F0.57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 - Reference to 0x60F0.58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 - Reference to 0x60F0.59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 - Reference to 0x60F0.60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 - Reference to 0x60F0.61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 - Reference to 0x60F0.62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 - Reference to 0x60F0.63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 - Reference to 0x60F0.64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 - Reference to 0x60F0.65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 - Reference to 0x60F0.66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 - Reference to 0x60F0.67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 - Reference to 0x60F0.68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 - Reference to 0x60F0.69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 - Reference to 0x60F0.70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 - Reference to 0x60F0.71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 - Reference to 0x60F0.72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 - Reference to 0x60F0.73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 - Reference to 0x60F0.74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 - Reference to 0x60F0.75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 - Reference to 0x60F0.76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 - Reference to 0x60F0.77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 - Reference to 0x60F0.78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 - Reference to 0x60F0.79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 - Reference to 0x60F0.80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 - Reference to 0x60F0.81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 - Reference to 0x60F0.82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 - Reference to 0x60F0.83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 - Reference to 0x60F0.84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 - Reference to 0x60F0.85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 - Reference to 0x60F0.86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 - Reference to 0x60F0.87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 - Reference to 0x60F0.88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 - Reference to 0x60F0.89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 - Reference to 0x60F0.90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 - Reference to 0x60F0.91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 - Reference to 0x60F0.92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 - Reference to 0x60F0.93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 - Reference to 0x60F0.94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 - Reference to 0x60F0.95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 - Reference to 0x60F0.96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 - Reference to 0x60F0.97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 - Reference to 0x60F0.98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 - Reference to 0x60F0.99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 - Reference to 0x60F0.100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 - Reference to 0x60F0.101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 - Reference to 0x60F0.102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 - Reference to 0x60F0.103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 - Reference to 0x60F0.104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 - Reference to 0x60F0.105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 - Reference to 0x60F0.106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 - Reference to 0x60F0.107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 - Reference to 0x60F0.108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 - Reference to 0x60F0.109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 - Reference to 0x60F0.110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 - Reference to 0x60F0.111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 - Reference to 0x60F0.112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 - Reference to 0x60F0.113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 - Reference to 0x60F0.114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex115 - Reference to 0x60F0.115 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex116 - Reference to 0x60F0.116 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex117 - Reference to 0x60F0.117 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex118 - Reference to 0x60F0.118 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex119 - Reference to 0x60F0.119 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex120 - Reference to 0x60F0.120 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex121 - Reference to 0x60F0.121 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex122 - Reference to 0x60F0.122 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex123 - Reference to 0x60F0.123 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex124 - Reference to 0x60F0.124 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex125 - Reference to 0x60F0.125 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex126 - Reference to 0x60F0.126 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex127 - Reference to 0x60F0.127 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex128 - Reference to 0x60F0.128 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex129 - Reference to 0x60F0.129 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex130 - Reference to 0x60F0.130 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex131 - Reference to 0x60F0.131 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex132 - Reference to 0x60F0.132 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex133 - Reference to 0x60F0.133 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex134 - Reference to 0x60F0.134 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex135 - Reference to 0x60F0.135 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex136 - Reference to 0x60F0.136 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex137 - Reference to 0x60F0.137 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex138 - Reference to 0x60F0.138 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex139 - Reference to 0x60F0.139 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex140 - Reference to 0x60F0.140 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex141 - Reference to 0x60F0.141 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex142 - Reference to 0x60F0.142 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex143 - Reference to 0x60F0.143 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex144 - Reference to 0x60F0.144 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex145 - Reference to 0x60F0.145 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex146 - Reference to 0x60F0.146 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex147 - Reference to 0x60F0.147 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex148 - Reference to 0x60F0.148 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex149 - Reference to 0x60F0.149 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex150 - Reference to 0x60F0.150 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex151 - Reference to 0x60F0.151 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex152 - Reference to 0x60F0.152 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex153 - Reference to 0x60F0.153 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex154 - Reference to 0x60F0.154 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex155 - Reference to 0x60F0.155 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex156 - Reference to 0x60F0.156 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex157 - Reference to 0x60F0.157 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex158 - Reference to 0x60F0.158 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex159 - Reference to 0x60F0.159 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex160 - Reference to 0x60F0.160 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex161 - Reference to 0x60F0.161 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex162 - Reference to 0x60F0.162 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex163 - Reference to 0x60F0.163 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex164 - Reference to 0x60F0.164 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex165 - Reference to 0x60F0.165 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex166 - Reference to 0x60F0.166 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex167 - Reference to 0x60F0.167 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex168 - Reference to 0x60F0.168 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex169 - Reference to 0x60F0.169 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex170 - Reference to 0x60F0.170 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex171 - Reference to 0x60F0.171 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex172 - Reference to 0x60F0.172 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex173 - Reference to 0x60F0.173 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex174 - Reference to 0x60F0.174 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex175 - Reference to 0x60F0.175 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex176 - Reference to 0x60F0.176 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex177 - Reference to 0x60F0.177 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex178 - Reference to 0x60F0.178 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex179 - Reference to 0x60F0.179 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex180 - Reference to 0x60F0.180 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex181 - Reference to 0x60F0.181 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex182 - Reference to 0x60F0.182 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex183 - Reference to 0x60F0.183 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex184 - Reference to 0x60F0.184 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex185 - Reference to 0x60F0.185 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex186 - Reference to 0x60F0.186 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex187 - Reference to 0x60F0.187 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex188 - Reference to 0x60F0.188 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex189 - Reference to 0x60F0.189 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex190 - Reference to 0x60F0.190 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex191 - Reference to 0x60F0.191 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex192 - Reference to 0x60F0.192 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex193 - Reference to 0x60F0.193 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex194 - Reference to 0x60F0.194 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex195 - Reference to 0x60F0.195 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex196 - Reference to 0x60F0.196 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex197 - Reference to 0x60F0.197 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex198 - Reference to 0x60F0.198 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex199 - Reference to 0x60F0.199 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex200 - Reference to 0x60F0.200 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A0F[] = "RMDAPDIChannel process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000"
"SubIndex 069\000"
"SubIndex 070\000"
"SubIndex 071\000"
"SubIndex 072\000"
"SubIndex 073\000"
"SubIndex 074\000"
"SubIndex 075\000"
"SubIndex 076\000"
"SubIndex 077\000"
"SubIndex 078\000"
"SubIndex 079\000"
"SubIndex 080\000"
"SubIndex 081\000"
"SubIndex 082\000"
"SubIndex 083\000"
"SubIndex 084\000"
"SubIndex 085\000"
"SubIndex 086\000"
"SubIndex 087\000"
"SubIndex 088\000"
"SubIndex 089\000"
"SubIndex 090\000"
"SubIndex 091\000"
"SubIndex 092\000"
"SubIndex 093\000"
"SubIndex 094\000"
"SubIndex 095\000"
"SubIndex 096\000"
"SubIndex 097\000"
"SubIndex 098\000"
"SubIndex 099\000"
"SubIndex 100\000"
"SubIndex 101\000"
"SubIndex 102\000"
"SubIndex 103\000"
"SubIndex 104\000"
"SubIndex 105\000"
"SubIndex 106\000"
"SubIndex 107\000"
"SubIndex 108\000"
"SubIndex 109\000"
"SubIndex 110\000"
"SubIndex 111\000"
"SubIndex 112\000"
"SubIndex 113\000"
"SubIndex 114\000"
"SubIndex 115\000"
"SubIndex 116\000"
"SubIndex 117\000"
"SubIndex 118\000"
"SubIndex 119\000"
"SubIndex 120\000"
"SubIndex 121\000"
"SubIndex 122\000"
"SubIndex 123\000"
"SubIndex 124\000"
"SubIndex 125\000"
"SubIndex 126\000"
"SubIndex 127\000"
"SubIndex 128\000"
"SubIndex 129\000"
"SubIndex 130\000"
"SubIndex 131\000"
"SubIndex 132\000"
"SubIndex 133\000"
"SubIndex 134\000"
"SubIndex 135\000"
"SubIndex 136\000"
"SubIndex 137\000"
"SubIndex 138\000"
"SubIndex 139\000"
"SubIndex 140\000"
"SubIndex 141\000"
"SubIndex 142\000"
"SubIndex 143\000"
"SubIndex 144\000"
"SubIndex 145\000"
"SubIndex 146\000"
"SubIndex 147\000"
"SubIndex 148\000"
"SubIndex 149\000"
"SubIndex 150\000"
"SubIndex 151\000"
"SubIndex 152\000"
"SubIndex 153\000"
"SubIndex 154\000"
"SubIndex 155\000"
"SubIndex 156\000"
"SubIndex 157\000"
"SubIndex 158\000"
"SubIndex 159\000"
"SubIndex 160\000"
"SubIndex 161\000"
"SubIndex 162\000"
"SubIndex 163\000"
"SubIndex 164\000"
"SubIndex 165\000"
"SubIndex 166\000"
"SubIndex 167\000"
"SubIndex 168\000"
"SubIndex 169\000"
"SubIndex 170\000"
"SubIndex 171\000"
"SubIndex 172\000"
"SubIndex 173\000"
"SubIndex 174\000"
"SubIndex 175\000"
"SubIndex 176\000"
"SubIndex 177\000"
"SubIndex 178\000"
"SubIndex 179\000"
"SubIndex 180\000"
"SubIndex 181\000"
"SubIndex 182\000"
"SubIndex 183\000"
"SubIndex 184\000"
"SubIndex 185\000"
"SubIndex 186\000"
"SubIndex 187\000"
"SubIndex 188\000"
"SubIndex 189\000"
"SubIndex 190\000"
"SubIndex 191\000"
"SubIndex 192\000"
"SubIndex 193\000"
"SubIndex 194\000"
"SubIndex 195\000"
"SubIndex 196\000"
"SubIndex 197\000"
"SubIndex 198\000"
"SubIndex 199\000"
"SubIndex 200\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x60F0.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x60F0.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x60F0.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x60F0.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x60F0.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x60F0.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x60F0.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x60F0.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x60F0.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x60F0.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x60F0.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x60F0.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x60F0.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x60F0.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x60F0.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x60F0.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x60F0.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x60F0.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x60F0.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x60F0.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x60F0.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x60F0.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x60F0.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x60F0.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x60F0.25 */
UINT32 SI26; /* Subindex26 - Reference to 0x60F0.26 */
UINT32 SI27; /* Subindex27 - Reference to 0x60F0.27 */
UINT32 SI28; /* Subindex28 - Reference to 0x60F0.28 */
UINT32 SI29; /* Subindex29 - Reference to 0x60F0.29 */
UINT32 SI30; /* Subindex30 - Reference to 0x60F0.30 */
UINT32 SI31; /* Subindex31 - Reference to 0x60F0.31 */
UINT32 SI32; /* Subindex32 - Reference to 0x60F0.32 */
UINT32 SI33; /* Subindex33 - Reference to 0x60F0.33 */
UINT32 SI34; /* Subindex34 - Reference to 0x60F0.34 */
UINT32 SI35; /* Subindex35 - Reference to 0x60F0.35 */
UINT32 SI36; /* Subindex36 - Reference to 0x60F0.36 */
UINT32 SI37; /* Subindex37 - Reference to 0x60F0.37 */
UINT32 SI38; /* Subindex38 - Reference to 0x60F0.38 */
UINT32 SI39; /* Subindex39 - Reference to 0x60F0.39 */
UINT32 SI40; /* Subindex40 - Reference to 0x60F0.40 */
UINT32 SI41; /* Subindex41 - Reference to 0x60F0.41 */
UINT32 SI42; /* Subindex42 - Reference to 0x60F0.42 */
UINT32 SI43; /* Subindex43 - Reference to 0x60F0.43 */
UINT32 SI44; /* Subindex44 - Reference to 0x60F0.44 */
UINT32 SI45; /* Subindex45 - Reference to 0x60F0.45 */
UINT32 SI46; /* Subindex46 - Reference to 0x60F0.46 */
UINT32 SI47; /* Subindex47 - Reference to 0x60F0.47 */
UINT32 SI48; /* Subindex48 - Reference to 0x60F0.48 */
UINT32 SI49; /* Subindex49 - Reference to 0x60F0.49 */
UINT32 SI50; /* Subindex50 - Reference to 0x60F0.50 */
UINT32 SI51; /* Subindex51 - Reference to 0x60F0.51 */
UINT32 SI52; /* Subindex52 - Reference to 0x60F0.52 */
UINT32 SI53; /* Subindex53 - Reference to 0x60F0.53 */
UINT32 SI54; /* Subindex54 - Reference to 0x60F0.54 */
UINT32 SI55; /* Subindex55 - Reference to 0x60F0.55 */
UINT32 SI56; /* Subindex56 - Reference to 0x60F0.56 */
UINT32 SI57; /* Subindex57 - Reference to 0x60F0.57 */
UINT32 SI58; /* Subindex58 - Reference to 0x60F0.58 */
UINT32 SI59; /* Subindex59 - Reference to 0x60F0.59 */
UINT32 SI60; /* Subindex60 - Reference to 0x60F0.60 */
UINT32 SI61; /* Subindex61 - Reference to 0x60F0.61 */
UINT32 SI62; /* Subindex62 - Reference to 0x60F0.62 */
UINT32 SI63; /* Subindex63 - Reference to 0x60F0.63 */
UINT32 SI64; /* Subindex64 - Reference to 0x60F0.64 */
UINT32 SI65; /* Subindex65 - Reference to 0x60F0.65 */
UINT32 SI66; /* Subindex66 - Reference to 0x60F0.66 */
UINT32 SI67; /* Subindex67 - Reference to 0x60F0.67 */
UINT32 SI68; /* Subindex68 - Reference to 0x60F0.68 */
UINT32 SI69; /* Subindex69 - Reference to 0x60F0.69 */
UINT32 SI70; /* Subindex70 - Reference to 0x60F0.70 */
UINT32 SI71; /* Subindex71 - Reference to 0x60F0.71 */
UINT32 SI72; /* Subindex72 - Reference to 0x60F0.72 */
UINT32 SI73; /* Subindex73 - Reference to 0x60F0.73 */
UINT32 SI74; /* Subindex74 - Reference to 0x60F0.74 */
UINT32 SI75; /* Subindex75 - Reference to 0x60F0.75 */
UINT32 SI76; /* Subindex76 - Reference to 0x60F0.76 */
UINT32 SI77; /* Subindex77 - Reference to 0x60F0.77 */
UINT32 SI78; /* Subindex78 - Reference to 0x60F0.78 */
UINT32 SI79; /* Subindex79 - Reference to 0x60F0.79 */
UINT32 SI80; /* Subindex80 - Reference to 0x60F0.80 */
UINT32 SI81; /* Subindex81 - Reference to 0x60F0.81 */
UINT32 SI82; /* Subindex82 - Reference to 0x60F0.82 */
UINT32 SI83; /* Subindex83 - Reference to 0x60F0.83 */
UINT32 SI84; /* Subindex84 - Reference to 0x60F0.84 */
UINT32 SI85; /* Subindex85 - Reference to 0x60F0.85 */
UINT32 SI86; /* Subindex86 - Reference to 0x60F0.86 */
UINT32 SI87; /* Subindex87 - Reference to 0x60F0.87 */
UINT32 SI88; /* Subindex88 - Reference to 0x60F0.88 */
UINT32 SI89; /* Subindex89 - Reference to 0x60F0.89 */
UINT32 SI90; /* Subindex90 - Reference to 0x60F0.90 */
UINT32 SI91; /* Subindex91 - Reference to 0x60F0.91 */
UINT32 SI92; /* Subindex92 - Reference to 0x60F0.92 */
UINT32 SI93; /* Subindex93 - Reference to 0x60F0.93 */
UINT32 SI94; /* Subindex94 - Reference to 0x60F0.94 */
UINT32 SI95; /* Subindex95 - Reference to 0x60F0.95 */
UINT32 SI96; /* Subindex96 - Reference to 0x60F0.96 */
UINT32 SI97; /* Subindex97 - Reference to 0x60F0.97 */
UINT32 SI98; /* Subindex98 - Reference to 0x60F0.98 */
UINT32 SI99; /* Subindex99 - Reference to 0x60F0.99 */
UINT32 SI100; /* Subindex100 - Reference to 0x60F0.100 */
UINT32 SI101; /* Subindex101 - Reference to 0x60F0.101 */
UINT32 SI102; /* Subindex102 - Reference to 0x60F0.102 */
UINT32 SI103; /* Subindex103 - Reference to 0x60F0.103 */
UINT32 SI104; /* Subindex104 - Reference to 0x60F0.104 */
UINT32 SI105; /* Subindex105 - Reference to 0x60F0.105 */
UINT32 SI106; /* Subindex106 - Reference to 0x60F0.106 */
UINT32 SI107; /* Subindex107 - Reference to 0x60F0.107 */
UINT32 SI108; /* Subindex108 - Reference to 0x60F0.108 */
UINT32 SI109; /* Subindex109 - Reference to 0x60F0.109 */
UINT32 SI110; /* Subindex110 - Reference to 0x60F0.110 */
UINT32 SI111; /* Subindex111 - Reference to 0x60F0.111 */
UINT32 SI112; /* Subindex112 - Reference to 0x60F0.112 */
UINT32 SI113; /* Subindex113 - Reference to 0x60F0.113 */
UINT32 SI114; /* Subindex114 - Reference to 0x60F0.114 */
UINT32 SI115; /* Subindex115 - Reference to 0x60F0.115 */
UINT32 SI116; /* Subindex116 - Reference to 0x60F0.116 */
UINT32 SI117; /* Subindex117 - Reference to 0x60F0.117 */
UINT32 SI118; /* Subindex118 - Reference to 0x60F0.118 */
UINT32 SI119; /* Subindex119 - Reference to 0x60F0.119 */
UINT32 SI120; /* Subindex120 - Reference to 0x60F0.120 */
UINT32 SI121; /* Subindex121 - Reference to 0x60F0.121 */
UINT32 SI122; /* Subindex122 - Reference to 0x60F0.122 */
UINT32 SI123; /* Subindex123 - Reference to 0x60F0.123 */
UINT32 SI124; /* Subindex124 - Reference to 0x60F0.124 */
UINT32 SI125; /* Subindex125 - Reference to 0x60F0.125 */
UINT32 SI126; /* Subindex126 - Reference to 0x60F0.126 */
UINT32 SI127; /* Subindex127 - Reference to 0x60F0.127 */
UINT32 SI128; /* Subindex128 - Reference to 0x60F0.128 */
UINT32 SI129; /* Subindex129 - Reference to 0x60F0.129 */
UINT32 SI130; /* Subindex130 - Reference to 0x60F0.130 */
UINT32 SI131; /* Subindex131 - Reference to 0x60F0.131 */
UINT32 SI132; /* Subindex132 - Reference to 0x60F0.132 */
UINT32 SI133; /* Subindex133 - Reference to 0x60F0.133 */
UINT32 SI134; /* Subindex134 - Reference to 0x60F0.134 */
UINT32 SI135; /* Subindex135 - Reference to 0x60F0.135 */
UINT32 SI136; /* Subindex136 - Reference to 0x60F0.136 */
UINT32 SI137; /* Subindex137 - Reference to 0x60F0.137 */
UINT32 SI138; /* Subindex138 - Reference to 0x60F0.138 */
UINT32 SI139; /* Subindex139 - Reference to 0x60F0.139 */
UINT32 SI140; /* Subindex140 - Reference to 0x60F0.140 */
UINT32 SI141; /* Subindex141 - Reference to 0x60F0.141 */
UINT32 SI142; /* Subindex142 - Reference to 0x60F0.142 */
UINT32 SI143; /* Subindex143 - Reference to 0x60F0.143 */
UINT32 SI144; /* Subindex144 - Reference to 0x60F0.144 */
UINT32 SI145; /* Subindex145 - Reference to 0x60F0.145 */
UINT32 SI146; /* Subindex146 - Reference to 0x60F0.146 */
UINT32 SI147; /* Subindex147 - Reference to 0x60F0.147 */
UINT32 SI148; /* Subindex148 - Reference to 0x60F0.148 */
UINT32 SI149; /* Subindex149 - Reference to 0x60F0.149 */
UINT32 SI150; /* Subindex150 - Reference to 0x60F0.150 */
UINT32 SI151; /* Subindex151 - Reference to 0x60F0.151 */
UINT32 SI152; /* Subindex152 - Reference to 0x60F0.152 */
UINT32 SI153; /* Subindex153 - Reference to 0x60F0.153 */
UINT32 SI154; /* Subindex154 - Reference to 0x60F0.154 */
UINT32 SI155; /* Subindex155 - Reference to 0x60F0.155 */
UINT32 SI156; /* Subindex156 - Reference to 0x60F0.156 */
UINT32 SI157; /* Subindex157 - Reference to 0x60F0.157 */
UINT32 SI158; /* Subindex158 - Reference to 0x60F0.158 */
UINT32 SI159; /* Subindex159 - Reference to 0x60F0.159 */
UINT32 SI160; /* Subindex160 - Reference to 0x60F0.160 */
UINT32 SI161; /* Subindex161 - Reference to 0x60F0.161 */
UINT32 SI162; /* Subindex162 - Reference to 0x60F0.162 */
UINT32 SI163; /* Subindex163 - Reference to 0x60F0.163 */
UINT32 SI164; /* Subindex164 - Reference to 0x60F0.164 */
UINT32 SI165; /* Subindex165 - Reference to 0x60F0.165 */
UINT32 SI166; /* Subindex166 - Reference to 0x60F0.166 */
UINT32 SI167; /* Subindex167 - Reference to 0x60F0.167 */
UINT32 SI168; /* Subindex168 - Reference to 0x60F0.168 */
UINT32 SI169; /* Subindex169 - Reference to 0x60F0.169 */
UINT32 SI170; /* Subindex170 - Reference to 0x60F0.170 */
UINT32 SI171; /* Subindex171 - Reference to 0x60F0.171 */
UINT32 SI172; /* Subindex172 - Reference to 0x60F0.172 */
UINT32 SI173; /* Subindex173 - Reference to 0x60F0.173 */
UINT32 SI174; /* Subindex174 - Reference to 0x60F0.174 */
UINT32 SI175; /* Subindex175 - Reference to 0x60F0.175 */
UINT32 SI176; /* Subindex176 - Reference to 0x60F0.176 */
UINT32 SI177; /* Subindex177 - Reference to 0x60F0.177 */
UINT32 SI178; /* Subindex178 - Reference to 0x60F0.178 */
UINT32 SI179; /* Subindex179 - Reference to 0x60F0.179 */
UINT32 SI180; /* Subindex180 - Reference to 0x60F0.180 */
UINT32 SI181; /* Subindex181 - Reference to 0x60F0.181 */
UINT32 SI182; /* Subindex182 - Reference to 0x60F0.182 */
UINT32 SI183; /* Subindex183 - Reference to 0x60F0.183 */
UINT32 SI184; /* Subindex184 - Reference to 0x60F0.184 */
UINT32 SI185; /* Subindex185 - Reference to 0x60F0.185 */
UINT32 SI186; /* Subindex186 - Reference to 0x60F0.186 */
UINT32 SI187; /* Subindex187 - Reference to 0x60F0.187 */
UINT32 SI188; /* Subindex188 - Reference to 0x60F0.188 */
UINT32 SI189; /* Subindex189 - Reference to 0x60F0.189 */
UINT32 SI190; /* Subindex190 - Reference to 0x60F0.190 */
UINT32 SI191; /* Subindex191 - Reference to 0x60F0.191 */
UINT32 SI192; /* Subindex192 - Reference to 0x60F0.192 */
UINT32 SI193; /* Subindex193 - Reference to 0x60F0.193 */
UINT32 SI194; /* Subindex194 - Reference to 0x60F0.194 */
UINT32 SI195; /* Subindex195 - Reference to 0x60F0.195 */
UINT32 SI196; /* Subindex196 - Reference to 0x60F0.196 */
UINT32 SI197; /* Subindex197 - Reference to 0x60F0.197 */
UINT32 SI198; /* Subindex198 - Reference to 0x60F0.198 */
UINT32 SI199; /* Subindex199 - Reference to 0x60F0.199 */
UINT32 SI200; /* Subindex200 - Reference to 0x60F0.200 */
} OBJ_STRUCT_PACKED_END
TOBJ1A0F;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A0F RMDAPDIChannelProcessDataMapping0x1A0F
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={200,0x60F00108,0x60F00208,0x60F00308,0x60F00408,0x60F00508,0x60F00608,0x60F00708,0x60F00808,0x60F00908,0x60F00A08,0x60F00B08,0x60F00C08,0x60F00D08,0x60F00E08,0x60F00F08,0x60F01008,0x60F01108,0x60F01208,0x60F01308,0x60F01408,0x60F01508,0x60F01608,0x60F01708,0x60F01808,0x60F01908,0x60F01A08,0x60F01B08,0x60F01C08,0x60F01D08,0x60F01E08,0x60F01F08,0x60F02008,0x60F02108,0x60F02208,0x60F02308,0x60F02408,0x60F02508,0x60F02608,0x60F02708,0x60F02808,0x60F02908,0x60F02A08,0x60F02B08,0x60F02C08,0x60F02D08,0x60F02E08,0x60F02F08,0x60F03008,0x60F03108,0x60F03208,0x60F03308,0x60F03408,0x60F03508,0x60F03608,0x60F03708,0x60F03808,0x60F03908,0x60F03A08,0x60F03B08,0x60F03C08,0x60F03D08,0x60F03E08,0x60F03F08,0x60F04008,0x60F04108,0x60F04208,0x60F04308,0x60F04408,0x60F04508,0x60F04608,0x60F04708,0x60F04808,0x60F04908,0x60F04A08,0x60F04B08,0x60F04C08,0x60F04D08,0x60F04E08,0x60F04F08,0x60F05008,0x60F05108,0x60F05208,0x60F05308,0x60F05408,0x60F05508,0x60F05608,0x60F05708,0x60F05808,0x60F05908,0x60F05A08,0x60F05B08,0x60F05C08,0x60F05D08,0x60F05E08,0x60F05F08,0x60F06008,0x60F06108,0x60F06208,0x60F06308,0x60F06408,0x60F06508,0x60F06608,0x60F06708,0x60F06808,0x60F06908,0x60F06A08,0x60F06B08,0x60F06C08,0x60F06D08,0x60F06E08,0x60F06F08,0x60F07008,0x60F07108,0x60F07208,0x60F07308,0x60F07408,0x60F07508,0x60F07608,0x60F07708,0x60F07808,0x60F07908,0x60F07A08,0x60F07B08,0x60F07C08,0x60F07D08,0x60F07E08,0x60F07F08,0x60F08008,0x60F08108,0x60F08208,0x60F08308,0x60F08408,0x60F08508,0x60F08608,0x60F08708,0x60F08808,0x60F08908,0x60F08A08,0x60F08B08,0x60F08C08,0x60F08D08,0x60F08E08,0x60F08F08,0x60F09008,0x60F09108,0x60F09208,0x60F09308,0x60F09408,0x60F09508,0x60F09608,0x60F09708,0x60F09808,0x60F09908,0x60F09A08,0x60F09B08,0x60F09C08,0x60F09D08,0x60F09E08,0x60F09F08,0x60F0A008,0x60F0A108,0x60F0A208,0x60F0A308,0x60F0A408,0x60F0A508,0x60F0A608,0x60F0A708,0x60F0A808,0x60F0A908,0x60F0AA08,0x60F0AB08,0x60F0AC08,0x60F0AD08,0x60F0AE08,0x60F0AF08,0x60F0B008,0x60F0B108,0x60F0B208,0x60F0B308,0x60F0B408,0x60F0B508,0x60F0B608,0x60F0B708,0x60F0B808,0x60F0B908,0x60F0BA08,0x60F0BB08,0x60F0BC08,0x60F0BD08,0x60F0BE08,0x60F0BF08,0x60F0C008,0x60F0C108,0x60F0C208,0x60F0C308,0x60F0C408,0x60F0C508,0x60F0C608,0x60F0C708,0x60F0C808}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[2];  /**< \brief Subindex 1 - 2 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={2,{0x1600,0x1605}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[2];  /**< \brief Subindex 1 - 2 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={2,{0x1A00,0x1A0F}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : PDIChannel
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | PDIChannel
* @{
* \brief Object 0x6000 (PDIChannel) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - AX1<br>
* SubIndex 2 - AX2<br>
* SubIndex 3 - AY1<br>
* SubIndex 4 - AY2<br>
* SubIndex 5 - AZ1<br>
* SubIndex 6 - AZ2<br>
* SubIndex 7 - GX1<br>
* SubIndex 8 - GX2<br>
* SubIndex 9 - GY1<br>
* SubIndex 10 - GY2<br>
* SubIndex 11 - GZ1<br>
* SubIndex 12 - GZ2<br>
* SubIndex 13 - T1<br>
* SubIndex 14 - T2<br>
* SubIndex 15 - C1AID1<br>
* SubIndex 16 - C1AID2<br>
* SubIndex 17 - C1A1<br>
* SubIndex 18 - C1A2<br>
* SubIndex 19 - C1A3<br>
* SubIndex 20 - C1A4<br>
* SubIndex 21 - C1A5<br>
* SubIndex 22 - C1A6<br>
* SubIndex 23 - C1A7<br>
* SubIndex 24 - C1A8<br>
* SubIndex 25 - C1BID1<br>
* SubIndex 26 - C1BID2<br>
* SubIndex 27 - C1B1<br>
* SubIndex 28 - C1B2<br>
* SubIndex 29 - C1B3<br>
* SubIndex 30 - C1B4<br>
* SubIndex 31 - C1B5<br>
* SubIndex 32 - C1B6<br>
* SubIndex 33 - C1B7<br>
* SubIndex 34 - C1B8<br>
* SubIndex 35 - C1CID1<br>
* SubIndex 36 - C1CID2<br>
* SubIndex 37 - C1C1<br>
* SubIndex 38 - C1C2<br>
* SubIndex 39 - C1C3<br>
* SubIndex 40 - C1C4<br>
* SubIndex 41 - C1C5<br>
* SubIndex 42 - C1C6<br>
* SubIndex 43 - C1C7<br>
* SubIndex 44 - C1C8<br>
* SubIndex 45 - C1DID1<br>
* SubIndex 46 - C1DID2<br>
* SubIndex 47 - C1D1<br>
* SubIndex 48 - C1D2<br>
* SubIndex 49 - C1D3<br>
* SubIndex 50 - C1D4<br>
* SubIndex 51 - C1D5<br>
* SubIndex 52 - C1D6<br>
* SubIndex 53 - C1D7<br>
* SubIndex 54 - C1D8<br>
* SubIndex 55 - C1EID1<br>
* SubIndex 56 - C1EID2<br>
* SubIndex 57 - C1E1<br>
* SubIndex 58 - C1E2<br>
* SubIndex 59 - C1E3<br>
* SubIndex 60 - C1E4<br>
* SubIndex 61 - C1E5<br>
* SubIndex 62 - C1E6<br>
* SubIndex 63 - C1E7<br>
* SubIndex 64 - C1E8<br>
* SubIndex 65 - C1FID1<br>
* SubIndex 66 - C1FID2<br>
* SubIndex 67 - C1F1<br>
* SubIndex 68 - C1F2<br>
* SubIndex 69 - C1F3<br>
* SubIndex 70 - C1F4<br>
* SubIndex 71 - C1F5<br>
* SubIndex 72 - C1F6<br>
* SubIndex 73 - C1F7<br>
* SubIndex 74 - C1F8<br>
* SubIndex 75 - C2AID1<br>
* SubIndex 76 - C2AID2<br>
* SubIndex 77 - C2A1<br>
* SubIndex 78 - C2A2<br>
* SubIndex 79 - C2A3<br>
* SubIndex 80 - C2A4<br>
* SubIndex 81 - C2A5<br>
* SubIndex 82 - C2A6<br>
* SubIndex 83 - C2A7<br>
* SubIndex 84 - C2A8<br>
* SubIndex 85 - C2BID1<br>
* SubIndex 86 - C2BID2<br>
* SubIndex 87 - C2B1<br>
* SubIndex 88 - C2B2<br>
* SubIndex 89 - C2B3<br>
* SubIndex 90 - C2B4<br>
* SubIndex 91 - C2B5<br>
* SubIndex 92 - C2B6<br>
* SubIndex 93 - C2B7<br>
* SubIndex 94 - C2B8<br>
* SubIndex 95 - C2CID1<br>
* SubIndex 96 - C2CID2<br>
* SubIndex 97 - C2C1<br>
* SubIndex 98 - C2C2<br>
* SubIndex 99 - C2C3<br>
* SubIndex 100 - C2C4<br>
* SubIndex 101 - C2C5<br>
* SubIndex 102 - C2C6<br>
* SubIndex 103 - C2C7<br>
* SubIndex 104 - C2C8<br>
* SubIndex 105 - C2DID1<br>
* SubIndex 106 - C2DID2<br>
* SubIndex 107 - C2D1<br>
* SubIndex 108 - C2D2<br>
* SubIndex 109 - C2D3<br>
* SubIndex 110 - C2D4<br>
* SubIndex 111 - C2D5<br>
* SubIndex 112 - C2D6<br>
* SubIndex 113 - C2D7<br>
* SubIndex 114 - C2D8<br>
* SubIndex 115 - C2EID1<br>
* SubIndex 116 - C2EID2<br>
* SubIndex 117 - C2E1<br>
* SubIndex 118 - C2E2<br>
* SubIndex 119 - C2E3<br>
* SubIndex 120 - C2E4<br>
* SubIndex 121 - C2E5<br>
* SubIndex 122 - C2E6<br>
* SubIndex 123 - C2E7<br>
* SubIndex 124 - C2E8<br>
* SubIndex 125 - C2FID1<br>
* SubIndex 126 - C2FID2<br>
* SubIndex 127 - C2F1<br>
* SubIndex 128 - C2F2<br>
* SubIndex 129 - C2F3<br>
* SubIndex 130 - C2F4<br>
* SubIndex 131 - C2F5<br>
* SubIndex 132 - C2F6<br>
* SubIndex 133 - C2F7<br>
* SubIndex 134 - C2F8<br>
* SubIndex 135 - C3AID1<br>
* SubIndex 136 - C3AID2<br>
* SubIndex 137 - C3A1<br>
* SubIndex 138 - C3A2<br>
* SubIndex 139 - C3A3<br>
* SubIndex 140 - C3A4<br>
* SubIndex 141 - C3A5<br>
* SubIndex 142 - C3A6<br>
* SubIndex 143 - C3A7<br>
* SubIndex 144 - C3A8<br>
* SubIndex 145 - C3BID1<br>
* SubIndex 146 - C3BID2<br>
* SubIndex 147 - C3B1<br>
* SubIndex 148 - C3B2<br>
* SubIndex 149 - C3B3<br>
* SubIndex 150 - C3B4<br>
* SubIndex 151 - C3B5<br>
* SubIndex 152 - C3B6<br>
* SubIndex 153 - C3B7<br>
* SubIndex 154 - C3B8<br>
* SubIndex 155 - C3CID1<br>
* SubIndex 156 - C3CID2<br>
* SubIndex 157 - C3C1<br>
* SubIndex 158 - C3C2<br>
* SubIndex 159 - C3C3<br>
* SubIndex 160 - C3C4<br>
* SubIndex 161 - C3C5<br>
* SubIndex 162 - C3C6<br>
* SubIndex 163 - C3C7<br>
* SubIndex 164 - C3C8<br>
* SubIndex 165 - C3DID1<br>
* SubIndex 166 - C3DID2<br>
* SubIndex 167 - C3D1<br>
* SubIndex 168 - C3D2<br>
* SubIndex 169 - C3D3<br>
* SubIndex 170 - C3D4<br>
* SubIndex 171 - C3D5<br>
* SubIndex 172 - C3D6<br>
* SubIndex 173 - C3D7<br>
* SubIndex 174 - C3D8<br>
* SubIndex 175 - C3EID1<br>
* SubIndex 176 - C3EID2<br>
* SubIndex 177 - C3E1<br>
* SubIndex 178 - C3E2<br>
* SubIndex 179 - C3E3<br>
* SubIndex 180 - C3E4<br>
* SubIndex 181 - C3E5<br>
* SubIndex 182 - C3E6<br>
* SubIndex 183 - C3E7<br>
* SubIndex 184 - C3E8<br>
* SubIndex 185 - C3FID1<br>
* SubIndex 186 - C3FID2<br>
* SubIndex 187 - C3F1<br>
* SubIndex 188 - C3F2<br>
* SubIndex 189 - C3F3<br>
* SubIndex 190 - C3F4<br>
* SubIndex 191 - C3F5<br>
* SubIndex 192 - C3F6<br>
* SubIndex 193 - C3F7<br>
* SubIndex 194 - C3F8<br>
* SubIndex 195 - VT1<br>
* SubIndex 196 - VT2<br>
* SubIndex 197 - VT3<br>
* SubIndex 198 - VT4<br>
* SubIndex 199 - VT5<br>
* SubIndex 200 - VT6<br>
* SubIndex 201 - VT7<br>
* SubIndex 202 - VT8<br>
* SubIndex 203 - VT9<br>
* SubIndex 204 - VT10<br>
* SubIndex 205 - VT11<br>
* SubIndex 206 - VT12<br>
* SubIndex 207 - VT13<br>
* SubIndex 208 - VT14<br>
* SubIndex 209 - VT15<br>
* SubIndex 210 - VT16<br>
* SubIndex 211 - VT17<br>
* SubIndex 212 - VT18<br>
* SubIndex 213 - VT19<br>
* SubIndex 214 - VT20<br>
* SubIndex 215 - VT21<br>
* SubIndex 216 - end1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - AX1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - AX2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex3 - AY1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex4 - AY2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex5 - AZ1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex6 - AZ2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex7 - GX1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex8 - GX2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex9 - GY1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex10 - GY2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex11 - GZ1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex12 - GZ2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex13 - T1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex14 - T2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex15 - C1AID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex16 - C1AID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex17 - C1A1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex18 - C1A2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex19 - C1A3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex20 - C1A4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex21 - C1A5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex22 - C1A6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex23 - C1A7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex24 - C1A8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex25 - C1BID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex26 - C1BID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex27 - C1B1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex28 - C1B2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex29 - C1B3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex30 - C1B4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex31 - C1B5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex32 - C1B6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex33 - C1B7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex34 - C1B8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex35 - C1CID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex36 - C1CID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex37 - C1C1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex38 - C1C2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex39 - C1C3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex40 - C1C4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex41 - C1C5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex42 - C1C6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex43 - C1C7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex44 - C1C8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex45 - C1DID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex46 - C1DID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex47 - C1D1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex48 - C1D2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex49 - C1D3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex50 - C1D4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex51 - C1D5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex52 - C1D6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex53 - C1D7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex54 - C1D8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex55 - C1EID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex56 - C1EID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex57 - C1E1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex58 - C1E2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex59 - C1E3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex60 - C1E4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex61 - C1E5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex62 - C1E6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex63 - C1E7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex64 - C1E8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex65 - C1FID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex66 - C1FID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex67 - C1F1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex68 - C1F2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex69 - C1F3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex70 - C1F4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex71 - C1F5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex72 - C1F6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex73 - C1F7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex74 - C1F8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex75 - C2AID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex76 - C2AID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex77 - C2A1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex78 - C2A2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex79 - C2A3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex80 - C2A4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex81 - C2A5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex82 - C2A6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex83 - C2A7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex84 - C2A8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex85 - C2BID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex86 - C2BID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex87 - C2B1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex88 - C2B2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex89 - C2B3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex90 - C2B4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex91 - C2B5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex92 - C2B6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex93 - C2B7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex94 - C2B8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex95 - C2CID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex96 - C2CID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex97 - C2C1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex98 - C2C2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex99 - C2C3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex100 - C2C4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex101 - C2C5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex102 - C2C6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex103 - C2C7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex104 - C2C8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex105 - C2DID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex106 - C2DID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex107 - C2D1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex108 - C2D2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex109 - C2D3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex110 - C2D4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex111 - C2D5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex112 - C2D6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex113 - C2D7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex114 - C2D8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex115 - C2EID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex116 - C2EID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex117 - C2E1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex118 - C2E2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex119 - C2E3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex120 - C2E4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex121 - C2E5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex122 - C2E6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex123 - C2E7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex124 - C2E8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex125 - C2FID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex126 - C2FID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex127 - C2F1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex128 - C2F2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex129 - C2F3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex130 - C2F4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex131 - C2F5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex132 - C2F6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex133 - C2F7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex134 - C2F8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex135 - C3AID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex136 - C3AID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex137 - C3A1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex138 - C3A2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex139 - C3A3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex140 - C3A4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex141 - C3A5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex142 - C3A6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex143 - C3A7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex144 - C3A8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex145 - C3BID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex146 - C3BID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex147 - C3B1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex148 - C3B2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex149 - C3B3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex150 - C3B4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex151 - C3B5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex152 - C3B6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex153 - C3B7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex154 - C3B8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex155 - C3CID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex156 - C3CID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex157 - C3C1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex158 - C3C2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex159 - C3C3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex160 - C3C4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex161 - C3C5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex162 - C3C6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex163 - C3C7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex164 - C3C8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex165 - C3DID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex166 - C3DID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex167 - C3D1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex168 - C3D2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex169 - C3D3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex170 - C3D4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex171 - C3D5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex172 - C3D6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex173 - C3D7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex174 - C3D8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex175 - C3EID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex176 - C3EID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex177 - C3E1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex178 - C3E2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex179 - C3E3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex180 - C3E4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex181 - C3E5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex182 - C3E6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex183 - C3E7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex184 - C3E8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex185 - C3FID1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex186 - C3FID2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex187 - C3F1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex188 - C3F2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex189 - C3F3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex190 - C3F4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex191 - C3F5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex192 - C3F6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex193 - C3F7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex194 - C3F8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex195 - VT1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex196 - VT2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex197 - VT3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex198 - VT4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex199 - VT5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex200 - VT6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex201 - VT7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex202 - VT8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex203 - VT9 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex204 - VT10 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex205 - VT11 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex206 - VT12 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex207 - VT13 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex208 - VT14 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex209 - VT15 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex210 - VT16 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex211 - VT17 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex212 - VT18 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex213 - VT19 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex214 - VT20 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex215 - VT21 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }}; /* Subindex216 - end1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "PDIChannel\000"
"AX1\000"
"AX2\000"
"AY1\000"
"AY2\000"
"AZ1\000"
"AZ2\000"
"GX1\000"
"GX2\000"
"GY1\000"
"GY2\000"
"GZ1\000"
"GZ2\000"
"T1\000"
"T2\000"
"C1AID1\000"
"C1AID2\000"
"C1A1\000"
"C1A2\000"
"C1A3\000"
"C1A4\000"
"C1A5\000"
"C1A6\000"
"C1A7\000"
"C1A8\000"
"C1BID1\000"
"C1BID2\000"
"C1B1\000"
"C1B2\000"
"C1B3\000"
"C1B4\000"
"C1B5\000"
"C1B6\000"
"C1B7\000"
"C1B8\000"
"C1CID1\000"
"C1CID2\000"
"C1C1\000"
"C1C2\000"
"C1C3\000"
"C1C4\000"
"C1C5\000"
"C1C6\000"
"C1C7\000"
"C1C8\000"
"C1DID1\000"
"C1DID2\000"
"C1D1\000"
"C1D2\000"
"C1D3\000"
"C1D4\000"
"C1D5\000"
"C1D6\000"
"C1D7\000"
"C1D8\000"
"C1EID1\000"
"C1EID2\000"
"C1E1\000"
"C1E2\000"
"C1E3\000"
"C1E4\000"
"C1E5\000"
"C1E6\000"
"C1E7\000"
"C1E8\000"
"C1FID1\000"
"C1FID2\000"
"C1F1\000"
"C1F2\000"
"C1F3\000"
"C1F4\000"
"C1F5\000"
"C1F6\000"
"C1F7\000"
"C1F8\000"
"C2AID1\000"
"C2AID2\000"
"C2A1\000"
"C2A2\000"
"C2A3\000"
"C2A4\000"
"C2A5\000"
"C2A6\000"
"C2A7\000"
"C2A8\000"
"C2BID1\000"
"C2BID2\000"
"C2B1\000"
"C2B2\000"
"C2B3\000"
"C2B4\000"
"C2B5\000"
"C2B6\000"
"C2B7\000"
"C2B8\000"
"C2CID1\000"
"C2CID2\000"
"C2C1\000"
"C2C2\000"
"C2C3\000"
"C2C4\000"
"C2C5\000"
"C2C6\000"
"C2C7\000"
"C2C8\000"
"C2DID1\000"
"C2DID2\000"
"C2D1\000"
"C2D2\000"
"C2D3\000"
"C2D4\000"
"C2D5\000"
"C2D6\000"
"C2D7\000"
"C2D8\000"
"C2EID1\000"
"C2EID2\000"
"C2E1\000"
"C2E2\000"
"C2E3\000"
"C2E4\000"
"C2E5\000"
"C2E6\000"
"C2E7\000"
"C2E8\000"
"C2FID1\000"
"C2FID2\000"
"C2F1\000"
"C2F2\000"
"C2F3\000"
"C2F4\000"
"C2F5\000"
"C2F6\000"
"C2F7\000"
"C2F8\000"
"C3AID1\000"
"C3AID2\000"
"C3A1\000"
"C3A2\000"
"C3A3\000"
"C3A4\000"
"C3A5\000"
"C3A6\000"
"C3A7\000"
"C3A8\000"
"C3BID1\000"
"C3BID2\000"
"C3B1\000"
"C3B2\000"
"C3B3\000"
"C3B4\000"
"C3B5\000"
"C3B6\000"
"C3B7\000"
"C3B8\000"
"C3CID1\000"
"C3CID2\000"
"C3C1\000"
"C3C2\000"
"C3C3\000"
"C3C4\000"
"C3C5\000"
"C3C6\000"
"C3C7\000"
"C3C8\000"
"C3DID1\000"
"C3DID2\000"
"C3D1\000"
"C3D2\000"
"C3D3\000"
"C3D4\000"
"C3D5\000"
"C3D6\000"
"C3D7\000"
"C3D8\000"
"C3EID1\000"
"C3EID2\000"
"C3E1\000"
"C3E2\000"
"C3E3\000"
"C3E4\000"
"C3E5\000"
"C3E6\000"
"C3E7\000"
"C3E8\000"
"C3FID1\000"
"C3FID2\000"
"C3F1\000"
"C3F2\000"
"C3F3\000"
"C3F4\000"
"C3F5\000"
"C3F6\000"
"C3F7\000"
"C3F8\000"
"VT1\000"
"VT2\000"
"VT3\000"
"VT4\000"
"VT5\000"
"VT6\000"
"VT7\000"
"VT8\000"
"VT9\000"
"VT10\000"
"VT11\000"
"VT12\000"
"VT13\000"
"VT14\000"
"VT15\000"
"VT16\000"
"VT17\000"
"VT18\000"
"VT19\000"
"VT20\000"
"VT21\000"
"end1\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 AX1; /* Subindex1 - AX1 */
UINT8 AX2; /* Subindex2 - AX2 */
UINT8 AY1; /* Subindex3 - AY1 */
UINT8 AY2; /* Subindex4 - AY2 */
UINT8 AZ1; /* Subindex5 - AZ1 */
UINT8 AZ2; /* Subindex6 - AZ2 */
UINT8 GX1; /* Subindex7 - GX1 */
UINT8 GX2; /* Subindex8 - GX2 */
UINT8 GY1; /* Subindex9 - GY1 */
UINT8 GY2; /* Subindex10 - GY2 */
UINT8 GZ1; /* Subindex11 - GZ1 */
UINT8 GZ2; /* Subindex12 - GZ2 */
UINT8 T1; /* Subindex13 - T1 */
UINT8 T2; /* Subindex14 - T2 */
UINT8 C1AID1; /* Subindex15 - C1AID1 */
UINT8 C1AID2; /* Subindex16 - C1AID2 */
UINT8 C1A1; /* Subindex17 - C1A1 */
UINT8 C1A2; /* Subindex18 - C1A2 */
UINT8 C1A3; /* Subindex19 - C1A3 */
UINT8 C1A4; /* Subindex20 - C1A4 */
UINT8 C1A5; /* Subindex21 - C1A5 */
UINT8 C1A6; /* Subindex22 - C1A6 */
UINT8 C1A7; /* Subindex23 - C1A7 */
UINT8 C1A8; /* Subindex24 - C1A8 */
UINT8 C1BID1; /* Subindex25 - C1BID1 */
UINT8 C1BID2; /* Subindex26 - C1BID2 */
UINT8 C1B1; /* Subindex27 - C1B1 */
UINT8 C1B2; /* Subindex28 - C1B2 */
UINT8 C1B3; /* Subindex29 - C1B3 */
UINT8 C1B4; /* Subindex30 - C1B4 */
UINT8 C1B5; /* Subindex31 - C1B5 */
UINT8 C1B6; /* Subindex32 - C1B6 */
UINT8 C1B7; /* Subindex33 - C1B7 */
UINT8 C1B8; /* Subindex34 - C1B8 */
UINT8 C1CID1; /* Subindex35 - C1CID1 */
UINT8 C1CID2; /* Subindex36 - C1CID2 */
UINT8 C1C1; /* Subindex37 - C1C1 */
UINT8 C1C2; /* Subindex38 - C1C2 */
UINT8 C1C3; /* Subindex39 - C1C3 */
UINT8 C1C4; /* Subindex40 - C1C4 */
UINT8 C1C5; /* Subindex41 - C1C5 */
UINT8 C1C6; /* Subindex42 - C1C6 */
UINT8 C1C7; /* Subindex43 - C1C7 */
UINT8 C1C8; /* Subindex44 - C1C8 */
UINT8 C1DID1; /* Subindex45 - C1DID1 */
UINT8 C1DID2; /* Subindex46 - C1DID2 */
UINT8 C1D1; /* Subindex47 - C1D1 */
UINT8 C1D2; /* Subindex48 - C1D2 */
UINT8 C1D3; /* Subindex49 - C1D3 */
UINT8 C1D4; /* Subindex50 - C1D4 */
UINT8 C1D5; /* Subindex51 - C1D5 */
UINT8 C1D6; /* Subindex52 - C1D6 */
UINT8 C1D7; /* Subindex53 - C1D7 */
UINT8 C1D8; /* Subindex54 - C1D8 */
UINT8 C1EID1; /* Subindex55 - C1EID1 */
UINT8 C1EID2; /* Subindex56 - C1EID2 */
UINT8 C1E1; /* Subindex57 - C1E1 */
UINT8 C1E2; /* Subindex58 - C1E2 */
UINT8 C1E3; /* Subindex59 - C1E3 */
UINT8 C1E4; /* Subindex60 - C1E4 */
UINT8 C1E5; /* Subindex61 - C1E5 */
UINT8 C1E6; /* Subindex62 - C1E6 */
UINT8 C1E7; /* Subindex63 - C1E7 */
UINT8 C1E8; /* Subindex64 - C1E8 */
UINT8 C1FID1; /* Subindex65 - C1FID1 */
UINT8 C1FID2; /* Subindex66 - C1FID2 */
UINT8 C1F1; /* Subindex67 - C1F1 */
UINT8 C1F2; /* Subindex68 - C1F2 */
UINT8 C1F3; /* Subindex69 - C1F3 */
UINT8 C1F4; /* Subindex70 - C1F4 */
UINT8 C1F5; /* Subindex71 - C1F5 */
UINT8 C1F6; /* Subindex72 - C1F6 */
UINT8 C1F7; /* Subindex73 - C1F7 */
UINT8 C1F8; /* Subindex74 - C1F8 */
UINT8 C2AID1; /* Subindex75 - C2AID1 */
UINT8 C2AID2; /* Subindex76 - C2AID2 */
UINT8 C2A1; /* Subindex77 - C2A1 */
UINT8 C2A2; /* Subindex78 - C2A2 */
UINT8 C2A3; /* Subindex79 - C2A3 */
UINT8 C2A4; /* Subindex80 - C2A4 */
UINT8 C2A5; /* Subindex81 - C2A5 */
UINT8 C2A6; /* Subindex82 - C2A6 */
UINT8 C2A7; /* Subindex83 - C2A7 */
UINT8 C2A8; /* Subindex84 - C2A8 */
UINT8 C2BID1; /* Subindex85 - C2BID1 */
UINT8 C2BID2; /* Subindex86 - C2BID2 */
UINT8 C2B1; /* Subindex87 - C2B1 */
UINT8 C2B2; /* Subindex88 - C2B2 */
UINT8 C2B3; /* Subindex89 - C2B3 */
UINT8 C2B4; /* Subindex90 - C2B4 */
UINT8 C2B5; /* Subindex91 - C2B5 */
UINT8 C2B6; /* Subindex92 - C2B6 */
UINT8 C2B7; /* Subindex93 - C2B7 */
UINT8 C2B8; /* Subindex94 - C2B8 */
UINT8 C2CID1; /* Subindex95 - C2CID1 */
UINT8 C2CID2; /* Subindex96 - C2CID2 */
UINT8 C2C1; /* Subindex97 - C2C1 */
UINT8 C2C2; /* Subindex98 - C2C2 */
UINT8 C2C3; /* Subindex99 - C2C3 */
UINT8 C2C4; /* Subindex100 - C2C4 */
UINT8 C2C5; /* Subindex101 - C2C5 */
UINT8 C2C6; /* Subindex102 - C2C6 */
UINT8 C2C7; /* Subindex103 - C2C7 */
UINT8 C2C8; /* Subindex104 - C2C8 */
UINT8 C2DID1; /* Subindex105 - C2DID1 */
UINT8 C2DID2; /* Subindex106 - C2DID2 */
UINT8 C2D1; /* Subindex107 - C2D1 */
UINT8 C2D2; /* Subindex108 - C2D2 */
UINT8 C2D3; /* Subindex109 - C2D3 */
UINT8 C2D4; /* Subindex110 - C2D4 */
UINT8 C2D5; /* Subindex111 - C2D5 */
UINT8 C2D6; /* Subindex112 - C2D6 */
UINT8 C2D7; /* Subindex113 - C2D7 */
UINT8 C2D8; /* Subindex114 - C2D8 */
UINT8 C2EID1; /* Subindex115 - C2EID1 */
UINT8 C2EID2; /* Subindex116 - C2EID2 */
UINT8 C2E1; /* Subindex117 - C2E1 */
UINT8 C2E2; /* Subindex118 - C2E2 */
UINT8 C2E3; /* Subindex119 - C2E3 */
UINT8 C2E4; /* Subindex120 - C2E4 */
UINT8 C2E5; /* Subindex121 - C2E5 */
UINT8 C2E6; /* Subindex122 - C2E6 */
UINT8 C2E7; /* Subindex123 - C2E7 */
UINT8 C2E8; /* Subindex124 - C2E8 */
UINT8 C2FID1; /* Subindex125 - C2FID1 */
UINT8 C2FID2; /* Subindex126 - C2FID2 */
UINT8 C2F1; /* Subindex127 - C2F1 */
UINT8 C2F2; /* Subindex128 - C2F2 */
UINT8 C2F3; /* Subindex129 - C2F3 */
UINT8 C2F4; /* Subindex130 - C2F4 */
UINT8 C2F5; /* Subindex131 - C2F5 */
UINT8 C2F6; /* Subindex132 - C2F6 */
UINT8 C2F7; /* Subindex133 - C2F7 */
UINT8 C2F8; /* Subindex134 - C2F8 */
UINT8 C3AID1; /* Subindex135 - C3AID1 */
UINT8 C3AID2; /* Subindex136 - C3AID2 */
UINT8 C3A1; /* Subindex137 - C3A1 */
UINT8 C3A2; /* Subindex138 - C3A2 */
UINT8 C3A3; /* Subindex139 - C3A3 */
UINT8 C3A4; /* Subindex140 - C3A4 */
UINT8 C3A5; /* Subindex141 - C3A5 */
UINT8 C3A6; /* Subindex142 - C3A6 */
UINT8 C3A7; /* Subindex143 - C3A7 */
UINT8 C3A8; /* Subindex144 - C3A8 */
UINT8 C3BID1; /* Subindex145 - C3BID1 */
UINT8 C3BID2; /* Subindex146 - C3BID2 */
UINT8 C3B1; /* Subindex147 - C3B1 */
UINT8 C3B2; /* Subindex148 - C3B2 */
UINT8 C3B3; /* Subindex149 - C3B3 */
UINT8 C3B4; /* Subindex150 - C3B4 */
UINT8 C3B5; /* Subindex151 - C3B5 */
UINT8 C3B6; /* Subindex152 - C3B6 */
UINT8 C3B7; /* Subindex153 - C3B7 */
UINT8 C3B8; /* Subindex154 - C3B8 */
UINT8 C3CID1; /* Subindex155 - C3CID1 */
UINT8 C3CID2; /* Subindex156 - C3CID2 */
UINT8 C3C1; /* Subindex157 - C3C1 */
UINT8 C3C2; /* Subindex158 - C3C2 */
UINT8 C3C3; /* Subindex159 - C3C3 */
UINT8 C3C4; /* Subindex160 - C3C4 */
UINT8 C3C5; /* Subindex161 - C3C5 */
UINT8 C3C6; /* Subindex162 - C3C6 */
UINT8 C3C7; /* Subindex163 - C3C7 */
UINT8 C3C8; /* Subindex164 - C3C8 */
UINT8 C3DID1; /* Subindex165 - C3DID1 */
UINT8 C3DID2; /* Subindex166 - C3DID2 */
UINT8 C3D1; /* Subindex167 - C3D1 */
UINT8 C3D2; /* Subindex168 - C3D2 */
UINT8 C3D3; /* Subindex169 - C3D3 */
UINT8 C3D4; /* Subindex170 - C3D4 */
UINT8 C3D5; /* Subindex171 - C3D5 */
UINT8 C3D6; /* Subindex172 - C3D6 */
UINT8 C3D7; /* Subindex173 - C3D7 */
UINT8 C3D8; /* Subindex174 - C3D8 */
UINT8 C3EID1; /* Subindex175 - C3EID1 */
UINT8 C3EID2; /* Subindex176 - C3EID2 */
UINT8 C3E1; /* Subindex177 - C3E1 */
UINT8 C3E2; /* Subindex178 - C3E2 */
UINT8 C3E3; /* Subindex179 - C3E3 */
UINT8 C3E4; /* Subindex180 - C3E4 */
UINT8 C3E5; /* Subindex181 - C3E5 */
UINT8 C3E6; /* Subindex182 - C3E6 */
UINT8 C3E7; /* Subindex183 - C3E7 */
UINT8 C3E8; /* Subindex184 - C3E8 */
UINT8 C3FID1; /* Subindex185 - C3FID1 */
UINT8 C3FID2; /* Subindex186 - C3FID2 */
UINT8 C3F1; /* Subindex187 - C3F1 */
UINT8 C3F2; /* Subindex188 - C3F2 */
UINT8 C3F3; /* Subindex189 - C3F3 */
UINT8 C3F4; /* Subindex190 - C3F4 */
UINT8 C3F5; /* Subindex191 - C3F5 */
UINT8 C3F6; /* Subindex192 - C3F6 */
UINT8 C3F7; /* Subindex193 - C3F7 */
UINT8 C3F8; /* Subindex194 - C3F8 */
UINT8 VT1; /* Subindex195 - VT1 */
UINT8 VT2; /* Subindex196 - VT2 */
UINT8 VT3; /* Subindex197 - VT3 */
UINT8 VT4; /* Subindex198 - VT4 */
UINT8 VT5; /* Subindex199 - VT5 */
UINT8 VT6; /* Subindex200 - VT6 */
UINT8 VT7; /* Subindex201 - VT7 */
UINT8 VT8; /* Subindex202 - VT8 */
UINT8 VT9; /* Subindex203 - VT9 */
UINT8 VT10; /* Subindex204 - VT10 */
UINT8 VT11; /* Subindex205 - VT11 */
UINT8 VT12; /* Subindex206 - VT12 */
UINT8 VT13; /* Subindex207 - VT13 */
UINT8 VT14; /* Subindex208 - VT14 */
UINT8 VT15; /* Subindex209 - VT15 */
UINT8 VT16; /* Subindex210 - VT16 */
UINT8 VT17; /* Subindex211 - VT17 */
UINT8 VT18; /* Subindex212 - VT18 */
UINT8 VT19; /* Subindex213 - VT19 */
UINT8 VT20; /* Subindex214 - VT20 */
UINT8 VT21; /* Subindex215 - VT21 */
UINT8 End1; /* Subindex216 - end1 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 PDIChannel0x6000
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={216,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x60F0 : RMDAPDIChannel
******************************************************************************/
/**
* \addtogroup 0x60F0 0x60F0 | RMDAPDIChannel
* @{
* \brief Object 0x60F0 (RMDAPDIChannel) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - R1<br>
* SubIndex 2 - R2<br>
* SubIndex 3 - R3<br>
* SubIndex 4 - R4<br>
* SubIndex 5 - R5<br>
* SubIndex 6 - R6<br>
* SubIndex 7 - R7<br>
* SubIndex 8 - R8<br>
* SubIndex 9 - R9<br>
* SubIndex 10 - R10<br>
* SubIndex 11 - R11<br>
* SubIndex 12 - R12<br>
* SubIndex 13 - R13<br>
* SubIndex 14 - R14<br>
* SubIndex 15 - R15<br>
* SubIndex 16 - R16<br>
* SubIndex 17 - R17<br>
* SubIndex 18 - R18<br>
* SubIndex 19 - R19<br>
* SubIndex 20 - R20<br>
* SubIndex 21 - R21<br>
* SubIndex 22 - R22<br>
* SubIndex 23 - R23<br>
* SubIndex 24 - R24<br>
* SubIndex 25 - R25<br>
* SubIndex 26 - R26<br>
* SubIndex 27 - R27<br>
* SubIndex 28 - R28<br>
* SubIndex 29 - R29<br>
* SubIndex 30 - R30<br>
* SubIndex 31 - R31<br>
* SubIndex 32 - R32<br>
* SubIndex 33 - R33<br>
* SubIndex 34 - R34<br>
* SubIndex 35 - R35<br>
* SubIndex 36 - R36<br>
* SubIndex 37 - R37<br>
* SubIndex 38 - R38<br>
* SubIndex 39 - R39<br>
* SubIndex 40 - R40<br>
* SubIndex 41 - R41<br>
* SubIndex 42 - R42<br>
* SubIndex 43 - R43<br>
* SubIndex 44 - R44<br>
* SubIndex 45 - R45<br>
* SubIndex 46 - R46<br>
* SubIndex 47 - R47<br>
* SubIndex 48 - R48<br>
* SubIndex 49 - R49<br>
* SubIndex 50 - R50<br>
* SubIndex 51 - R51<br>
* SubIndex 52 - R52<br>
* SubIndex 53 - R53<br>
* SubIndex 54 - R54<br>
* SubIndex 55 - R55<br>
* SubIndex 56 - R56<br>
* SubIndex 57 - R57<br>
* SubIndex 58 - R58<br>
* SubIndex 59 - R59<br>
* SubIndex 60 - R60<br>
* SubIndex 61 - R61<br>
* SubIndex 62 - R62<br>
* SubIndex 63 - R63<br>
* SubIndex 64 - R64<br>
* SubIndex 65 - R65<br>
* SubIndex 66 - R66<br>
* SubIndex 67 - R67<br>
* SubIndex 68 - R68<br>
* SubIndex 69 - R69<br>
* SubIndex 70 - R70<br>
* SubIndex 71 - R71<br>
* SubIndex 72 - R72<br>
* SubIndex 73 - R73<br>
* SubIndex 74 - R74<br>
* SubIndex 75 - R75<br>
* SubIndex 76 - R76<br>
* SubIndex 77 - R77<br>
* SubIndex 78 - R78<br>
* SubIndex 79 - R79<br>
* SubIndex 80 - R80<br>
* SubIndex 81 - R81<br>
* SubIndex 82 - R82<br>
* SubIndex 83 - R83<br>
* SubIndex 84 - R84<br>
* SubIndex 85 - R85<br>
* SubIndex 86 - R86<br>
* SubIndex 87 - R87<br>
* SubIndex 88 - R88<br>
* SubIndex 89 - R89<br>
* SubIndex 90 - R90<br>
* SubIndex 91 - R91<br>
* SubIndex 92 - R92<br>
* SubIndex 93 - R93<br>
* SubIndex 94 - R94<br>
* SubIndex 95 - R95<br>
* SubIndex 96 - R96<br>
* SubIndex 97 - R97<br>
* SubIndex 98 - R98<br>
* SubIndex 99 - R99<br>
* SubIndex 100 - R100<br>
* SubIndex 101 - R101<br>
* SubIndex 102 - R102<br>
* SubIndex 103 - R103<br>
* SubIndex 104 - R104<br>
* SubIndex 105 - R105<br>
* SubIndex 106 - R106<br>
* SubIndex 107 - R107<br>
* SubIndex 108 - R108<br>
* SubIndex 109 - R109<br>
* SubIndex 110 - R110<br>
* SubIndex 111 - R111<br>
* SubIndex 112 - R112<br>
* SubIndex 113 - R113<br>
* SubIndex 114 - R114<br>
* SubIndex 115 - R115<br>
* SubIndex 116 - R116<br>
* SubIndex 117 - R117<br>
* SubIndex 118 - R118<br>
* SubIndex 119 - R119<br>
* SubIndex 120 - R120<br>
* SubIndex 121 - R121<br>
* SubIndex 122 - R122<br>
* SubIndex 123 - R123<br>
* SubIndex 124 - R124<br>
* SubIndex 125 - R125<br>
* SubIndex 126 - R126<br>
* SubIndex 127 - R127<br>
* SubIndex 128 - R128<br>
* SubIndex 129 - R129<br>
* SubIndex 130 - R130<br>
* SubIndex 131 - R131<br>
* SubIndex 132 - R132<br>
* SubIndex 133 - R133<br>
* SubIndex 134 - R134<br>
* SubIndex 135 - R135<br>
* SubIndex 136 - R136<br>
* SubIndex 137 - R137<br>
* SubIndex 138 - R138<br>
* SubIndex 139 - R139<br>
* SubIndex 140 - R140<br>
* SubIndex 141 - R141<br>
* SubIndex 142 - R142<br>
* SubIndex 143 - R143<br>
* SubIndex 144 - R144<br>
* SubIndex 145 - R145<br>
* SubIndex 146 - R146<br>
* SubIndex 147 - R147<br>
* SubIndex 148 - R148<br>
* SubIndex 149 - R149<br>
* SubIndex 150 - R150<br>
* SubIndex 151 - R151<br>
* SubIndex 152 - R152<br>
* SubIndex 153 - R153<br>
* SubIndex 154 - R154<br>
* SubIndex 155 - R155<br>
* SubIndex 156 - R156<br>
* SubIndex 157 - R157<br>
* SubIndex 158 - R158<br>
* SubIndex 159 - R159<br>
* SubIndex 160 - R160<br>
* SubIndex 161 - R161<br>
* SubIndex 162 - R162<br>
* SubIndex 163 - R163<br>
* SubIndex 164 - R164<br>
* SubIndex 165 - R165<br>
* SubIndex 166 - R166<br>
* SubIndex 167 - R167<br>
* SubIndex 168 - R168<br>
* SubIndex 169 - R169<br>
* SubIndex 170 - R170<br>
* SubIndex 171 - R171<br>
* SubIndex 172 - R172<br>
* SubIndex 173 - R173<br>
* SubIndex 174 - R174<br>
* SubIndex 175 - R175<br>
* SubIndex 176 - R176<br>
* SubIndex 177 - R177<br>
* SubIndex 178 - R178<br>
* SubIndex 179 - R179<br>
* SubIndex 180 - R180<br>
* SubIndex 181 - R181<br>
* SubIndex 182 - R182<br>
* SubIndex 183 - R183<br>
* SubIndex 184 - R184<br>
* SubIndex 185 - R185<br>
* SubIndex 186 - R186<br>
* SubIndex 187 - R187<br>
* SubIndex 188 - R188<br>
* SubIndex 189 - R189<br>
* SubIndex 190 - R190<br>
* SubIndex 191 - R191<br>
* SubIndex 192 - R192<br>
* SubIndex 193 - R193<br>
* SubIndex 194 - R194<br>
* SubIndex 195 - R195<br>
* SubIndex 196 - R196<br>
* SubIndex 197 - R197<br>
* SubIndex 198 - R198<br>
* SubIndex 199 - R199<br>
* SubIndex 200 - R200<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x60F0[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - R1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - R2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex3 - R3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex4 - R4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex5 - R5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex6 - R6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex7 - R7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex8 - R8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex9 - R9 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex10 - R10 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex11 - R11 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex12 - R12 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex13 - R13 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex14 - R14 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex15 - R15 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex16 - R16 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex17 - R17 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex18 - R18 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex19 - R19 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex20 - R20 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex21 - R21 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex22 - R22 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex23 - R23 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex24 - R24 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex25 - R25 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex26 - R26 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex27 - R27 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex28 - R28 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex29 - R29 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex30 - R30 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex31 - R31 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex32 - R32 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex33 - R33 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex34 - R34 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex35 - R35 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex36 - R36 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex37 - R37 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex38 - R38 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex39 - R39 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex40 - R40 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex41 - R41 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex42 - R42 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex43 - R43 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex44 - R44 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex45 - R45 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex46 - R46 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex47 - R47 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex48 - R48 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex49 - R49 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex50 - R50 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex51 - R51 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex52 - R52 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex53 - R53 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex54 - R54 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex55 - R55 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex56 - R56 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex57 - R57 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex58 - R58 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex59 - R59 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex60 - R60 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex61 - R61 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex62 - R62 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex63 - R63 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex64 - R64 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex65 - R65 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex66 - R66 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex67 - R67 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex68 - R68 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex69 - R69 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex70 - R70 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex71 - R71 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex72 - R72 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex73 - R73 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex74 - R74 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex75 - R75 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex76 - R76 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex77 - R77 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex78 - R78 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex79 - R79 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex80 - R80 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex81 - R81 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex82 - R82 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex83 - R83 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex84 - R84 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex85 - R85 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex86 - R86 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex87 - R87 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex88 - R88 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex89 - R89 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex90 - R90 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex91 - R91 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex92 - R92 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex93 - R93 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex94 - R94 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex95 - R95 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex96 - R96 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex97 - R97 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex98 - R98 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex99 - R99 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex100 - R100 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex101 - R101 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex102 - R102 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex103 - R103 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex104 - R104 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex105 - R105 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex106 - R106 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex107 - R107 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex108 - R108 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex109 - R109 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex110 - R110 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex111 - R111 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex112 - R112 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex113 - R113 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex114 - R114 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex115 - R115 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex116 - R116 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex117 - R117 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex118 - R118 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex119 - R119 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex120 - R120 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex121 - R121 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex122 - R122 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex123 - R123 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex124 - R124 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex125 - R125 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex126 - R126 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex127 - R127 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex128 - R128 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex129 - R129 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex130 - R130 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex131 - R131 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex132 - R132 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex133 - R133 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex134 - R134 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex135 - R135 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex136 - R136 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex137 - R137 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex138 - R138 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex139 - R139 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex140 - R140 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex141 - R141 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex142 - R142 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex143 - R143 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex144 - R144 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex145 - R145 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex146 - R146 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex147 - R147 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex148 - R148 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex149 - R149 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex150 - R150 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex151 - R151 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex152 - R152 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex153 - R153 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex154 - R154 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex155 - R155 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex156 - R156 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex157 - R157 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex158 - R158 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex159 - R159 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex160 - R160 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex161 - R161 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex162 - R162 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex163 - R163 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex164 - R164 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex165 - R165 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex166 - R166 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex167 - R167 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex168 - R168 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex169 - R169 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex170 - R170 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex171 - R171 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex172 - R172 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex173 - R173 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex174 - R174 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex175 - R175 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex176 - R176 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex177 - R177 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex178 - R178 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex179 - R179 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex180 - R180 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex181 - R181 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex182 - R182 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex183 - R183 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex184 - R184 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex185 - R185 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex186 - R186 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex187 - R187 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex188 - R188 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex189 - R189 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex190 - R190 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex191 - R191 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex192 - R192 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex193 - R193 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex194 - R194 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex195 - R195 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex196 - R196 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex197 - R197 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex198 - R198 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex199 - R199 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }}; /* Subindex200 - R200 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x60F0[] = "RMDAPDIChannel\000"
"R1\000"
"R2\000"
"R3\000"
"R4\000"
"R5\000"
"R6\000"
"R7\000"
"R8\000"
"R9\000"
"R10\000"
"R11\000"
"R12\000"
"R13\000"
"R14\000"
"R15\000"
"R16\000"
"R17\000"
"R18\000"
"R19\000"
"R20\000"
"R21\000"
"R22\000"
"R23\000"
"R24\000"
"R25\000"
"R26\000"
"R27\000"
"R28\000"
"R29\000"
"R30\000"
"R31\000"
"R32\000"
"R33\000"
"R34\000"
"R35\000"
"R36\000"
"R37\000"
"R38\000"
"R39\000"
"R40\000"
"R41\000"
"R42\000"
"R43\000"
"R44\000"
"R45\000"
"R46\000"
"R47\000"
"R48\000"
"R49\000"
"R50\000"
"R51\000"
"R52\000"
"R53\000"
"R54\000"
"R55\000"
"R56\000"
"R57\000"
"R58\000"
"R59\000"
"R60\000"
"R61\000"
"R62\000"
"R63\000"
"R64\000"
"R65\000"
"R66\000"
"R67\000"
"R68\000"
"R69\000"
"R70\000"
"R71\000"
"R72\000"
"R73\000"
"R74\000"
"R75\000"
"R76\000"
"R77\000"
"R78\000"
"R79\000"
"R80\000"
"R81\000"
"R82\000"
"R83\000"
"R84\000"
"R85\000"
"R86\000"
"R87\000"
"R88\000"
"R89\000"
"R90\000"
"R91\000"
"R92\000"
"R93\000"
"R94\000"
"R95\000"
"R96\000"
"R97\000"
"R98\000"
"R99\000"
"R100\000"
"R101\000"
"R102\000"
"R103\000"
"R104\000"
"R105\000"
"R106\000"
"R107\000"
"R108\000"
"R109\000"
"R110\000"
"R111\000"
"R112\000"
"R113\000"
"R114\000"
"R115\000"
"R116\000"
"R117\000"
"R118\000"
"R119\000"
"R120\000"
"R121\000"
"R122\000"
"R123\000"
"R124\000"
"R125\000"
"R126\000"
"R127\000"
"R128\000"
"R129\000"
"R130\000"
"R131\000"
"R132\000"
"R133\000"
"R134\000"
"R135\000"
"R136\000"
"R137\000"
"R138\000"
"R139\000"
"R140\000"
"R141\000"
"R142\000"
"R143\000"
"R144\000"
"R145\000"
"R146\000"
"R147\000"
"R148\000"
"R149\000"
"R150\000"
"R151\000"
"R152\000"
"R153\000"
"R154\000"
"R155\000"
"R156\000"
"R157\000"
"R158\000"
"R159\000"
"R160\000"
"R161\000"
"R162\000"
"R163\000"
"R164\000"
"R165\000"
"R166\000"
"R167\000"
"R168\000"
"R169\000"
"R170\000"
"R171\000"
"R172\000"
"R173\000"
"R174\000"
"R175\000"
"R176\000"
"R177\000"
"R178\000"
"R179\000"
"R180\000"
"R181\000"
"R182\000"
"R183\000"
"R184\000"
"R185\000"
"R186\000"
"R187\000"
"R188\000"
"R189\000"
"R190\000"
"R191\000"
"R192\000"
"R193\000"
"R194\000"
"R195\000"
"R196\000"
"R197\000"
"R198\000"
"R199\000"
"R200\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 R1; /* Subindex1 - R1 */
UINT8 R2; /* Subindex2 - R2 */
UINT8 R3; /* Subindex3 - R3 */
UINT8 R4; /* Subindex4 - R4 */
UINT8 R5; /* Subindex5 - R5 */
UINT8 R6; /* Subindex6 - R6 */
UINT8 R7; /* Subindex7 - R7 */
UINT8 R8; /* Subindex8 - R8 */
UINT8 R9; /* Subindex9 - R9 */
UINT8 R10; /* Subindex10 - R10 */
UINT8 R11; /* Subindex11 - R11 */
UINT8 R12; /* Subindex12 - R12 */
UINT8 R13; /* Subindex13 - R13 */
UINT8 R14; /* Subindex14 - R14 */
UINT8 R15; /* Subindex15 - R15 */
UINT8 R16; /* Subindex16 - R16 */
UINT8 R17; /* Subindex17 - R17 */
UINT8 R18; /* Subindex18 - R18 */
UINT8 R19; /* Subindex19 - R19 */
UINT8 R20; /* Subindex20 - R20 */
UINT8 R21; /* Subindex21 - R21 */
UINT8 R22; /* Subindex22 - R22 */
UINT8 R23; /* Subindex23 - R23 */
UINT8 R24; /* Subindex24 - R24 */
UINT8 R25; /* Subindex25 - R25 */
UINT8 R26; /* Subindex26 - R26 */
UINT8 R27; /* Subindex27 - R27 */
UINT8 R28; /* Subindex28 - R28 */
UINT8 R29; /* Subindex29 - R29 */
UINT8 R30; /* Subindex30 - R30 */
UINT8 R31; /* Subindex31 - R31 */
UINT8 R32; /* Subindex32 - R32 */
UINT8 R33; /* Subindex33 - R33 */
UINT8 R34; /* Subindex34 - R34 */
UINT8 R35; /* Subindex35 - R35 */
UINT8 R36; /* Subindex36 - R36 */
UINT8 R37; /* Subindex37 - R37 */
UINT8 R38; /* Subindex38 - R38 */
UINT8 R39; /* Subindex39 - R39 */
UINT8 R40; /* Subindex40 - R40 */
UINT8 R41; /* Subindex41 - R41 */
UINT8 R42; /* Subindex42 - R42 */
UINT8 R43; /* Subindex43 - R43 */
UINT8 R44; /* Subindex44 - R44 */
UINT8 R45; /* Subindex45 - R45 */
UINT8 R46; /* Subindex46 - R46 */
UINT8 R47; /* Subindex47 - R47 */
UINT8 R48; /* Subindex48 - R48 */
UINT8 R49; /* Subindex49 - R49 */
UINT8 R50; /* Subindex50 - R50 */
UINT8 R51; /* Subindex51 - R51 */
UINT8 R52; /* Subindex52 - R52 */
UINT8 R53; /* Subindex53 - R53 */
UINT8 R54; /* Subindex54 - R54 */
UINT8 R55; /* Subindex55 - R55 */
UINT8 R56; /* Subindex56 - R56 */
UINT8 R57; /* Subindex57 - R57 */
UINT8 R58; /* Subindex58 - R58 */
UINT8 R59; /* Subindex59 - R59 */
UINT8 R60; /* Subindex60 - R60 */
UINT8 R61; /* Subindex61 - R61 */
UINT8 R62; /* Subindex62 - R62 */
UINT8 R63; /* Subindex63 - R63 */
UINT8 R64; /* Subindex64 - R64 */
UINT8 R65; /* Subindex65 - R65 */
UINT8 R66; /* Subindex66 - R66 */
UINT8 R67; /* Subindex67 - R67 */
UINT8 R68; /* Subindex68 - R68 */
UINT8 R69; /* Subindex69 - R69 */
UINT8 R70; /* Subindex70 - R70 */
UINT8 R71; /* Subindex71 - R71 */
UINT8 R72; /* Subindex72 - R72 */
UINT8 R73; /* Subindex73 - R73 */
UINT8 R74; /* Subindex74 - R74 */
UINT8 R75; /* Subindex75 - R75 */
UINT8 R76; /* Subindex76 - R76 */
UINT8 R77; /* Subindex77 - R77 */
UINT8 R78; /* Subindex78 - R78 */
UINT8 R79; /* Subindex79 - R79 */
UINT8 R80; /* Subindex80 - R80 */
UINT8 R81; /* Subindex81 - R81 */
UINT8 R82; /* Subindex82 - R82 */
UINT8 R83; /* Subindex83 - R83 */
UINT8 R84; /* Subindex84 - R84 */
UINT8 R85; /* Subindex85 - R85 */
UINT8 R86; /* Subindex86 - R86 */
UINT8 R87; /* Subindex87 - R87 */
UINT8 R88; /* Subindex88 - R88 */
UINT8 R89; /* Subindex89 - R89 */
UINT8 R90; /* Subindex90 - R90 */
UINT8 R91; /* Subindex91 - R91 */
UINT8 R92; /* Subindex92 - R92 */
UINT8 R93; /* Subindex93 - R93 */
UINT8 R94; /* Subindex94 - R94 */
UINT8 R95; /* Subindex95 - R95 */
UINT8 R96; /* Subindex96 - R96 */
UINT8 R97; /* Subindex97 - R97 */
UINT8 R98; /* Subindex98 - R98 */
UINT8 R99; /* Subindex99 - R99 */
UINT8 R100; /* Subindex100 - R100 */
UINT8 R101; /* Subindex101 - R101 */
UINT8 R102; /* Subindex102 - R102 */
UINT8 R103; /* Subindex103 - R103 */
UINT8 R104; /* Subindex104 - R104 */
UINT8 R105; /* Subindex105 - R105 */
UINT8 R106; /* Subindex106 - R106 */
UINT8 R107; /* Subindex107 - R107 */
UINT8 R108; /* Subindex108 - R108 */
UINT8 R109; /* Subindex109 - R109 */
UINT8 R110; /* Subindex110 - R110 */
UINT8 R111; /* Subindex111 - R111 */
UINT8 R112; /* Subindex112 - R112 */
UINT8 R113; /* Subindex113 - R113 */
UINT8 R114; /* Subindex114 - R114 */
UINT8 R115; /* Subindex115 - R115 */
UINT8 R116; /* Subindex116 - R116 */
UINT8 R117; /* Subindex117 - R117 */
UINT8 R118; /* Subindex118 - R118 */
UINT8 R119; /* Subindex119 - R119 */
UINT8 R120; /* Subindex120 - R120 */
UINT8 R121; /* Subindex121 - R121 */
UINT8 R122; /* Subindex122 - R122 */
UINT8 R123; /* Subindex123 - R123 */
UINT8 R124; /* Subindex124 - R124 */
UINT8 R125; /* Subindex125 - R125 */
UINT8 R126; /* Subindex126 - R126 */
UINT8 R127; /* Subindex127 - R127 */
UINT8 R128; /* Subindex128 - R128 */
UINT8 R129; /* Subindex129 - R129 */
UINT8 R130; /* Subindex130 - R130 */
UINT8 R131; /* Subindex131 - R131 */
UINT8 R132; /* Subindex132 - R132 */
UINT8 R133; /* Subindex133 - R133 */
UINT8 R134; /* Subindex134 - R134 */
UINT8 R135; /* Subindex135 - R135 */
UINT8 R136; /* Subindex136 - R136 */
UINT8 R137; /* Subindex137 - R137 */
UINT8 R138; /* Subindex138 - R138 */
UINT8 R139; /* Subindex139 - R139 */
UINT8 R140; /* Subindex140 - R140 */
UINT8 R141; /* Subindex141 - R141 */
UINT8 R142; /* Subindex142 - R142 */
UINT8 R143; /* Subindex143 - R143 */
UINT8 R144; /* Subindex144 - R144 */
UINT8 R145; /* Subindex145 - R145 */
UINT8 R146; /* Subindex146 - R146 */
UINT8 R147; /* Subindex147 - R147 */
UINT8 R148; /* Subindex148 - R148 */
UINT8 R149; /* Subindex149 - R149 */
UINT8 R150; /* Subindex150 - R150 */
UINT8 R151; /* Subindex151 - R151 */
UINT8 R152; /* Subindex152 - R152 */
UINT8 R153; /* Subindex153 - R153 */
UINT8 R154; /* Subindex154 - R154 */
UINT8 R155; /* Subindex155 - R155 */
UINT8 R156; /* Subindex156 - R156 */
UINT8 R157; /* Subindex157 - R157 */
UINT8 R158; /* Subindex158 - R158 */
UINT8 R159; /* Subindex159 - R159 */
UINT8 R160; /* Subindex160 - R160 */
UINT8 R161; /* Subindex161 - R161 */
UINT8 R162; /* Subindex162 - R162 */
UINT8 R163; /* Subindex163 - R163 */
UINT8 R164; /* Subindex164 - R164 */
UINT8 R165; /* Subindex165 - R165 */
UINT8 R166; /* Subindex166 - R166 */
UINT8 R167; /* Subindex167 - R167 */
UINT8 R168; /* Subindex168 - R168 */
UINT8 R169; /* Subindex169 - R169 */
UINT8 R170; /* Subindex170 - R170 */
UINT8 R171; /* Subindex171 - R171 */
UINT8 R172; /* Subindex172 - R172 */
UINT8 R173; /* Subindex173 - R173 */
UINT8 R174; /* Subindex174 - R174 */
UINT8 R175; /* Subindex175 - R175 */
UINT8 R176; /* Subindex176 - R176 */
UINT8 R177; /* Subindex177 - R177 */
UINT8 R178; /* Subindex178 - R178 */
UINT8 R179; /* Subindex179 - R179 */
UINT8 R180; /* Subindex180 - R180 */
UINT8 R181; /* Subindex181 - R181 */
UINT8 R182; /* Subindex182 - R182 */
UINT8 R183; /* Subindex183 - R183 */
UINT8 R184; /* Subindex184 - R184 */
UINT8 R185; /* Subindex185 - R185 */
UINT8 R186; /* Subindex186 - R186 */
UINT8 R187; /* Subindex187 - R187 */
UINT8 R188; /* Subindex188 - R188 */
UINT8 R189; /* Subindex189 - R189 */
UINT8 R190; /* Subindex190 - R190 */
UINT8 R191; /* Subindex191 - R191 */
UINT8 R192; /* Subindex192 - R192 */
UINT8 R193; /* Subindex193 - R193 */
UINT8 R194; /* Subindex194 - R194 */
UINT8 R195; /* Subindex195 - R195 */
UINT8 R196; /* Subindex196 - R196 */
UINT8 R197; /* Subindex197 - R197 */
UINT8 R198; /* Subindex198 - R198 */
UINT8 R199; /* Subindex199 - R199 */
UINT8 R200; /* Subindex200 - R200 */
} OBJ_STRUCT_PACKED_END
TOBJ60F0;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ60F0 RMDAPDIChannel0x60F0
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={200,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7000 : PDOChannel
******************************************************************************/
/**
* \addtogroup 0x7000 0x7000 | PDOChannel
* @{
* \brief Object 0x7000 (PDOChannel) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - R<br>
* SubIndex 2 - G<br>
* SubIndex 3 - B<br>
* SubIndex 4 - T1<br>
* SubIndex 5 - T2<br>
* SubIndex 6 - C1ID1A<br>
* SubIndex 7 - C1ID2A<br>
* SubIndex 8 - C11A<br>
* SubIndex 9 - C12A<br>
* SubIndex 10 - C13A<br>
* SubIndex 11 - C14A<br>
* SubIndex 12 - C15A<br>
* SubIndex 13 - C16A<br>
* SubIndex 14 - C17A<br>
* SubIndex 15 - C18A<br>
* SubIndex 16 - C1ID1B<br>
* SubIndex 17 - C1ID2B<br>
* SubIndex 18 - C11B<br>
* SubIndex 19 - C12B<br>
* SubIndex 20 - C13B<br>
* SubIndex 21 - C14B<br>
* SubIndex 22 - C15B<br>
* SubIndex 23 - C16B<br>
* SubIndex 24 - C17B<br>
* SubIndex 25 - C18B<br>
* SubIndex 26 - C2ID1A<br>
* SubIndex 27 - C2ID2A<br>
* SubIndex 28 - C21A<br>
* SubIndex 29 - C22A<br>
* SubIndex 30 - C23A<br>
* SubIndex 31 - C24A<br>
* SubIndex 32 - C25A<br>
* SubIndex 33 - C26A<br>
* SubIndex 34 - C27A<br>
* SubIndex 35 - C28A<br>
* SubIndex 36 - C2ID1B<br>
* SubIndex 37 - C2ID2B<br>
* SubIndex 38 - C21B<br>
* SubIndex 39 - C22B<br>
* SubIndex 40 - C23B<br>
* SubIndex 41 - C24B<br>
* SubIndex 42 - C25B<br>
* SubIndex 43 - C26B<br>
* SubIndex 44 - C27B<br>
* SubIndex 45 - C28B<br>
* SubIndex 46 - C3ID1A<br>
* SubIndex 47 - C3ID2A<br>
* SubIndex 48 - C31A<br>
* SubIndex 49 - C32A<br>
* SubIndex 50 - C33A<br>
* SubIndex 51 - C34A<br>
* SubIndex 52 - C35A<br>
* SubIndex 53 - C36A<br>
* SubIndex 54 - C37A<br>
* SubIndex 55 - C38A<br>
* SubIndex 56 - C3ID1B<br>
* SubIndex 57 - C3ID2B<br>
* SubIndex 58 - C31B<br>
* SubIndex 59 - C32B<br>
* SubIndex 60 - C33B<br>
* SubIndex 61 - C34B<br>
* SubIndex 62 - C35B<br>
* SubIndex 63 - C36B<br>
* SubIndex 64 - C37B<br>
* SubIndex 65 - C38B<br>
* SubIndex 66 - end2<br>
* SubIndex 67 - end4<br>
* SubIndex 68 - end5<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - R */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - G */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex3 - B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex4 - T1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex5 - T2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex6 - C1ID1A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex7 - C1ID2A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex8 - C11A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex9 - C12A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex10 - C13A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex11 - C14A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex12 - C15A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex13 - C16A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex14 - C17A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex15 - C18A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex16 - C1ID1B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex17 - C1ID2B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex18 - C11B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex19 - C12B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex20 - C13B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex21 - C14B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex22 - C15B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex23 - C16B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex24 - C17B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex25 - C18B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex26 - C2ID1A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex27 - C2ID2A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex28 - C21A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex29 - C22A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex30 - C23A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex31 - C24A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex32 - C25A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex33 - C26A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex34 - C27A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex35 - C28A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex36 - C2ID1B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex37 - C2ID2B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex38 - C21B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex39 - C22B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex40 - C23B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex41 - C24B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex42 - C25B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex43 - C26B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex44 - C27B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex45 - C28B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex46 - C3ID1A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex47 - C3ID2A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex48 - C31A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex49 - C32A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex50 - C33A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex51 - C34A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex52 - C35A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex53 - C36A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex54 - C37A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex55 - C38A */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex56 - C3ID1B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex57 - C3ID2B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex58 - C31B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex59 - C32B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex60 - C33B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex61 - C34B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex62 - C35B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex63 - C36B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex64 - C37B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex65 - C38B */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex66 - end2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex67 - end4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex68 - end5 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "PDOChannel\000"
"R\000"
"G\000"
"B\000"
"T1\000"
"T2\000"
"C1ID1A\000"
"C1ID2A\000"
"C11A\000"
"C12A\000"
"C13A\000"
"C14A\000"
"C15A\000"
"C16A\000"
"C17A\000"
"C18A\000"
"C1ID1B\000"
"C1ID2B\000"
"C11B\000"
"C12B\000"
"C13B\000"
"C14B\000"
"C15B\000"
"C16B\000"
"C17B\000"
"C18B\000"
"C2ID1A\000"
"C2ID2A\000"
"C21A\000"
"C22A\000"
"C23A\000"
"C24A\000"
"C25A\000"
"C26A\000"
"C27A\000"
"C28A\000"
"C2ID1B\000"
"C2ID2B\000"
"C21B\000"
"C22B\000"
"C23B\000"
"C24B\000"
"C25B\000"
"C26B\000"
"C27B\000"
"C28B\000"
"C3ID1A\000"
"C3ID2A\000"
"C31A\000"
"C32A\000"
"C33A\000"
"C34A\000"
"C35A\000"
"C36A\000"
"C37A\000"
"C38A\000"
"C3ID1B\000"
"C3ID2B\000"
"C31B\000"
"C32B\000"
"C33B\000"
"C34B\000"
"C35B\000"
"C36B\000"
"C37B\000"
"C38B\000"
"end2\000"
"end4\000"
"end5\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 R; /* Subindex1 - R */
UINT8 G; /* Subindex2 - G */
UINT8 B; /* Subindex3 - B */
UINT8 T1; /* Subindex4 - T1 */
UINT8 T2; /* Subindex5 - T2 */
UINT8 C1ID1A; /* Subindex6 - C1ID1A */
UINT8 C1ID2A; /* Subindex7 - C1ID2A */
UINT8 C11A; /* Subindex8 - C11A */
UINT8 C12A; /* Subindex9 - C12A */
UINT8 C13A; /* Subindex10 - C13A */
UINT8 C14A; /* Subindex11 - C14A */
UINT8 C15A; /* Subindex12 - C15A */
UINT8 C16A; /* Subindex13 - C16A */
UINT8 C17A; /* Subindex14 - C17A */
UINT8 C18A; /* Subindex15 - C18A */
UINT8 C1ID1B; /* Subindex16 - C1ID1B */
UINT8 C1ID2B; /* Subindex17 - C1ID2B */
UINT8 C11B; /* Subindex18 - C11B */
UINT8 C12B; /* Subindex19 - C12B */
UINT8 C13B; /* Subindex20 - C13B */
UINT8 C14B; /* Subindex21 - C14B */
UINT8 C15B; /* Subindex22 - C15B */
UINT8 C16B; /* Subindex23 - C16B */
UINT8 C17B; /* Subindex24 - C17B */
UINT8 C18B; /* Subindex25 - C18B */
UINT8 C2ID1A; /* Subindex26 - C2ID1A */
UINT8 C2ID2A; /* Subindex27 - C2ID2A */
UINT8 C21A; /* Subindex28 - C21A */
UINT8 C22A; /* Subindex29 - C22A */
UINT8 C23A; /* Subindex30 - C23A */
UINT8 C24A; /* Subindex31 - C24A */
UINT8 C25A; /* Subindex32 - C25A */
UINT8 C26A; /* Subindex33 - C26A */
UINT8 C27A; /* Subindex34 - C27A */
UINT8 C28A; /* Subindex35 - C28A */
UINT8 C2ID1B; /* Subindex36 - C2ID1B */
UINT8 C2ID2B; /* Subindex37 - C2ID2B */
UINT8 C21B; /* Subindex38 - C21B */
UINT8 C22B; /* Subindex39 - C22B */
UINT8 C23B; /* Subindex40 - C23B */
UINT8 C24B; /* Subindex41 - C24B */
UINT8 C25B; /* Subindex42 - C25B */
UINT8 C26B; /* Subindex43 - C26B */
UINT8 C27B; /* Subindex44 - C27B */
UINT8 C28B; /* Subindex45 - C28B */
UINT8 C3ID1A; /* Subindex46 - C3ID1A */
UINT8 C3ID2A; /* Subindex47 - C3ID2A */
UINT8 C31A; /* Subindex48 - C31A */
UINT8 C32A; /* Subindex49 - C32A */
UINT8 C33A; /* Subindex50 - C33A */
UINT8 C34A; /* Subindex51 - C34A */
UINT8 C35A; /* Subindex52 - C35A */
UINT8 C36A; /* Subindex53 - C36A */
UINT8 C37A; /* Subindex54 - C37A */
UINT8 C38A; /* Subindex55 - C38A */
UINT8 C3ID1B; /* Subindex56 - C3ID1B */
UINT8 C3ID2B; /* Subindex57 - C3ID2B */
UINT8 C31B; /* Subindex58 - C31B */
UINT8 C32B; /* Subindex59 - C32B */
UINT8 C33B; /* Subindex60 - C33B */
UINT8 C34B; /* Subindex61 - C34B */
UINT8 C35B; /* Subindex62 - C35B */
UINT8 C36B; /* Subindex63 - C36B */
UINT8 C37B; /* Subindex64 - C37B */
UINT8 C38B; /* Subindex65 - C38B */
UINT8 End2; /* Subindex66 - end2 */
UINT8 End4; /* Subindex67 - end4 */
UINT8 End5; /* Subindex68 - end5 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 PDOChannel0x7000
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={68,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7050 : RMUIPDOChannel
******************************************************************************/
/**
* \addtogroup 0x7050 0x7050 | RMUIPDOChannel
* @{
* \brief Object 0x7050 (RMUIPDOChannel) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - U1<br>
* SubIndex 2 - U2<br>
* SubIndex 3 - U3<br>
* SubIndex 4 - U4<br>
* SubIndex 5 - U5<br>
* SubIndex 6 - U6<br>
* SubIndex 7 - U7<br>
* SubIndex 8 - U8<br>
* SubIndex 9 - U9<br>
* SubIndex 10 - U10<br>
* SubIndex 11 - U11<br>
* SubIndex 12 - U12<br>
* SubIndex 13 - U13<br>
* SubIndex 14 - U14<br>
* SubIndex 15 - U15<br>
* SubIndex 16 - U16<br>
* SubIndex 17 - U17<br>
* SubIndex 18 - U18<br>
* SubIndex 19 - U19<br>
* SubIndex 20 - U20<br>
* SubIndex 21 - U21<br>
* SubIndex 22 - U22<br>
* SubIndex 23 - U23<br>
* SubIndex 24 - U24<br>
* SubIndex 25 - U25<br>
* SubIndex 26 - U26<br>
* SubIndex 27 - U27<br>
* SubIndex 28 - U28<br>
* SubIndex 29 - U29<br>
* SubIndex 30 - U30<br>
* SubIndex 31 - U31<br>
* SubIndex 32 - U32<br>
* SubIndex 33 - U33<br>
* SubIndex 34 - U34<br>
* SubIndex 35 - U35<br>
* SubIndex 36 - U36<br>
* SubIndex 37 - U37<br>
* SubIndex 38 - U38<br>
* SubIndex 39 - U39<br>
* SubIndex 40 - U40<br>
* SubIndex 41 - U41<br>
* SubIndex 42 - U42<br>
* SubIndex 43 - U43<br>
* SubIndex 44 - U44<br>
* SubIndex 45 - U45<br>
* SubIndex 46 - U46<br>
* SubIndex 47 - U47<br>
* SubIndex 48 - U48<br>
* SubIndex 49 - U49<br>
* SubIndex 50 - U50<br>
* SubIndex 51 - U51<br>
* SubIndex 52 - U52<br>
* SubIndex 53 - U53<br>
* SubIndex 54 - U54<br>
* SubIndex 55 - U55<br>
* SubIndex 56 - U56<br>
* SubIndex 57 - U57<br>
* SubIndex 58 - U58<br>
* SubIndex 59 - U59<br>
* SubIndex 60 - U60<br>
* SubIndex 61 - U61<br>
* SubIndex 62 - U62<br>
* SubIndex 63 - U63<br>
* SubIndex 64 - U64<br>
* SubIndex 65 - U65<br>
* SubIndex 66 - U66<br>
* SubIndex 67 - U67<br>
* SubIndex 68 - U68<br>
* SubIndex 69 - U69<br>
* SubIndex 70 - U70<br>
* SubIndex 71 - U71<br>
* SubIndex 72 - U72<br>
* SubIndex 73 - U73<br>
* SubIndex 74 - U74<br>
* SubIndex 75 - U75<br>
* SubIndex 76 - U76<br>
* SubIndex 77 - U77<br>
* SubIndex 78 - U78<br>
* SubIndex 79 - U79<br>
* SubIndex 80 - U80<br>
* SubIndex 81 - U81<br>
* SubIndex 82 - U82<br>
* SubIndex 83 - U83<br>
* SubIndex 84 - U84<br>
* SubIndex 85 - U85<br>
* SubIndex 86 - U86<br>
* SubIndex 87 - U87<br>
* SubIndex 88 - U88<br>
* SubIndex 89 - U89<br>
* SubIndex 90 - U90<br>
* SubIndex 91 - U91<br>
* SubIndex 92 - U92<br>
* SubIndex 93 - U93<br>
* SubIndex 94 - U94<br>
* SubIndex 95 - U95<br>
* SubIndex 96 - U96<br>
* SubIndex 97 - U97<br>
* SubIndex 98 - U98<br>
* SubIndex 99 - U99<br>
* SubIndex 100 - U100<br>
* SubIndex 101 - U101<br>
* SubIndex 102 - U102<br>
* SubIndex 103 - U103<br>
* SubIndex 104 - U104<br>
* SubIndex 105 - U105<br>
* SubIndex 106 - U106<br>
* SubIndex 107 - U107<br>
* SubIndex 108 - U108<br>
* SubIndex 109 - U109<br>
* SubIndex 110 - U110<br>
* SubIndex 111 - U111<br>
* SubIndex 112 - U112<br>
* SubIndex 113 - U113<br>
* SubIndex 114 - U114<br>
* SubIndex 115 - U115<br>
* SubIndex 116 - U116<br>
* SubIndex 117 - U117<br>
* SubIndex 118 - U118<br>
* SubIndex 119 - U119<br>
* SubIndex 120 - U120<br>
* SubIndex 121 - U121<br>
* SubIndex 122 - U122<br>
* SubIndex 123 - U123<br>
* SubIndex 124 - U124<br>
* SubIndex 125 - U125<br>
* SubIndex 126 - U126<br>
* SubIndex 127 - U127<br>
* SubIndex 128 - end3<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7050[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - U1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - U2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex3 - U3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex4 - U4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex5 - U5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex6 - U6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex7 - U7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex8 - U8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex9 - U9 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex10 - U10 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex11 - U11 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex12 - U12 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex13 - U13 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex14 - U14 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex15 - U15 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex16 - U16 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex17 - U17 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex18 - U18 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex19 - U19 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex20 - U20 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex21 - U21 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex22 - U22 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex23 - U23 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex24 - U24 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex25 - U25 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex26 - U26 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex27 - U27 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex28 - U28 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex29 - U29 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex30 - U30 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex31 - U31 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex32 - U32 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex33 - U33 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex34 - U34 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex35 - U35 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex36 - U36 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex37 - U37 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex38 - U38 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex39 - U39 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex40 - U40 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex41 - U41 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex42 - U42 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex43 - U43 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex44 - U44 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex45 - U45 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex46 - U46 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex47 - U47 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex48 - U48 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex49 - U49 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex50 - U50 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex51 - U51 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex52 - U52 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex53 - U53 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex54 - U54 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex55 - U55 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex56 - U56 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex57 - U57 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex58 - U58 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex59 - U59 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex60 - U60 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex61 - U61 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex62 - U62 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex63 - U63 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex64 - U64 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex65 - U65 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex66 - U66 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex67 - U67 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex68 - U68 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex69 - U69 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex70 - U70 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex71 - U71 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex72 - U72 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex73 - U73 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex74 - U74 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex75 - U75 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex76 - U76 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex77 - U77 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex78 - U78 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex79 - U79 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex80 - U80 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex81 - U81 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex82 - U82 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex83 - U83 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex84 - U84 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex85 - U85 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex86 - U86 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex87 - U87 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex88 - U88 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex89 - U89 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex90 - U90 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex91 - U91 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex92 - U92 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex93 - U93 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex94 - U94 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex95 - U95 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex96 - U96 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex97 - U97 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex98 - U98 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex99 - U99 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex100 - U100 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex101 - U101 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex102 - U102 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex103 - U103 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex104 - U104 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex105 - U105 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex106 - U106 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex107 - U107 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex108 - U108 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex109 - U109 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex110 - U110 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex111 - U111 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex112 - U112 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex113 - U113 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex114 - U114 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex115 - U115 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex116 - U116 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex117 - U117 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex118 - U118 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex119 - U119 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex120 - U120 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex121 - U121 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex122 - U122 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex123 - U123 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex124 - U124 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex125 - U125 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex126 - U126 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex127 - U127 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex128 - end3 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7050[] = "RMUIPDOChannel\000"
"U1\000"
"U2\000"
"U3\000"
"U4\000"
"U5\000"
"U6\000"
"U7\000"
"U8\000"
"U9\000"
"U10\000"
"U11\000"
"U12\000"
"U13\000"
"U14\000"
"U15\000"
"U16\000"
"U17\000"
"U18\000"
"U19\000"
"U20\000"
"U21\000"
"U22\000"
"U23\000"
"U24\000"
"U25\000"
"U26\000"
"U27\000"
"U28\000"
"U29\000"
"U30\000"
"U31\000"
"U32\000"
"U33\000"
"U34\000"
"U35\000"
"U36\000"
"U37\000"
"U38\000"
"U39\000"
"U40\000"
"U41\000"
"U42\000"
"U43\000"
"U44\000"
"U45\000"
"U46\000"
"U47\000"
"U48\000"
"U49\000"
"U50\000"
"U51\000"
"U52\000"
"U53\000"
"U54\000"
"U55\000"
"U56\000"
"U57\000"
"U58\000"
"U59\000"
"U60\000"
"U61\000"
"U62\000"
"U63\000"
"U64\000"
"U65\000"
"U66\000"
"U67\000"
"U68\000"
"U69\000"
"U70\000"
"U71\000"
"U72\000"
"U73\000"
"U74\000"
"U75\000"
"U76\000"
"U77\000"
"U78\000"
"U79\000"
"U80\000"
"U81\000"
"U82\000"
"U83\000"
"U84\000"
"U85\000"
"U86\000"
"U87\000"
"U88\000"
"U89\000"
"U90\000"
"U91\000"
"U92\000"
"U93\000"
"U94\000"
"U95\000"
"U96\000"
"U97\000"
"U98\000"
"U99\000"
"U100\000"
"U101\000"
"U102\000"
"U103\000"
"U104\000"
"U105\000"
"U106\000"
"U107\000"
"U108\000"
"U109\000"
"U110\000"
"U111\000"
"U112\000"
"U113\000"
"U114\000"
"U115\000"
"U116\000"
"U117\000"
"U118\000"
"U119\000"
"U120\000"
"U121\000"
"U122\000"
"U123\000"
"U124\000"
"U125\000"
"U126\000"
"U127\000"
"end3\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 U1; /* Subindex1 - U1 */
UINT8 U2; /* Subindex2 - U2 */
UINT8 U3; /* Subindex3 - U3 */
UINT8 U4; /* Subindex4 - U4 */
UINT8 U5; /* Subindex5 - U5 */
UINT8 U6; /* Subindex6 - U6 */
UINT8 U7; /* Subindex7 - U7 */
UINT8 U8; /* Subindex8 - U8 */
UINT8 U9; /* Subindex9 - U9 */
UINT8 U10; /* Subindex10 - U10 */
UINT8 U11; /* Subindex11 - U11 */
UINT8 U12; /* Subindex12 - U12 */
UINT8 U13; /* Subindex13 - U13 */
UINT8 U14; /* Subindex14 - U14 */
UINT8 U15; /* Subindex15 - U15 */
UINT8 U16; /* Subindex16 - U16 */
UINT8 U17; /* Subindex17 - U17 */
UINT8 U18; /* Subindex18 - U18 */
UINT8 U19; /* Subindex19 - U19 */
UINT8 U20; /* Subindex20 - U20 */
UINT8 U21; /* Subindex21 - U21 */
UINT8 U22; /* Subindex22 - U22 */
UINT8 U23; /* Subindex23 - U23 */
UINT8 U24; /* Subindex24 - U24 */
UINT8 U25; /* Subindex25 - U25 */
UINT8 U26; /* Subindex26 - U26 */
UINT8 U27; /* Subindex27 - U27 */
UINT8 U28; /* Subindex28 - U28 */
UINT8 U29; /* Subindex29 - U29 */
UINT8 U30; /* Subindex30 - U30 */
UINT8 U31; /* Subindex31 - U31 */
UINT8 U32; /* Subindex32 - U32 */
UINT8 U33; /* Subindex33 - U33 */
UINT8 U34; /* Subindex34 - U34 */
UINT8 U35; /* Subindex35 - U35 */
UINT8 U36; /* Subindex36 - U36 */
UINT8 U37; /* Subindex37 - U37 */
UINT8 U38; /* Subindex38 - U38 */
UINT8 U39; /* Subindex39 - U39 */
UINT8 U40; /* Subindex40 - U40 */
UINT8 U41; /* Subindex41 - U41 */
UINT8 U42; /* Subindex42 - U42 */
UINT8 U43; /* Subindex43 - U43 */
UINT8 U44; /* Subindex44 - U44 */
UINT8 U45; /* Subindex45 - U45 */
UINT8 U46; /* Subindex46 - U46 */
UINT8 U47; /* Subindex47 - U47 */
UINT8 U48; /* Subindex48 - U48 */
UINT8 U49; /* Subindex49 - U49 */
UINT8 U50; /* Subindex50 - U50 */
UINT8 U51; /* Subindex51 - U51 */
UINT8 U52; /* Subindex52 - U52 */
UINT8 U53; /* Subindex53 - U53 */
UINT8 U54; /* Subindex54 - U54 */
UINT8 U55; /* Subindex55 - U55 */
UINT8 U56; /* Subindex56 - U56 */
UINT8 U57; /* Subindex57 - U57 */
UINT8 U58; /* Subindex58 - U58 */
UINT8 U59; /* Subindex59 - U59 */
UINT8 U60; /* Subindex60 - U60 */
UINT8 U61; /* Subindex61 - U61 */
UINT8 U62; /* Subindex62 - U62 */
UINT8 U63; /* Subindex63 - U63 */
UINT8 U64; /* Subindex64 - U64 */
UINT8 U65; /* Subindex65 - U65 */
UINT8 U66; /* Subindex66 - U66 */
UINT8 U67; /* Subindex67 - U67 */
UINT8 U68; /* Subindex68 - U68 */
UINT8 U69; /* Subindex69 - U69 */
UINT8 U70; /* Subindex70 - U70 */
UINT8 U71; /* Subindex71 - U71 */
UINT8 U72; /* Subindex72 - U72 */
UINT8 U73; /* Subindex73 - U73 */
UINT8 U74; /* Subindex74 - U74 */
UINT8 U75; /* Subindex75 - U75 */
UINT8 U76; /* Subindex76 - U76 */
UINT8 U77; /* Subindex77 - U77 */
UINT8 U78; /* Subindex78 - U78 */
UINT8 U79; /* Subindex79 - U79 */
UINT8 U80; /* Subindex80 - U80 */
UINT8 U81; /* Subindex81 - U81 */
UINT8 U82; /* Subindex82 - U82 */
UINT8 U83; /* Subindex83 - U83 */
UINT8 U84; /* Subindex84 - U84 */
UINT8 U85; /* Subindex85 - U85 */
UINT8 U86; /* Subindex86 - U86 */
UINT8 U87; /* Subindex87 - U87 */
UINT8 U88; /* Subindex88 - U88 */
UINT8 U89; /* Subindex89 - U89 */
UINT8 U90; /* Subindex90 - U90 */
UINT8 U91; /* Subindex91 - U91 */
UINT8 U92; /* Subindex92 - U92 */
UINT8 U93; /* Subindex93 - U93 */
UINT8 U94; /* Subindex94 - U94 */
UINT8 U95; /* Subindex95 - U95 */
UINT8 U96; /* Subindex96 - U96 */
UINT8 U97; /* Subindex97 - U97 */
UINT8 U98; /* Subindex98 - U98 */
UINT8 U99; /* Subindex99 - U99 */
UINT8 U100; /* Subindex100 - U100 */
UINT8 U101; /* Subindex101 - U101 */
UINT8 U102; /* Subindex102 - U102 */
UINT8 U103; /* Subindex103 - U103 */
UINT8 U104; /* Subindex104 - U104 */
UINT8 U105; /* Subindex105 - U105 */
UINT8 U106; /* Subindex106 - U106 */
UINT8 U107; /* Subindex107 - U107 */
UINT8 U108; /* Subindex108 - U108 */
UINT8 U109; /* Subindex109 - U109 */
UINT8 U110; /* Subindex110 - U110 */
UINT8 U111; /* Subindex111 - U111 */
UINT8 U112; /* Subindex112 - U112 */
UINT8 U113; /* Subindex113 - U113 */
UINT8 U114; /* Subindex114 - U114 */
UINT8 U115; /* Subindex115 - U115 */
UINT8 U116; /* Subindex116 - U116 */
UINT8 U117; /* Subindex117 - U117 */
UINT8 U118; /* Subindex118 - U118 */
UINT8 U119; /* Subindex119 - U119 */
UINT8 U120; /* Subindex120 - U120 */
UINT8 U121; /* Subindex121 - U121 */
UINT8 U122; /* Subindex122 - U122 */
UINT8 U123; /* Subindex123 - U123 */
UINT8 U124; /* Subindex124 - U124 */
UINT8 U125; /* Subindex125 - U125 */
UINT8 U126; /* Subindex126 - U126 */
UINT8 U127; /* Subindex127 - U127 */
UINT8 End3; /* Subindex128 - end3 */
} OBJ_STRUCT_PACKED_END
TOBJ7050;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7050 RMUIPDOChannel0x7050
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 68 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &PDOChannelProcessDataMapping0x1600, NULL , NULL , 0x0000 },
/* Object 0x1605 */
{NULL , NULL ,  0x1605 , {DEFTYPE_PDOMAPPING , 128 | (OBJCODE_REC << 8)} , asEntryDesc0x1605 , aName0x1605 , &RMUIPDOChannelProcessDataMapping0x1605, NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 216 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &PDIChannelProcessDataMapping0x1A00, NULL , NULL , 0x0000 },
/* Object 0x1A0F */
{NULL , NULL ,  0x1A0F , {DEFTYPE_PDOMAPPING , 200 | (OBJCODE_REC << 8)} , asEntryDesc0x1A0F , aName0x1A0F , &RMDAPDIChannelProcessDataMapping0x1A0F, NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 2 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 2 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 216 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &PDIChannel0x6000, NULL , NULL , 0x0000 },
/* Object 0x60F0 */
{NULL , NULL ,  0x60F0 , {DEFTYPE_RECORD , 200 | (OBJCODE_REC << 8)} , asEntryDesc0x60F0 , aName0x60F0 , &RMDAPDIChannel0x60F0, NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 68 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &PDOChannel0x7000, NULL , NULL , 0x0000 },
/* Object 0x7050 */
{NULL , NULL ,  0x7050 , {DEFTYPE_RECORD , 128 | (OBJCODE_REC << 8)} , asEntryDesc0x7050 , aName0x7050 , &RMUIPDOChannel0x7050, NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _SSC__DEVICE_OBJECTS_H_
