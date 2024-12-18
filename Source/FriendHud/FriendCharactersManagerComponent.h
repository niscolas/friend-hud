#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "FriendsListControllerComponent.h"
#include "FriendCharactersManagerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class FRIENDHUD_API UFriendCharactersManagerComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UFriendCharactersManagerComponent();

private:
    virtual void BeginPlay() override;

    virtual void
    TickComponent(float DeltaTime,
                  ELevelTick TickType,
                  FActorComponentTickFunction *ThisTickFunction) override;

    UPROPERTY(VisibleAnywhere,
              BlueprintReadOnly,
              Category = "Friends",
              meta = (AllowPrivateAccess))
    UFriendsListControllerComponent *FriendsListControllerComponent;
};
