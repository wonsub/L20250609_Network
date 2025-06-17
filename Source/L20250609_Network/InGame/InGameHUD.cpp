// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"
#include "Engine/Canvas.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

void AInGameHUD::DrawHUD()
{

	Super::DrawHUD();

	ACharacter* Pawn= Cast<ACharacter>(GetOwningPawn());
	if (IsValid(Pawn))
	{
		float Speed = Pawn->GetVelocity().Size();
		float SpeedRatio = Speed / 300.0f;

		float Unit = Canvas->SizeX / 100.0f;

		float CenterX = Canvas->SizeX / 2.0f;
		float CenterY = Canvas->SizeY / 2.0f;

		float CrosshairStartX = CenterX - (Unit * 4);
		float CrosshairStartY = CenterY - (Unit * 2);

		float CrosshairEndX = CenterX - (Unit * 2);
		float CrosshairEndY = CenterY + (Unit * 2);

		//Left
		DrawLine(CenterX - (Unit * 2)-(Unit* SpeedRatio),
			CenterY,
			CenterX - (Unit * SpeedRatio),
			CenterY,
			FLinearColor::Red, 2.0f);

		//Right
		DrawLine(CenterX + (Unit * SpeedRatio),
			CenterY,
			CenterX + (Unit * 2)+(Unit * SpeedRatio),
			CenterY,
			FLinearColor::Red, 2.0f);

		//Up
		DrawLine(CenterX,
			CenterY - (Unit * SpeedRatio),
			CenterX,
			CenterY - (Unit * 2)- (Unit * SpeedRatio),
			FLinearColor::Red, 2.0f);

		//Down
		DrawLine(CenterX,
			CenterY + (Unit * SpeedRatio),
			CenterX,
			CenterY + (Unit * 2) + (Unit * SpeedRatio),
			FLinearColor::Red, 2.0f);


	}
	if (bShowHeight)
	{

		FVector FootStep = Pawn->GetActorLocation();
		FootStep.Z -= Pawn -> GetCapsuleComponent()->GetScaledCapsuleHalfHeight();


		FVector Height = Pawn->GetActorLocation();
		Height.Z += Pawn->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

		

		DrawDebugLine(GetWorld(),
			FootStep,
			Height,
			FColor::Green,
			false,
			0.5f);

		DrawDebugCapsule(
			GetWorld(),
			Pawn->GetActorLocation(),
			Pawn->GetCapsuleComponent()->GetScaledCapsuleHalfHeight(),
			Pawn->GetCapsuleComponent()->GetScaledCapsuleRadius(),
			Pawn->GetActorQuat(),
			FColor::Green
		);
	}
	

}

void AInGameHUD::ShowHeight()
{
	bShowHeight = !bShowHeight;
}
