// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TimeManager.h"		
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimeReversalGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TIMEPOWER1_API ATimeReversalGameMode : public AGameModeBase
{
	GENERATED_BODY()
	public:
public:
	// Called before actor initializations
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	public:
		UFUNCTION(BlueprintCallable)
		ATimeManager* GetTimeManager();
    protected:
		UPROPERTY(BlueprintReadOnly)
		ATimeManager* TimeManager = nullptr;

};
