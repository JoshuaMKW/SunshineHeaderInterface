#pragma once

#include <Dolphin/types.h>
#include <JSystem/J3D/J3DJoint.hxx>
#include <JSystem/J3D/J3DModel.hxx>
#include <JSystem/JDrama/JDRGraphics.hxx>
#include <JSystem/JDrama/JDRViewObj.hxx>
#include <SMS/M3DUtil/MActor.hxx>

class TJointObj {

public:
    u32 *vTable;
    u32 _4;
    u32 _8;
    J3DJoint *joint;          // _C
    u32 numChildJoints;       // _10
    TJointObj **childJoints;  // _14 (array of child joints, non-fixed size)
    u32 _18;
    u32 _1C;
};

class TJointModelManager : public JDrama::TViewObj {

public:
    u32 _10;
    u32 _14;
    u32 _18;
    char *modelName;        // _1C
    MActorAnmData anmData;  // _20
};

class TJointModel : public TJointObj {

public:
    TJointModelManager *mModelManager;  // _20
    J3DModelData *mModelData;           // _24
    J3DModel *mModel;                   // _28
    MActor *mActor;                     // _2C
};