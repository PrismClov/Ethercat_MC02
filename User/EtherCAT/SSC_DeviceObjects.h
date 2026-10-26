/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup SSC_Device SSC_Device
* @{
*/

/**
\file SSC_DeviceObjects
\author ET9300Utilities.ApplicationHandler (Version 1.6.4.0) | EthercatSSC@beckhoff.com

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
* SubIndex 69 - Reference to 0x7000.69<br>
* SubIndex 70 - Reference to 0x7000.70<br>
* SubIndex 71 - Reference to 0x7000.71<br>
* SubIndex 72 - Reference to 0x7000.72<br>
* SubIndex 73 - Reference to 0x7000.73<br>
* SubIndex 74 - Reference to 0x7000.74<br>
* SubIndex 75 - Reference to 0x7000.75<br>
* SubIndex 76 - Reference to 0x7000.76<br>
* SubIndex 77 - Reference to 0x7000.77<br>
* SubIndex 78 - Reference to 0x7000.78<br>
* SubIndex 79 - Reference to 0x7000.79<br>
* SubIndex 80 - Reference to 0x7000.80<br>
* SubIndex 81 - Reference to 0x7000.81<br>
* SubIndex 82 - Reference to 0x7000.82<br>
* SubIndex 83 - Reference to 0x7000.83<br>
* SubIndex 84 - Reference to 0x7000.84<br>
* SubIndex 85 - Reference to 0x7000.85<br>
* SubIndex 86 - Reference to 0x7000.86<br>
* SubIndex 87 - Reference to 0x7000.87<br>
* SubIndex 88 - Reference to 0x7000.88<br>
* SubIndex 89 - Reference to 0x7000.89<br>
* SubIndex 90 - Reference to 0x7000.90<br>
* SubIndex 91 - Reference to 0x7000.91<br>
* SubIndex 92 - Reference to 0x7000.92<br>
* SubIndex 93 - Reference to 0x7000.93<br>
* SubIndex 94 - Reference to 0x7000.94<br>
* SubIndex 95 - Reference to 0x7000.95<br>
* SubIndex 96 - Reference to 0x7000.96<br>
* SubIndex 97 - Reference to 0x7000.97<br>
* SubIndex 98 - Reference to 0x7000.98<br>
* SubIndex 99 - Reference to 0x7000.99<br>
* SubIndex 100 - Reference to 0x7000.100<br>
* SubIndex 101 - Reference to 0x7000.101<br>
* SubIndex 102 - Reference to 0x7000.102<br>
* SubIndex 103 - Reference to 0x7000.103<br>
* SubIndex 104 - Reference to 0x7000.104<br>
* SubIndex 105 - Reference to 0x7000.105<br>
* SubIndex 106 - Reference to 0x7000.106<br>
* SubIndex 107 - Reference to 0x7000.107<br>
* SubIndex 108 - Reference to 0x7000.108<br>
* SubIndex 109 - Reference to 0x7000.109<br>
* SubIndex 110 - Reference to 0x7000.110<br>
* SubIndex 111 - Reference to 0x7000.111<br>
* SubIndex 112 - Reference to 0x7000.112<br>
* SubIndex 113 - Reference to 0x7000.113<br>
* SubIndex 114 - Reference to 0x7000.114<br>
* SubIndex 115 - Reference to 0x7000.115<br>
* SubIndex 116 - Reference to 0x7000.116<br>
* SubIndex 117 - Reference to 0x7000.117<br>
* SubIndex 118 - Reference to 0x7000.118<br>
* SubIndex 119 - Reference to 0x7000.119<br>
* SubIndex 120 - Reference to 0x7000.120<br>
* SubIndex 121 - Reference to 0x7000.121<br>
* SubIndex 122 - Reference to 0x7000.122<br>
* SubIndex 123 - Reference to 0x7000.123<br>
* SubIndex 124 - Reference to 0x7000.124<br>
* SubIndex 125 - Reference to 0x7000.125<br>
* SubIndex 126 - Reference to 0x7000.126<br>
* SubIndex 127 - Reference to 0x7000.127<br>
* SubIndex 128 - Reference to 0x7000.128<br>
* SubIndex 129 - Reference to 0x7000.129<br>
* SubIndex 130 - Reference to 0x7000.130<br>
* SubIndex 131 - Reference to 0x7000.131<br>
* SubIndex 132 - Reference to 0x7000.132<br>
* SubIndex 133 - Reference to 0x7000.133<br>
* SubIndex 134 - Reference to 0x7000.134<br>
* SubIndex 135 - Reference to 0x7000.135<br>
* SubIndex 136 - Reference to 0x7000.136<br>
* SubIndex 137 - Reference to 0x7000.137<br>
* SubIndex 138 - Reference to 0x7000.138<br>
* SubIndex 139 - Reference to 0x7000.139<br>
* SubIndex 140 - Reference to 0x7000.140<br>
* SubIndex 141 - Reference to 0x7000.141<br>
* SubIndex 142 - Reference to 0x7000.142<br>
* SubIndex 143 - Reference to 0x7000.143<br>
* SubIndex 144 - Reference to 0x7000.144<br>
* SubIndex 145 - Reference to 0x7000.145<br>
* SubIndex 146 - Reference to 0x7000.146<br>
* SubIndex 147 - Reference to 0x7000.147<br>
* SubIndex 148 - Reference to 0x7000.148<br>
* SubIndex 149 - Reference to 0x7000.149<br>
* SubIndex 150 - Reference to 0x7000.150<br>
* SubIndex 151 - Reference to 0x7000.151<br>
* SubIndex 152 - Reference to 0x7000.152<br>
* SubIndex 153 - Reference to 0x7000.153<br>
* SubIndex 154 - Reference to 0x7000.154<br>
* SubIndex 155 - Reference to 0x7000.155<br>
* SubIndex 156 - Reference to 0x7000.156<br>
* SubIndex 157 - Reference to 0x7000.157<br>
* SubIndex 158 - Reference to 0x7000.158<br>
* SubIndex 159 - Reference to 0x7000.159<br>
* SubIndex 160 - Reference to 0x7000.160<br>
* SubIndex 161 - Reference to 0x7000.161<br>
* SubIndex 162 - Reference to 0x7000.162<br>
* SubIndex 163 - Reference to 0x7000.163<br>
* SubIndex 164 - Reference to 0x7000.164<br>
* SubIndex 165 - Reference to 0x7000.165<br>
* SubIndex 166 - Reference to 0x7000.166<br>
* SubIndex 167 - Reference to 0x7000.167<br>
* SubIndex 168 - Reference to 0x7000.168<br>
* SubIndex 169 - Reference to 0x7000.169<br>
* SubIndex 170 - Reference to 0x7000.170<br>
* SubIndex 171 - Reference to 0x7000.171<br>
* SubIndex 172 - Reference to 0x7000.172<br>
* SubIndex 173 - Reference to 0x7000.173<br>
* SubIndex 174 - Reference to 0x7000.174<br>
* SubIndex 175 - Reference to 0x7000.175<br>
* SubIndex 176 - Reference to 0x7000.176<br>
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 - Reference to 0x7000.68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 - Reference to 0x7000.69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 - Reference to 0x7000.70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 - Reference to 0x7000.71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 - Reference to 0x7000.72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 - Reference to 0x7000.73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 - Reference to 0x7000.74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 - Reference to 0x7000.75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 - Reference to 0x7000.76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 - Reference to 0x7000.77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 - Reference to 0x7000.78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 - Reference to 0x7000.79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 - Reference to 0x7000.80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 - Reference to 0x7000.81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 - Reference to 0x7000.82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 - Reference to 0x7000.83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 - Reference to 0x7000.84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 - Reference to 0x7000.85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 - Reference to 0x7000.86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 - Reference to 0x7000.87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 - Reference to 0x7000.88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 - Reference to 0x7000.89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 - Reference to 0x7000.90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 - Reference to 0x7000.91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 - Reference to 0x7000.92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 - Reference to 0x7000.93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 - Reference to 0x7000.94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 - Reference to 0x7000.95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 - Reference to 0x7000.96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 - Reference to 0x7000.97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 - Reference to 0x7000.98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 - Reference to 0x7000.99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 - Reference to 0x7000.100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 - Reference to 0x7000.101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 - Reference to 0x7000.102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 - Reference to 0x7000.103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 - Reference to 0x7000.104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 - Reference to 0x7000.105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 - Reference to 0x7000.106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 - Reference to 0x7000.107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 - Reference to 0x7000.108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 - Reference to 0x7000.109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 - Reference to 0x7000.110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 - Reference to 0x7000.111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 - Reference to 0x7000.112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 - Reference to 0x7000.113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 - Reference to 0x7000.114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex115 - Reference to 0x7000.115 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex116 - Reference to 0x7000.116 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex117 - Reference to 0x7000.117 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex118 - Reference to 0x7000.118 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex119 - Reference to 0x7000.119 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex120 - Reference to 0x7000.120 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex121 - Reference to 0x7000.121 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex122 - Reference to 0x7000.122 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex123 - Reference to 0x7000.123 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex124 - Reference to 0x7000.124 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex125 - Reference to 0x7000.125 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex126 - Reference to 0x7000.126 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex127 - Reference to 0x7000.127 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex128 - Reference to 0x7000.128 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex129 - Reference to 0x7000.129 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex130 - Reference to 0x7000.130 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex131 - Reference to 0x7000.131 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex132 - Reference to 0x7000.132 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex133 - Reference to 0x7000.133 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex134 - Reference to 0x7000.134 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex135 - Reference to 0x7000.135 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex136 - Reference to 0x7000.136 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex137 - Reference to 0x7000.137 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex138 - Reference to 0x7000.138 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex139 - Reference to 0x7000.139 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex140 - Reference to 0x7000.140 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex141 - Reference to 0x7000.141 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex142 - Reference to 0x7000.142 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex143 - Reference to 0x7000.143 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex144 - Reference to 0x7000.144 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex145 - Reference to 0x7000.145 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex146 - Reference to 0x7000.146 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex147 - Reference to 0x7000.147 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex148 - Reference to 0x7000.148 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex149 - Reference to 0x7000.149 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex150 - Reference to 0x7000.150 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex151 - Reference to 0x7000.151 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex152 - Reference to 0x7000.152 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex153 - Reference to 0x7000.153 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex154 - Reference to 0x7000.154 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex155 - Reference to 0x7000.155 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex156 - Reference to 0x7000.156 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex157 - Reference to 0x7000.157 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex158 - Reference to 0x7000.158 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex159 - Reference to 0x7000.159 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex160 - Reference to 0x7000.160 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex161 - Reference to 0x7000.161 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex162 - Reference to 0x7000.162 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex163 - Reference to 0x7000.163 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex164 - Reference to 0x7000.164 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex165 - Reference to 0x7000.165 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex166 - Reference to 0x7000.166 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex167 - Reference to 0x7000.167 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex168 - Reference to 0x7000.168 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex169 - Reference to 0x7000.169 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex170 - Reference to 0x7000.170 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex171 - Reference to 0x7000.171 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex172 - Reference to 0x7000.172 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex173 - Reference to 0x7000.173 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex174 - Reference to 0x7000.174 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex175 - Reference to 0x7000.175 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex176 - Reference to 0x7000.176 */

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
"SubIndex 176\000\377";
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
UINT32 SI69; /* Subindex69 - Reference to 0x7000.69 */
UINT32 SI70; /* Subindex70 - Reference to 0x7000.70 */
UINT32 SI71; /* Subindex71 - Reference to 0x7000.71 */
UINT32 SI72; /* Subindex72 - Reference to 0x7000.72 */
UINT32 SI73; /* Subindex73 - Reference to 0x7000.73 */
UINT32 SI74; /* Subindex74 - Reference to 0x7000.74 */
UINT32 SI75; /* Subindex75 - Reference to 0x7000.75 */
UINT32 SI76; /* Subindex76 - Reference to 0x7000.76 */
UINT32 SI77; /* Subindex77 - Reference to 0x7000.77 */
UINT32 SI78; /* Subindex78 - Reference to 0x7000.78 */
UINT32 SI79; /* Subindex79 - Reference to 0x7000.79 */
UINT32 SI80; /* Subindex80 - Reference to 0x7000.80 */
UINT32 SI81; /* Subindex81 - Reference to 0x7000.81 */
UINT32 SI82; /* Subindex82 - Reference to 0x7000.82 */
UINT32 SI83; /* Subindex83 - Reference to 0x7000.83 */
UINT32 SI84; /* Subindex84 - Reference to 0x7000.84 */
UINT32 SI85; /* Subindex85 - Reference to 0x7000.85 */
UINT32 SI86; /* Subindex86 - Reference to 0x7000.86 */
UINT32 SI87; /* Subindex87 - Reference to 0x7000.87 */
UINT32 SI88; /* Subindex88 - Reference to 0x7000.88 */
UINT32 SI89; /* Subindex89 - Reference to 0x7000.89 */
UINT32 SI90; /* Subindex90 - Reference to 0x7000.90 */
UINT32 SI91; /* Subindex91 - Reference to 0x7000.91 */
UINT32 SI92; /* Subindex92 - Reference to 0x7000.92 */
UINT32 SI93; /* Subindex93 - Reference to 0x7000.93 */
UINT32 SI94; /* Subindex94 - Reference to 0x7000.94 */
UINT32 SI95; /* Subindex95 - Reference to 0x7000.95 */
UINT32 SI96; /* Subindex96 - Reference to 0x7000.96 */
UINT32 SI97; /* Subindex97 - Reference to 0x7000.97 */
UINT32 SI98; /* Subindex98 - Reference to 0x7000.98 */
UINT32 SI99; /* Subindex99 - Reference to 0x7000.99 */
UINT32 SI100; /* Subindex100 - Reference to 0x7000.100 */
UINT32 SI101; /* Subindex101 - Reference to 0x7000.101 */
UINT32 SI102; /* Subindex102 - Reference to 0x7000.102 */
UINT32 SI103; /* Subindex103 - Reference to 0x7000.103 */
UINT32 SI104; /* Subindex104 - Reference to 0x7000.104 */
UINT32 SI105; /* Subindex105 - Reference to 0x7000.105 */
UINT32 SI106; /* Subindex106 - Reference to 0x7000.106 */
UINT32 SI107; /* Subindex107 - Reference to 0x7000.107 */
UINT32 SI108; /* Subindex108 - Reference to 0x7000.108 */
UINT32 SI109; /* Subindex109 - Reference to 0x7000.109 */
UINT32 SI110; /* Subindex110 - Reference to 0x7000.110 */
UINT32 SI111; /* Subindex111 - Reference to 0x7000.111 */
UINT32 SI112; /* Subindex112 - Reference to 0x7000.112 */
UINT32 SI113; /* Subindex113 - Reference to 0x7000.113 */
UINT32 SI114; /* Subindex114 - Reference to 0x7000.114 */
UINT32 SI115; /* Subindex115 - Reference to 0x7000.115 */
UINT32 SI116; /* Subindex116 - Reference to 0x7000.116 */
UINT32 SI117; /* Subindex117 - Reference to 0x7000.117 */
UINT32 SI118; /* Subindex118 - Reference to 0x7000.118 */
UINT32 SI119; /* Subindex119 - Reference to 0x7000.119 */
UINT32 SI120; /* Subindex120 - Reference to 0x7000.120 */
UINT32 SI121; /* Subindex121 - Reference to 0x7000.121 */
UINT32 SI122; /* Subindex122 - Reference to 0x7000.122 */
UINT32 SI123; /* Subindex123 - Reference to 0x7000.123 */
UINT32 SI124; /* Subindex124 - Reference to 0x7000.124 */
UINT32 SI125; /* Subindex125 - Reference to 0x7000.125 */
UINT32 SI126; /* Subindex126 - Reference to 0x7000.126 */
UINT32 SI127; /* Subindex127 - Reference to 0x7000.127 */
UINT32 SI128; /* Subindex128 - Reference to 0x7000.128 */
UINT32 SI129; /* Subindex129 - Reference to 0x7000.129 */
UINT32 SI130; /* Subindex130 - Reference to 0x7000.130 */
UINT32 SI131; /* Subindex131 - Reference to 0x7000.131 */
UINT32 SI132; /* Subindex132 - Reference to 0x7000.132 */
UINT32 SI133; /* Subindex133 - Reference to 0x7000.133 */
UINT32 SI134; /* Subindex134 - Reference to 0x7000.134 */
UINT32 SI135; /* Subindex135 - Reference to 0x7000.135 */
UINT32 SI136; /* Subindex136 - Reference to 0x7000.136 */
UINT32 SI137; /* Subindex137 - Reference to 0x7000.137 */
UINT32 SI138; /* Subindex138 - Reference to 0x7000.138 */
UINT32 SI139; /* Subindex139 - Reference to 0x7000.139 */
UINT32 SI140; /* Subindex140 - Reference to 0x7000.140 */
UINT32 SI141; /* Subindex141 - Reference to 0x7000.141 */
UINT32 SI142; /* Subindex142 - Reference to 0x7000.142 */
UINT32 SI143; /* Subindex143 - Reference to 0x7000.143 */
UINT32 SI144; /* Subindex144 - Reference to 0x7000.144 */
UINT32 SI145; /* Subindex145 - Reference to 0x7000.145 */
UINT32 SI146; /* Subindex146 - Reference to 0x7000.146 */
UINT32 SI147; /* Subindex147 - Reference to 0x7000.147 */
UINT32 SI148; /* Subindex148 - Reference to 0x7000.148 */
UINT32 SI149; /* Subindex149 - Reference to 0x7000.149 */
UINT32 SI150; /* Subindex150 - Reference to 0x7000.150 */
UINT32 SI151; /* Subindex151 - Reference to 0x7000.151 */
UINT32 SI152; /* Subindex152 - Reference to 0x7000.152 */
UINT32 SI153; /* Subindex153 - Reference to 0x7000.153 */
UINT32 SI154; /* Subindex154 - Reference to 0x7000.154 */
UINT32 SI155; /* Subindex155 - Reference to 0x7000.155 */
UINT32 SI156; /* Subindex156 - Reference to 0x7000.156 */
UINT32 SI157; /* Subindex157 - Reference to 0x7000.157 */
UINT32 SI158; /* Subindex158 - Reference to 0x7000.158 */
UINT32 SI159; /* Subindex159 - Reference to 0x7000.159 */
UINT32 SI160; /* Subindex160 - Reference to 0x7000.160 */
UINT32 SI161; /* Subindex161 - Reference to 0x7000.161 */
UINT32 SI162; /* Subindex162 - Reference to 0x7000.162 */
UINT32 SI163; /* Subindex163 - Reference to 0x7000.163 */
UINT32 SI164; /* Subindex164 - Reference to 0x7000.164 */
UINT32 SI165; /* Subindex165 - Reference to 0x7000.165 */
UINT32 SI166; /* Subindex166 - Reference to 0x7000.166 */
UINT32 SI167; /* Subindex167 - Reference to 0x7000.167 */
UINT32 SI168; /* Subindex168 - Reference to 0x7000.168 */
UINT32 SI169; /* Subindex169 - Reference to 0x7000.169 */
UINT32 SI170; /* Subindex170 - Reference to 0x7000.170 */
UINT32 SI171; /* Subindex171 - Reference to 0x7000.171 */
UINT32 SI172; /* Subindex172 - Reference to 0x7000.172 */
UINT32 SI173; /* Subindex173 - Reference to 0x7000.173 */
UINT32 SI174; /* Subindex174 - Reference to 0x7000.174 */
UINT32 SI175; /* Subindex175 - Reference to 0x7000.175 */
UINT32 SI176; /* Subindex176 - Reference to 0x7000.176 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 PDOChannelProcessDataMapping0x1600
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={176,0x70000108,0x70000208,0x70000308,0x70000408,0x70000508,0x70000608,0x70000708,0x70000808,0x70000908,0x70000A08,0x70000B08,0x70000C08,0x70000D08,0x70000E08,0x70000F08,0x70001008,0x70001108,0x70001208,0x70001308,0x70001408,0x70001508,0x70001608,0x70001708,0x70001808,0x70001908,0x70001A08,0x70001B08,0x70001C08,0x70001D08,0x70001E08,0x70001F08,0x70002008,0x70002108,0x70002208,0x70002308,0x70002408,0x70002508,0x70002608,0x70002708,0x70002808,0x70002908,0x70002A08,0x70002B08,0x70002C08,0x70002D08,0x70002E08,0x70002F08,0x70003008,0x70003108,0x70003208,0x70003308,0x70003408,0x70003508,0x70003608,0x70003708,0x70003808,0x70003908,0x70003A08,0x70003B08,0x70003C08,0x70003D08,0x70003E08,0x70003F08,0x70004008,0x70004108,0x70004208,0x70004308,0x70004408,0x70004508,0x70004608,0x70004708,0x70004808,0x70004908,0x70004A08,0x70004B08,0x70004C08,0x70004D08,0x70004E08,0x70004F08,0x70005008,0x70005108,0x70005208,0x70005308,0x70005408,0x70005508,0x70005608,0x70005708,0x70005808,0x70005908,0x70005A08,0x70005B08,0x70005C08,0x70005D08,0x70005E08,0x70005F08,0x70006008,0x70006108,0x70006208,0x70006308,0x70006408,0x70006508,0x70006608,0x70006708,0x70006808,0x70006908,0x70006A08,0x70006B08,0x70006C08,0x70006D08,0x70006E08,0x70006F08,0x70007008,0x70007108,0x70007208,0x70007308,0x70007408,0x70007508,0x70007608,0x70007708,0x70007808,0x70007908,0x70007A08,0x70007B08,0x70007C08,0x70007D08,0x70007E08,0x70007F08,0x70008008,0x70008108,0x70008208,0x70008308,0x70008408,0x70008508,0x70008608,0x70008708,0x70008808,0x70008908,0x70008A08,0x70008B08,0x70008C08,0x70008D08,0x70008E08,0x70008F08,0x70009008,0x70009108,0x70009208,0x70009308,0x70009408,0x70009508,0x70009608,0x70009708,0x70009808,0x70009908,0x70009A08,0x70009B08,0x70009C08,0x70009D08,0x70009E08,0x70009F08,0x7000A008,0x7000A108,0x7000A208,0x7000A308,0x7000A408,0x7000A508,0x7000A608,0x7000A708,0x7000A808,0x7000A908,0x7000AA08,0x7000AB08,0x7000AC08,0x7000AD08,0x7000AE08,0x7000AF08,0x7000B008}
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex20 - Reference to 0x7050.20 */

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
"SubIndex 020\000\377";
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
} OBJ_STRUCT_PACKED_END
TOBJ1605;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1605 RMUIPDOChannelProcessDataMapping0x1605
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={20,0x70500108,0x70500208,0x70500308,0x70500408,0x70500508,0x70500608,0x70500708,0x70500808,0x70500908,0x70500A08,0x70500B08,0x70500C08,0x70500D08,0x70500E08,0x70500F08,0x70501008,0x70501108,0x70501208,0x70501308,0x70501408}
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex204 - Reference to 0x6000.204 */

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
"SubIndex 204\000\377";
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
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 PDIChannelProcessDataMapping0x1A00
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={204,0x60000108,0x60000208,0x60000308,0x60000408,0x60000508,0x60000608,0x60000708,0x60000808,0x60000908,0x60000A08,0x60000B08,0x60000C08,0x60000D08,0x60000E08,0x60000F08,0x60001008,0x60001108,0x60001208,0x60001308,0x60001408,0x60001508,0x60001608,0x60001708,0x60001808,0x60001908,0x60001A08,0x60001B08,0x60001C08,0x60001D08,0x60001E08,0x60001F08,0x60002008,0x60002108,0x60002208,0x60002308,0x60002408,0x60002508,0x60002608,0x60002708,0x60002808,0x60002908,0x60002A08,0x60002B08,0x60002C08,0x60002D08,0x60002E08,0x60002F08,0x60003008,0x60003108,0x60003208,0x60003308,0x60003408,0x60003508,0x60003608,0x60003708,0x60003808,0x60003908,0x60003A08,0x60003B08,0x60003C08,0x60003D08,0x60003E08,0x60003F08,0x60004008,0x60004108,0x60004208,0x60004308,0x60004408,0x60004508,0x60004608,0x60004708,0x60004808,0x60004908,0x60004A08,0x60004B08,0x60004C08,0x60004D08,0x60004E08,0x60004F08,0x60005008,0x60005108,0x60005208,0x60005308,0x60005408,0x60005508,0x60005608,0x60005708,0x60005808,0x60005908,0x60005A08,0x60005B08,0x60005C08,0x60005D08,0x60005E08,0x60005F08,0x60006008,0x60006108,0x60006208,0x60006308,0x60006408,0x60006508,0x60006608,0x60006708,0x60006808,0x60006908,0x60006A08,0x60006B08,0x60006C08,0x60006D08,0x60006E08,0x60006F08,0x60007008,0x60007108,0x60007208,0x60007308,0x60007408,0x60007508,0x60007608,0x60007708,0x60007808,0x60007908,0x60007A08,0x60007B08,0x60007C08,0x60007D08,0x60007E08,0x60007F08,0x60008008,0x60008108,0x60008208,0x60008308,0x60008408,0x60008508,0x60008608,0x60008708,0x60008808,0x60008908,0x60008A08,0x60008B08,0x60008C08,0x60008D08,0x60008E08,0x60008F08,0x60009008,0x60009108,0x60009208,0x60009308,0x60009408,0x60009508,0x60009608,0x60009708,0x60009808,0x60009908,0x60009A08,0x60009B08,0x60009C08,0x60009D08,0x60009E08,0x60009F08,0x6000A008,0x6000A108,0x6000A208,0x6000A308,0x6000A408,0x6000A508,0x6000A608,0x6000A708,0x6000A808,0x6000A908,0x6000AA08,0x6000AB08,0x6000AC08,0x6000AD08,0x6000AE08,0x6000AF08,0x6000B008,0x6000B108,0x6000B208,0x6000B308,0x6000B408,0x6000B508,0x6000B608,0x6000B708,0x6000B808,0x6000B908,0x6000BA08,0x6000BB08,0x6000BC08,0x6000BD08,0x6000BE08,0x6000BF08,0x6000C008,0x6000C108,0x6000C208,0x6000C308,0x6000C408,0x6000C508,0x6000C608,0x6000C708,0x6000C808,0x6000C908,0x6000CA08,0x6000CB08,0x6000CC08}
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
* SubIndex 201 - Reference to 0x60F0.201<br>
* SubIndex 202 - Reference to 0x60F0.202<br>
* SubIndex 203 - Reference to 0x60F0.203<br>
* SubIndex 204 - Reference to 0x60F0.204<br>
* SubIndex 205 - Reference to 0x60F0.205<br>
* SubIndex 206 - Reference to 0x60F0.206<br>
* SubIndex 207 - Reference to 0x60F0.207<br>
* SubIndex 208 - Reference to 0x60F0.208<br>
* SubIndex 209 - Reference to 0x60F0.209<br>
* SubIndex 210 - Reference to 0x60F0.210<br>
* SubIndex 211 - Reference to 0x60F0.211<br>
* SubIndex 212 - Reference to 0x60F0.212<br>
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex200 - Reference to 0x60F0.200 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex201 - Reference to 0x60F0.201 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex202 - Reference to 0x60F0.202 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex203 - Reference to 0x60F0.203 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex204 - Reference to 0x60F0.204 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex205 - Reference to 0x60F0.205 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex206 - Reference to 0x60F0.206 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex207 - Reference to 0x60F0.207 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex208 - Reference to 0x60F0.208 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex209 - Reference to 0x60F0.209 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex210 - Reference to 0x60F0.210 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex211 - Reference to 0x60F0.211 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex212 - Reference to 0x60F0.212 */

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
"SubIndex 212\000\377";
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
UINT32 SI201; /* Subindex201 - Reference to 0x60F0.201 */
UINT32 SI202; /* Subindex202 - Reference to 0x60F0.202 */
UINT32 SI203; /* Subindex203 - Reference to 0x60F0.203 */
UINT32 SI204; /* Subindex204 - Reference to 0x60F0.204 */
UINT32 SI205; /* Subindex205 - Reference to 0x60F0.205 */
UINT32 SI206; /* Subindex206 - Reference to 0x60F0.206 */
UINT32 SI207; /* Subindex207 - Reference to 0x60F0.207 */
UINT32 SI208; /* Subindex208 - Reference to 0x60F0.208 */
UINT32 SI209; /* Subindex209 - Reference to 0x60F0.209 */
UINT32 SI210; /* Subindex210 - Reference to 0x60F0.210 */
UINT32 SI211; /* Subindex211 - Reference to 0x60F0.211 */
UINT32 SI212; /* Subindex212 - Reference to 0x60F0.212 */
} OBJ_STRUCT_PACKED_END
TOBJ1A0F;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A0F RMDAPDIChannelProcessDataMapping0x1A0F
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={212,0x60F00108,0x60F00208,0x60F00308,0x60F00408,0x60F00508,0x60F00608,0x60F00708,0x60F00808,0x60F00908,0x60F00A08,0x60F00B08,0x60F00C08,0x60F00D08,0x60F00E08,0x60F00F08,0x60F01008,0x60F01108,0x60F01208,0x60F01308,0x60F01408,0x60F01508,0x60F01608,0x60F01708,0x60F01808,0x60F01908,0x60F01A08,0x60F01B08,0x60F01C08,0x60F01D08,0x60F01E08,0x60F01F08,0x60F02008,0x60F02108,0x60F02208,0x60F02308,0x60F02408,0x60F02508,0x60F02608,0x60F02708,0x60F02808,0x60F02908,0x60F02A08,0x60F02B08,0x60F02C08,0x60F02D08,0x60F02E08,0x60F02F08,0x60F03008,0x60F03108,0x60F03208,0x60F03308,0x60F03408,0x60F03508,0x60F03608,0x60F03708,0x60F03808,0x60F03908,0x60F03A08,0x60F03B08,0x60F03C08,0x60F03D08,0x60F03E08,0x60F03F08,0x60F04008,0x60F04108,0x60F04208,0x60F04308,0x60F04408,0x60F04508,0x60F04608,0x60F04708,0x60F04808,0x60F04908,0x60F04A08,0x60F04B08,0x60F04C08,0x60F04D08,0x60F04E08,0x60F04F08,0x60F05008,0x60F05108,0x60F05208,0x60F05308,0x60F05408,0x60F05508,0x60F05608,0x60F05708,0x60F05808,0x60F05908,0x60F05A08,0x60F05B08,0x60F05C08,0x60F05D08,0x60F05E08,0x60F05F08,0x60F06008,0x60F06108,0x60F06208,0x60F06308,0x60F06408,0x60F06508,0x60F06608,0x60F06708,0x60F06808,0x60F06908,0x60F06A08,0x60F06B08,0x60F06C08,0x60F06D08,0x60F06E08,0x60F06F08,0x60F07008,0x60F07108,0x60F07208,0x60F07308,0x60F07408,0x60F07508,0x60F07608,0x60F07708,0x60F07808,0x60F07908,0x60F07A08,0x60F07B08,0x60F07C08,0x60F07D08,0x60F07E08,0x60F07F08,0x60F08008,0x60F08108,0x60F08208,0x60F08308,0x60F08408,0x60F08508,0x60F08608,0x60F08708,0x60F08808,0x60F08908,0x60F08A08,0x60F08B08,0x60F08C08,0x60F08D08,0x60F08E08,0x60F08F08,0x60F09008,0x60F09108,0x60F09208,0x60F09308,0x60F09408,0x60F09508,0x60F09608,0x60F09708,0x60F09808,0x60F09908,0x60F09A08,0x60F09B08,0x60F09C08,0x60F09D08,0x60F09E08,0x60F09F08,0x60F0A008,0x60F0A108,0x60F0A208,0x60F0A308,0x60F0A408,0x60F0A508,0x60F0A608,0x60F0A708,0x60F0A808,0x60F0A908,0x60F0AA08,0x60F0AB08,0x60F0AC08,0x60F0AD08,0x60F0AE08,0x60F0AF08,0x60F0B008,0x60F0B108,0x60F0B208,0x60F0B308,0x60F0B408,0x60F0B508,0x60F0B608,0x60F0B708,0x60F0B808,0x60F0B908,0x60F0BA08,0x60F0BB08,0x60F0BC08,0x60F0BD08,0x60F0BE08,0x60F0BF08,0x60F0C008,0x60F0C108,0x60F0C208,0x60F0C308,0x60F0C408,0x60F0C508,0x60F0C608,0x60F0C708,0x60F0C808,0x60F0C908,0x60F0CA08,0x60F0CB08,0x60F0CC08,0x60F0CD08,0x60F0CE08,0x60F0CF08,0x60F0D008,0x60F0D108,0x60F0D208,0x60F0D308,0x60F0D408}
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
* SubIndex 13 - C1AID1<br>
* SubIndex 14 - C1AID2<br>
* SubIndex 15 - C1AP1<br>
* SubIndex 16 - C1AP2<br>
* SubIndex 17 - C1AP3<br>
* SubIndex 18 - C1AP4<br>
* SubIndex 19 - C1AV1<br>
* SubIndex 20 - C1AV2<br>
* SubIndex 21 - C1AST1<br>
* SubIndex 22 - C1AST2<br>
* SubIndex 23 - C1BID1<br>
* SubIndex 24 - C1BID2<br>
* SubIndex 25 - C1BP1<br>
* SubIndex 26 - C1BP2<br>
* SubIndex 27 - C1BP3<br>
* SubIndex 28 - C1BP4<br>
* SubIndex 29 - C1BV1<br>
* SubIndex 30 - C1BV2<br>
* SubIndex 31 - C1BST1<br>
* SubIndex 32 - C1BST2<br>
* SubIndex 33 - C1CID1<br>
* SubIndex 34 - C1CID2<br>
* SubIndex 35 - C1CP1<br>
* SubIndex 36 - C1CP2<br>
* SubIndex 37 - C1CP3<br>
* SubIndex 38 - C1CP4<br>
* SubIndex 39 - C1CV1<br>
* SubIndex 40 - C1CV2<br>
* SubIndex 41 - C1CST1<br>
* SubIndex 42 - C1CST2<br>
* SubIndex 43 - C1DID1<br>
* SubIndex 44 - C1DID2<br>
* SubIndex 45 - C1DP1<br>
* SubIndex 46 - C1DP2<br>
* SubIndex 47 - C1DP3<br>
* SubIndex 48 - C1DP4<br>
* SubIndex 49 - C1DV1<br>
* SubIndex 50 - C1DV2<br>
* SubIndex 51 - C1DST1<br>
* SubIndex 52 - C1DST2<br>
* SubIndex 53 - C1EID1<br>
* SubIndex 54 - C1EID2<br>
* SubIndex 55 - C1EP1<br>
* SubIndex 56 - C1EP2<br>
* SubIndex 57 - C1EP3<br>
* SubIndex 58 - C1EP4<br>
* SubIndex 59 - C1EV1<br>
* SubIndex 60 - C1EV2<br>
* SubIndex 61 - C1EST1<br>
* SubIndex 62 - C1EST2<br>
* SubIndex 63 - C1FID1<br>
* SubIndex 64 - C1FID2<br>
* SubIndex 65 - C1FP1<br>
* SubIndex 66 - C1FP2<br>
* SubIndex 67 - C1FP3<br>
* SubIndex 68 - C1FP4<br>
* SubIndex 69 - C1FV1<br>
* SubIndex 70 - C1FV2<br>
* SubIndex 71 - C1FST1<br>
* SubIndex 72 - C1FST2<br>
* SubIndex 73 - C1GID1<br>
* SubIndex 74 - C1GID2<br>
* SubIndex 75 - C1GP1<br>
* SubIndex 76 - C1GP2<br>
* SubIndex 77 - C1GP3<br>
* SubIndex 78 - C1GP4<br>
* SubIndex 79 - C1GV1<br>
* SubIndex 80 - C1GV2<br>
* SubIndex 81 - C1GST1<br>
* SubIndex 82 - C1GST2<br>
* SubIndex 83 - C2AID1<br>
* SubIndex 84 - C2AID2<br>
* SubIndex 85 - C2AP1<br>
* SubIndex 86 - C2AP2<br>
* SubIndex 87 - C2AP3<br>
* SubIndex 88 - C2AP4<br>
* SubIndex 89 - C2AV1<br>
* SubIndex 90 - C2AV2<br>
* SubIndex 91 - C2AST1<br>
* SubIndex 92 - C2AST2<br>
* SubIndex 93 - C2BID1<br>
* SubIndex 94 - C2BID2<br>
* SubIndex 95 - C2BP1<br>
* SubIndex 96 - C2BP2<br>
* SubIndex 97 - C2BP3<br>
* SubIndex 98 - C2BP4<br>
* SubIndex 99 - C2BV1<br>
* SubIndex 100 - C2BV2<br>
* SubIndex 101 - C2BST1<br>
* SubIndex 102 - C2BST2<br>
* SubIndex 103 - C2CID1<br>
* SubIndex 104 - C2CID2<br>
* SubIndex 105 - C2CP1<br>
* SubIndex 106 - C2CP2<br>
* SubIndex 107 - C2CP3<br>
* SubIndex 108 - C2CP4<br>
* SubIndex 109 - C2CV1<br>
* SubIndex 110 - C2CV2<br>
* SubIndex 111 - C2CST1<br>
* SubIndex 112 - C2CST2<br>
* SubIndex 113 - C2DID1<br>
* SubIndex 114 - C2DID2<br>
* SubIndex 115 - C2DP1<br>
* SubIndex 116 - C2DP2<br>
* SubIndex 117 - C2DP3<br>
* SubIndex 118 - C2DP4<br>
* SubIndex 119 - C2DV1<br>
* SubIndex 120 - C2DV2<br>
* SubIndex 121 - C2DST1<br>
* SubIndex 122 - C2DST2<br>
* SubIndex 123 - C2EID1<br>
* SubIndex 124 - C2EID2<br>
* SubIndex 125 - C2EP1<br>
* SubIndex 126 - C2EP2<br>
* SubIndex 127 - C2EP3<br>
* SubIndex 128 - C2EP4<br>
* SubIndex 129 - C2EV1<br>
* SubIndex 130 - C2EV2<br>
* SubIndex 131 - C2EST1<br>
* SubIndex 132 - C2EST2<br>
* SubIndex 133 - C2FID1<br>
* SubIndex 134 - C2FID2<br>
* SubIndex 135 - C2FP1<br>
* SubIndex 136 - C2FP2<br>
* SubIndex 137 - C2FP3<br>
* SubIndex 138 - C2FP4<br>
* SubIndex 139 - C2FV1<br>
* SubIndex 140 - C2FV2<br>
* SubIndex 141 - C2FST1<br>
* SubIndex 142 - C2FST2<br>
* SubIndex 143 - C2GID1<br>
* SubIndex 144 - C2GID2<br>
* SubIndex 145 - C2GP1<br>
* SubIndex 146 - C2GP2<br>
* SubIndex 147 - C2GP3<br>
* SubIndex 148 - C2GP4<br>
* SubIndex 149 - C2GV1<br>
* SubIndex 150 - C2GV2<br>
* SubIndex 151 - C2GST1<br>
* SubIndex 152 - C2GST2<br>
* SubIndex 153 - C3AID1<br>
* SubIndex 154 - C3AID2<br>
* SubIndex 155 - C3AP1<br>
* SubIndex 156 - C3AP2<br>
* SubIndex 157 - C3AP3<br>
* SubIndex 158 - C3AP4<br>
* SubIndex 159 - C3AV1<br>
* SubIndex 160 - C3AV2<br>
* SubIndex 161 - C3AST1<br>
* SubIndex 162 - C3AST2<br>
* SubIndex 163 - C3BID1<br>
* SubIndex 164 - C3BID2<br>
* SubIndex 165 - C3BP1<br>
* SubIndex 166 - C3BP2<br>
* SubIndex 167 - C3BP3<br>
* SubIndex 168 - C3BP4<br>
* SubIndex 169 - C3BV1<br>
* SubIndex 170 - C3BV2<br>
* SubIndex 171 - C3BST1<br>
* SubIndex 172 - C3BST2<br>
* SubIndex 173 - C3CID1<br>
* SubIndex 174 - C3CID2<br>
* SubIndex 175 - C3CP1<br>
* SubIndex 176 - C3CP2<br>
* SubIndex 177 - C3CP3<br>
* SubIndex 178 - C3CP4<br>
* SubIndex 179 - C3CV1<br>
* SubIndex 180 - C3CV2<br>
* SubIndex 181 - C3CST1<br>
* SubIndex 182 - C3CST2<br>
* SubIndex 183 - VT1<br>
* SubIndex 184 - VT2<br>
* SubIndex 185 - VT3<br>
* SubIndex 186 - VT4<br>
* SubIndex 187 - VT5<br>
* SubIndex 188 - VT6<br>
* SubIndex 189 - VT7<br>
* SubIndex 190 - VT8<br>
* SubIndex 191 - VT9<br>
* SubIndex 192 - VT10<br>
* SubIndex 193 - VT11<br>
* SubIndex 194 - VT12<br>
* SubIndex 195 - VT13<br>
* SubIndex 196 - VT14<br>
* SubIndex 197 - VT15<br>
* SubIndex 198 - VT16<br>
* SubIndex 199 - VT17<br>
* SubIndex 200 - VT18<br>
* SubIndex 201 - VT19<br>
* SubIndex 202 - VT20<br>
* SubIndex 203 - VT21<br>
* SubIndex 204 - end1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - AX1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - AX2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex3 - AY1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex4 - AY2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex5 - AZ1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex6 - AZ2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex7 - GX1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex8 - GX2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex9 - GY1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex10 - GY2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex11 - GZ1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex12 - GZ2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex13 - C1AID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex14 - C1AID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex15 - C1AP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex16 - C1AP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex17 - C1AP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex18 - C1AP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex19 - C1AV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex20 - C1AV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex21 - C1AST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex22 - C1AST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex23 - C1BID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex24 - C1BID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex25 - C1BP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex26 - C1BP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex27 - C1BP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex28 - C1BP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex29 - C1BV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex30 - C1BV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex31 - C1BST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex32 - C1BST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex33 - C1CID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex34 - C1CID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex35 - C1CP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex36 - C1CP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex37 - C1CP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex38 - C1CP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex39 - C1CV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex40 - C1CV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex41 - C1CST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex42 - C1CST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex43 - C1DID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex44 - C1DID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex45 - C1DP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex46 - C1DP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex47 - C1DP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex48 - C1DP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex49 - C1DV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex50 - C1DV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex51 - C1DST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex52 - C1DST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex53 - C1EID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex54 - C1EID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex55 - C1EP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex56 - C1EP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex57 - C1EP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex58 - C1EP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex59 - C1EV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex60 - C1EV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex61 - C1EST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex62 - C1EST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex63 - C1FID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex64 - C1FID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex65 - C1FP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex66 - C1FP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex67 - C1FP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex68 - C1FP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex69 - C1FV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex70 - C1FV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex71 - C1FST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex72 - C1FST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex73 - C1GID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex74 - C1GID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex75 - C1GP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex76 - C1GP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex77 - C1GP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex78 - C1GP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex79 - C1GV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex80 - C1GV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex81 - C1GST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex82 - C1GST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex83 - C2AID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex84 - C2AID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex85 - C2AP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex86 - C2AP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex87 - C2AP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex88 - C2AP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex89 - C2AV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex90 - C2AV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex91 - C2AST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex92 - C2AST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex93 - C2BID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex94 - C2BID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex95 - C2BP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex96 - C2BP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex97 - C2BP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex98 - C2BP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex99 - C2BV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex100 - C2BV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex101 - C2BST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex102 - C2BST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex103 - C2CID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex104 - C2CID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex105 - C2CP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex106 - C2CP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex107 - C2CP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex108 - C2CP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex109 - C2CV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex110 - C2CV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex111 - C2CST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex112 - C2CST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex113 - C2DID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex114 - C2DID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex115 - C2DP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex116 - C2DP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex117 - C2DP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex118 - C2DP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex119 - C2DV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex120 - C2DV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex121 - C2DST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex122 - C2DST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex123 - C2EID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex124 - C2EID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex125 - C2EP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex126 - C2EP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex127 - C2EP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex128 - C2EP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex129 - C2EV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex130 - C2EV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex131 - C2EST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex132 - C2EST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex133 - C2FID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex134 - C2FID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex135 - C2FP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex136 - C2FP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex137 - C2FP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex138 - C2FP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex139 - C2FV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex140 - C2FV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex141 - C2FST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex142 - C2FST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex143 - C2GID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex144 - C2GID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex145 - C2GP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex146 - C2GP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex147 - C2GP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex148 - C2GP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex149 - C2GV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex150 - C2GV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex151 - C2GST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex152 - C2GST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex153 - C3AID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex154 - C3AID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex155 - C3AP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex156 - C3AP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex157 - C3AP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex158 - C3AP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex159 - C3AV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex160 - C3AV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex161 - C3AST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex162 - C3AST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex163 - C3BID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex164 - C3BID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex165 - C3BP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex166 - C3BP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex167 - C3BP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex168 - C3BP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex169 - C3BV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex170 - C3BV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex171 - C3BST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex172 - C3BST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex173 - C3CID1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex174 - C3CID2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex175 - C3CP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex176 - C3CP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex177 - C3CP3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex178 - C3CP4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex179 - C3CV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex180 - C3CV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex181 - C3CST1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex182 - C3CST2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex183 - VT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex184 - VT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex185 - VT3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex186 - VT4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex187 - VT5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex188 - VT6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex189 - VT7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex190 - VT8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex191 - VT9 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex192 - VT10 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex193 - VT11 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex194 - VT12 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex195 - VT13 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex196 - VT14 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex197 - VT15 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex198 - VT16 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex199 - VT17 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex200 - VT18 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex201 - VT19 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex202 - VT20 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex203 - VT21 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }}; /* Subindex204 - end1 */

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
"C1AID1\000"
"C1AID2\000"
"C1AP1\000"
"C1AP2\000"
"C1AP3\000"
"C1AP4\000"
"C1AV1\000"
"C1AV2\000"
"C1AST1\000"
"C1AST2\000"
"C1BID1\000"
"C1BID2\000"
"C1BP1\000"
"C1BP2\000"
"C1BP3\000"
"C1BP4\000"
"C1BV1\000"
"C1BV2\000"
"C1BST1\000"
"C1BST2\000"
"C1CID1\000"
"C1CID2\000"
"C1CP1\000"
"C1CP2\000"
"C1CP3\000"
"C1CP4\000"
"C1CV1\000"
"C1CV2\000"
"C1CST1\000"
"C1CST2\000"
"C1DID1\000"
"C1DID2\000"
"C1DP1\000"
"C1DP2\000"
"C1DP3\000"
"C1DP4\000"
"C1DV1\000"
"C1DV2\000"
"C1DST1\000"
"C1DST2\000"
"C1EID1\000"
"C1EID2\000"
"C1EP1\000"
"C1EP2\000"
"C1EP3\000"
"C1EP4\000"
"C1EV1\000"
"C1EV2\000"
"C1EST1\000"
"C1EST2\000"
"C1FID1\000"
"C1FID2\000"
"C1FP1\000"
"C1FP2\000"
"C1FP3\000"
"C1FP4\000"
"C1FV1\000"
"C1FV2\000"
"C1FST1\000"
"C1FST2\000"
"C1GID1\000"
"C1GID2\000"
"C1GP1\000"
"C1GP2\000"
"C1GP3\000"
"C1GP4\000"
"C1GV1\000"
"C1GV2\000"
"C1GST1\000"
"C1GST2\000"
"C2AID1\000"
"C2AID2\000"
"C2AP1\000"
"C2AP2\000"
"C2AP3\000"
"C2AP4\000"
"C2AV1\000"
"C2AV2\000"
"C2AST1\000"
"C2AST2\000"
"C2BID1\000"
"C2BID2\000"
"C2BP1\000"
"C2BP2\000"
"C2BP3\000"
"C2BP4\000"
"C2BV1\000"
"C2BV2\000"
"C2BST1\000"
"C2BST2\000"
"C2CID1\000"
"C2CID2\000"
"C2CP1\000"
"C2CP2\000"
"C2CP3\000"
"C2CP4\000"
"C2CV1\000"
"C2CV2\000"
"C2CST1\000"
"C2CST2\000"
"C2DID1\000"
"C2DID2\000"
"C2DP1\000"
"C2DP2\000"
"C2DP3\000"
"C2DP4\000"
"C2DV1\000"
"C2DV2\000"
"C2DST1\000"
"C2DST2\000"
"C2EID1\000"
"C2EID2\000"
"C2EP1\000"
"C2EP2\000"
"C2EP3\000"
"C2EP4\000"
"C2EV1\000"
"C2EV2\000"
"C2EST1\000"
"C2EST2\000"
"C2FID1\000"
"C2FID2\000"
"C2FP1\000"
"C2FP2\000"
"C2FP3\000"
"C2FP4\000"
"C2FV1\000"
"C2FV2\000"
"C2FST1\000"
"C2FST2\000"
"C2GID1\000"
"C2GID2\000"
"C2GP1\000"
"C2GP2\000"
"C2GP3\000"
"C2GP4\000"
"C2GV1\000"
"C2GV2\000"
"C2GST1\000"
"C2GST2\000"
"C3AID1\000"
"C3AID2\000"
"C3AP1\000"
"C3AP2\000"
"C3AP3\000"
"C3AP4\000"
"C3AV1\000"
"C3AV2\000"
"C3AST1\000"
"C3AST2\000"
"C3BID1\000"
"C3BID2\000"
"C3BP1\000"
"C3BP2\000"
"C3BP3\000"
"C3BP4\000"
"C3BV1\000"
"C3BV2\000"
"C3BST1\000"
"C3BST2\000"
"C3CID1\000"
"C3CID2\000"
"C3CP1\000"
"C3CP2\000"
"C3CP3\000"
"C3CP4\000"
"C3CV1\000"
"C3CV2\000"
"C3CST1\000"
"C3CST2\000"
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
UINT8 C1AID1; /* Subindex13 - C1AID1 */
UINT8 C1AID2; /* Subindex14 - C1AID2 */
UINT8 C1AP1; /* Subindex15 - C1AP1 */
UINT8 C1AP2; /* Subindex16 - C1AP2 */
UINT8 C1AP3; /* Subindex17 - C1AP3 */
UINT8 C1AP4; /* Subindex18 - C1AP4 */
UINT8 C1AV1; /* Subindex19 - C1AV1 */
UINT8 C1AV2; /* Subindex20 - C1AV2 */
UINT8 C1AST1; /* Subindex21 - C1AST1 */
UINT8 C1AST2; /* Subindex22 - C1AST2 */
UINT8 C1BID1; /* Subindex23 - C1BID1 */
UINT8 C1BID2; /* Subindex24 - C1BID2 */
UINT8 C1BP1; /* Subindex25 - C1BP1 */
UINT8 C1BP2; /* Subindex26 - C1BP2 */
UINT8 C1BP3; /* Subindex27 - C1BP3 */
UINT8 C1BP4; /* Subindex28 - C1BP4 */
UINT8 C1BV1; /* Subindex29 - C1BV1 */
UINT8 C1BV2; /* Subindex30 - C1BV2 */
UINT8 C1BST1; /* Subindex31 - C1BST1 */
UINT8 C1BST2; /* Subindex32 - C1BST2 */
UINT8 C1CID1; /* Subindex33 - C1CID1 */
UINT8 C1CID2; /* Subindex34 - C1CID2 */
UINT8 C1CP1; /* Subindex35 - C1CP1 */
UINT8 C1CP2; /* Subindex36 - C1CP2 */
UINT8 C1CP3; /* Subindex37 - C1CP3 */
UINT8 C1CP4; /* Subindex38 - C1CP4 */
UINT8 C1CV1; /* Subindex39 - C1CV1 */
UINT8 C1CV2; /* Subindex40 - C1CV2 */
UINT8 C1CST1; /* Subindex41 - C1CST1 */
UINT8 C1CST2; /* Subindex42 - C1CST2 */
UINT8 C1DID1; /* Subindex43 - C1DID1 */
UINT8 C1DID2; /* Subindex44 - C1DID2 */
UINT8 C1DP1; /* Subindex45 - C1DP1 */
UINT8 C1DP2; /* Subindex46 - C1DP2 */
UINT8 C1DP3; /* Subindex47 - C1DP3 */
UINT8 C1DP4; /* Subindex48 - C1DP4 */
UINT8 C1DV1; /* Subindex49 - C1DV1 */
UINT8 C1DV2; /* Subindex50 - C1DV2 */
UINT8 C1DST1; /* Subindex51 - C1DST1 */
UINT8 C1DST2; /* Subindex52 - C1DST2 */
UINT8 C1EID1; /* Subindex53 - C1EID1 */
UINT8 C1EID2; /* Subindex54 - C1EID2 */
UINT8 C1EP1; /* Subindex55 - C1EP1 */
UINT8 C1EP2; /* Subindex56 - C1EP2 */
UINT8 C1EP3; /* Subindex57 - C1EP3 */
UINT8 C1EP4; /* Subindex58 - C1EP4 */
UINT8 C1EV1; /* Subindex59 - C1EV1 */
UINT8 C1EV2; /* Subindex60 - C1EV2 */
UINT8 C1EST1; /* Subindex61 - C1EST1 */
UINT8 C1EST2; /* Subindex62 - C1EST2 */
UINT8 C1FID1; /* Subindex63 - C1FID1 */
UINT8 C1FID2; /* Subindex64 - C1FID2 */
UINT8 C1FP1; /* Subindex65 - C1FP1 */
UINT8 C1FP2; /* Subindex66 - C1FP2 */
UINT8 C1FP3; /* Subindex67 - C1FP3 */
UINT8 C1FP4; /* Subindex68 - C1FP4 */
UINT8 C1FV1; /* Subindex69 - C1FV1 */
UINT8 C1FV2; /* Subindex70 - C1FV2 */
UINT8 C1FST1; /* Subindex71 - C1FST1 */
UINT8 C1FST2; /* Subindex72 - C1FST2 */
UINT8 C1GID1; /* Subindex73 - C1GID1 */
UINT8 C1GID2; /* Subindex74 - C1GID2 */
UINT8 C1GP1; /* Subindex75 - C1GP1 */
UINT8 C1GP2; /* Subindex76 - C1GP2 */
UINT8 C1GP3; /* Subindex77 - C1GP3 */
UINT8 C1GP4; /* Subindex78 - C1GP4 */
UINT8 C1GV1; /* Subindex79 - C1GV1 */
UINT8 C1GV2; /* Subindex80 - C1GV2 */
UINT8 C1GST1; /* Subindex81 - C1GST1 */
UINT8 C1GST2; /* Subindex82 - C1GST2 */
UINT8 C2AID1; /* Subindex83 - C2AID1 */
UINT8 C2AID2; /* Subindex84 - C2AID2 */
UINT8 C2AP1; /* Subindex85 - C2AP1 */
UINT8 C2AP2; /* Subindex86 - C2AP2 */
UINT8 C2AP3; /* Subindex87 - C2AP3 */
UINT8 C2AP4; /* Subindex88 - C2AP4 */
UINT8 C2AV1; /* Subindex89 - C2AV1 */
UINT8 C2AV2; /* Subindex90 - C2AV2 */
UINT8 C2AST1; /* Subindex91 - C2AST1 */
UINT8 C2AST2; /* Subindex92 - C2AST2 */
UINT8 C2BID1; /* Subindex93 - C2BID1 */
UINT8 C2BID2; /* Subindex94 - C2BID2 */
UINT8 C2BP1; /* Subindex95 - C2BP1 */
UINT8 C2BP2; /* Subindex96 - C2BP2 */
UINT8 C2BP3; /* Subindex97 - C2BP3 */
UINT8 C2BP4; /* Subindex98 - C2BP4 */
UINT8 C2BV1; /* Subindex99 - C2BV1 */
UINT8 C2BV2; /* Subindex100 - C2BV2 */
UINT8 C2BST1; /* Subindex101 - C2BST1 */
UINT8 C2BST2; /* Subindex102 - C2BST2 */
UINT8 C2CID1; /* Subindex103 - C2CID1 */
UINT8 C2CID2; /* Subindex104 - C2CID2 */
UINT8 C2CP1; /* Subindex105 - C2CP1 */
UINT8 C2CP2; /* Subindex106 - C2CP2 */
UINT8 C2CP3; /* Subindex107 - C2CP3 */
UINT8 C2CP4; /* Subindex108 - C2CP4 */
UINT8 C2CV1; /* Subindex109 - C2CV1 */
UINT8 C2CV2; /* Subindex110 - C2CV2 */
UINT8 C2CST1; /* Subindex111 - C2CST1 */
UINT8 C2CST2; /* Subindex112 - C2CST2 */
UINT8 C2DID1; /* Subindex113 - C2DID1 */
UINT8 C2DID2; /* Subindex114 - C2DID2 */
UINT8 C2DP1; /* Subindex115 - C2DP1 */
UINT8 C2DP2; /* Subindex116 - C2DP2 */
UINT8 C2DP3; /* Subindex117 - C2DP3 */
UINT8 C2DP4; /* Subindex118 - C2DP4 */
UINT8 C2DV1; /* Subindex119 - C2DV1 */
UINT8 C2DV2; /* Subindex120 - C2DV2 */
UINT8 C2DST1; /* Subindex121 - C2DST1 */
UINT8 C2DST2; /* Subindex122 - C2DST2 */
UINT8 C2EID1; /* Subindex123 - C2EID1 */
UINT8 C2EID2; /* Subindex124 - C2EID2 */
UINT8 C2EP1; /* Subindex125 - C2EP1 */
UINT8 C2EP2; /* Subindex126 - C2EP2 */
UINT8 C2EP3; /* Subindex127 - C2EP3 */
UINT8 C2EP4; /* Subindex128 - C2EP4 */
UINT8 C2EV1; /* Subindex129 - C2EV1 */
UINT8 C2EV2; /* Subindex130 - C2EV2 */
UINT8 C2EST1; /* Subindex131 - C2EST1 */
UINT8 C2EST2; /* Subindex132 - C2EST2 */
UINT8 C2FID1; /* Subindex133 - C2FID1 */
UINT8 C2FID2; /* Subindex134 - C2FID2 */
UINT8 C2FP1; /* Subindex135 - C2FP1 */
UINT8 C2FP2; /* Subindex136 - C2FP2 */
UINT8 C2FP3; /* Subindex137 - C2FP3 */
UINT8 C2FP4; /* Subindex138 - C2FP4 */
UINT8 C2FV1; /* Subindex139 - C2FV1 */
UINT8 C2FV2; /* Subindex140 - C2FV2 */
UINT8 C2FST1; /* Subindex141 - C2FST1 */
UINT8 C2FST2; /* Subindex142 - C2FST2 */
UINT8 C2GID1; /* Subindex143 - C2GID1 */
UINT8 C2GID2; /* Subindex144 - C2GID2 */
UINT8 C2GP1; /* Subindex145 - C2GP1 */
UINT8 C2GP2; /* Subindex146 - C2GP2 */
UINT8 C2GP3; /* Subindex147 - C2GP3 */
UINT8 C2GP4; /* Subindex148 - C2GP4 */
UINT8 C2GV1; /* Subindex149 - C2GV1 */
UINT8 C2GV2; /* Subindex150 - C2GV2 */
UINT8 C2GST1; /* Subindex151 - C2GST1 */
UINT8 C2GST2; /* Subindex152 - C2GST2 */
UINT8 C3AID1; /* Subindex153 - C3AID1 */
UINT8 C3AID2; /* Subindex154 - C3AID2 */
UINT8 C3AP1; /* Subindex155 - C3AP1 */
UINT8 C3AP2; /* Subindex156 - C3AP2 */
UINT8 C3AP3; /* Subindex157 - C3AP3 */
UINT8 C3AP4; /* Subindex158 - C3AP4 */
UINT8 C3AV1; /* Subindex159 - C3AV1 */
UINT8 C3AV2; /* Subindex160 - C3AV2 */
UINT8 C3AST1; /* Subindex161 - C3AST1 */
UINT8 C3AST2; /* Subindex162 - C3AST2 */
UINT8 C3BID1; /* Subindex163 - C3BID1 */
UINT8 C3BID2; /* Subindex164 - C3BID2 */
UINT8 C3BP1; /* Subindex165 - C3BP1 */
UINT8 C3BP2; /* Subindex166 - C3BP2 */
UINT8 C3BP3; /* Subindex167 - C3BP3 */
UINT8 C3BP4; /* Subindex168 - C3BP4 */
UINT8 C3BV1; /* Subindex169 - C3BV1 */
UINT8 C3BV2; /* Subindex170 - C3BV2 */
UINT8 C3BST1; /* Subindex171 - C3BST1 */
UINT8 C3BST2; /* Subindex172 - C3BST2 */
UINT8 C3CID1; /* Subindex173 - C3CID1 */
UINT8 C3CID2; /* Subindex174 - C3CID2 */
UINT8 C3CP1; /* Subindex175 - C3CP1 */
UINT8 C3CP2; /* Subindex176 - C3CP2 */
UINT8 C3CP3; /* Subindex177 - C3CP3 */
UINT8 C3CP4; /* Subindex178 - C3CP4 */
UINT8 C3CV1; /* Subindex179 - C3CV1 */
UINT8 C3CV2; /* Subindex180 - C3CV2 */
UINT8 C3CST1; /* Subindex181 - C3CST1 */
UINT8 C3CST2; /* Subindex182 - C3CST2 */
UINT8 VT1; /* Subindex183 - VT1 */
UINT8 VT2; /* Subindex184 - VT2 */
UINT8 VT3; /* Subindex185 - VT3 */
UINT8 VT4; /* Subindex186 - VT4 */
UINT8 VT5; /* Subindex187 - VT5 */
UINT8 VT6; /* Subindex188 - VT6 */
UINT8 VT7; /* Subindex189 - VT7 */
UINT8 VT8; /* Subindex190 - VT8 */
UINT8 VT9; /* Subindex191 - VT9 */
UINT8 VT10; /* Subindex192 - VT10 */
UINT8 VT11; /* Subindex193 - VT11 */
UINT8 VT12; /* Subindex194 - VT12 */
UINT8 VT13; /* Subindex195 - VT13 */
UINT8 VT14; /* Subindex196 - VT14 */
UINT8 VT15; /* Subindex197 - VT15 */
UINT8 VT16; /* Subindex198 - VT16 */
UINT8 VT17; /* Subindex199 - VT17 */
UINT8 VT18; /* Subindex200 - VT18 */
UINT8 VT19; /* Subindex201 - VT19 */
UINT8 VT20; /* Subindex202 - VT20 */
UINT8 VT21; /* Subindex203 - VT21 */
UINT8 End1; /* Subindex204 - end1 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 PDIChannel0x6000
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={204,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
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
* SubIndex 201 - R201<br>
* SubIndex 202 - R202<br>
* SubIndex 203 - R203<br>
* SubIndex 204 - R204<br>
* SubIndex 205 - R205<br>
* SubIndex 206 - R206<br>
* SubIndex 207 - R207<br>
* SubIndex 208 - R208<br>
* SubIndex 209 - R209<br>
* SubIndex 210 - R210<br>
* SubIndex 211 - R211<br>
* SubIndex 212 - R212<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x60F0[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - R1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - R2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex3 - R3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex4 - R4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex5 - R5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex6 - R6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex7 - R7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex8 - R8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex9 - R9 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex10 - R10 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex11 - R11 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex12 - R12 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex13 - R13 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex14 - R14 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex15 - R15 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex16 - R16 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex17 - R17 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex18 - R18 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex19 - R19 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex20 - R20 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex21 - R21 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex22 - R22 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex23 - R23 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex24 - R24 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex25 - R25 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex26 - R26 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex27 - R27 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex28 - R28 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex29 - R29 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex30 - R30 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex31 - R31 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex32 - R32 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex33 - R33 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex34 - R34 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex35 - R35 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex36 - R36 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex37 - R37 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex38 - R38 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex39 - R39 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex40 - R40 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex41 - R41 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex42 - R42 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex43 - R43 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex44 - R44 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex45 - R45 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex46 - R46 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex47 - R47 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex48 - R48 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex49 - R49 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex50 - R50 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex51 - R51 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex52 - R52 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex53 - R53 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex54 - R54 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex55 - R55 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex56 - R56 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex57 - R57 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex58 - R58 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex59 - R59 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex60 - R60 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex61 - R61 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex62 - R62 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex63 - R63 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex64 - R64 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex65 - R65 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex66 - R66 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex67 - R67 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex68 - R68 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex69 - R69 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex70 - R70 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex71 - R71 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex72 - R72 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex73 - R73 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex74 - R74 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex75 - R75 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex76 - R76 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex77 - R77 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex78 - R78 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex79 - R79 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex80 - R80 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex81 - R81 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex82 - R82 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex83 - R83 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex84 - R84 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex85 - R85 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex86 - R86 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex87 - R87 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex88 - R88 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex89 - R89 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex90 - R90 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex91 - R91 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex92 - R92 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex93 - R93 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex94 - R94 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex95 - R95 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex96 - R96 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex97 - R97 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex98 - R98 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex99 - R99 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex100 - R100 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex101 - R101 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex102 - R102 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex103 - R103 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex104 - R104 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex105 - R105 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex106 - R106 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex107 - R107 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex108 - R108 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex109 - R109 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex110 - R110 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex111 - R111 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex112 - R112 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex113 - R113 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex114 - R114 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex115 - R115 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex116 - R116 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex117 - R117 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex118 - R118 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex119 - R119 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex120 - R120 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex121 - R121 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex122 - R122 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex123 - R123 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex124 - R124 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex125 - R125 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex126 - R126 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex127 - R127 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex128 - R128 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex129 - R129 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex130 - R130 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex131 - R131 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex132 - R132 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex133 - R133 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex134 - R134 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex135 - R135 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex136 - R136 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex137 - R137 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex138 - R138 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex139 - R139 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex140 - R140 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex141 - R141 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex142 - R142 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex143 - R143 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex144 - R144 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex145 - R145 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex146 - R146 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex147 - R147 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex148 - R148 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex149 - R149 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex150 - R150 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex151 - R151 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex152 - R152 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex153 - R153 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex154 - R154 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex155 - R155 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex156 - R156 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex157 - R157 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex158 - R158 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex159 - R159 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex160 - R160 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex161 - R161 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex162 - R162 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex163 - R163 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex164 - R164 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex165 - R165 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex166 - R166 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex167 - R167 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex168 - R168 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex169 - R169 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex170 - R170 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex171 - R171 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex172 - R172 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex173 - R173 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex174 - R174 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex175 - R175 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex176 - R176 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex177 - R177 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex178 - R178 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex179 - R179 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex180 - R180 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex181 - R181 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex182 - R182 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex183 - R183 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex184 - R184 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex185 - R185 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex186 - R186 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex187 - R187 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex188 - R188 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex189 - R189 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex190 - R190 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex191 - R191 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex192 - R192 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex193 - R193 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex194 - R194 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex195 - R195 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex196 - R196 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex197 - R197 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex198 - R198 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex199 - R199 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex200 - R200 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex201 - R201 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex202 - R202 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex203 - R203 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex204 - R204 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex205 - R205 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex206 - R206 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex207 - R207 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex208 - R208 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex209 - R209 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex210 - R210 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }, /* Subindex211 - R211 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING }}; /* Subindex212 - R212 */

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
"R200\000"
"R201\000"
"R202\000"
"R203\000"
"R204\000"
"R205\000"
"R206\000"
"R207\000"
"R208\000"
"R209\000"
"R210\000"
"R211\000"
"R212\000\377";
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
UINT8 R201; /* Subindex201 - R201 */
UINT8 R202; /* Subindex202 - R202 */
UINT8 R203; /* Subindex203 - R203 */
UINT8 R204; /* Subindex204 - R204 */
UINT8 R205; /* Subindex205 - R205 */
UINT8 R206; /* Subindex206 - R206 */
UINT8 R207; /* Subindex207 - R207 */
UINT8 R208; /* Subindex208 - R208 */
UINT8 R209; /* Subindex209 - R209 */
UINT8 R210; /* Subindex210 - R210 */
UINT8 R211; /* Subindex211 - R211 */
UINT8 R212; /* Subindex212 - R212 */
} OBJ_STRUCT_PACKED_END
TOBJ60F0;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ60F0 RMDAPDIChannel0x60F0
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={212,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
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
* SubIndex 1 - Ctrl<br>
* SubIndex 2 - Seq1<br>
* SubIndex 3 - Seq2<br>
* SubIndex 4 - Seq3<br>
* SubIndex 5 - C1AP1<br>
* SubIndex 6 - C1AP2<br>
* SubIndex 7 - C1AV1<br>
* SubIndex 8 - C1AV2<br>
* SubIndex 9 - C1AT1<br>
* SubIndex 10 - C1AT2<br>
* SubIndex 11 - C1AKP1<br>
* SubIndex 12 - C1AKP2<br>
* SubIndex 13 - C1AKD1<br>
* SubIndex 14 - C1AKD2<br>
* SubIndex 15 - C1BP1<br>
* SubIndex 16 - C1BP2<br>
* SubIndex 17 - C1BV1<br>
* SubIndex 18 - C1BV2<br>
* SubIndex 19 - C1BT1<br>
* SubIndex 20 - C1BT2<br>
* SubIndex 21 - C1BKP1<br>
* SubIndex 22 - C1BKP2<br>
* SubIndex 23 - C1BKD1<br>
* SubIndex 24 - C1BKD2<br>
* SubIndex 25 - C1CP1<br>
* SubIndex 26 - C1CP2<br>
* SubIndex 27 - C1CV1<br>
* SubIndex 28 - C1CV2<br>
* SubIndex 29 - C1CT1<br>
* SubIndex 30 - C1CT2<br>
* SubIndex 31 - C1CKP1<br>
* SubIndex 32 - C1CKP2<br>
* SubIndex 33 - C1CKD1<br>
* SubIndex 34 - C1CKD2<br>
* SubIndex 35 - C1DP1<br>
* SubIndex 36 - C1DP2<br>
* SubIndex 37 - C1DV1<br>
* SubIndex 38 - C1DV2<br>
* SubIndex 39 - C1DT1<br>
* SubIndex 40 - C1DT2<br>
* SubIndex 41 - C1DKP1<br>
* SubIndex 42 - C1DKP2<br>
* SubIndex 43 - C1DKD1<br>
* SubIndex 44 - C1DKD2<br>
* SubIndex 45 - C1EP1<br>
* SubIndex 46 - C1EP2<br>
* SubIndex 47 - C1EV1<br>
* SubIndex 48 - C1EV2<br>
* SubIndex 49 - C1ET1<br>
* SubIndex 50 - C1ET2<br>
* SubIndex 51 - C1EKP1<br>
* SubIndex 52 - C1EKP2<br>
* SubIndex 53 - C1EKD1<br>
* SubIndex 54 - C1EKD2<br>
* SubIndex 55 - C1FP1<br>
* SubIndex 56 - C1FP2<br>
* SubIndex 57 - C1FV1<br>
* SubIndex 58 - C1FV2<br>
* SubIndex 59 - C1FT1<br>
* SubIndex 60 - C1FT2<br>
* SubIndex 61 - C1FKP1<br>
* SubIndex 62 - C1FKP2<br>
* SubIndex 63 - C1FKD1<br>
* SubIndex 64 - C1FKD2<br>
* SubIndex 65 - C1GP1<br>
* SubIndex 66 - C1GP2<br>
* SubIndex 67 - C1GV1<br>
* SubIndex 68 - C1GV2<br>
* SubIndex 69 - C1GT1<br>
* SubIndex 70 - C1GT2<br>
* SubIndex 71 - C1GKP1<br>
* SubIndex 72 - C1GKP2<br>
* SubIndex 73 - C1GKD1<br>
* SubIndex 74 - C1GKD2<br>
* SubIndex 75 - C2AP1<br>
* SubIndex 76 - C2AP2<br>
* SubIndex 77 - C2AV1<br>
* SubIndex 78 - C2AV2<br>
* SubIndex 79 - C2AT1<br>
* SubIndex 80 - C2AT2<br>
* SubIndex 81 - C2AKP1<br>
* SubIndex 82 - C2AKP2<br>
* SubIndex 83 - C2AKD1<br>
* SubIndex 84 - C2AKD2<br>
* SubIndex 85 - C2BP1<br>
* SubIndex 86 - C2BP2<br>
* SubIndex 87 - C2BV1<br>
* SubIndex 88 - C2BV2<br>
* SubIndex 89 - C2BT1<br>
* SubIndex 90 - C2BT2<br>
* SubIndex 91 - C2BKP1<br>
* SubIndex 92 - C2BKP2<br>
* SubIndex 93 - C2BKD1<br>
* SubIndex 94 - C2BKD2<br>
* SubIndex 95 - C2CP1<br>
* SubIndex 96 - C2CP2<br>
* SubIndex 97 - C2CV1<br>
* SubIndex 98 - C2CV2<br>
* SubIndex 99 - C2CT1<br>
* SubIndex 100 - C2CT2<br>
* SubIndex 101 - C2CKP1<br>
* SubIndex 102 - C2CKP2<br>
* SubIndex 103 - C2CKD1<br>
* SubIndex 104 - C2CKD2<br>
* SubIndex 105 - C2DP1<br>
* SubIndex 106 - C2DP2<br>
* SubIndex 107 - C2DV1<br>
* SubIndex 108 - C2DV2<br>
* SubIndex 109 - C2DT1<br>
* SubIndex 110 - C2DT2<br>
* SubIndex 111 - C2DKP1<br>
* SubIndex 112 - C2DKP2<br>
* SubIndex 113 - C2DKD1<br>
* SubIndex 114 - C2DKD2<br>
* SubIndex 115 - C2EP1<br>
* SubIndex 116 - C2EP2<br>
* SubIndex 117 - C2EV1<br>
* SubIndex 118 - C2EV2<br>
* SubIndex 119 - C2ET1<br>
* SubIndex 120 - C2ET2<br>
* SubIndex 121 - C2EKP1<br>
* SubIndex 122 - C2EKP2<br>
* SubIndex 123 - C2EKD1<br>
* SubIndex 124 - C2EKD2<br>
* SubIndex 125 - C2FP1<br>
* SubIndex 126 - C2FP2<br>
* SubIndex 127 - C2FV1<br>
* SubIndex 128 - C2FV2<br>
* SubIndex 129 - C2FT1<br>
* SubIndex 130 - C2FT2<br>
* SubIndex 131 - C2FKP1<br>
* SubIndex 132 - C2FKP2<br>
* SubIndex 133 - C2FKD1<br>
* SubIndex 134 - C2FKD2<br>
* SubIndex 135 - C2GP1<br>
* SubIndex 136 - C2GP2<br>
* SubIndex 137 - C2GV1<br>
* SubIndex 138 - C2GV2<br>
* SubIndex 139 - C2GT1<br>
* SubIndex 140 - C2GT2<br>
* SubIndex 141 - C2GKP1<br>
* SubIndex 142 - C2GKP2<br>
* SubIndex 143 - C2GKD1<br>
* SubIndex 144 - C2GKD2<br>
* SubIndex 145 - C3AP1<br>
* SubIndex 146 - C3AP2<br>
* SubIndex 147 - C3AV1<br>
* SubIndex 148 - C3AV2<br>
* SubIndex 149 - C3AT1<br>
* SubIndex 150 - C3AT2<br>
* SubIndex 151 - C3AKP1<br>
* SubIndex 152 - C3AKP2<br>
* SubIndex 153 - C3AKD1<br>
* SubIndex 154 - C3AKD2<br>
* SubIndex 155 - C3BP1<br>
* SubIndex 156 - C3BP2<br>
* SubIndex 157 - C3BV1<br>
* SubIndex 158 - C3BV2<br>
* SubIndex 159 - C3BT1<br>
* SubIndex 160 - C3BT2<br>
* SubIndex 161 - C3BKP1<br>
* SubIndex 162 - C3BKP2<br>
* SubIndex 163 - C3BKD1<br>
* SubIndex 164 - C3BKD2<br>
* SubIndex 165 - C3CP1<br>
* SubIndex 166 - C3CP2<br>
* SubIndex 167 - C3CV1<br>
* SubIndex 168 - C3CV2<br>
* SubIndex 169 - C3CT1<br>
* SubIndex 170 - C3CT2<br>
* SubIndex 171 - C3CKP1<br>
* SubIndex 172 - C3CKP2<br>
* SubIndex 173 - C3CKD1<br>
* SubIndex 174 - C3CKD2<br>
* SubIndex 175 - Pad1<br>
* SubIndex 176 - Pad2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - Ctrl */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - Seq1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex3 - Seq2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex4 - Seq3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex5 - C1AP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex6 - C1AP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex7 - C1AV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex8 - C1AV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex9 - C1AT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex10 - C1AT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex11 - C1AKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex12 - C1AKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex13 - C1AKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex14 - C1AKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex15 - C1BP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex16 - C1BP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex17 - C1BV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex18 - C1BV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex19 - C1BT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex20 - C1BT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex21 - C1BKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex22 - C1BKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex23 - C1BKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex24 - C1BKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex25 - C1CP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex26 - C1CP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex27 - C1CV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex28 - C1CV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex29 - C1CT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex30 - C1CT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex31 - C1CKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex32 - C1CKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex33 - C1CKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex34 - C1CKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex35 - C1DP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex36 - C1DP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex37 - C1DV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex38 - C1DV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex39 - C1DT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex40 - C1DT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex41 - C1DKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex42 - C1DKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex43 - C1DKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex44 - C1DKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex45 - C1EP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex46 - C1EP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex47 - C1EV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex48 - C1EV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex49 - C1ET1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex50 - C1ET2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex51 - C1EKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex52 - C1EKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex53 - C1EKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex54 - C1EKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex55 - C1FP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex56 - C1FP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex57 - C1FV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex58 - C1FV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex59 - C1FT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex60 - C1FT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex61 - C1FKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex62 - C1FKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex63 - C1FKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex64 - C1FKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex65 - C1GP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex66 - C1GP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex67 - C1GV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex68 - C1GV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex69 - C1GT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex70 - C1GT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex71 - C1GKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex72 - C1GKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex73 - C1GKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex74 - C1GKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex75 - C2AP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex76 - C2AP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex77 - C2AV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex78 - C2AV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex79 - C2AT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex80 - C2AT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex81 - C2AKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex82 - C2AKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex83 - C2AKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex84 - C2AKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex85 - C2BP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex86 - C2BP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex87 - C2BV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex88 - C2BV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex89 - C2BT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex90 - C2BT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex91 - C2BKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex92 - C2BKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex93 - C2BKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex94 - C2BKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex95 - C2CP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex96 - C2CP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex97 - C2CV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex98 - C2CV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex99 - C2CT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex100 - C2CT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex101 - C2CKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex102 - C2CKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex103 - C2CKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex104 - C2CKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex105 - C2DP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex106 - C2DP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex107 - C2DV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex108 - C2DV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex109 - C2DT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex110 - C2DT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex111 - C2DKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex112 - C2DKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex113 - C2DKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex114 - C2DKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex115 - C2EP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex116 - C2EP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex117 - C2EV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex118 - C2EV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex119 - C2ET1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex120 - C2ET2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex121 - C2EKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex122 - C2EKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex123 - C2EKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex124 - C2EKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex125 - C2FP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex126 - C2FP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex127 - C2FV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex128 - C2FV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex129 - C2FT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex130 - C2FT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex131 - C2FKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex132 - C2FKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex133 - C2FKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex134 - C2FKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex135 - C2GP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex136 - C2GP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex137 - C2GV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex138 - C2GV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex139 - C2GT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex140 - C2GT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex141 - C2GKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex142 - C2GKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex143 - C2GKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex144 - C2GKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex145 - C3AP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex146 - C3AP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex147 - C3AV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex148 - C3AV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex149 - C3AT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex150 - C3AT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex151 - C3AKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex152 - C3AKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex153 - C3AKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex154 - C3AKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex155 - C3BP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex156 - C3BP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex157 - C3BV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex158 - C3BV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex159 - C3BT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex160 - C3BT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex161 - C3BKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex162 - C3BKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex163 - C3BKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex164 - C3BKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex165 - C3CP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex166 - C3CP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex167 - C3CV1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex168 - C3CV2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex169 - C3CT1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex170 - C3CT2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex171 - C3CKP1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex172 - C3CKP2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex173 - C3CKD1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex174 - C3CKD2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex175 - Pad1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex176 - Pad2 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "PDOChannel\000"
"Ctrl\000"
"Seq1\000"
"Seq2\000"
"Seq3\000"
"C1AP1\000"
"C1AP2\000"
"C1AV1\000"
"C1AV2\000"
"C1AT1\000"
"C1AT2\000"
"C1AKP1\000"
"C1AKP2\000"
"C1AKD1\000"
"C1AKD2\000"
"C1BP1\000"
"C1BP2\000"
"C1BV1\000"
"C1BV2\000"
"C1BT1\000"
"C1BT2\000"
"C1BKP1\000"
"C1BKP2\000"
"C1BKD1\000"
"C1BKD2\000"
"C1CP1\000"
"C1CP2\000"
"C1CV1\000"
"C1CV2\000"
"C1CT1\000"
"C1CT2\000"
"C1CKP1\000"
"C1CKP2\000"
"C1CKD1\000"
"C1CKD2\000"
"C1DP1\000"
"C1DP2\000"
"C1DV1\000"
"C1DV2\000"
"C1DT1\000"
"C1DT2\000"
"C1DKP1\000"
"C1DKP2\000"
"C1DKD1\000"
"C1DKD2\000"
"C1EP1\000"
"C1EP2\000"
"C1EV1\000"
"C1EV2\000"
"C1ET1\000"
"C1ET2\000"
"C1EKP1\000"
"C1EKP2\000"
"C1EKD1\000"
"C1EKD2\000"
"C1FP1\000"
"C1FP2\000"
"C1FV1\000"
"C1FV2\000"
"C1FT1\000"
"C1FT2\000"
"C1FKP1\000"
"C1FKP2\000"
"C1FKD1\000"
"C1FKD2\000"
"C1GP1\000"
"C1GP2\000"
"C1GV1\000"
"C1GV2\000"
"C1GT1\000"
"C1GT2\000"
"C1GKP1\000"
"C1GKP2\000"
"C1GKD1\000"
"C1GKD2\000"
"C2AP1\000"
"C2AP2\000"
"C2AV1\000"
"C2AV2\000"
"C2AT1\000"
"C2AT2\000"
"C2AKP1\000"
"C2AKP2\000"
"C2AKD1\000"
"C2AKD2\000"
"C2BP1\000"
"C2BP2\000"
"C2BV1\000"
"C2BV2\000"
"C2BT1\000"
"C2BT2\000"
"C2BKP1\000"
"C2BKP2\000"
"C2BKD1\000"
"C2BKD2\000"
"C2CP1\000"
"C2CP2\000"
"C2CV1\000"
"C2CV2\000"
"C2CT1\000"
"C2CT2\000"
"C2CKP1\000"
"C2CKP2\000"
"C2CKD1\000"
"C2CKD2\000"
"C2DP1\000"
"C2DP2\000"
"C2DV1\000"
"C2DV2\000"
"C2DT1\000"
"C2DT2\000"
"C2DKP1\000"
"C2DKP2\000"
"C2DKD1\000"
"C2DKD2\000"
"C2EP1\000"
"C2EP2\000"
"C2EV1\000"
"C2EV2\000"
"C2ET1\000"
"C2ET2\000"
"C2EKP1\000"
"C2EKP2\000"
"C2EKD1\000"
"C2EKD2\000"
"C2FP1\000"
"C2FP2\000"
"C2FV1\000"
"C2FV2\000"
"C2FT1\000"
"C2FT2\000"
"C2FKP1\000"
"C2FKP2\000"
"C2FKD1\000"
"C2FKD2\000"
"C2GP1\000"
"C2GP2\000"
"C2GV1\000"
"C2GV2\000"
"C2GT1\000"
"C2GT2\000"
"C2GKP1\000"
"C2GKP2\000"
"C2GKD1\000"
"C2GKD2\000"
"C3AP1\000"
"C3AP2\000"
"C3AV1\000"
"C3AV2\000"
"C3AT1\000"
"C3AT2\000"
"C3AKP1\000"
"C3AKP2\000"
"C3AKD1\000"
"C3AKD2\000"
"C3BP1\000"
"C3BP2\000"
"C3BV1\000"
"C3BV2\000"
"C3BT1\000"
"C3BT2\000"
"C3BKP1\000"
"C3BKP2\000"
"C3BKD1\000"
"C3BKD2\000"
"C3CP1\000"
"C3CP2\000"
"C3CV1\000"
"C3CV2\000"
"C3CT1\000"
"C3CT2\000"
"C3CKP1\000"
"C3CKP2\000"
"C3CKD1\000"
"C3CKD2\000"
"Pad1\000"
"Pad2\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC__DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 Ctrl; /* Subindex1 - Ctrl */
UINT8 Seq1; /* Subindex2 - Seq1 */
UINT8 Seq2; /* Subindex3 - Seq2 */
UINT8 Seq3; /* Subindex4 - Seq3 */
UINT8 C1AP1; /* Subindex5 - C1AP1 */
UINT8 C1AP2; /* Subindex6 - C1AP2 */
UINT8 C1AV1; /* Subindex7 - C1AV1 */
UINT8 C1AV2; /* Subindex8 - C1AV2 */
UINT8 C1AT1; /* Subindex9 - C1AT1 */
UINT8 C1AT2; /* Subindex10 - C1AT2 */
UINT8 C1AKP1; /* Subindex11 - C1AKP1 */
UINT8 C1AKP2; /* Subindex12 - C1AKP2 */
UINT8 C1AKD1; /* Subindex13 - C1AKD1 */
UINT8 C1AKD2; /* Subindex14 - C1AKD2 */
UINT8 C1BP1; /* Subindex15 - C1BP1 */
UINT8 C1BP2; /* Subindex16 - C1BP2 */
UINT8 C1BV1; /* Subindex17 - C1BV1 */
UINT8 C1BV2; /* Subindex18 - C1BV2 */
UINT8 C1BT1; /* Subindex19 - C1BT1 */
UINT8 C1BT2; /* Subindex20 - C1BT2 */
UINT8 C1BKP1; /* Subindex21 - C1BKP1 */
UINT8 C1BKP2; /* Subindex22 - C1BKP2 */
UINT8 C1BKD1; /* Subindex23 - C1BKD1 */
UINT8 C1BKD2; /* Subindex24 - C1BKD2 */
UINT8 C1CP1; /* Subindex25 - C1CP1 */
UINT8 C1CP2; /* Subindex26 - C1CP2 */
UINT8 C1CV1; /* Subindex27 - C1CV1 */
UINT8 C1CV2; /* Subindex28 - C1CV2 */
UINT8 C1CT1; /* Subindex29 - C1CT1 */
UINT8 C1CT2; /* Subindex30 - C1CT2 */
UINT8 C1CKP1; /* Subindex31 - C1CKP1 */
UINT8 C1CKP2; /* Subindex32 - C1CKP2 */
UINT8 C1CKD1; /* Subindex33 - C1CKD1 */
UINT8 C1CKD2; /* Subindex34 - C1CKD2 */
UINT8 C1DP1; /* Subindex35 - C1DP1 */
UINT8 C1DP2; /* Subindex36 - C1DP2 */
UINT8 C1DV1; /* Subindex37 - C1DV1 */
UINT8 C1DV2; /* Subindex38 - C1DV2 */
UINT8 C1DT1; /* Subindex39 - C1DT1 */
UINT8 C1DT2; /* Subindex40 - C1DT2 */
UINT8 C1DKP1; /* Subindex41 - C1DKP1 */
UINT8 C1DKP2; /* Subindex42 - C1DKP2 */
UINT8 C1DKD1; /* Subindex43 - C1DKD1 */
UINT8 C1DKD2; /* Subindex44 - C1DKD2 */
UINT8 C1EP1; /* Subindex45 - C1EP1 */
UINT8 C1EP2; /* Subindex46 - C1EP2 */
UINT8 C1EV1; /* Subindex47 - C1EV1 */
UINT8 C1EV2; /* Subindex48 - C1EV2 */
UINT8 C1ET1; /* Subindex49 - C1ET1 */
UINT8 C1ET2; /* Subindex50 - C1ET2 */
UINT8 C1EKP1; /* Subindex51 - C1EKP1 */
UINT8 C1EKP2; /* Subindex52 - C1EKP2 */
UINT8 C1EKD1; /* Subindex53 - C1EKD1 */
UINT8 C1EKD2; /* Subindex54 - C1EKD2 */
UINT8 C1FP1; /* Subindex55 - C1FP1 */
UINT8 C1FP2; /* Subindex56 - C1FP2 */
UINT8 C1FV1; /* Subindex57 - C1FV1 */
UINT8 C1FV2; /* Subindex58 - C1FV2 */
UINT8 C1FT1; /* Subindex59 - C1FT1 */
UINT8 C1FT2; /* Subindex60 - C1FT2 */
UINT8 C1FKP1; /* Subindex61 - C1FKP1 */
UINT8 C1FKP2; /* Subindex62 - C1FKP2 */
UINT8 C1FKD1; /* Subindex63 - C1FKD1 */
UINT8 C1FKD2; /* Subindex64 - C1FKD2 */
UINT8 C1GP1; /* Subindex65 - C1GP1 */
UINT8 C1GP2; /* Subindex66 - C1GP2 */
UINT8 C1GV1; /* Subindex67 - C1GV1 */
UINT8 C1GV2; /* Subindex68 - C1GV2 */
UINT8 C1GT1; /* Subindex69 - C1GT1 */
UINT8 C1GT2; /* Subindex70 - C1GT2 */
UINT8 C1GKP1; /* Subindex71 - C1GKP1 */
UINT8 C1GKP2; /* Subindex72 - C1GKP2 */
UINT8 C1GKD1; /* Subindex73 - C1GKD1 */
UINT8 C1GKD2; /* Subindex74 - C1GKD2 */
UINT8 C2AP1; /* Subindex75 - C2AP1 */
UINT8 C2AP2; /* Subindex76 - C2AP2 */
UINT8 C2AV1; /* Subindex77 - C2AV1 */
UINT8 C2AV2; /* Subindex78 - C2AV2 */
UINT8 C2AT1; /* Subindex79 - C2AT1 */
UINT8 C2AT2; /* Subindex80 - C2AT2 */
UINT8 C2AKP1; /* Subindex81 - C2AKP1 */
UINT8 C2AKP2; /* Subindex82 - C2AKP2 */
UINT8 C2AKD1; /* Subindex83 - C2AKD1 */
UINT8 C2AKD2; /* Subindex84 - C2AKD2 */
UINT8 C2BP1; /* Subindex85 - C2BP1 */
UINT8 C2BP2; /* Subindex86 - C2BP2 */
UINT8 C2BV1; /* Subindex87 - C2BV1 */
UINT8 C2BV2; /* Subindex88 - C2BV2 */
UINT8 C2BT1; /* Subindex89 - C2BT1 */
UINT8 C2BT2; /* Subindex90 - C2BT2 */
UINT8 C2BKP1; /* Subindex91 - C2BKP1 */
UINT8 C2BKP2; /* Subindex92 - C2BKP2 */
UINT8 C2BKD1; /* Subindex93 - C2BKD1 */
UINT8 C2BKD2; /* Subindex94 - C2BKD2 */
UINT8 C2CP1; /* Subindex95 - C2CP1 */
UINT8 C2CP2; /* Subindex96 - C2CP2 */
UINT8 C2CV1; /* Subindex97 - C2CV1 */
UINT8 C2CV2; /* Subindex98 - C2CV2 */
UINT8 C2CT1; /* Subindex99 - C2CT1 */
UINT8 C2CT2; /* Subindex100 - C2CT2 */
UINT8 C2CKP1; /* Subindex101 - C2CKP1 */
UINT8 C2CKP2; /* Subindex102 - C2CKP2 */
UINT8 C2CKD1; /* Subindex103 - C2CKD1 */
UINT8 C2CKD2; /* Subindex104 - C2CKD2 */
UINT8 C2DP1; /* Subindex105 - C2DP1 */
UINT8 C2DP2; /* Subindex106 - C2DP2 */
UINT8 C2DV1; /* Subindex107 - C2DV1 */
UINT8 C2DV2; /* Subindex108 - C2DV2 */
UINT8 C2DT1; /* Subindex109 - C2DT1 */
UINT8 C2DT2; /* Subindex110 - C2DT2 */
UINT8 C2DKP1; /* Subindex111 - C2DKP1 */
UINT8 C2DKP2; /* Subindex112 - C2DKP2 */
UINT8 C2DKD1; /* Subindex113 - C2DKD1 */
UINT8 C2DKD2; /* Subindex114 - C2DKD2 */
UINT8 C2EP1; /* Subindex115 - C2EP1 */
UINT8 C2EP2; /* Subindex116 - C2EP2 */
UINT8 C2EV1; /* Subindex117 - C2EV1 */
UINT8 C2EV2; /* Subindex118 - C2EV2 */
UINT8 C2ET1; /* Subindex119 - C2ET1 */
UINT8 C2ET2; /* Subindex120 - C2ET2 */
UINT8 C2EKP1; /* Subindex121 - C2EKP1 */
UINT8 C2EKP2; /* Subindex122 - C2EKP2 */
UINT8 C2EKD1; /* Subindex123 - C2EKD1 */
UINT8 C2EKD2; /* Subindex124 - C2EKD2 */
UINT8 C2FP1; /* Subindex125 - C2FP1 */
UINT8 C2FP2; /* Subindex126 - C2FP2 */
UINT8 C2FV1; /* Subindex127 - C2FV1 */
UINT8 C2FV2; /* Subindex128 - C2FV2 */
UINT8 C2FT1; /* Subindex129 - C2FT1 */
UINT8 C2FT2; /* Subindex130 - C2FT2 */
UINT8 C2FKP1; /* Subindex131 - C2FKP1 */
UINT8 C2FKP2; /* Subindex132 - C2FKP2 */
UINT8 C2FKD1; /* Subindex133 - C2FKD1 */
UINT8 C2FKD2; /* Subindex134 - C2FKD2 */
UINT8 C2GP1; /* Subindex135 - C2GP1 */
UINT8 C2GP2; /* Subindex136 - C2GP2 */
UINT8 C2GV1; /* Subindex137 - C2GV1 */
UINT8 C2GV2; /* Subindex138 - C2GV2 */
UINT8 C2GT1; /* Subindex139 - C2GT1 */
UINT8 C2GT2; /* Subindex140 - C2GT2 */
UINT8 C2GKP1; /* Subindex141 - C2GKP1 */
UINT8 C2GKP2; /* Subindex142 - C2GKP2 */
UINT8 C2GKD1; /* Subindex143 - C2GKD1 */
UINT8 C2GKD2; /* Subindex144 - C2GKD2 */
UINT8 C3AP1; /* Subindex145 - C3AP1 */
UINT8 C3AP2; /* Subindex146 - C3AP2 */
UINT8 C3AV1; /* Subindex147 - C3AV1 */
UINT8 C3AV2; /* Subindex148 - C3AV2 */
UINT8 C3AT1; /* Subindex149 - C3AT1 */
UINT8 C3AT2; /* Subindex150 - C3AT2 */
UINT8 C3AKP1; /* Subindex151 - C3AKP1 */
UINT8 C3AKP2; /* Subindex152 - C3AKP2 */
UINT8 C3AKD1; /* Subindex153 - C3AKD1 */
UINT8 C3AKD2; /* Subindex154 - C3AKD2 */
UINT8 C3BP1; /* Subindex155 - C3BP1 */
UINT8 C3BP2; /* Subindex156 - C3BP2 */
UINT8 C3BV1; /* Subindex157 - C3BV1 */
UINT8 C3BV2; /* Subindex158 - C3BV2 */
UINT8 C3BT1; /* Subindex159 - C3BT1 */
UINT8 C3BT2; /* Subindex160 - C3BT2 */
UINT8 C3BKP1; /* Subindex161 - C3BKP1 */
UINT8 C3BKP2; /* Subindex162 - C3BKP2 */
UINT8 C3BKD1; /* Subindex163 - C3BKD1 */
UINT8 C3BKD2; /* Subindex164 - C3BKD2 */
UINT8 C3CP1; /* Subindex165 - C3CP1 */
UINT8 C3CP2; /* Subindex166 - C3CP2 */
UINT8 C3CV1; /* Subindex167 - C3CV1 */
UINT8 C3CV2; /* Subindex168 - C3CV2 */
UINT8 C3CT1; /* Subindex169 - C3CT1 */
UINT8 C3CT2; /* Subindex170 - C3CT2 */
UINT8 C3CKP1; /* Subindex171 - C3CKP1 */
UINT8 C3CKP2; /* Subindex172 - C3CKP2 */
UINT8 C3CKD1; /* Subindex173 - C3CKD1 */
UINT8 C3CKD2; /* Subindex174 - C3CKD2 */
UINT8 Pad1; /* Subindex175 - Pad1 */
UINT8 Pad2; /* Subindex176 - Pad2 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 PDOChannel0x7000
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={176,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
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
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7050[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - U1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - U2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex3 - U3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex4 - U4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex5 - U5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex6 - U6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex7 - U7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex8 - U8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex9 - U9 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex10 - U10 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex11 - U11 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex12 - U12 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex13 - U13 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex14 - U14 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex15 - U15 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex16 - U16 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex17 - U17 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex18 - U18 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex19 - U19 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex20 - U20 */

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
"U20\000\377";
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
} OBJ_STRUCT_PACKED_END
TOBJ7050;
#endif //#ifndef _SSC__DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7050 RMUIPDOChannel0x7050
#if defined(_SSC__DEVICE_) && (_SSC__DEVICE_ == 1)
={20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 176 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &PDOChannelProcessDataMapping0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1605 */
{NULL , NULL ,  0x1605 , {DEFTYPE_PDOMAPPING , 20 | (OBJCODE_REC << 8)} , asEntryDesc0x1605 , aName0x1605 , &RMUIPDOChannelProcessDataMapping0x1605 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 204 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &PDIChannelProcessDataMapping0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1A0F */
{NULL , NULL ,  0x1A0F , {DEFTYPE_PDOMAPPING , 212 | (OBJCODE_REC << 8)} , asEntryDesc0x1A0F , aName0x1A0F , &RMDAPDIChannelProcessDataMapping0x1A0F , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 2 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 2 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 204 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &PDIChannel0x6000 , NULL , NULL , 0x0000 },
/* Object 0x60F0 */
{NULL , NULL ,  0x60F0 , {DEFTYPE_RECORD , 212 | (OBJCODE_REC << 8)} , asEntryDesc0x60F0 , aName0x60F0 , &RMDAPDIChannel0x60F0 , NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 176 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &PDOChannel0x7000 , NULL , NULL , 0x0000 },
/* Object 0x7050 */
{NULL , NULL ,  0x7050 , {DEFTYPE_RECORD , 20 | (OBJCODE_REC << 8)} , asEntryDesc0x7050 , aName0x7050 , &RMUIPDOChannel0x7050 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

#undef PROTO

/** @}*/
#define _SSC__DEVICE_OBJECTS_H_
