// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

static int32 Step() {
	int32 stepSize = FMath::RandRange(0, 1);

	return stepSize;
}

static float Distance(FVector2D first, FVector2D second) {
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

int32 TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		return 1;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
		return 0;
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector2D Pos = { 0, 0 };

	float TotalMoveDistance = 0.0f;
	int32 EventCount = 0;

	for (int32 i = 0; i < 10; i++) {
		FVector2D TempPos = Pos;

		Pos.X += Step();
		Pos.Y += Step();

		float DistancePoint = Distance(TempPos, Pos);
		TotalMoveDistance += DistancePoint;

		UE_LOG(LogTemp, Log, TEXT("The Present Position : (%.0f, %.0f), Distance : %.3f"), Pos.X, Pos.Y, DistancePoint);
		EventCount += TriggerEventWithProbability(50);
	}
	UE_LOG(LogTemp, Log, TEXT("Total Move Distance : %.3f, EventCount : %d"), TotalMoveDistance, EventCount);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



