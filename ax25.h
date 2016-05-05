/*
 * Adapted from Polaric Tracker code. 
 * By LA7ECA, ohanssen@acm.org and LA3T.
 */

#if !defined __AX25_H__
#define __AX25_H__

#include <inttypes.h>
#include "fbuf.h"
#include <stdbool.h>
#include "defines.h"
#include "hal_streams.h"


#define ASCII_0    0x00                 
#define ASCII_SPC  0x20

#define FLAG_CMD   0x80
#define FLAG_LAST  0x01
#define FLAG_DIGI  0x80

#define FTYPE_I      0x00
#define FTYPE_RR     0x01
#define FTYPE_RNR    0x05
#define FTYPE_REJ    0x09
#define FTYPE_SABM   0x2F
#define FTYPE_SABME  0x6F
#define FTYPE_DISC   0x43
#define FTYPE_DM     0x0F

#define FTYPE_UA     0x63
#define FTYPE_FRMR   0x87
#define FTYPE_UI     0x03

#define PID_NO_L3    0xf0

#define AX25_HDR_LEN(ndigis) (14+2+(ndigis)*7)
#define AX25_ADDR_LEN 9


/* AX.25 Address Field type */
typedef struct {
    char callsign[7];
    uint8_t ssid;
    uint8_t flags;
} addr_t;


addr_t* addr(addr_t*, char*, uint8_t); 
char* addr2str(char*, const addr_t*);
void str2addr(addr_t* a, const char* str, bool d);

/* Encode or decode header */
void ax25_encode_header( FBUF*, addr_t*, addr_t*, addr_t[], uint8_t, 
                        uint8_t, uint8_t );
uint8_t ax25_decode_header(FBUF*, addr_t*, addr_t*, addr_t[],
                        uint8_t*, uint8_t*);


/* Display information about frame */
void ax25_display_frame(Stream*, FBUF *);
void ax25_display_addr(Stream*, addr_t*);

                         
#endif /* __AX25_H__ */
