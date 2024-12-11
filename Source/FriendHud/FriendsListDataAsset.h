#pragma once

#include "CoreMinimal.h"
#include "DefaultUserData.h"
#include "Engine/DataAsset.h"
#include "FriendsListDataAsset.generated.h"

UCLASS()

class FRIENDHUD_API UFriendsListDataAsset : public UPrimaryDataAsset {
    GENERATED_BODY()

public:
    FORCEINLINE TArray<FDefaultUserData> GetContent() const {
        return Content;
    }

private:
    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    TArray<FDefaultUserData> Content;
};
