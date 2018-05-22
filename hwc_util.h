#ifndef _HWC_UTIL_
#define _HWC_UTIL_
#include <stdio.h>

#define CPU_CLUST0_GOV_PATH "/sys/devices/system/cpu/cpufreq/policy0/scaling_governor"
#define CPU_CLUST1_GOV_PATH "/sys/devices/system/cpu/cpufreq/policy4/scaling_governor"

//or /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq
#define CPU0_SCALING_MIN_FREQ "/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq"
//or /sys/devices/system/cpu/cpufreq/policy4/scaling_min_freq
#define CPU4_SCALING_MIN_FREQ "/sys/devices/system/cpu/cpu4/cpufreq/scaling_min_freq"

#if RK_CTS_WORKROUND
#define RK_CTS_DEBUG        (0)

#define VIEW_CTS_FILE           "/metadata/view_cts.ini"
#define AUTO_FILL_PROG_NAME     "android.autofillservice.cts"

#define VIEW_CTS_PROG_NAME      "android.view.cts"
#define VIEW_CTS_HINT           "view_cts"
#define BIG_SCALE_HINT          "big_scale"
#define IS_AUTO_FILL            "is_auto_fill"

typedef unsigned int       u32;
typedef enum
{
       IMG_STRING_TYPE         = 1,                    /*!< String type */
       IMG_FLOAT_TYPE          ,                       /*!< Float type */
       IMG_UINT_TYPE           ,                       /*!< Unsigned Int type */
       IMG_INT_TYPE            ,                       /*!< (Signed) Int type */
       IMG_FLAG_TYPE                               /*!< Flag Type */
}IMG_DATA_TYPE;
#endif

#define hwcMIN(x, y)			(((x) <= (y)) ?  (x) :  (y))
#define hwcMAX(x, y)			(((x) >= (y)) ?  (x) :  (y))
#define IS_ALIGN(val,align)    (((val)&(align-1))==0)
#ifndef ALIGN
#define ALIGN( value, base ) (((value) + ((base) - 1)) & ~((base) - 1))
#endif
#define ALIGN_DOWN( value, base)	(value & (~(base-1)) )

int hwc_get_int_property(const char* pcProperty,const char* default_value);
int hwc_get_string_property(const char* pcProperty,const char* default_value,char* retult);
int DetectValidData(int *data,int w,int h);
void ctl_cpu_performance(int on, int type);
void ctl_little_cpu(int on);
int set_cpu_min_freq(int freq);
#if RK_CTS_WORKROUND
bool FindAppHintInFile(FILE *regFile, const char *pszAppName,
                        const char *pszHintName, void *pReturn,IMG_DATA_TYPE eDataType);
#endif

#endif // _HWC_UTIL_
