/*
 * This software is contributed or developed by KYOCERA Corporation.
 * (C) 2017 KYOCERA Corporation
 * (C) 2018 KYOCERA Corporation
 */


#ifndef CYTTSP5_DISPLAY
#define CYTTSP5_DISPLAY
#define CONFIG_INCELL_TOUCH

#ifdef CONFIG_INCELL_TOUCH
extern int cyttsp5_display_watchdog(void *cyttsp5_data);
extern int cyttsp5_display_suspend(void *cyttsp5_data, int order);
extern int cyttsp5_display_resume(void *cyttsp5_data, int order);
extern void cyttsp5_display_set_easywake_mode(void *cyttsp5_data, int easywake_mode);
#endif

#endif
