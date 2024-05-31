// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimePointBase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class TIMEPOWER1_API UTimePointBase : public UObject
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite)
	float Time = 0.0f;

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	UTimePointBase* Interpolate(const UTimePointBase* other, float distance);

private:
	virtual UTimePointBase* Interpolate_Implementation(const UTimePointBase* other, float distance) const;
};
