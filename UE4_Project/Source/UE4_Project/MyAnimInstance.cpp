// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyCharacter.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Revenant_Skeleton_Montage.Revenant_Skeleton_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

// ��� ������ �� �����ϰ� �� �����Ӵ� �ش� �Լ��� ���´�.
void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn))
	{
		Speed = pawn->GetVelocity().Size();

		auto Character = Cast<AMyCharacter>(pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();

			Vertical = Character->UpDownValue;
			Horizontal = Character->LeftRightValue;
		}
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
	//if (!Montage_IsPlaying(AttackMontage)) // �÷������� �ƴϾ��ٸ�
	//{
		Montage_Play(AttackMontage, 1.f);
	//}
}

void UMyAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UMyAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	return FName(*FString::Printf(TEXT("Attack%d"), SectionIndex));
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	//UE_LOG(LogTemp, Log, TEXT("AnimNotify_AttackHit"));
	OnAttackHit.Broadcast(); // ���� �޼��� ����
}
