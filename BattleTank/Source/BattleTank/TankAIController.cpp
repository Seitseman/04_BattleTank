// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Pawn.h"


void ATankAIController::BeginPlay()
{

    Super::BeginPlay();
    APawn* PossessedPawn = GetPawn();

    if (!PossessedPawn)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI  NOT possesing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AI possesing a tank %s"), *PossessedPawn->GetName());
    }
}
