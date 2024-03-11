// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS() // 세트
class UE4_PROJECT_API AMyActor : public AActor // A가 붙은 것은 네이밍컨벤션
{
	GENERATED_BODY() // 세트
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere) // 리플랙션 기능, 매개변수는 옵션, VisibleAnywhere : 밖에서 추가할 수 있도록 함
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 Hp = 5;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 Mp = 5;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	float RotateSpeed = 30.f;
};
