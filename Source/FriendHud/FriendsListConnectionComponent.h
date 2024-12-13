#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "FriendsListControllerComponent.h"
#include "FriendsListConnectionComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class FRIENDHUD_API UFriendsListConnectionComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UFriendsListConnectionComponent();

private:
    virtual void BeginPlay() override;

    virtual void
    TickComponent(float DeltaTime,
                  ELevelTick TickType,
                  FActorComponentTickFunction *ThisTickFunction) override;

    UPROPERTY(VisibleAnywhere,
              BlueprintReadOnly,
              Category = "Friends List|Connection",
              meta = (AllowPrivateAccess))
    UFriendsListControllerComponent *FriendsListControllerComponent;
};
