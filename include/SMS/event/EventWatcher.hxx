#pragma once

#include <Dolphin/types.h>

#include <JSystem/JDrama/JDRGraphics.hxx>
#include <JSystem/JDrama/JDRViewObj.hxx>
#include <SMS/spc/SpcTypedBinary.hxx>

class TEventWatcher : public JDrama::TViewObj {
public:
    TEventWatcher(const char *, const char *);
    TEventWatcher(const char *);
    virtual ~TEventWatcher();

    virtual void perform(u32, JDrama::TGraphics *);
    virtual void launchScript(const char *);

    TSpcTypedBinary<TEventWatcher> *_10;
    TSpcTypedBinary<TEventWatcher> *_14;
};

char *sShineViewObjName;