// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/Data/StatTable.StatTable'"));
	//if (DATA.Succeeded())
	MyStats = DATA.Object;
}

void UMyGameInstance::Init()
{
}

FMyCharacterData* UMyGameInstance::GetStatData(int32 Level)
{
	//MyStats->FindRow<FMyCharacterData>(FString::FromInt(Level), TEXT(""));
}
