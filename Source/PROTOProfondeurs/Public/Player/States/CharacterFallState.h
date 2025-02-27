// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterMoveState.h"
#include "CharacterFallState.generated.h"

UCLASS()
class PROTOPROFONDEURS_API UCharacterFallState : public UCharacterMoveState
{
	GENERATED_BODY()

public:
	UCharacterFallState();

protected:
	virtual void StateEnter_Implementation(const ECharacterStateID& PreviousStateID) override;

	virtual void StateTick_Implementation(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Fall", meta = (ClampMin = 0.0f, ClampMax = 1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float AirControl = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Fall", meta = (ClampMin = 0.0f))
	float GravityScale = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Fall", DisplayName = "CoyoteTime", meta = (ClampMin = 0.0f, Units = "s"))
	float CoyoteTimeMaxDuration = 0.3f;

private:
	bool bCanDoCoyoteTime = false;

	float CoyoteTime = 0.0f;
};
