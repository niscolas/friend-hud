#pragma once

#include "CoreMinimal.h"
#include "DefaultUserData.h"
#include "UObject/NoExportTypes.h"
#include "DefaultUserDataWrapper.generated.h"

UCLASS(BlueprintType)

class FRIENDHUD_API UDefaultUserDataWrapper : public UObject {
    GENERATED_BODY()

public:
    static UDefaultUserDataWrapper *From(FDefaultUserData Data);

private:
    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "User Data",
              meta = (AllowPrivateAccess))
    FDefaultUserData SourceData;
};
