// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH")); // CreateDefaultSubobject는 스마트 포인터와 같은 기능을 함.
	RootComponent = Mesh; // 컴포넌트를 추가하면 한개는 루트컴포넌트로 만들어줘야함.

	ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Statue.SM_Statue'"));
	if (SM.Succeeded())
		Mesh->SetStaticMesh(SM.Object);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 카테고리, 로깅 수준, 형식, 인자
	//UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);

	// 회전
	AddActorLocalRotation(FRotator(0.f, RotateSpeed* DeltaTime, 0.f)); // Y, Z, X//
}

