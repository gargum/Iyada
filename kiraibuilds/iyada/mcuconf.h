/*
* This file exists to configure the RP2040. 
* It is also used to turn on features such as increased USB power consumption, and the use of PIO to connect the two halves of the Iyada.
*/

#pragma once

#include_next <mcuconf.h>

// for the bootloader reset behaviour configuration
    #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
    #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
    #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

// for the serial connection between the two keyboard halves
    #undef RP_SERIAL_USE_USART0
    #define RP_SERIAL_USE_USART0 TRUE
    #undef SERIAL_PIO_USE_PIO0
    #define SERIAL_PIO_USE_PIO0 TRUE
    #undef SERIAL_USART_TX_PIN
    #define SERIAL_USART_TX_PIN GP0
    #undef SERIAL_USART_RX_PIN
    #define SERIAL_USART_RX_PIN GP25
    #undef SERIAL_USART_PIN_SWAP
    #define SERIAL_USART_PIN_SWAP TRUE
    #undef SERIAL_USART_FULL_DUPLEX
    #define SERIAL_USART_FULL_DUPLEX TRUE
    #undef SELECT_SOFT_SERIAL_SPEED
    #define SELECT_SOFT_SERIAL_SPEED 1
    #undef SERIAL_USART_TIMEOUT
    #define SERIAL_USART_TIMEOUT 20
    #undef USB_SUSPEND_WAKEUP_DELAY
    #define USB_SUSPEND_WAKEUP_DELAY 200
    #undef USB_MAX_POWER_CONSUMPTION
    #define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(100)

// for all I2C peripherals
    #undef RP_I2C_USE_I2C1
    #define RP_I2C_USE_I2C1 TRUE
    #undef I2C1_SDA_PIN
    #define I2C1_SDA_PIN GP2
    #undef I2C1_SCL_PIN
    #define I2C1_SCL_PIN GP3
    #undef I2C1_OPMODE
    #define I2C1_OPMODE OPMODE_SMBUS_DEVICE
    #undef I2C1_DUTY_CYCLE
    #define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
    #undef I2C1_CLOCK_SPEED
    #define I2C1_CLOCK_SPEED 400000

// for all SPI peripherals
    #undef RP_SPI_USE_SPI1
    #define RP_SPI_USE_SPI1 TRUE
    #undef SPI_SCK_PIN
    #define SPI_SCK_PIN GP14
    #undef SPI_MISO_PIN
    #define SPI_MISO_PIN GP12
    #undef SPI_MOSI_PIN
    #define SPI_MOSI_PIN GP15

// for PWM audio playback
#ifdef AUDIO_ENABLE
    #undef RP_PWM_USE_PWM0
    #define RP_PWM_USE_PWM0 TRUE
    #undef AUDIO_PIN
    #define AUDIO_PIN GP16
    #undef AUDIO_PWM_DRIVER
    #define AUDIO_PWM_DRIVER PWMD0
    #undef AUDIO_PWM_CHANNEL
    #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
    #undef AUDIO_INIT_DELAY
    #define AUDIO_INIT_DELAY
    #undef SPEAKER_SHUTDOWN
    #define SPEAKER_SHUTDOWN GP19
#endif

// for all rotary and scroll encoders
#ifdef ENCODER_ENABLE

    #undef ENCODERS_PAD_A
    #undef ENCODERS_PAD_B
    #undef ENCODER_RESOLUTIONS
    #undef ENCODERS_PAD_A_RIGHT
    #undef ENCODERS_PAD_B_RIGHT
    #undef ENCODER_RESOLUTIONS_RIGHT

// for selecting between EC11 and EC12 rotary encoders
#if(EC12_LEFT == yes)
    #define ENCODERS_PAD_A { GP20, GP23 }
    #define ENCODERS_PAD_B { GP22, GP21 }
    #define ENCODER_RESOLUTIONS { 4, 4 }
#elif(EC12_LEFT == no)
    #define ENCODERS_PAD_A { GP22, GP23 }
    #define ENCODERS_PAD_B { GP20, GP21 }
    #define ENCODER_RESOLUTIONS { 4, 4 }
#endif
    
#if(EC12_RIGHT == yes)
    #define ENCODERS_PAD_A_RIGHT { GP23, GP20 }
    #define ENCODERS_PAD_B_RIGHT { GP21, GP22 }
    #define ENCODER_RESOLUTIONS_RIGHT { 4, 4 }
#elif(EC12_RIGHT == no)
    #define ENCODERS_PAD_A_RIGHT { GP23, GP22 }
    #define ENCODERS_PAD_B_RIGHT { GP21, GP20 }
    #define ENCODER_RESOLUTIONS_RIGHT { 4, 4 }
#endif 

#endif

// for firmware size reduction
    #undef NO_DEBUG
    #define NO_DEBUG
    #undef NO_PRINT
    #define NO_PRINT
