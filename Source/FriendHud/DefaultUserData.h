#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DefaultUserData.generated.h"

UENUM(BlueprintType)
enum class EUserConnectionStateType : uint8 {
    Offline UMETA(DisplayName = "Offline"),
    Online UMETA(DisplayName = "Online"),
};

USTRUCT(BlueprintType)

struct FRIENDHUD_API FDefaultUserData {
    GENERATED_BODY()

public:
    FDefaultUserData(){};
    FDefaultUserData(UTexture2D *PIcon,
                     FString PName,
                     EUserConnectionStateType PConnectionState,
                     FText PDescription)
        : Icon(PIcon), Name(PName), ConnectionState(PConnectionState),
          Description(PDescription){};

private:
    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "User Data",
              meta = (AllowPrivateAccess))
    UTexture2D *Icon;

    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "User Data",
              meta = (AllowPrivateAccess))
    FString Name;

    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "User Data",
              meta = (AllowPrivateAccess))
    EUserConnectionStateType ConnectionState;

    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "User Data",
              meta = (AllowPrivateAccess))
    FText Description;
};