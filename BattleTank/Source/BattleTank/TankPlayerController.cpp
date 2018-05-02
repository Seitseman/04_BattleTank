// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Templates/Casts.h"

ATank * ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ContrrolledTank = GetControlledTank();
    if (!ContrrolledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController NOT possesing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController possesing a tank %s"), *ContrrolledTank->GetName());
    }

    UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController::BeginPlay"));
}
