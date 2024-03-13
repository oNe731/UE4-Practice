// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	//DefaultPawnClass = AMyCharacter::StaticClass();

	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/Blueprints/Bp_MyCharacter.Bp_MyCharacter_C'")); // _C 추가 입력
	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
}