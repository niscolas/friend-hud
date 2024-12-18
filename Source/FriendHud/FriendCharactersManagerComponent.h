#pragma once

#include "Components/ActorComponent.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "CoreMinimal.h"
#include "FriendHud/DefaultUserDataWrapper.h"
#include "FriendsListControllerComponent.h"
#include "Math/Color.h"
#include "FriendCharactersManagerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class FRIENDHUD_API UFriendCharactersManagerComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UFriendCharactersManagerComponent();

private:
    UFUNCTION(BlueprintCallable,
              Category = "Friends",
              meta = (AllowPrivateAccess))
    void SpawnAndSetupFriendCharacters(
        const TArray<UDefaultUserDataWrapper *> &Database);

    virtual void BeginPlay() override;

    virtual void
    TickComponent(float DeltaTime,
                  ELevelTick TickType,
                  FActorComponentTickFunction *ThisTickFunction) override;

    const TSubclassOf<AActor>
    GetCharacterBlueprintForUserData(UDefaultUserDataWrapper *UserData) const;

    TSubclassOf<AActor> GetRandomCharacterBlueprint() const;

    void SpawnAndSetupFriendCharacter(TSubclassOf<AActor> CharacterBlueprint,
                                      UDefaultUserDataWrapper *UserData);

    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "Friends",
              meta = (AllowPrivateAccess))
    TMap<UTexture2D *, TSubclassOf<AActor>> IconToCharacterBlueprintMap;

    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "Friends",
              meta = (AllowPrivateAccess))
    TArray<TSubclassOf<AActor>> FallbackCharacterBlueprints;

    UPROPERTY(EditAnywhere,
              BlueprintReadWrite,
              Category = "Friends",
              meta = (AllowPrivateAccess))
    float SpawnAreaRadius = 2000;
};
