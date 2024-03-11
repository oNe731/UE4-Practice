// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS() // ��Ʈ
class UE4_PROJECT_API AMyActor : public AActor // A�� ���� ���� ���̹�������
{
	GENERATED_BODY() // ��Ʈ
	
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
	UPROPERTY(VisibleAnywhere) // ���÷��� ���, �Ű������� �ɼ�, VisibleAnywhere : �ۿ��� �߰��� �� �ֵ��� ��
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 Hp = 5;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 Mp = 5;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	float RotateSpeed = 30.f;
};
