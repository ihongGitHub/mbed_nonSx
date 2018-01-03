#ifndef __UttecUtil_H__
#define __UttecUtil_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "Flash.h"

#define UartTx   p9
#define UartRx   p11
typedef enum{
	eUp = 0,
	eDown = 1
} UttecDirection_t;

typedef struct{
	float targetValue;
	float nowValue;
	bool forced;
	uint8_t sensorType;	
} dimFactors_t;

typedef union
{
	uint8_t u8[2];
  uint16_t u16;                        
} ChangeByte_t;

class UttecUtil
{	
private: 
	static dimFactors_t myDimFact;
public:
	UttecUtil();
	uint16_t gen_crc16(const uint8_t *data, uint16_t size);
	uint8_t Hex2Dec(uint8_t cHex);

	void setWdt(uint8_t ucTime);
	void setWdtReload();
	void dispSec(rfFrame_t*);
	void testProc(uint8_t , uint32_t );
	void testProc(uint8_t , uint32_t , uint32_t);
	void testProc(uint8_t , uint32_t , float);
	void setDimFactor(dimFactors_t);
	dimFactors_t getDimFactor();
	uint16_t changeBytesInWord(uint16_t);

	bool isMstOrGw(rfFrame_t*);
	bool isMst(rfFrame_t*);
	bool isGw(rfFrame_t*);
	bool isTx(rfFrame_t*);
	bool isSRx(rfFrame_t*);
	bool isRx(rfFrame_t*);
	bool isRpt(rfFrame_t*);
	void dispRfFactor(rfFrame_t*);
	void dispCmdandSub(char*, char*, rfFrame_t*);
	bool isNotMyGroup(rfFrame_t* pSrc, rfFrame_t* pMy);
};

#endif
