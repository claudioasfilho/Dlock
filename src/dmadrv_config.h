/***************************************************************************//**
 * @file
 * @brief Provide stdio retargeting configuration parameters.
 * @version 4.0.0
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#ifndef __SILICON_LABS_DMADRV_CONFIG_H__
#define __SILICON_LABS_DMADRV_CONFIG_H__

// DMADRV DMA interrupt priority configuration option.
// Set DMA interrupt priority. Range is 0..7, 0 is highest priority.
#define EMDRV_DMADRV_DMA_IRQ_PRIORITY 0
#define EMDRV_DMADRV_DMA_CH_PRIORITY 0

// DMADRV channel count configuration option.
// Number of DMA channels to support. A lower DMA channel count will reduce
// ram memory footprint.
#define EMDRV_DMADRV_DMA_CH_COUNT 1

// DMADRV native API configuration option.
// Use the native emlib api of the DMA controller, but still use DMADRV
// housekeeping functions as AllocateChannel/FreeChannel etc.
//#define EMDRV_DMADRV_USE_NATIVE_API

#endif
