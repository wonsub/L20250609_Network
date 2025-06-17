// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPC.generated.h"

class ULobbyWidgetBase;
/**
 * 
 */
UCLASS()
class L20250609_NETWORK_API ALobbyPC : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category="UI", BlueprintReadOnly)
	TObjectPtr<ULobbyWidgetBase> WidgetObject;

	UFUNCTION(Server, Reliable, WithValidation)
	void C2S_SendMessage(const FText& Message); //(call Clinet->Server)
	bool C2S_SendMessage_Validate(class FText const& Message); //(Server)
	void C2S_SendMessage_Implementation(class FText const& Message); //(execute server)

	UFUNCTION(Client, Unreliable)
	void S2C_SendMessage(const FText& Message); // (call server)
	void S2C_SendMessage_Implementation(const FText& Message); //(execute client)


};
