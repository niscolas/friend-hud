#include "FriendsListConnectionComponent.h"
#include "HelperMacros.h"
#include "Math/UnrealMathUtility.h"

UFriendsListConnectionComponent::UFriendsListConnectionComponent() {
}

void UFriendsListConnectionComponent::BeginPlay() {
    Super::BeginPlay();
}

void UFriendsListConnectionComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
