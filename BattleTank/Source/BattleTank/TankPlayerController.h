// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    explicit ATankPlayerController();
	
    void BeginPlay() override;
    void Tick(float DeltaSeconds) override;

private:
    ATank * GetControlledTank() const;
    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;

    bool GetLookDirection(const FVector2D &ScreenLocation, FVector &LookDirection) const;

    UPROPERTY(EditAnywhere)
        float CrossHairXLocation = 0.5f;
    UPROPERTY(EditAnywhere)
        float CrossHairYLocation = 1.0f / 3;
	
};
