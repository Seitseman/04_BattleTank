// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Templates/Casts.h"

ATankPlayerController::ATankPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

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

void ATankPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank())
    {
        return;
    }
    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation))
    {
        //UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    bool bHitLandscape = true;
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);

    FVector2D ScreenLocation = FVector2D(CrossHairXLocation *  ViewportSizeX, CrossHairYLocation * ViewportSizeY);
    UE_LOG(LogTemp, Warning, TEXT("ScreenLocation is: %s"), *ScreenLocation.ToString());

    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        UE_LOG(LogTemp, Warning, TEXT("WorldDirection is: %s"), *LookDirection.ToString());
    }


    return bHitLandscape;
}

bool ATankPlayerController::GetLookDirection(const FVector2D &ScreenLocation, FVector &LookDirection) const
{
    FVector CameraWorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

