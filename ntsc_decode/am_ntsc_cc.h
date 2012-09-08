/***************************************************************************
 *  Copyright C 2009 by Amlogic, Inc. All Rights Reserved.
 */
/**\file
 * \brief Teletextģ��(version 2)
 *
 * \author kui.zhang <kui.zhang@amlogic.com>
 * \date 2012-09-03: create the document
 ***************************************************************************/



#ifndef _AM_NTSC_CC_H
#define _AM_NTSC_CC_H


#include <unistd.h>
#include "misc.h"
#include "trigger.h"
#include "format.h"
#include "lang.h"
#include "hamm.h"
#include "tables.h"
#include "vbi.h"
#include <android/log.h>    
#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************
 * Type definitions
 ***************************************************************************/
 /**\brief Teletext���������*/
typedef void* AM_NTSC_CC_Handle_t;

/**\brief ��ʼ����*/
typedef void (*AM_TT2_DrawBegin_t)(AM_NTSC_CC_Handle_t handle);

/**\brief ��������*/
typedef void (*AM_TT2_DrawEnd_t)(AM_NTSC_CC_Handle_t handle);

 typedef struct
{
	AM_TT2_DrawBegin_t draw_begin;   /**< ��ʼ����*/
	AM_TT2_DrawEnd_t   draw_end;     /**< ��������*/
	vbi_bool        is_subtitle;    /**< �Ƿ�Ϊ��Ļ*/
	uint8_t         *bitmap;         /**< ��ͼ������*/
	int              pitch;          /**< ��ͼ������ÿ���ֽ���*/
	void            *user_data;      /**< �û���������*/
}AM_NTSC_CC_Para_t;


extern vbi_bool AM_NTSC_Create(AM_NTSC_CC_Handle_t *handle, AM_NTSC_CC_Para_t *para);

extern  vbi_bool AM_NTSC_CC_Start(AM_NTSC_CC_Handle_t handle);



#ifdef __cplusplus
}
#endif



#endif
