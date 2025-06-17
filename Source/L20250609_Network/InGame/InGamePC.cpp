// Fill out your copyright notice in the Description page of Project Settings.


#include "InGamePC.h"
#include "Blueprint/UserWidget.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"



void AInGamePC::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;


	if (IsLocalPlayerController())
	{
		InventoryWidget = CreateWidget<UUserWidget>(this, InventoryTemplate);

		InventoryWidget->AddToViewport();
		InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
		bShowInventory = false;
	}
}



void AInGamePC::ShowInventory(bool bShow)
{
	if (bShow)
	{

		bShowMouseCursor = true;
		SetInputMode(FInputModeGameAndUI());

		bShowInventory = bShow;
		InventoryWidget->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		bShowMouseCursor = false;
		SetInputMode(FInputModeGameOnly());

		bShowInventory = bShow;
		InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);

	}
}


void AInGamePC::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(InputComponent);
	if (IsValid(UIC))
	{
		UIC->BindAction(InventoryInput, ETriggerEvent::Completed, this, &AInGamePC::SwitchInventory);
	}
}

void AInGamePC::SwitchInventory()
{
	bShowInventory = !bShowInventory;
	ShowInventory(bShowInventory);
}
