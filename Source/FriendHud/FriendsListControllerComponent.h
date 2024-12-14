#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "DefaultUserData.h"
#include "DefaultUserDataWrapper.h"
#include "FriendsListDataAsset.h"
#include "FriendsListControllerComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnlineUsersChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOfflineUsersChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLastConnectedUserChanged,
                                            UDefaultUserDataWrapper *,
                                            Value);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class FRIENDHUD_API UFriendsListControllerComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UFriendsListControllerComponent();

    UFUNCTION(BlueprintCallable, Category = "Friends List")
    void AppendToDatabase(TArray<FDefaultUserData> RawUsersData);

private:
    UFUNCTION(BlueprintCallable, Category = "Friends List|Connection")
    void ReconnectOrDisconnectRandomPlayer();

    virtual void BeginPlay() override;
    virtual void
    TickComponent(float DeltaTime,
                  ELevelTick TickType,
                  FActorComponentTickFunction *ThisTickFunction) override;

    void CacheUsers();
    void BroadcastOnlineUsersChanged();
    void BroadcastOfflineUsersChanged();

    UPROPERTY(VisibleAnywhere,
              BlueprintReadOnly,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    TArray<UDefaultUserDataWrapper *> Database;

    UPROPERTY(VisibleAnywhere,
              BlueprintReadOnly,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    TArray<UDefaultUserDataWrapper *> OnlineUsersCached;

    UPROPERTY(VisibleAnywhere,
              BlueprintReadOnly,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    TArray<UDefaultUserDataWrapper *> OfflineUsersCached;

    UPROPERTY(BlueprintAssignable,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    FOnlineUsersChanged OnlineUsersChanged;

    UPROPERTY(BlueprintAssignable,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    FOfflineUsersChanged OfflineUsersChanged;

    UPROPERTY(BlueprintAssignable,
              Category = "Friend List",
              meta = (AllowPrivateAccess))
    FLastConnectedUserChanged LastConnectedUserChanged;
};
