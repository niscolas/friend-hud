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

    FORCEINLINE const FDefaultUserData &GetSourceData() const {
        return SourceData;
    }

    FORCEINLINE void SetSourceData(FDefaultUserData Value) {
        SourceData = Value;
        SourceDataChanged.Broadcast(Value);
    }

    FORCEINLINE EUserConnectionStateType GetConnectionState() {
        return SourceData.GetConnectionState();
    }

    FORCEINLINE void
    SetConnectionState(EUserConnectionStateType PConnectionState) {
        SourceData.SetConnectionState(PConnectionState);
        SourceDataChanged.Broadcast(SourceData);
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
