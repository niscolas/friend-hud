#include "FriendCharactersManagerComponent.h"
#include "FriendCharacter.h"
#include "FriendsListControllerComponent.h"
#include "HelperMacros.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NavigationSystem.h"

UFriendCharactersManagerComponent::UFriendCharactersManagerComponent() {
}

void UFriendCharactersManagerComponent::BeginPlay() {
    Super::BeginPlay();
}

void UFriendCharactersManagerComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

const TSubclassOf<AActor>
UFriendCharactersManagerComponent::GetCharacterBlueprintForUserData(
    UDefaultUserDataWrapper *UserData) const {
    TSubclassOf<AActor> Result;
    UTIL_RETURN_VALUE_IF(!UserData, Result);

    const UTexture2D *UserIcon = UserData->GetSourceData().GetIcon();
    if (UserIcon) {
        if (const TSubclassOf<AActor> *FoundBlueprint =
                IconToCharacterBlueprintMap.Find(UserIcon)) {
            Result = *FoundBlueprint;
        }
    }

    if (!Result) {
        Result = GetRandomCharacterBlueprint();
    }

    return Result;
}

TSubclassOf<AActor>
UFriendCharactersManagerComponent::GetRandomCharacterBlueprint() const {
    int RandomIndex =
        FMath::RandRange(0, FallbackCharacterBlueprints.Num() - 1);
    return FallbackCharacterBlueprints[RandomIndex];
}

void UFriendCharactersManagerComponent::SpawnAndSetupFriendCharacters(
    const TArray<UDefaultUserDataWrapper *> &Database) {
    for (auto UserData : Database) {
        TSubclassOf<AActor> CharacterBlueprint =
            GetCharacterBlueprintForUserData(UserData);

        UTIL_CONTINUE_IF(!CharacterBlueprint);

        SpawnAndSetupFriendCharacter(CharacterBlueprint, UserData);
    }
}

void UFriendCharactersManagerComponent::SpawnAndSetupFriendCharacter(
    TSubclassOf<AActor> CharacterBlueprint, UDefaultUserDataWrapper *UserData) {
    UNavigationSystemV1 *NavSystem =
        UNavigationSystemV1::GetCurrent(GetWorld());
    FNavLocation NavLocation;
    NavSystem->GetRandomPointInNavigableRadius(GetOwner()->GetActorLocation(),
                                               SpawnAreaRadius, NavLocation);

    FRotator SpawnRotation(0.0f, 0.0f, 0.0f);

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = GetOwner();
    SpawnParams.SpawnCollisionHandlingOverride =
        ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    AActor *CharacterInstanceActor = GetWorld()->SpawnActor<AActor>(
        CharacterBlueprint, NavLocation, SpawnRotation, SpawnParams);

    UTIL_LOG_AND_RETURN_IF(!CharacterInstanceActor, LogTemp, Warning,
                           "Failed to spawn actor.");

    if (CharacterInstanceActor->Implements<UFriendCharacter>()) {
        IFriendCharacter::Execute_Setup(CharacterInstanceActor, UserData);
    }
}
