/*
 * This software is contributed or developed by KYOCERA Corporation.
 * (C) 2018 KYOCERA Corporation
 */

#ifndef __UAPI_LINUX_MSM_CAM_SENSOR_KC_H
#define __UAPI_LINUX_MSM_CAM_SENSOR_KC_H

#define MAX_CONFIG_NAME 100

struct msm_config_xml_info_t {
	int config_count;
	char cam_config_name[4][MAX_CONFIG_NAME];
	char cam_sensor_name[4][32];
	int cam_type[4]; // 0:out 1:in 2:wide
};

#define CFG_SINIT_CONFIG_XML_NAME 100

#endif
