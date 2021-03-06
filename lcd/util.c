#include <util/delay.h>
#include "defines.h"
#include "ctrl.h"
#include "data.h"
#include "util.h"

uint8_t _lcd_read(uint8_t rs) {
	_lcd_set_ctrl_mode(LCD_MODE_WRITE);
	_lcd_set_data_mode(LCD_MODE_READ);

	_lcd_set_ctrl(rs, LCD_REG_READ, 1);
	_delay_us(5);

	_lcd_set_ctrl(rs, LCD_REG_READ, 0);
	_delay_us(5);

	return _lcd_get_data();
	
}

void _lcd_write(uint8_t rs, uint8_t val) {
	_lcd_set_ctrl_mode(LCD_MODE_WRITE);
	_lcd_set_data_mode(LCD_MODE_WRITE);

	_lcd_set_ctrl(rs, LCD_REG_WRITE, 1);
	_lcd_set_data(val);
	_delay_us(5);

	_lcd_set_ctrl(rs, LCD_REG_WRITE, 0);

	_delay_ms(5);

	return;
}

void _lcd_wait(void) {
	while(_lcd_read(LCD_REG_CTRL) & LCD_MASK_BF);

	return;
}
