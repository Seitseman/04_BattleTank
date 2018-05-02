// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Templates/Casts.h"


ATankAIController::ATankAIController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::BeginPlay()
{

    Super::BeginPlay();
    APawn* PlayerTank = GetPlayerTank();

    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI cannot find player tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AI has found player tank %s"), *PlayerTank->GetName());
    }
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    auto ThisTank = GetControlledTank();
    auto PlayerTank = GetPlayerTank();
    if (ThisTank && PlayerTank)
    {
        ThisTank->AimAt(PlayerTank->GetActorLocation());
    }
}

ATank * ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
    if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
    {
        return Cast<ATank>(PlayerController->GetPawn());
    }
    return nullptr;
}
