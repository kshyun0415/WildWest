// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TownPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WILDWEST_API ATownPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerCharacterSpawn(TSubclassOf<AActor> SelectedCharacter, ECharacterState CharacterState);
	
};