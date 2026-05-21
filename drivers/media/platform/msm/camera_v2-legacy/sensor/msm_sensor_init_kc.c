/*
 * This software is contributed or developed by KYOCERA Corporation.
 * (C) 2018 KYOCERA Corporation
 */

/* Header files */
#include "msm_sensor.h"

/* Logging macro */
#undef CDBG
#define CDBG(fmt, args...) pr_debug(fmt, ##args)

int32_t msm_sensor_config_xml_name_kc(void *config_xml_info) {
	struct device_node *np;
	struct msm_config_xml_info_t xml;
	int32_t rc = 0;
	int i = 0;
	const char *val_string;
	int maxcount = 0;

	np = of_find_compatible_node(NULL, NULL, "kc,cam-conf");
	if (!np) {
		pr_err("find node failed");
		return -EINVAL;
	}

	memset(&xml, 0, sizeof(xml));

	if (of_property_read_u32(np, "conf-count", &xml.config_count)) {
		pr_err("read property failed");
		return -EINVAL;
	}

	maxcount = sizeof(xml.cam_config_name) / sizeof(xml.cam_config_name[0]);
	if(xml.config_count > maxcount){
		pr_err("config_count Invalid value %d", xml.config_count);
		xml.config_count = maxcount;
	}

	CDBG("%s rc = %d conf-count = %d", __func__, rc, xml.config_count);

	rc = of_property_read_u32_array(np, "cam-types", xml.cam_type, xml.config_count);

	if (rc != 0) {
		pr_err("%s rc = %d cam-types read failed!", __func__, rc);
		return -EINVAL;
	}

	for (i = 0; i < xml.config_count; i++) {
		val_string = NULL;

		rc = of_property_read_string_index(np, "conf-names", i,	&val_string);
		if ((rc == 0) && (val_string != NULL)) {
			strncpy(xml.cam_config_name[i], val_string, MAX_CONFIG_NAME);
		} else {
			pr_err("%s rc = %d conf-names[%d] read failed!", __func__, rc, i);
			return -EINVAL;
		}

		rc = of_property_read_string_index(np, "sensor-names", i, &val_string);
		if ((rc == 0) && (val_string != NULL)) {
			strncpy(xml.cam_sensor_name[i], val_string, MAX_SENSOR_NAME);
		} else {
			pr_err("%s rc = %d sensor-names[%d] read failed!", __func__, rc, i);
			return -EINVAL;
		}

		CDBG("%s xml.cam_config_name[%d] = %s",	__func__, i, xml.cam_config_name[i]);
		CDBG("%s xml.cam_sensor_name[%d] = %s",	__func__, i, xml.cam_sensor_name[i]);
		CDBG("%s xml.cam_type[%d] = %d", __func__, i, xml.cam_type[i]);
	}

	rc = copy_to_user(config_xml_info, &xml, sizeof(xml));
	if (rc != 0) {
		pr_err("%s copy_to_user failed rc = %d", __func__, rc);
	}
	return rc;
}
