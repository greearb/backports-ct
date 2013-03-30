--- a/drivers/net/usb/cdc_ether.c
+++ b/drivers/net/usb/cdc_ether.c
@@ -720,7 +720,9 @@
 	.resume =	usbnet_resume,
 	.reset_resume =	usbnet_resume,
 	.supports_autosuspend = 1,
+#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,5,0))
 	.disable_hub_initiated_lpm = 1,
+#endif
 };
 
 module_usb_driver(cdc_driver);