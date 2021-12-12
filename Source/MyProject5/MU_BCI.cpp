// Fill out your copyright notice in the Description page of Project Settings.


#include "MU_BCI.h"
#include <windows.h>






// Sets default values
AMU_BCI::AMU_BCI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMU_BCI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMU_BCI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMU_BCI::BCI_GetData()
{
    struct BrainFlowInputParams params;
    int board_id = 39;
    BoardShim* board = new BoardShim(board_id, params);


    board->prepare_session();
    board->start_stream();

    Sleep(10000);

    board->stop_stream();
    BrainFlowArray<double, 2> data = board->get_current_board_data(10);
    board->release_session();

    delete board;

    json board_descr = BoardShim::get_board_descr(board_id);
    int sampling_rate = (int)board_descr["sampling_rate"];

    return 0;

}