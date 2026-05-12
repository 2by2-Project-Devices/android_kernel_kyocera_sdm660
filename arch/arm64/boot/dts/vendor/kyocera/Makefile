ifeq ($(CONFIG_BUILD_ARM64_DT_OVERLAY),y)
dtbo-$(CONFIG_ARCH_SDM660) +=  sdm630-TSUBAKI02-rev00-overlay.dtbo \
                               sdm630-TSUBAKI02-rev10-overlay.dtbo \
                               sdm630-TSUBAKI02-rev20-overlay.dtbo \
                               sdm660-TSUBAKI03-rev10-overlay.dtbo \
                               sdm660-TSUBAKI03-rev20-overlay.dtbo

sdm630-TSUBAKI02-rev00-overlay.dtbo-base := sdm630-TSUBAKI02-rev00.dtb
sdm630-TSUBAKI02-rev10-overlay.dtbo-base := sdm630-TSUBAKI02-rev10.dtb
sdm630-TSUBAKI02-rev20-overlay.dtbo-base := sdm630-TSUBAKI02-rev20.dtb
sdm660-TSUBAKI03-rev10-overlay.dtbo-base := sdm660-TSUBAKI03-rev10.dtb
sdm660-TSUBAKI03-rev20-overlay.dtbo-base := sdm660-TSUBAKI03-rev20.dtb

else
dtb-$(CONFIG_ARCH_SDM660) += sdm630-SAKURA00-rev00.dtb \
                             sdm630-SAKURA01-rev10.dtb \
                             sdm630-SAKURA01-rev20.dtb \
                             sdm630-SAKURA02-rev10.dtb \
                             sdm630-TSUBAKI00-rev00.dtb \
                             sdm630-TSUBAKI00-rev11.dtb \
                             sdm630-TSUBAKI00-rev13.dtb \
                             sdm630-TSUBAKI00-rev14.dtb \
                             sdm630-TSUBAKI00-rev15.dtb \
                             sdm630-TSUBAKI01-rev11.dtb \
                             sdm630-TSUBAKI01-rev12.dtb \
                             sdm660-TSUBAKI03-rev10.dtb \
                             sdm660-TSUBAKI03-rev20.dtb

dtb-$(CONFIG_ARCH_SDM660) += sdm630-TSUBAKI02-rev00.dtb
dtb-$(CONFIG_ARCH_SDM660) += sdm630-TSUBAKI02-rev10.dtb
dtb-$(CONFIG_ARCH_SDM660) += sdm630-TSUBAKI02-rev20.dtb
endif

always          := $(dtb-y)
subdir-y        := $(dts-dirs)
clean-files := *.dtb
