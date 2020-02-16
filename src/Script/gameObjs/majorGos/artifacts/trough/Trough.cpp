/*
 * ========================= Trough.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.11.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "Script/gameObjs/majorGos/artifacts/trough/Trough.h"

//-------------------- CPP --------------------//
#include <functional>
#include <string>

//-------------------- Lib --------------------//
#include "tprGeneral.h"

//-------------------- Engine --------------------//
#include "tprAssert.h"
#include "Density.h"
#include "animSubspeciesId.h"
#include "dyParams.h"

#include "esrc_shader.h" 
#include "esrc_animFrameSet.h"

//-------------------- Script --------------------//


using namespace std::placeholders;

#include "tprDebug.h" 


namespace gameObjs {//------------- namespace gameObjs ----------------


struct Trough_PvtBinary{
    int   tmp {};
};



void Trough::init(GameObj &goRef_,const DyParam &dyParams_ ){


    //================ go.pvtBinary =================//
    auto *pvtBp = goRef_.init_pvtBinary<Trough_PvtBinary>();

    //================ dyParams =================//
    size_t typeHash = dyParams_.get_typeHash();
    tprAssert( typeHash == typeid(DyParams_Blueprint).hash_code() );
    const DyParams_Blueprint *bpParamPtr = dyParams_.get_binaryPtr<DyParams_Blueprint>();
    const GoDataForCreate *goDataPtr = bpParamPtr->goDataPtr;
    tprAssert( goDataPtr->isMultiGoMesh ); // must multi gomesh

    //----- must before creat_new_goMesh() !!! -----//
    goRef_.actionDirection.reset( goDataPtr->direction );

    if( auto retOpt = goDataPtr->get_brokenLvl(); retOpt.has_value() ){
        goRef_.brokenLvl.reset( retOpt.value() );
    }else{
        tprAssert(0);
    }

    //----- gomeshs -----//
    for( const auto &uptrRef : goDataPtr->goMeshDataUPtrs ){
        const GoDataEntForCreate &goDataEntRef = *uptrRef;

        auto &goMeshRef = goRef_.creat_new_goMesh( 
                                goDataEntRef.goMeshName,
                                goDataEntRef.subspeciesId,
                                goDataEntRef.animActionEName,
                                RenderLayerType::MajorGoes, //- 不设置 固定zOff值
                                &esrc::get_shaderRef(ShaderType::UnifiedColor),  // pic shader
                                goDataEntRef.dposOff, //- pposoff
                                goDataEntRef.zOff,  //- zOff
                                true //- isVisible
                                );
    }    

    //================ bind callback funcs =================//
    //-- 故意将 首参数this 绑定到 保留类实例 dog_a 身上
    goRef_.RenderUpdate = std::bind( &Trough::OnRenderUpdate,  _1 );   
    goRef_.LogicUpdate  = std::bind( &Trough::OnLogicUpdate,   _1 );

    //-------- actionSwitch ---------//
    goRef_.actionSwitch.bind_func( std::bind( &Trough::OnActionSwitch,  _1, _2 ) );
    goRef_.actionSwitch.signUp( ActionSwitchType::Idle );


    //================ go self vals =================//   

}


void Trough::OnRenderUpdate( GameObj &goRef_ ){
    //=====================================//
    //            ptr rebind
    //-------------------------------------//
    //auto *pvtBp = goRef_.get_pvtBinaryPtr<Trough_PvtBinary>();

    //=====================================//
    //  将 确认要渲染的 goMeshs，添加到 renderPool         
    //-------------------------------------//
    goRef_.render_all_goMesh();
}



void Trough::bind( GameObj &goRef_ ){}
void Trough::rebind( GameObj &goRef_ ){}
void Trough::OnLogicUpdate( GameObj &goRef_ ){}

void Trough::OnActionSwitch( GameObj &goRef_, ActionSwitchType type_ ){
        cout << "Trough::OnActionSwitch" << endl;
        tprAssert(0);
}




}//------------- namespace gameObjs: end ----------------
