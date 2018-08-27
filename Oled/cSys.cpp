#include "cSys.h"
#include "cOrignal.h"
#include "defTypes.h"

cSys::cSys(){
    // Serial.begin(115200);
    ;
}

void cSys::hello(){
  uchar buf[] = "hello";
    orignalFunc.comWrite(1, buf, sizeof(buf));
    ;
}
