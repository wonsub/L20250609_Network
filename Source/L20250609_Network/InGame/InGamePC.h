// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InGamePC.generated.h"


class UInputAction;
/**
 * 
 */

UCLASS()
class L20250609_NETWORK_API AInGamePC : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TObjectPtr<UUserWidget> InventoryWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> InventoryTemplate;

	UFUNCTION(BlueprintCallable)
	void ShowInventory(bool bShow);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	uint32 bShowInventory : 1;


	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputAction> InventoryInput;

	void SwitchInventory();

	virtual void SetupInputComponent() override;


};
