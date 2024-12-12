#include "FriendsListControllerComponent.h"
#include "DefaultUserDataWrapper.h"

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

TArray<UDefaultUserDataWrapper *>
UFriendsListControllerComponent::GetDatabaseAsUObjects() const {
    TArray<UDefaultUserDataWrapper *> Result;
    for (auto UserDataStruct : Database) {
        Result.Emplace(UDefaultUserDataWrapper::From(UserDataStruct));
    }

    return Result;
}
