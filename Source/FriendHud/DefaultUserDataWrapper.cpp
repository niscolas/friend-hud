#include "DefaultUserDataWrapper.h"
#include "DefaultUserData.h"

UDefaultUserDataWrapper *UDefaultUserDataWrapper::From(FDefaultUserData Data) {
    UDefaultUserDataWrapper *Instance = NewObject<UDefaultUserDataWrapper>();
    Instance->SourceData = Data;
    return Instance;
}
