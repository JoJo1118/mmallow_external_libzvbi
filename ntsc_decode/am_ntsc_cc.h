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



enum AM_CC_ErrorCode
{
	AM_CC_ERROR_BASE =0,
	AM_CC_ERR_INVALID_PARAM,   /**< ������Ч*/
	AM_CC_ERR_INVALID_HANDLE,  /**< �����Ч*/
	AM_CC_ERR_NOT_SUPPORTED,   /**< ��֧�ֵĲ���*/
	AM_CC_ERR_CREATE_DECODE,   /**< ��cc������ʧ��*/
	AM_CC_ERR_OPEN_PES,        /**< ��PESͨ��ʧ��*/
	AM_CC_ERR_SET_BUFFER,      /**< ����PES ������ʧ��*/
	AM_CC_ERR_NO_MEM,                  /**< �����ڴ治��*/
	AM_CC_ERR_CANNOT_CREATE_THREAD,    /**< �޷������߳�*/
	AM_CC_ERR_NOT_RUN,            /**< �޷������߳�*/
	AM_CC_INIT_DISPLAY_FAILED,    /**< ��ʼ����ʾ��Ļʧ��*/
	AM_CC_ERR_END
};


/****************************************************************************
 * Type definitions
 ***************************************************************************/
 /**\brief Teletext���������*/
typedef void* AM_NTSC_CC_Handle_t;

/**\brief ��ʼ����*/
typedef void (*AM_VBI_CC_DrawBegin_t)(AM_NTSC_CC_Handle_t handle);

/**\brief ��������*/
typedef void (*AM_VBI_CC_DrawEnd_t)(AM_NTSC_CC_Handle_t handle);

 typedef struct
{
	AM_VBI_CC_DrawBegin_t draw_begin;   /**< ��ʼ����*/
	AM_VBI_CC_DrawEnd_t   draw_end;     /**< ��������*/
	vbi_bool        is_subtitle;    /**< �Ƿ�Ϊ��Ļ*/
	uint8_t         *bitmap;         /**< ��ͼ������*/
	int              pitch;          /**< ��ͼ������ÿ���ֽ���*/
	void            *user_data;      /**< �û���������*/
}AM_NTSC_CC_Para_t;


extern vbi_bool AM_NTSC_Create(AM_NTSC_CC_Handle_t *handle, AM_NTSC_CC_Para_t *para);

extern  vbi_bool AM_NTSC_CC_Start(AM_NTSC_CC_Handle_t handle);

extern vbi_bool
decode_vbi		(int dev_no, int fid, const uint8_t *data, int len, void *user_data);

extern void* AM_VBI_CC_GetUserData(AM_NTSC_CC_Handle_t handle);

#ifdef __cplusplus
}
#endif



#endif
