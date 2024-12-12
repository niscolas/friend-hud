#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "DefaultUserData.h"
#include "DefaultUserDataWrapper.h"
#include "FriendsListDataAsset.h"
#include "FriendsListControllerComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDatabaseStateChanged);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class FRIENDHUD_API UFriendsListControllerComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UFriendsListControllerComponent();

    UFUNCTION(BlueprintPure, Category = "Friend List")
    TArray<UDefaultUserDataWrapper *> GetDatabaseAsUObjects() const;

private:
    virtual void BeginPlay() override;
    virtual void
    TickComponent(float DeltaTime,
                  ELevelTick TickType,
                  FActorComponentTickFunction *ThisTickFunction) override;

    UPROPERTY(VisibleAnywhere,
              BlueprintReadOnly,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    TArray<FDefaultUserData> Database;

    UPROPERTY(BlueprintAssignable,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    FDatabaseStateChanged DatabaseStateChanged;
};
