// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"


//Server, Client
void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	//#include "WB_Lobby"
	FSoftClassPath LobbyWidgetPath(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Bluprints/Lobby/WB_Lobby.WB_Lobby_C'"));

	UClass* WidgetClass = LobbyWidgetPath.TryLoadClass<ULobbyWidgetBase>();
	if (WidgetClass)
	{
		if (IsLocalPlayerController())
		{
			//ULobbyWidgetBase* WidgetObject = new WB_Lobby
			WidgetObject = CreateWidget<ULobbyWidgetBase>(this, WidgetClass);

			//Listen Server(client), Client 
			WidgetObject->AddToViewport();

			if (HasAuthority())
			{
				WidgetObject->ShowStartButton();
			}

			bShowMouseCursor = true;

			SetInputMode(FInputModeGameAndUI());
		}
	}

}

bool ALobbyPC::C2S_SendMessage_Validate(FText const& Message)
{
	return true;
}

void ALobbyPC::C2S_SendMessage_Implementation(FText const& Message)
{
	//at Server
	//정보를 가공 하던 다시 보내주던
	UE_LOG(LogTemp, Warning, TEXT("server %s"), *Message.ToString());

	for (auto Iter = GetWorld()->GetPlayerControllerIterator(); Iter; ++Iter)
	{
		ALobbyPC* PC = Cast<ALobbyPC>(*Iter);
		if (IsValid(PC))
		{
			PC->S2C_SendMessage(Message);
		}
	}
}

void ALobbyPC::S2C_SendMessage_Implementation(const FText& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("client %s"), *Message.ToString());
	if (WidgetObject)
	{
		WidgetObject->AddMessage(Message);
	}
}
