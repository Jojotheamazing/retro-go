#ifndef CONFIG_H
#define CONFIG_H

#include <driver/gpio.h>
#include <driver/adc.h>

// Target definition
#define RG_TARGET_NAME             "ESP32-S3-CUSTOM"

// Storage
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDSPI_HOST       SPI3_HOST           // FSPI / SPI3
#define RG_STORAGE_SDSPI_SPEED      SDMMC_FREQ_DEFAULT

// Audio
#define RG_AUDIO_USE_INT_DAC        0   // 0 = Disable
#define RG_AUDIO_USE_EXT_DAC        1   // 1 = Enable (MAX98357A I2S)

// Video (ILI9341 240x320 Portrait Display)
#define RG_SCREEN_DRIVER            0   // 0 = ILI9341/ST7789
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_BACKLIGHT         0   // Set to 0 if backlight is always tied to VCC
#define RG_SCREEN_WIDTH             240 // Your portrait width
#define RG_SCREEN_HEIGHT            320 // Your portrait height
#define RG_SCREEN_ROTATE            0   // Adjust (0-3) if the screen boots upside down

// Display initialization macro provided in your target template
#define RG_SCREEN_INIT()                                                                                         \
    ILI9341_CMD(0xCF, 0x00, 0xc3, 0x30);                                                                         \
    ILI9341_CMD(0xED, 0x64, 0x03, 0x12, 0x81);                                                                   \
    ILI9341_CMD(0xE8, 0x85, 0x00, 0x78);                                                                         \
    ILI9341_CMD(0xCB, 0x39, 0x2c, 0x00, 0x34, 0x02);                                                             \
    ILI9341_CMD(0xF7, 0x20);                                                                                     \
    ILI9341_CMD(0xEA, 0x00, 0x00);                                                                               \
    ILI9341_CMD(0xC0, 0x1B);                                                                                     \
    ILI9341_CMD(0xC1, 0x12);                                                                                     \
    ILI9341_CMD(0xC5, 0x32, 0x3C);                                                                               \
    ILI9341_CMD(0xC7, 0x91);                                                                                     \
    ILI9341_CMD(0x36, 0x48);                 /* Adjusted Memory Access for Portrait Mode orientation */          \
    ILI9341_CMD(0xB1, 0x00, 0x10);                                                                               \
    ILI9341_CMD(0xB6, 0x0A, 0xA2);                                                                               \
    ILI9341_CMD(0xF6, 0x01, 0x30);                                                                               \
    ILI9341_CMD(0xF2, 0x00);                                                                                     \
    ILI9341_CMD(0x26, 0x01);                                                                                     \
    ILI9341_CMD(0xE0, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00); \
    ILI9341_CMD(0xE1, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F);

// Input - Disabled original ADC/GPIO maps since you use MCP23017 over I2C
#undef RG_GAMEPAD_ADC_MAP
#undef RG_GAMEPAD_GPIO_MAP

// Retro-Go Native MCP23017 Config
#define RG_INPUT_DRIVER             3   // Driver code matching MCP23017 in rg_input.c
#define RG_GPIO_I2C_SDA             GPIO_NUM_2
#define RG_GPIO_I2C_SCL             GPIO_NUM_1
#define RG_MCP23017_ADDRESS         0x20

// Custom button pins mapped to Retro-Go functions (Port A = 0-7, Port B = 8-15)
#define RG_INPUT_MCP23017_UP        10
#define RG_INPUT_MCP23017_DOWN      5
#define RG_INPUT_MCP23017_LEFT      14
#define RG_INPUT_MCP23017_RIGHT     0

#define RG_INPUT_MCP23017_A         6
#define RG_INPUT_MCP23017_B         8
#define RG_INPUT_MCP23017_X         3
#define RG_INPUT_MCP23017_Y         4

#define RG_INPUT_MCP23017_L         1
#define RG_INPUT_MCP23017_R         2
#define RG_INPUT_MCP23017_START     7
#define RG_INPUT_MCP23017_SELECT    9

// Battery (Disabled or mapped to NC unless you have an analog voltage divider pin)
#define RG_BATTERY_DRIVER           0

// Physical Pin Bindings (Screen & SD Card SPI Buses)
#define RG_GPIO_LCD_MISO            GPIO_NUM_19
#define RG_GPIO_LCD_MOSI            GPIO_NUM_21
#define RG_GPIO_LCD_CLK             GPIO_NUM_20
#define RG_GPIO_LCD_CS              GPIO_NUM_45
#define RG_GPIO_LCD_DC              GPIO_NUM_47
#define RG_GPIO_LCD_RST             GPIO_NUM_48
#define RG_GPIO_LCD_BCKL            GPIO_NUM_NC // Set to NC since you lack a backlight GPIO line

#define RG_GPIO_SDSPI_CLK           GPIO_NUM_41
#define RG_GPIO_SDSPI_MISO          GPIO_NUM_40
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_39
#define RG_GPIO_SDSPI_CS            GPIO_NUM_38

// Audio Pin Bindings (External I2S DAC MAX98357A)
#define RG_GPIO_SND_I2S_BCK         4
#define RG_GPIO_SND_I2S_WS          5
#define RG_GPIO_SND_I2S_DATA        6

#endif // CONFIG_H
