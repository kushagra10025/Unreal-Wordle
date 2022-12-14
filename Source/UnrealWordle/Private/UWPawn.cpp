// Fill out your copyright notice in the Description page of Project Settings.


#include "UWPawn.h"

#include "Camera/CameraComponent.h"
#include "GameMode/UnrealWordleGM.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/UnrealWordleLibrary.h"

AUWPawn::AUWPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(RootComponent);

	UnrealWordleGMRef = Cast<AUnrealWordleGM>(UGameplayStatics::GetGameMode(this));
}

void AUWPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUWPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("IA_AnyKey", IE_Pressed, this, &AUWPawn::AnyKeyPressed);
	PlayerInputComponent->BindAction("IA_Backspace", IE_Pressed, this, &AUWPawn::BackspaceKeyPressed);
	PlayerInputComponent->BindAction("IA_Enter", IE_Pressed, this, &AUWPawn::EnterKeyPressed);

}

void AUWPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUWPawn::AnyKeyPressed(FKey Key)
{
	if(UUnrealWordleLibrary::IsLetter(Key.GetDisplayName().ToString()))
	{
		if(UnrealWordleGMRef)
		{
			UnrealWordleGMRef->OnLetterTyped(Key.GetDisplayName().ToString());
		}
	}
}

void AUWPawn::BackspaceKeyPressed(FKey Key)
{
	if(UnrealWordleGMRef)
	{
		UnrealWordleGMRef->OnBackspaceTyped();
	}
}

void AUWPawn::EnterKeyPressed(FKey Key)
{
	if(UnrealWordleGMRef)
	{
		UnrealWordleGMRef->SubmitWord();
	}
}


