// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "D:/UE_4.26/Projects/MyProject5/Plugins/BrainFlowPlugin/Source/BrainFlowPlugin/Public/BrainFlowPlugin.h"

#include "MU_BCI.generated.h"

UCLASS()
class MYPROJECT5_API AMU_BCI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMU_BCI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	int32 BCI_GetData();

};
