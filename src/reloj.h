#include <stdbool.h> 
#include <stdint.h>

#define TICKS_PER_SECOND 5

typedef struct clock_s * clock_t;


clock_t ClockCreate(int tics_por_segundo);

bool ClockGetTime(clock_t reloj, uint8_t * hora, int size);

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size);

void ClockTick(clock_t reloj);

