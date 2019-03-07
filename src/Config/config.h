/*
 * ========================= config.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2018.11.21
 *                                        MODIFY --
 * ----------------------------------------------------------
 *   配置 参数
 *   临时，后期会更换为 lua 来实现
 * ----------------------------
 */
#ifndef _TPR_CONFIG_H_
#define _TPR_CONFIG_H_

//-- window 显示尺寸（像素）--
//   拉升窗口将会改变这个值
//#define SCR_WIDTH  880 //- 早期版，游戏标配窗口大小
//#define SCR_HEIGHT  660
#define SCR_WIDTH  1280  //- 为了配合生态建设 设置的窗口大小。
#define SCR_HEIGHT  1280

//-- 游戏工作尺寸（游戏像素）--
//   由于是 pixel游戏，所以这个值会很小。
//   这个值 也是 Camera 的尺寸
//-- 目前版本中，拉升窗口并不会改变这个值。（后期应实现 自动匹配）
//-- 请尽量确保此变量 与 SCR_WIDTH／SCR_HEIGHT 等比例
//--:
//#define WORK_WIDTH  220 //- 早期版，游戏标配窗口大小
//#define WORK_HEIGHT 165
#define WORK_WIDTH  1280  //- 在 1280*1280 尺寸下，能显示一张完整的 section(256,256)
#define WORK_HEIGHT 1280  //- 仅用在 生态群落 建设阶段


//-- 是否开启 全屏模式 --
inline bool IS_FULL_SCREEN = false; 


//-- 一个 mapSection 占有 256*256 个 mapEnt
//  由于 section 始终是正方形，仅记录一条边的边长（包含多少个 mapents）
//#define SECTION_SIDE_ENTS 256



//-- 一个 section，占有 4*4 chunks
#define CHUNKS_PER_SECTION 4

//-- 一个 chunk，占有 16*16 fields
#define FIELDS_PER_CHUNK  16

//-- 一个 field，占有 4*4 mapents
#define ENTS_PER_FIELD 4

//-- 一个 mapent 占用 5*5像素
#define PIXES_PER_MAPENT  5
#define HALF_PIXES_PER_MAPENT 2.5
//-- 求 mpos 中间pixel的 ppos 时用到
#define MID_PPOS_IDX_IN_MAPENT 2 


//-- 一个 chunk，占有 64*64 mapents
#define ENTS_PER_CHUNK (FIELDS_PER_CHUNK*ENTS_PER_FIELD)

//-- 一个 section，占有 256*256 mapEnts
#define ENTS_PER_SECTION  (ENTS_PER_CHUNK*CHUNKS_PER_SECTION)

//-- 一个 field，占有 20*20 pixel
#define PIXES_PER_FIELD (ENTS_PER_FIELD*PIXES_PER_MAPENT)

//-- 一个 chunk，占有 320*320 pixel
#define PIXES_PER_CHUNK (ENTS_PER_CHUNK*PIXES_PER_MAPENT)


//-- camera.viewingBox z_deep
#define VIEWING_BOX_Z_DEEP  1000



#endif
