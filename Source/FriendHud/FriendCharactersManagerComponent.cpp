#include "FriendCharactersManagerComponent.h"
#include "FriendsListControllerComponent.h"

UFriendCharactersManagerComponent::UFriendCharactersManagerComponent() {
}

void UFriendCharactersManagerComponent::BeginPlay() {
    Super::BeginPlay();
    FriendsListControllerComponent =
        GetOwner()->GetComponentByClass<UFriendsListControllerComponent>();
}

void UFriendCharactersManagerComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
