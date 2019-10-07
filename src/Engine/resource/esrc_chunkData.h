/*
 * ========================= esrc_chunkData.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.04.19
 *                                        MODIFY --
 * ----------------------------------------------------------
 */
#ifndef TPR_ESRC_CHUNK_DATA_H
#define TPR_ESRC_CHUNK_DATA_H

//-------------------- Engine --------------------//
#include "ChunkData.h"
#include "chunkKey.h"


namespace esrc {//------------------ namespace: esrc -------------------------//

void init_chunkDatas();

ChunkData &atom_insert_new_chunkData( chunkKey_t chunkKey_, IntVec2 chunkMPos_ );
void atom_erase_from_chunkDatas( chunkKey_t chunkKey_ );


ChunkData &atom_getnc_chunkDataCRef( chunkKey_t chunkKey_ );


bool atom_is_chunkDataFlags_empty();
void atom_push_back_2_chunkDataFlags( chunkKey_t chunkKey_ );
chunkKey_t atom_pop_from_chunkDataFlags();


}//---------------------- namespace: esrc -------------------------//
#endif

