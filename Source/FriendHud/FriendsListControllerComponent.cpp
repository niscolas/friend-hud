#include "FriendsListControllerComponent.h"
#include "DefaultUserDataWrapper.h"

UFriendsListControllerComponent::UFriendsListControllerComponent() {
}

void UFriendsListControllerComponent::BeginPlay() {
    Super::BeginPlay();
    Database.Append(InitialFriendsList->GetContent());
}

void UFriendsListControllerComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

TArray<UDefaultUserDataWrapper *>
UFriendsListControllerComponent::GetDatabaseAsUObjects() {
    TArray<UDefaultUserDataWrapper *> Result;
    for (auto UserDataStruct : Database) {
        Result.Emplace(UDefaultUserDataWrapper::From(UserDataStruct));
    }

    return Result;
}
