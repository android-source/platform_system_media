/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* \file COutputMix.c OutputMix class */

#include "sles_allinclusive.h"


/** \brief Hook called by Object::Realize when an output mix is realized */

SLresult COutputMix_Realize(void *self, SLboolean async)
{
    SLresult result = SL_RESULT_SUCCESS;

#ifdef ANDROID
    COutputMix *this = (COutputMix *) self;
    result = android_outputMix_realize(this, async);
#endif

    return result;
}


/** \brief Hook called by Object::Resume when an output mix is resumed */

SLresult COutputMix_Resume(void *self, SLboolean async)
{
    return SL_RESULT_SUCCESS;
}


/** \brief Hook called by Object::Destroy when an output mix is destroyed */

void COutputMix_Destroy(void *self)
{

#ifdef ANDROID
    COutputMix *this = (COutputMix *) self;
    android_outputMix_destroy(this);
#endif
}


/** \brief Hook called by Object::Destroy before an output mix is about to be destroyed */

bool COutputMix_PreDestroy(void *self)
{
    return true;
}