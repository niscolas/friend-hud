#pragma once

#include "CoreMinimal.h"
#include "DefaultUserData.h"
#include "UObject/NoExportTypes.h"
#include "DefaultUserDataWrapper.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSourceDataChanged,
                                            FDefaultUserData,
                                            NewValue);

UCLASS(BlueprintType)

class FRIENDHUD_API UDefaultUserDataWrapper : public UObject {
    GENERATED_BODY()

public:
    static UDefaultUserDataWrapper *From(FDefaultUserData Data);

    FORCEINLINE FDefaultUserData &GetSourceData() {
        return SourceData;
    }

    FORCEINLINE void SetSourceData(FDefaultUserData Value) {
        SourceData = Value;
        SourceDataChanged.Broadcast(Value);
    }

private:
    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "User Data",
              meta = (AllowPrivateAccess))
    FDefaultUserData SourceData;

    UPROPERTY(BlueprintAssignable,
              Category = "User Data",
              meta = (AllowPrivateAccess))
    FSourceDataChanged SourceDataChanged;
};
