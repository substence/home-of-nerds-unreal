// Fill out your copyright notice in the Description page of Project Settings.

#include "HomeOfNerds.h"
#include "Tower.h"
#include "Minion.h"


// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATower::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMinion::StaticClass(), FoundActors);
	for (size_t i = 0; i < FoundActors.Num(); i++)
	{
		AActor* actor = FoundActors[i];
		if (CanFireAt(actor))
		{
			FireAt(actor);
			Reload();
		}
	}
}

bool ATower::CanFireAt(AActor* Actor)
{
	return !IsOnCooldown() && IsInRange(Actor);
}

bool ATower::IsInRange(AActor* Actor)
{
	return (Actor->GetActorLocation() - this->GetActorLocation()).Size < AttackRange;
}

void ATower::FireAt(AActor * Actor)
{	
	Actor->TakeDamage(Damage, DamageEvent, this->GetInstigatorController(), this);
}

void ATower::Reload()
{
	UWorld* const World = GetWorld();

	if (World != NULL)
	{
		LastFireTime = World->GetTimeSeconds;
	}
}

bool ATower::IsOnCooldown()
{
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		return false;
	}
	return World->TimeSeconds - LastFireTime < Cooldown;
}

