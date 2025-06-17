// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidgetBase.generated.h"


class UEditableTextBox;
class UButton;
/**
 * 
 */
UCLASS()
class L20250609_NETWORK_API UTitleWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta=(WidgetBinding), VisibleAnywhere, Category="Components",  BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> UserIdText;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> PasswordText;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> ServerIPText;

	UPROPERTY(meta = (WidgetBinding), VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UButton> StartServerButton;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UButton> ConnectButton;

	UFUNCTION()
	void OnClickServerStartButton();

	UFUNCTION()
	void OnClickConnectButton();

	void SaveUserId();

};
