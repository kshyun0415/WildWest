// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TownPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPossessCompleteDelegate);

UENUM(BlueprintType)
enum class EScreenIndex : uint8
{
	ECI_First UMETA(DisplayName = "First Screen"),
	ECI_Second UMETA(DisplayName = "Second Screen"),
	ECI_Third UMETA(DisplayName = "Third Screen"),
	ECI_Fourth UMETA(DisplayName = "Fourth Screen"),

	ECI_MAX UMETA(DisplayName = "DefaultMAX")
};

/**
 * 
 */
UCLASS()
class WILDWEST_API ATownPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(BlueprintAssignable)
	FOnPossessCompleteDelegate PossessCompleteDelegate;
	
private:
	EScreenIndex CurrentScreenIndex;

	UPROPERTY(ReplicatedUsing = OnRep_bIsPossessed)
	bool bIsPossessed{ false };

	UFUNCTION()
	void OnRep_bIsPossessed();

public:
	FORCEINLINE EScreenIndex GetCurrentScreenIndex() { return CurrentScreenIndex; }
	FORCEINLINE void SetCurrentScreenIndex(EScreenIndex NewScreenIndex) { CurrentScreenIndex = NewScreenIndex; }
};
