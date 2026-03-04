/*
 * LCD_interface.h
 *
 * Created: 9/13/2025 9:31:05 AM
 * Author: HASSAN ARIF
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*===========================================
  LCD Configuration Macros
===========================================*/

/*
 * LCD_4BITMODE: Use 4 data lines (D4–D7) for communication.
 * LCD_8BITMODE: Use all 8 data lines (D0–D7) for communication.
 */
#define LCD_4BITMODE        1
#define LCD_8BITMODE        0

/*
 * LCD_MODE: Select the desired communication mode.
 *           Set to LCD_4BITMODE or LCD_8BITMODE.
 */
#define LCD_MODE            LCD_4BITMODE

/*===========================================
  LCD Function Prototypes
===========================================*/

/*****************
* Function Name : LCD_voidInit
* Description   : Initializes the LCD by setting pin directions and sending
*                 required configuration commands (e.g. 2-line mode, cursor off).
* Parameters    : void
* Return        : void
*****************/
void LCD_voidInit(void);

/*****************
* Function Name : LCD_voidSendCommand
* Description   : Sends a command to the LCD (e.g. clear screen, move cursor).
* Parameters    : 
*   - copy_u8command : Command byte to send.
* Return        : void
*****************/
void LCD_voidSendCommand(u8 copy_u8command);

/*****************
* Function Name : LCD_voidSendData
* Description   : Sends a single character to be displayed on the LCD.
* Parameters    : 
*   - copy_u8data : ASCII character to display.
* Return        : void
*****************/
void LCD_voidSendData(u8 copy_u8data);

/*****************
* Function Name : LCD_voidSendString
* Description   : Sends a string to the LCD (displays characters sequentially).
* Parameters    : 
*   - str : Pointer to null-terminated string.
* Return        : void
*****************/
void LCD_voidSendString(char *str);

/*****************
* Function Name : LCD_voidSendNumber
* Description   : Converts an unsigned 32-bit integer to its decimal
*                 representation and sends each digit to the LCD.
* Parameters    :
*   - copy_u32num : The 32-bit unsigned number to display on the LCD.
* Return        : void
*****************/
void LCD_voidSendNumber(u32 copy_u32num);

/*****************
* Function Name : LCD_voidGoToxy
* Description   : Moves the LCD cursor to a specific position on the screen
*                 based on the given row (x) and column (y).
* Parameters    :
*   - copy_u8x : Row number (0 for first row, 1 for second row, etc.).
*   - copy_u8y : Column number (0 to 15 for standard 16x2 LCD).
* Return        : void
*****************/
void LCD_voidGoToxy(u8 copy_u8x , u8 copy_u8y);

/*****************
* Function Name : LCD_voidDrawData
* Description   : Creates and displays a custom character pattern on the LCD.
*                 The pattern is stored in CGRAM and displayed at the specified
*                 position.
* Parameters    :
*   - copy_u8pattern : CGRAM location (0 to 7) to store the custom character.
*   - copy_u8data    : Pointer to an array of 8 bytes representing the character.
*   - copy_u8x       : Row number where the character will be displayed.
*   - copy_u8y       : Column number where the character will be displayed.
* Return        : void
*****************/
void LCD_voidDrawData(u8 copy_u8pattern, u8 *copy_u8data, u8 copy_u8x , u8 copy_u8y);
/*****************
* Function Name : LCD_voidSendRealNumber
* Description   : Converts a floating-point number into its string representation
*                 (integer part and fractional part) and sends it to the LCD
*                 for display.
* Parameters    :
*   - copy_f32realnumber : The floating-point number to display on the LCD.
* Return        : void
*****************/
void LCD_voidSendRealNumber(f32 copy_f32realnumber);


#endif /* LCD_INTERFACE_H_ */