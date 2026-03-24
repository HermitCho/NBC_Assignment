#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
    RootComponent = Mesh;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    SetActorLocation(FVector(0.0f, 50.0f, 0.0f));

    GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyActor::ExecuteStep, 0.3f, true);
}

void AMyActor::ExecuteStep()
{
    if (CurrentCount >= 10)
    {
        GetWorldTimerManager().ClearTimer(MemberTimerHandle);
        FString FinMsg = FString::Printf(TEXT("총 이동한 거리 : X=%.1f, Y=%.1f, Z=%.1f"), LocSum.X, LocSum.Y, LocSum.Z);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FinMsg);
        FString FinMsg2 = FString::Printf(TEXT("총 이벤트 발생 : %d"), totalEvent);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FinMsg2);
        return;
    }

    Move();
    Turn();
    CurrentCount++;


    if (GEngine)
    {
        FVector Loc = GetActorLocation();
        FString Msg = FString::Printf(TEXT("Step: %d | Pos: X=%.1f, Y=%.1f, Z=%.1f"),
            CurrentCount, Loc.X, Loc.Y, Loc.Z);
        LocSum += {Loc.X, Loc.Y, Loc.Z};
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, Msg);
    }
}

void AMyActor::Move()
{
    int random = FMath::RandRange(0, 1);

    FVector Loc = GetActorLocation();
    float RandDist = FMath::FRandRange(-500.0f, 500.0f);
    SetActorLocation(Loc + FVector(RandDist, RandDist, 0.0f));

    if (random == 1)
    {
        TriggerEvent();
    }
}

void AMyActor::Turn()
{
    SetActorRotation(GetActorRotation() + FRotator(0.0f, FMath::FRandRange(0.0f, 360.0f), 0.0f));
}

void AMyActor::TriggerEvent()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("이벤트 발생!"));
        ++totalEvent;
    }
}