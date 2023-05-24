#include "reloj.h"
#include <string.h>



struct clock_s {
    uint8_t hora_actual[6];
    uint8_t ticks;
    uint8_t ticks_per_second;
    bool valida;
};

clock_t ClockCreate(int tics_por_segundo){
    static struct clock_s self[1];
    memset(self, 0, sizeof(self));
    self->ticks_per_second = TICKS_PER_SECOND;
    return self;   
}

bool ClockGetTime(clock_t reloj, uint8_t * hora, int size){
    memcpy(hora, reloj->hora_actual, size);
    return reloj->valida;
}

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size){
    memcpy(reloj->hora_actual, hora, size);
    reloj->valida = true;
    return true;
}

void ClockTick(clock_t reloj){
    reloj->ticks++;
    if(reloj->ticks == reloj->ticks_per_second){
        reloj->ticks = 0;
        reloj->hora_actual[5]++;
    }
    if (reloj->hora_actual[5] == 10){
        reloj->hora_actual[5] = 0;
        reloj->hora_actual[4]++;
    }    
    if (reloj->hora_actual[4] == 6){
        reloj->hora_actual[4] = 0;
        reloj->hora_actual[3]++;
    }   
    if (reloj->hora_actual[3] == 10){
        reloj->hora_actual[3] = 0;
        reloj->hora_actual[2]++;
    }    
    if (reloj->hora_actual[2] == 6){
        reloj->hora_actual[2] = 0;
        reloj->hora_actual[1]++;
    }   
    if (reloj->hora_actual[1] == 10){
        reloj->hora_actual[1] = 0;
        reloj->hora_actual[0]++;
    }    
    if ((reloj->hora_actual[0] == 2) && (reloj->hora_actual[1] == 4)){
        reloj->hora_actual[0] = 0;
        reloj->hora_actual[1] = 0;
    }   
}