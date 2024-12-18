#pragma once

#include "CoreMinimal.h"
#include "FriendHud/DefaultUserDataWrapper.h"
#include "UObject/Interface.h"
#include "FriendCharacter.generated.h"

UINTERFACE(MinimalAPI)

class UFriendCharacter : public UInterface {
    GENERATED_BODY()
};

class FRIENDHUD_API IFriendCharacter {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent,
              BlueprintCallable,
              Category = "Friend Character")
    void Setup(UDefaultUserDataWrapper *UserData);
};
