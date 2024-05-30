/*/ Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATimeManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}*/

#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentTimeFactor = NormalTimeFactor;
}

void ATimeManager::BeginTimeReverse()
{
	CurrentTimeFactor = ReverseTimeFactor;
}

void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

