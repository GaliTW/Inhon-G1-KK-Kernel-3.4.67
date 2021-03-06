#include <cust_leds.h>
#include <cust_leds_def.h>
#include <mach/mt_pwm.h>

#include <linux/kernel.h>
#include <mach/pmic_mt6329_hw_bank1.h> 
#include <mach/pmic_mt6329_sw_bank1.h> 
#include <mach/pmic_mt6329_hw.h>
#include <mach/pmic_mt6329_sw.h>
#include <mach/upmu_common_sw.h>
#include <mach/upmu_hw.h>

extern int mtkfb_set_backlight_level(unsigned int level);
extern int mtkfb_set_backlight_pwm(int div);
extern void hwBacklightFlashlightTuning(kal_uint32 duty, kal_uint32 mode);
extern void hwBacklightFlashlightTurnOn(void);
extern void hwBacklightFlashlightTurnOff(void);
extern void upmu_flash_step_sel(kal_uint32 val);
extern void upmu_flash_mode_select(kal_uint32 val);
extern void upmu_flash_dim_duty(kal_uint32 val);

#define CLEDS "[CUST_LEDS]"
#define CLED_INFO(fmt, arg...)    printk(KERN_INFO CLEDS "%s: " fmt, __FUNCTION__ ,##arg)

#define ERROR_BL_LEVEL 0xFFFFFFFF

unsigned int brightness_mapping(unsigned int level)
{
	unsigned int mapped_level;
    
	mapped_level = level;
       
	return mapped_level;
}

unsigned int Cust_SetBacklight(int level, int div)
{
	// CLED_INFO( "level=%d", level ) ;
	mtkfb_set_backlight_level(brightness_mapping(level));
	return 0;
}

unsigned int Cust_SetTorch(int level)
{
	// CLED_INFO( "%d", level ) ;
	if ( level <= 0 ) hwBacklightFlashlightTurnOff() ;
	else hwBacklightFlashlightTurnOn() ;
	return 0;
}

static struct cust_mt65xx_led cust_led_list[MT65XX_LED_TYPE_TOTAL] = {
	{"red",               MT65XX_LED_MODE_NONE, -1,{0}},
	{"green",             MT65XX_LED_MODE_NONE, -1,{0}},
	{"blue",              MT65XX_LED_MODE_NONE, -1,{0}},
	{"jogball-backlight", MT65XX_LED_MODE_NONE, -1,{0}},
	{"keyboard-backlight",MT65XX_LED_MODE_NONE, -1,{0}},
	{"button-backlight",  MT65XX_LED_MODE_NONE, -1,{0}},
	{"lcd-backlight",     MT65XX_LED_MODE_CUST_LCM, (int)Cust_SetBacklight,{0}},
	{"torch",             MT65XX_LED_MODE_CUST, (int)Cust_SetTorch,{0}},

};

struct cust_mt65xx_led *get_cust_led_list(void)
{
	return cust_led_list;
}
