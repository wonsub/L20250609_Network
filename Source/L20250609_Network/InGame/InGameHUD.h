// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class L20250609_NETWORK_API AInGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;

	int8 bShowHeight : 1;

	//콘솔에 사용가능
	UFUNCTION(Exec)
	void ShowHeight();

};
