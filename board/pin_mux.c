/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v13.0
processor: MKL46Z256xxx4
package_id: MKL46Z256VLL4
mcu_data: ksdk2_0
processor_version: 13.0.1
board: FRDM-KL46Z
pin_labels:
- {pin_num: '3', pin_signal: LCD_P50/PTE2/SPI1_SCK/LCD_P50_Fault, label: SSDP, identifier: SSDP}
- {pin_num: '4', pin_signal: LCD_P51/PTE3/SPI1_MISO/SPI1_MOSI/LCD_P51_Fault, label: SSC, identifier: SSC}
- {pin_num: '7', pin_signal: LCD_P54/PTE6/I2S0_MCLK/USB_SOF_OUT/LCD_P54_Fault, label: SSA, identifier: SSA}
- {pin_num: '14', pin_signal: LCD_P55/ADC0_DP1/ADC0_SE1/PTE16/SPI0_PCS0/UART2_TX/TPM_CLKIN0/LCD_P55_Fault, label: SSB, identifier: SSB}
- {pin_num: '15', pin_signal: LCD_P56/ADC0_DM1/ADC0_SE5a/PTE17/SPI0_SCK/UART2_RX/TPM_CLKIN1/LPTMR0_ALT3/LCD_P56_Fault, label: SSD, identifier: SSD}
- {pin_num: '16', pin_signal: LCD_P57/ADC0_DP2/ADC0_SE2/PTE18/SPI0_MOSI/I2C0_SDA/SPI0_MISO/LCD_P57_Fault, label: SSE, identifier: SSE}
- {pin_num: '17', pin_signal: LCD_P58/ADC0_DM2/ADC0_SE6a/PTE19/SPI0_MISO/I2C0_SCL/SPI0_MOSI/LCD_P58_Fault, label: SSF, identifier: SSF}
- {pin_num: '28', pin_signal: PTE31/TPM0_CH4, label: SSG, identifier: SSG}
- {pin_num: '56', pin_signal: LCD_P3/ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1/LCD_P3_Fault, label: SW_3, identifier: SW_3}
- {pin_num: '72', pin_signal: LCD_P22/ADC0_SE11/TSI0_CH15/PTC2/I2C1_SDA/TPM0_CH1/I2S0_TX_FS/LCD_P22_Fault, label: SW_2, identifier: SW_2}
- {pin_num: '71', pin_signal: LCD_P21/ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0/I2S0_TXD0/LCD_P21_Fault, label: SW_1, identifier: SW_1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '35', peripheral: UART0, signal: RX, pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0}
  - {pin_num: '36', peripheral: UART0, signal: TX, pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1}
  - {pin_num: '28', peripheral: GPIOE, signal: 'GPIO, 31', pin_signal: PTE31/TPM0_CH4, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '16', peripheral: GPIOE, signal: 'GPIO, 18', pin_signal: LCD_P57/ADC0_DP2/ADC0_SE2/PTE18/SPI0_MOSI/I2C0_SDA/SPI0_MISO/LCD_P57_Fault, direction: OUTPUT,
    gpio_init_state: 'true'}
  - {pin_num: '17', peripheral: GPIOE, signal: 'GPIO, 19', pin_signal: LCD_P58/ADC0_DM2/ADC0_SE6a/PTE19/SPI0_MISO/I2C0_SCL/SPI0_MOSI/LCD_P58_Fault, direction: OUTPUT,
    gpio_init_state: 'true'}
  - {pin_num: '15', peripheral: GPIOE, signal: 'GPIO, 17', pin_signal: LCD_P56/ADC0_DM1/ADC0_SE5a/PTE17/SPI0_SCK/UART2_RX/TPM_CLKIN1/LPTMR0_ALT3/LCD_P56_Fault, direction: OUTPUT,
    gpio_init_state: 'true'}
  - {pin_num: '14', peripheral: GPIOE, signal: 'GPIO, 16', pin_signal: LCD_P55/ADC0_DP1/ADC0_SE1/PTE16/SPI0_PCS0/UART2_TX/TPM_CLKIN0/LCD_P55_Fault, direction: OUTPUT,
    gpio_init_state: 'true'}
  - {pin_num: '7', peripheral: GPIOE, signal: 'GPIO, 6', pin_signal: LCD_P54/PTE6/I2S0_MCLK/USB_SOF_OUT/LCD_P54_Fault, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '4', peripheral: GPIOE, signal: 'GPIO, 3', pin_signal: LCD_P51/PTE3/SPI1_MISO/SPI1_MOSI/LCD_P51_Fault, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '3', peripheral: GPIOE, signal: 'GPIO, 2', pin_signal: LCD_P50/PTE2/SPI1_SCK/LCD_P50_Fault, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '71', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal: LCD_P21/ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0/I2S0_TXD0/LCD_P21_Fault,
    direction: INPUT}
  - {pin_num: '72', peripheral: GPIOC, signal: 'GPIO, 2', pin_signal: LCD_P22/ADC0_SE11/TSI0_CH15/PTC2/I2C1_SDA/TPM0_CH1/I2S0_TX_FS/LCD_P22_Fault, direction: INPUT}
  - {pin_num: '56', peripheral: GPIOB, signal: 'GPIO, 3', pin_signal: LCD_P3/ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1/LCD_P3_Fault, direction: INPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t SW_3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB3 (pin 56)  */
    GPIO_PinInit(BOARD_INITPINS_SW_3_GPIO, BOARD_INITPINS_SW_3_PIN, &SW_3_config);

    gpio_pin_config_t SW_1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC1 (pin 71)  */
    GPIO_PinInit(BOARD_INITPINS_SW_1_GPIO, BOARD_INITPINS_SW_1_PIN, &SW_1_config);

    gpio_pin_config_t SW_2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC2 (pin 72)  */
    GPIO_PinInit(BOARD_INITPINS_SW_2_GPIO, BOARD_INITPINS_SW_2_PIN, &SW_2_config);

    gpio_pin_config_t SSDP_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE2 (pin 3)  */
    GPIO_PinInit(BOARD_INITPINS_SSDP_GPIO, BOARD_INITPINS_SSDP_PIN, &SSDP_config);

    gpio_pin_config_t SSC_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE3 (pin 4)  */
    GPIO_PinInit(BOARD_INITPINS_SSC_GPIO, BOARD_INITPINS_SSC_PIN, &SSC_config);

    gpio_pin_config_t SSA_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE6 (pin 7)  */
    GPIO_PinInit(BOARD_INITPINS_SSA_GPIO, BOARD_INITPINS_SSA_PIN, &SSA_config);

    gpio_pin_config_t SSB_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE16 (pin 14)  */
    GPIO_PinInit(BOARD_INITPINS_SSB_GPIO, BOARD_INITPINS_SSB_PIN, &SSB_config);

    gpio_pin_config_t SSD_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE17 (pin 15)  */
    GPIO_PinInit(BOARD_INITPINS_SSD_GPIO, BOARD_INITPINS_SSD_PIN, &SSD_config);

    gpio_pin_config_t SSE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE18 (pin 16)  */
    GPIO_PinInit(BOARD_INITPINS_SSE_GPIO, BOARD_INITPINS_SSE_PIN, &SSE_config);

    gpio_pin_config_t SSF_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE19 (pin 17)  */
    GPIO_PinInit(BOARD_INITPINS_SSF_GPIO, BOARD_INITPINS_SSF_PIN, &SSF_config);

    gpio_pin_config_t SSG_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE31 (pin 28)  */
    GPIO_PinInit(BOARD_INITPINS_SSG_GPIO, BOARD_INITPINS_SSG_PIN, &SSG_config);

    /* PORTA1 (pin 35) is configured as UART0_RX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_RX_PORT, BOARD_INITPINS_DEBUG_UART_RX_PIN, kPORT_MuxAlt2);

    /* PORTA2 (pin 36) is configured as UART0_TX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_TX_PORT, BOARD_INITPINS_DEBUG_UART_TX_PIN, kPORT_MuxAlt2);

    /* PORTB3 (pin 56) is configured as PTB3 */
    PORT_SetPinMux(BOARD_INITPINS_SW_3_PORT, BOARD_INITPINS_SW_3_PIN, kPORT_MuxAsGpio);

    /* PORTC1 (pin 71) is configured as PTC1 */
    PORT_SetPinMux(BOARD_INITPINS_SW_1_PORT, BOARD_INITPINS_SW_1_PIN, kPORT_MuxAsGpio);

    /* PORTC2 (pin 72) is configured as PTC2 */
    PORT_SetPinMux(BOARD_INITPINS_SW_2_PORT, BOARD_INITPINS_SW_2_PIN, kPORT_MuxAsGpio);

    /* PORTE16 (pin 14) is configured as PTE16 */
    PORT_SetPinMux(BOARD_INITPINS_SSB_PORT, BOARD_INITPINS_SSB_PIN, kPORT_MuxAsGpio);

    /* PORTE17 (pin 15) is configured as PTE17 */
    PORT_SetPinMux(BOARD_INITPINS_SSD_PORT, BOARD_INITPINS_SSD_PIN, kPORT_MuxAsGpio);

    /* PORTE18 (pin 16) is configured as PTE18 */
    PORT_SetPinMux(BOARD_INITPINS_SSE_PORT, BOARD_INITPINS_SSE_PIN, kPORT_MuxAsGpio);

    /* PORTE19 (pin 17) is configured as PTE19 */
    PORT_SetPinMux(BOARD_INITPINS_SSF_PORT, BOARD_INITPINS_SSF_PIN, kPORT_MuxAsGpio);

    /* PORTE2 (pin 3) is configured as PTE2 */
    PORT_SetPinMux(BOARD_INITPINS_SSDP_PORT, BOARD_INITPINS_SSDP_PIN, kPORT_MuxAsGpio);

    /* PORTE3 (pin 4) is configured as PTE3 */
    PORT_SetPinMux(BOARD_INITPINS_SSC_PORT, BOARD_INITPINS_SSC_PIN, kPORT_MuxAsGpio);

    /* PORTE31 (pin 28) is configured as PTE31 */
    PORT_SetPinMux(BOARD_INITPINS_SSG_PORT, BOARD_INITPINS_SSG_PIN, kPORT_MuxAsGpio);

    /* PORTE6 (pin 7) is configured as PTE6 */
    PORT_SetPinMux(BOARD_INITPINS_SSA_PORT, BOARD_INITPINS_SSA_PIN, kPORT_MuxAsGpio);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART0TXSRC_MASK | SIM_SOPT5_UART0RXSRC_MASK)))

                  /* UART0 Transmit Data Source Select: UART0_TX pin. */
                  | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)

                  /* UART0 Receive Data Source Select: UART_RX pin. */
                  | SIM_SOPT5_UART0RXSRC(SOPT5_UART0RXSRC_UART_RX));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
