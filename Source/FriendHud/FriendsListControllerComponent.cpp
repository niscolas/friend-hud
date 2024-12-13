#include "FriendsListControllerComponent.h"
#include "DefaultUserDataWrapper.h"
#include "FriendHud/DefaultUserData.h"
#include "HelperMacros.h"
#include "Logging/LogMacros.h"
#include "Templates/UnrealTemplate.h"
#include "UObject/UObjectGlobals.h"

UFriendsListControllerComponent::UFriendsListControllerComponent() {
}

void UFriendsListControllerComponent::BeginPlay() {
    Super::BeginPlay();
}

void UFriendsListControllerComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UFriendsListControllerComponent::AppendToDatabase(
    TArray<FDefaultUserData> RawUsersData) {
    for (int i = 0; i < RawUsersData.Num(); i++) {
        Database.Emplace(NewObject<UDefaultUserDataWrapper>(
            GetTransientPackage(), UDefaultUserDataWrapper::StaticClass()));
        Database[i]->SetSourceData(RawUsersData[i]);

        EUserConnectionStateType UserConnectionState =
            RawUsersData[i].GetConnectionState();

        if (UserConnectionState == EUserConnectionStateType::Online) {
            OnlineUsersCached.Emplace(Database[i]);
        } else {
            OfflineUsersCached.Emplace(Database[i]);
        }
    }

    BroadcastOnlineUsersChanged();
    BroadcastOfflineUsersChanged();
}

void UFriendsListControllerComponent::CacheUsers() {
}

void UFriendsListControllerComponent::BroadcastOnlineUsersChanged() {
    OnlineUsersChanged.Broadcast();
}

void UFriendsListControllerComponent::BroadcastOfflineUsersChanged() {
    OfflineUsersChanged.Broadcast();
}

void UFriendsListControllerComponent::ReconnectOrDisconnectRandomPlayer() {
    int RandomUserIndex = FMath::RandRange(0, Database.Num() - 1);
    FDefaultUserData &RandomUserData =
        Database[RandomUserIndex]->GetSourceData();

    if (RandomUserData.GetConnectionState() ==
        EUserConnectionStateType::Online) {
        RandomUserData.SetConnectionState(EUserConnectionStateType::Offline);

        OfflineUsersCached.Emplace(Database[RandomUserIndex]);
        OnlineUsersCached.Remove(Database[RandomUserIndex]);
    } else {
        RandomUserData.SetConnectionState(EUserConnectionStateType::Online);

        OnlineUsersCached.Emplace(Database[RandomUserIndex]);
        OfflineUsersCached.Remove(Database[RandomUserIndex]);
    }

    BroadcastOnlineUsersChanged();
    BroadcastOfflineUsersChanged();
}
