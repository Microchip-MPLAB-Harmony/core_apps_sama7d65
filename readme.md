![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Harmony 3 driver and system service application examples for SAMA7D65 family

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices.  Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 driver and system service application examples for SAMA7D65 family

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](Microchip_SLA001.md)

To clone or download these applications from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sama7d65) and then click **Clone**<br /> button to clone this repository or download as zip file. This content can also be<br /> downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

## Contents Summary

|Folder|Description|
|:-----|:----------|
|apps|Contains driver and system service<br /> example applications|
|docs|Contains documentation in html<br /> format for offline viewing \(to be used only after cloning this<br /> repository onto a local machine\). Use [github pages](https://microchip-mplab-harmony.github.io/) of this repository for<br /> viewing it online.|

## Code Examples

The following applications are provided to demonstrate the typical or interesting<br /> usage models of one or more peripheral libraries.

|Name|Description|
|----|-----------|
|[FAT Filesystem using SDMMC Media](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-B5563423-281A-403C-9C2F-CE8590A82DD7.html)|This<br /> application shows an example of using the MPLAB Harmony File<br /> System to access and modify the contents of a SD card using the<br /> SDMMC driver|
|[FAT Filesystem using SQI Flash Media](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-E5C6EED2-CF9A-449C-BE44-E419138CA940.html)|This<br /> application shows an example of using the MPLAB Harmony File<br /> System to access SQI based flash media|
|[FreeRTOS Basic](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-048E1CE7-8796-45A5-821C-10E5FA32289A.html)|This<br /> example application demonstrates context switching between four<br /> tasks of different priorities. Two tasks run periodically while<br /> the other two tasks are event driven|
|[I2C Driver Asynchronous - I2C EEPROM](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-689CC2BF-B7D5-407D-93A2-5DB38DDC3A14.html)|This<br /> example application shows how to use the I2C driver in<br /> asynchronous mode to perform operations on the EEPROM|
|[I2C Driver Synchronous - I2C EEPROM](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-F19CCFFA-E474-4C03-8245-97903530F087.html)|This<br /> example application shows how to use the I2C driver in<br /> synchronous mode to perform operations on the EEPROM|
|[I2C EEPROM AT24 Driver - EEPROM Read Write](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-628B7B9A-1977-4E94-90E6-480C12BA1103.html)|This<br /> example application shows how to use the AT24 driver to perform<br /> read and write operations on AT24 series of EEPROM|
|[SPI Driver Asynchronous - Multi Client](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-14BFF118-3ADC-4DAB-88C0-91419A5670DF.html)|This<br /> example demonstrates how to use single instance of the SPI<br /> driver in asynchronous mode to communicate with multiple<br /> EEPROMs|
|[SPI Driver Synchronous - Multi Client](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-9C095771-E17E-4C45-B77C-59577E4C603D.html)|This<br /> example demonstrates how to use single instance of the SPI<br /> driver in synchronous mode to communicate with multiple EEPROMs<br /> in an RTOS environment|
|[SPI EEPROM AT25 Driver - EEPROM Read Write](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-5E414246-76C7-4A15-A275-CCF8E892FDCE.html)|This<br /> example application shows how to use the AT25 driver to perform<br /> read and write operations on AT25 series of EEPROM|
|[Time System Service Multi-client](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-EAFAB6F6-932C-4107-8997-9BA48821927F.html)|This<br /> example application demonstrates the multi-client system timer<br /> functionality|
|[USART Driver Asynchronous - USART Echo](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-C74930DE-0C6C-42BB-9E5F-08223BEB4924.html)|This<br /> example echoes the received characters over the console using<br /> the USART driver in asynchronous mode|
|[USART Driver Synchronous - USART Echo](https://microchip-mplab-harmony.github.io/core_apps_sama7d65/GUID-2E16A61D-B945-42B6-98B4-FA0E92C7DF69.html)|This<br /> example echoes the received characters over the console using<br /> the USART driver in synchronous mode|

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/core_apps_sama7d65/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/core_apps_sama7d65.svg)](https://github.com/Microchip-MPLAB-Harmony/core_apps_sama7d65/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/core_apps_sama7d65.svg)](https://github.com/Microchip-MPLAB-Harmony/core_apps_sama7d65/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/core_apps_sama7d65.svg)](https://github.com/Microchip-MPLAB-Harmony/core_apps_sama7d65/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/core_apps_sama7d65.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/core_apps_sama7d65.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/core_apps_sama7d65.svg?style=social)]()


