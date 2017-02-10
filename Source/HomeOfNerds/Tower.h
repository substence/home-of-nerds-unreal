// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class HOMEOFNERDS_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	bool CanFireAt(AActor * Actor);

	bool IsInRange(AActor * Actor);

	float AttackRange = 100.0f;
	float Damage = 10.0;
	float Cooldown = 1.0f;

protected:
	void FireAt(AActor* Actor);

	void StartCoolDown();

	bool IsOnCooldown();

private:
	FDamageEvent DamageEvent;

	float LastFireTime;
};
