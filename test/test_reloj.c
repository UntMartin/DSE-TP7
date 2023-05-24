#include "unity.h"
#include "reloj.h"



#define SIMULATE_SECONDS(VALUE, function)   \
    for(int count = 0; count < VALUE; count ++) {   \
        for (int index = 0; index < TICKS_PER_SECOND; index++) {    \
            function;   \
        }   \
    }


void test_hora_reloj_arranca_hora_invalida(void){
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6] = {0xFF};

    clock_t reloj = ClockCreate(5);
    TEST_ASSERT_FALSE(ClockGetTime(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

void test_ajustar_hora(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};
    uint8_t hora[6] = {0xFF};

    clock_t reloj = ClockCreate(5);
    TEST_ASSERT_TRUE(ClockSetTime(reloj, ESPERADO, 4));
    TEST_ASSERT_TRUE(ClockGetTime(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}

void test_incremet_seconds_unit(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 1};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetTime(reloj, INICIAL, sizeof(INICIAL));

    SIMULATE_SECONDS(1, ClockTick(reloj));
    ClockGetTime(reloj, hora, sizeof(hora));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}

void test_incremet_seconds_decenas(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 1, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetTime(reloj, INICIAL, sizeof(INICIAL));

    SIMULATE_SECONDS(10, ClockTick(reloj));
    ClockGetTime(reloj, hora, sizeof(hora));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}

void test_incremet_minutes_unit(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    static const uint8_t ESPERADO[] = {1, 2, 3, 5, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetTime(reloj, INICIAL, sizeof(INICIAL));

    SIMULATE_SECONDS(60, ClockTick(reloj));
    ClockGetTime(reloj, hora, sizeof(hora));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}

void test_incremet_minutes_decenas(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    static const uint8_t ESPERADO[] = {1, 2, 4, 4, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetTime(reloj, INICIAL, sizeof(INICIAL));

    SIMULATE_SECONDS(600, ClockTick(reloj));
    ClockGetTime(reloj, hora, sizeof(hora));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}

void test_incremet_hour_unit(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    static const uint8_t ESPERADO[] = {1, 3, 3, 4, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetTime(reloj, INICIAL, sizeof(INICIAL));

    SIMULATE_SECONDS(3600, ClockTick(reloj));
    ClockGetTime(reloj, hora, sizeof(hora));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}

void test_incremet_hour_decenas(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    static const uint8_t ESPERADO[] = {2, 2, 3, 4, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetTime(reloj, INICIAL, sizeof(INICIAL));

    SIMULATE_SECONDS(36000, ClockTick(reloj));
    ClockGetTime(reloj, hora, sizeof(hora));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}

void test_incremet_one_day(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetTime(reloj, INICIAL, sizeof(INICIAL));

    SIMULATE_SECONDS(86400, ClockTick(reloj));
    ClockGetTime(reloj, hora, sizeof(hora));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);    
}