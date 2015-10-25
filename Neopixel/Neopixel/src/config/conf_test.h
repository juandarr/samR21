/*
 * conf_test.h
 *
 * Created: 10/23/2015 10:06:28 PM
 *  Author: Juan Rios
 */ 


#ifndef CONF_TEST_H_
#define CONF_TEST_H_

#define CONF_TEST_TCC0            TCC0
#define CONF_TEST_TCC1            TCC1

#define CONF_EIC_CHAN             6
#define CONF_EIC_PIN              PIN_PA06A_EIC_EXTINT6
#define CONF_EIC_MUX              MUX_PA06A_EIC_EXTINT6

#define CONF_TEST_PIN_OUT         PIN_PA16F_TCC0_WO0//PIN_PA08E_TCC0_WO0
#define CONF_TEST_PIN_MUX         MUX_PA16F_TCC0_WO0//MUX_PA08E_TCC0_WO0

#define CONF_EVENT_GENERATOR_ID   EVSYS_ID_GEN_EIC_EXTINT_6
#define CONF_EVENT_USED_ID        EVSYS_ID_USER_TCC1_EV_1

#define CONF_CAPTURE_CHAN_0       0
#define CONF_CAPTURE_CHAN_1       1

#define CONF_TEST_TOLERANCE       10

#define CONF_EVENT_USER_ID_FAULTn EVSYS_ID_USER_TCC0_MC_0
#define CONF_EVENT_USER_ID_FAULTx EVSYS_ID_USER_TCC0_EV_0


#endif /* CONF_TEST_H_ */