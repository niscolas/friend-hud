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
                     int PLevel,
                     EUserConnectionStateType PConnectionState,
                     FText PDescription)
        : Icon(PIcon), Name(PName), Level(PLevel),
          ConnectionState(PConnectionState), Description(PDescription){};

    FORCEINLINE EUserConnectionStateType GetConnectionState() const {
        return ConnectionState;
    }

    FORCEINLINE void
    SetConnectionState(EUserConnectionStateType PConnectionState) {
        ConnectionState = PConnectionState;
    }

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
    int Level;

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
