// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


// Description: Definitions and implementations of things defined in the
//              readonly autoingest library that need to behave differently
//              in the read only clients than they do in the system manager.


#include "AssetThrowPolicy.h"
#include "Asset.h"
#include "AssetVersion.h"
#include <khVolumeManager.h>


// ****************************************************************************
// ***  Asset Handle & Cache Stuff
// ***
// ***  see sysman/SysManExtra.cpp for the system manager definitions
// ****************************************************************************
template <>
const bool AssetHandle_<AssetImpl>::check_timestamps(true);

template <>
const bool AssetHandle_<AssetVersionImpl>::check_timestamps(true);

bool AssetThrowPolicy::allow_throw(false);


// ****************************************************************************
// ***  theVolumeManager
// ***
// ***  see sysman/khResourceManager.cpp for the system manager definition
// ****************************************************************************
static khVolumeManager instance;
khVolumeManager &theVolumeManager(instance);
