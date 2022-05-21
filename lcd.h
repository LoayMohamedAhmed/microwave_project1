//datatypes definitions
  typedef unsigned char u8;
	typedef unsigned short int u16;
	typedef unsigned long  int u32;
	typedef signed char s8;
	typedef signed short int s16;
	typedef signed long  int s32;
	typedef float  f32;
	typedef double f64;
	
	
//prototypes definitions 
	void delay_ms(int t);
	void LCD_Cmd(unsigned char command);
	void lcd_write(u8 data);
  	void set_cursor(unsigned int x,unsigned int y) ;
 	 void Ports_Init ();
	void delay_micro();
	void LCD_printInt(int no);
	void lcd_print(u8 *str);
