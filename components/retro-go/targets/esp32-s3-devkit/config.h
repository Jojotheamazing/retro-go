// Target definition
#define RG_TARGET_NAME             "ESP32-S3-CUSTOM"

// Storage
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDSPI_HOST       SPI3_HOST
#define RG_STORAGE_SDSPI_SPEED      SDMMC_FREQ_DEFAULT

// Audio
#define RG_AUDIO_USE_INT_DAC        0   // 0 = Disable
#define RG_AUDIO_USE_EXT_DAC        1   // 1 = Enable (MAX98357A or similar)

// Video
#define RG_SCREEN_DRIVER            0   // 0 = ILI9341/ST7789
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_BACKLIGHT         1
#define RG_SCREEN_WIDTH             240
#define RG_SCREEN_HEIGHT            320
#define RG_SCREEN_ROTATE            0
#define RG_SCREEN_VISIBLE_AREA      {0, 0, 0, 0}
#define RG_SCREEN_SAFE_AREA         {0, 0, 0, 0}
#define RG_SCREEN_INIT()                                                                                         \
    ILI9341_CMD(0xCF, 0x00, 0xc3, 0x30);                                                                         \
    ILI9341_CMD(0xED, 0x64, 0x03, 0x12, 0x81);                                                                   \
    ILI9341_CMD(0xE8, 0x85, 0x00, 0x78);                                                                         \
    ILI9341_CMD(0xCB, 0x39, 0x2c, 0x00, 0x34, 0x02);                                                             \
    ILI9341_CMD(0xF7, 0x20);                                                                                     \
    ILI9341_CMD(0xEA, 0x00, 0x00);                                                                               \
    ILI9341_CMD(0xC0, 0x1B);                 /* Power control   //VRH[5:0] */                                    \
    ILI9341_CMD(0xC1, 0x12);                 /* Power control   //SAP[2:0];BT[3:0] */                            \
    ILI9341_CMD(0xC5, 0x32, 0x3C);           /* VCM control */                                                   \
    ILI9341_CMD(0xC7, 0x91);                 /* VCM control2 */                                                  \
    ILI9341_CMD(0x36, 0x48);                 /* Memory Access Control (MX|BGR) — portrait */                     \
    ILI9341_CMD(0xB1, 0x00, 0x10);           /* Frame Rate Control */                                            \
    ILI9341_CMD(0xB6, 0x0A, 0xA2);           /* Display Function Control */                                      \
    ILI9341_CMD(0xF6, 0x01, 0x30);                                                                               \
    ILI9341_CMD(0xF2, 0x00);                 /* 3Gamma Function Disable */                                       \
    ILI9341_CMD(0x26, 0x01);                 /* Gamma curve selected */                                          \
    ILI9341_CMD(0xE0, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00); \
    ILI9341_CMD(0xE1, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F);

// Input — MCP23017 I2C GPIO expander (active-LOW, internal pull-ups)
// GP pin numbers match ButtonID enum values in your firmware.
// Retro-Go's RG_GAMEPAD_GPIO_MAP is used here; the MCP23017 INT line
// (GPIO_NUM_42) must be wired and handled in your BSP/input driver.
#define RG_GAMEPAD_GPIO_MAP {\
    {RG_KEY_UP,     .num = GPIO_NUM_10, .pullup = 1, .level = 0},\
    {RG_KEY_DOWN,   .num = GPIO_NUM_5,  .pullup = 1, .level = 0},\
    {RG_KEY_LEFT,   .num = GPIO_NUM_14, .pullup = 1, .level = 0},\
    {RG_KEY_RIGHT,  .num = GPIO_NUM_0,  .pullup = 1, .level = 0},\
    {RG_KEY_A,      .num = GPIO_NUM_6,  .pullup = 1, .level = 0},\
    {RG_KEY_B,      .num = GPIO_NUM_8,  .pullup = 1, .level = 0},\
    {RG_KEY_SELECT, .num = GPIO_NUM_9,  .pullup = 1, .level = 0},\
    {RG_KEY_START,  .num = GPIO_NUM_7,  .pullup = 1, .level = 0},\
    {RG_KEY_MENU,   .num = GPIO_NUM_3,  .pullup = 1, .level = 0},\
    {RG_KEY_OPTION, .num = GPIO_NUM_4,  .pullup = 1, .level = 0},\
}

// Battery — not defined for this board; driver disabled
#define RG_BATTERY_DRIVER           0

// Status LED — not defined for this board
// #define RG_GPIO_LED              GPIO_NUM_NC

// SPI Display (ILI9341)
#define RG_GPIO_LCD_MISO            GPIO_NUM_19
#define RG_GPIO_LCD_MOSI            GPIO_NUM_21
#define RG_GPIO_LCD_CLK             GPIO_NUM_20
#define RG_GPIO_LCD_CS              GPIO_NUM_45
#define RG_GPIO_LCD_DC              GPIO_NUM_47
#define RG_GPIO_LCD_BCKL            GPIO_NUM_NC  // No backlight pin defined; tie high or add pin
#define RG_GPIO_LCD_RST             GPIO_NUM_48

// SPI SD Card (FSPI)
#define RG_GPIO_SDSPI_MISO          GPIO_NUM_40
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_39
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_41
#define RG_GPIO_SDSPI_CS            GPIO_NUM_38

// External I2S DAC (MAX98357A or similar)
#define RG_GPIO_SND_I2S_BCK         4
#define RG_GPIO_SND_I2S_WS          5
#define RG_GPIO_SND_I2S_DATA        6

// MCP23017 I2C input expander
// These are not standard Retro-Go defines — declare them for your BSP layer:
#define RG_GPIO_INPUT_SDA           GPIO_NUM_2
#define RG_GPIO_INPUT_SCL           GPIO_NUM_1
#define RG_GPIO_INPUT_INT           GPIO_NUM_42
#define RG_INPUT_MCP23017_ADDR      0x20
